#ifndef DLDL_LPDDEF_AST_LISTENER_USER_LPDDEF_H
#define DLDL_LPDDEF_AST_LISTENER_USER_LPDDEF_H

#include "DLDL_LPDDEF/Ast/Listener/EnterExitListener.h"
#include "DLDL_LPDDEF/Ast/Reference/Access.h"
#include "DLDL_LPDDEF/IR/LPDDEF.h"
#include "DLDL_LPDDEF_DF/Ast/Listener/User/DF.h"
#include "DLDL_LPDDEF_DF/Bison/Parser.h"
#include <limits>

namespace DLDL_LPDDEF::ast::listener::user
{
	class LpdDef : public ::DLDL_LPDDEF::ast::listener::EnterExitListener
	{
	private:
		DLDL::ir::LpdDef* lpdDef;

	public:
		LpdDef()
		{
			lpdDef = new ::DLDL::ir::LpdDef();
		}
		~LpdDef() override = default;

	public:
		void ListenEntry(const DLDL_LPDDEF::ast::node::argument* node) override
		{
			const auto argument_name =
				ToLower(reference::Access(node).argument_name().GetContent()[0]->GetText());
			if (argument_name == "name")
			{
				ParseLPDName(node);
			}
			else if (argument_name == "type")
			{
				ParseLPDType(node);
			}
			else if (argument_name == "description")
			{
				ParseLPDDescription(node);
			}
			else if (argument_name == "description_details")
			{
				// ParseLPDDescriptionDetailed(node);
			}
			else if (argument_name == "note")
			{
				// ParseLPDNote(node);
			}
			else if (argument_name == "ldo")
			{
				ParseLdoForwardDeclarations(node);
			}
			else if (argument_name == "struct")
			{
				// ParseStructForwardDeclaration(node);
			}
			else if (argument_name == "enumeration")
			{
				// ParseEnumerationForwardDeclaration(node);
			}
			else if (argument_name == "function")
			{
				ParseFunction(node);
			}
			else if (argument_name == "dependency")
			{
				ParseDependency(node);
			}
			else if (argument_name == "generate")
			{
				ParseGenerate(node);
			}
			else if (argument_name == "explicit")
			{
				ParseExplicitLpd(node);
			}
			else if (argument_name == "data")
			{
				ParseData(node);
			}
		}

		void ParseLPDName(const DLDL_LPDDEF::ast::node::argument* node)
		{
			reference::Access_if<node::VARNAME>(
				node->GetIndex(1), [this](reference::Access<node::VARNAME> varname) {
					lpdDef->SetLPDName(varname.GetContent()[0]->GetText());
				});
		}

		void ParseLPDType(const DLDL_LPDDEF::ast::node::argument* node)
		{
			reference::Access_if<node::VARNAME>(
				node->GetIndex(1), [this](reference::Access<node::VARNAME> varname) {
					const auto type = ToLower(varname.GetContent()[0]->GetText());
					lpdDef->SetLPDType(GetLPDType(type));
				});
		}

		std::string ConstructFormattedLines(const DLDL_LPDDEF::ast::node::argument* node)
		{
			std::string output;

			// Get minimal indentation, this will be the base indentation to remove
			// This allows more formatting options by the user
			bool changed = false;
			std::size_t minimal_count = std::numeric_limits<std::size_t>::max();
			reference::Access(node).argument_block().argument_stmt().for_all(
				[&, this](reference::Access<node::argument_stmt> ref_) {
					const auto ref = ref_.GetContent()[0]->GetIndex(0);
					changed = false;
					std::size_t tmp_count = 0;
					reference::Access_if<node::INDENTED_VALUE>(
						ref, [&, this](reference::Access<node::INDENTED_VALUE> value) {
							for (auto character : value.GetContent()[0]->GetText())
							{
								if (character == ' ' || character == '\t')
								{
									tmp_count++;
								}
								else
								{
									break;
								}
							}
							changed = true;
						});

					if (changed)
					{
						if (tmp_count < minimal_count)
						{
							minimal_count = tmp_count;
						}
					}
				});

			reference::Access(node).argument_block().argument_stmt().for_all(
				[&, this](reference::Access<node::argument_stmt> ref_) {
					const auto ref = ref_.GetContent()[0]->GetIndex(0);
					reference::Access_if<node::INDENTED_VALUE>(
						ref, [&, this](reference::Access<node::INDENTED_VALUE> value) {
							const auto text =
								value.GetContent()[0]->GetText().erase(0, minimal_count);
							output += text;
							if (text[text.size() - 1] == '\r')
							{
								output += '\n';
							}
						});
					reference::Access_if<node::VARNAME>(
						ref, [&, this](reference::Access<node::VARNAME> value) {
							const auto text = value.GetContent()[0]->GetText();
							output += text + '\n';
						});
				});

			return output;
		}

		void ParseLPDDescription(const DLDL_LPDDEF::ast::node::argument* node)
		{
			bool finished = false;
			reference::Access_if<node::VARNAME>(
				node->GetIndex(1), [&, this](reference::Access<node::VARNAME> varname) {
					finished = true;
					lpdDef->SetDescription(varname.GetContent()[0]->GetText());
				});

			if (finished)
			{
				return;
			}

			const auto description = ConstructFormattedLines(node);
			lpdDef->SetDescription(description);
		}

		void ParseLdoForwardDeclarations(const DLDL_LPDDEF::ast::node::argument* node)
		{
		}

		void ParseDependency(const node::argument* node)
		{
			auto lines = Split(ConstructFormattedLines(node), '\n');
			for (auto line : lines)
			{
				for (auto i = line.size() - 1; i > 0; i--)
				{
					if (line[i] == ' ' || line[i] == '\t' || line[i] == '\r' || line[i] == '\n')
					{
						line.pop_back();
					}
					else
					{
						break;
					}
				}

				lpdDef->AddDependency({line});
			}
		}

		void ParseData(const node::argument* node)
		{
			auto df = DLDL_LPDDEF_DF::ast::listener::user::LpdDefDf();
			const auto dfParser = DLDL_LPDDEF_DF::parser::Parser();
			const std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(
				dfParser.Parse(ConstructFormattedLines(node)));
			if (ast == nullptr)
			{
				std::cout << "Format could not get parsed by Data Format Parser!\n";
				return;
			}

			df.Dispatch(ast->GetStartNode());
			lpdDef->SetLpdMembers(df.GetDataMembers());
		}

		void ParseFunction(const node::argument* node)
		{
			lpdDef->AddFunction({ConstructFormattedLines(node)});
		}

		void ParseGenerate(const node::argument* node)
		{
			if (ToLower(reference::Access(node).VARNAME().GetContent()[0]->GetText()) != "true")
			{
				lpdDef->Generate = false;
			}
		}

		void ParseExplicitLpd(const node::argument* node)
		{
			if (ToLower(reference::Access(node).VARNAME().GetContent()[0]->GetText()) == "true")
			{
				lpdDef->Explicit = true;
			}
		}

	public:
		DLDL::ir::LpdDef* GetLpdDef() const
		{
			return lpdDef;
		}

	private:
		std::vector<std::string> Split(const std::string& str, char splitCharacter)
		{
			std::vector<std::string> output;
			std::string tmp;
			for (auto i = 0; i < str.size(); i++)
			{
				if (str[i] == splitCharacter)
				{
					output.push_back(tmp);
					tmp.clear();
				}
				else
				{
					tmp += str[i];
				}
			}
			if (!tmp.empty())
			{
				output.push_back(tmp);
				tmp.clear();
			}

			return output;
		}

		std::string ToLower(std::string str)
		{
			for (auto i = 0; i < str.size(); i++)
			{
				if (::isalpha(str[i]))
					str[i] = ::tolower(str[i]);
			}

			return str;
		}

		DLDL::ir::LPDType GetLPDType(const std::string& name)
		{
			static const std::map<std::string, DLDL::ir::LPDType> mapStrToType = {
				{"", DLDL::ir::LPDType::tool},
				{"main", DLDL::ir::LPDType::main},
				{"special", DLDL::ir::LPDType::special},
				{"tool", DLDL::ir::LPDType::tool},
			};
			
			auto iter = mapStrToType.find(ToLower(name));
			if (iter == mapStrToType.end())
			{
				return DLDL::ir::LPDType::tool;
			}

			return iter->second;
		}
	};
}

#endif // DLDL_LPDDEF_AST_LISTENER_USER_LPDDEF_H
