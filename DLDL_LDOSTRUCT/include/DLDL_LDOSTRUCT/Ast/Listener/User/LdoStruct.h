#ifndef DLDL_LDOSTRUCT_AST_LISTENER_USER_LDOSTRUCT_H
#define DLDL_LDOSTRUCT_AST_LISTENER_USER_LDOSTRUCT_H

#include "DLDL_LDOSTRUCT/Ast/Listener/EnterExitListener.h"
#include "DLDL_LDOSTRUCT/Ast/Reference/Access.h"
#include "DLDL_LPDDEF/IR/LPDDEF.h"
#include "DLDL_LPDDEF_DF/Ast/Listener/User/DF.h"
#include "DLDL_LPDDEF_DF/Bison/Parser.h"
#include "DLDL_LPDDEF_EF/Ast/Listener/User/EF.h"
#include "DLDL_LPDDEF_EF/Bison/Parser.h"
#include <limits>

namespace DLDL_LDOSTRUCT::ast::listener::user
{
	class LdoStruct : public ::DLDL_LDOSTRUCT::ast::listener::EnterExitListener
	{
	private:
		DLDL::ir::LDO* Ldo;

	public:
		LdoStruct()
		{
			Ldo = new ::DLDL::ir::LDO();
		}
		~LdoStruct() override = default;

	public:
		void ListenEntry(const DLDL_LDOSTRUCT::ast::node::argument* node) override
		{
			const auto argument_name =
				ToLower(reference::Access(node).argument_name().GetContent()[0]->GetText());
			if (argument_name == "name")
			{
				ParseLDOName(node);
			}
			else if (argument_name == "type")
			{
				ParseLDOType(node);
			}
			else if (argument_name == "description")
			{
				ParseLDODescription(node);
			}
			else if (argument_name == "description_details")
			{
				// ParseLDODescriptionDetailed(node);
			}
			else if (argument_name == "note")
			{
				// ParseLDONote(node);
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
			else if (argument_name == "dependency")
			{
				// ParseDependency(node);
			}
			else if (argument_name == "function")
			{
				ParseFunction(node);
			}
			else if (argument_name == "generate")
			{
				ParseGenerate(node);
			}
			else if (argument_name == "include")
			{
				ParseInclude(node);
			}
			else if (argument_name == "source_include")
			{
				ParseSourceInclude(node);
			}
			else if (argument_name == "data" || argument_name == "members")
			{
				ParseData(node);
			}
		}

		void ParseGenerate(const node::argument* node)
		{
			if (ToLower(reference::Access(node).VARNAME().GetContent()[0]->GetText()) != "true")
			{
				Ldo->Generate = false;
			}
		}

		void ParseLDOName(const DLDL_LDOSTRUCT::ast::node::argument* node)
		{
			reference::Access_if<node::VARNAME>(
				node->GetIndex(1), [this](reference::Access<node::VARNAME> varname) {
					Ldo->SetName(varname.GetContent()[0]->GetText());
				});
		}

		void ParseLDOType(const DLDL_LDOSTRUCT::ast::node::argument* node)
		{
			reference::Access_if<node::VARNAME>(
				node->GetIndex(1), [this](reference::Access<node::VARNAME> varname) {
					const auto type = ToLower(varname.GetContent()[0]->GetText());
					Ldo->SetType(GetLDOType(type));
				});
		}

		std::string ConstructFormattedLines(const DLDL_LDOSTRUCT::ast::node::argument* node)
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

		void ParseLDODescription(const DLDL_LDOSTRUCT::ast::node::argument* node)
		{
			bool finished = false;
			reference::Access_if<node::VARNAME>(
				node->GetIndex(1), [&, this](reference::Access<node::VARNAME> varname) {
					finished = true;
					Ldo->SetDescription(varname.GetContent()[0]->GetText());
				});

			if (finished)
			{
				return;
			}

			const std::string description = ConstructFormattedLines(node);

			Ldo->SetDescription(description);
		}

		void ParseLdoForwardDeclarations(const DLDL_LDOSTRUCT::ast::node::argument* node)
		{
		}

		void ParseData(const node::argument* node)
		{
			if (Ldo->GetLDOType() == DLDL::ir::LDOType::Ldo ||
				Ldo->GetLDOType() == DLDL::ir::LDOType::Struct)
			{
				auto df = DLDL_LPDDEF_DF::ast::listener::user::LpdDefDf();
				const auto dfParser = DLDL_LPDDEF_DF::bison::parser::Parser();
				const std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(
					dfParser.Parse(ConstructFormattedLines(node)));
				if (ast == nullptr)
				{
					std::cout << "Format could not get parsed by Data Format Parser!\n";
					return;
				}

				df.Dispatch(ast->GetStartNode());
				Ldo->SetDataMembers(df.GetDataMembers());
			}
			else if (Ldo->GetLDOType() == DLDL::ir::LDOType::Enumeration)
			{
				auto ef = DLDL_LPDDEF_EF::ast::listener::user::LpdDefEf();
				const auto efParser = DLDL_LPDDEF_EF::bison::parser::Parser();
				const std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(
					efParser.Parse(ConstructFormattedLines(node)));
				if (ast == nullptr)
				{
					std::cout << "Format could not get parsed by Data Format Parser!\n";
					return;
				}

				ef.Dispatch(ast->GetStartNode());
				Ldo->SetDataMembers(ef.GetDataMembers());
			}
		}

		void ParseFunction(const node::argument* node)
		{
			Ldo->AddFunction({ConstructFormattedLines(node)});
		}

		void ParseInclude(const node::argument* node)
		{
			Ldo->SetInclude(ConstructFormattedLines(node));
		}

		void ParseSourceInclude(const node::argument* node)
		{
			Ldo->SetSourceInclude(ConstructFormattedLines(node));
		}

	public:
		DLDL::ir::LDO* GetLdoStruct() const
		{
			return Ldo;
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

		std::string ToLower(std::string str) const
		{
			for (auto i = 0; i < str.size(); i++)
			{
				if (::isalpha(str[i]))
					str[i] = ::tolower(str[i]);
			}

			return str;
		}

		DLDL::ir::LDOType GetLDOType(const std::string& name)
		{
			static const std::map<std::string, DLDL::ir::LDOType> mapStrToType = {
				{"", DLDL::ir::LDOType::Ldo},
				{"struct", DLDL::ir::LDOType::Struct},
				{"structure", DLDL::ir::LDOType::Struct},
				{"enumeration", DLDL::ir::LDOType::Enumeration},
				{"enum", DLDL::ir::LDOType::Enumeration},
				{"ldo", DLDL::ir::LDOType::Ldo},
			};

			auto iter = mapStrToType.find(ToLower(name));
			if (iter == mapStrToType.end())
			{
				return DLDL::ir::LDOType::Ldo;
			}

			// For now Structs are unsupported, they default to LDOs from 2.3.0 and later.
			if (iter->second == DLDL::ir::LDOType::Struct)
			{
				return DLDL::ir::LDOType::Ldo;
			}
			return iter->second;
		}
	};
}

#endif // DLDL_LDOSTRUCT_AST_LISTENER_USER_LDOSTRUCT_H
