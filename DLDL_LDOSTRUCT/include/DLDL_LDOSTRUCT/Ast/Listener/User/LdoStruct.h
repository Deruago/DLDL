#ifndef DLDL_LDOSTRUCT_AST_LISTENER_USER_LDOSTRUCT_H
#define DLDL_LDOSTRUCT_AST_LISTENER_USER_LDOSTRUCT_H

#include "DLDL_LDODEF/IR/LDODEF.h"
#include "DLDL_LDOSTRUCT/Ast/Listener/EnterExitListener.h"
#include "DLDL_LDOSTRUCT/Ast/Reference/Access.h"

namespace DLDL_LDOSTRUCT::ast::listener::user
{
	class LdoStruct : public ::DLDL_LDOSTRUCT::ast::listener::EnterExitListener
	{
	private:
		DLDL::ir::LDO* LdoStruct;

	public:
		LdoStruct()
		{
			LdoStruct = new ::DLDL::ir::LDO();
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
				ParseLDPType(node);
			}
			else if (argument_name == "description")
			{
				ParseLDPDescription(node);
			}
			else if (argument_name == "description_details")
			{
				// ParseLDPDescriptionDetailed(node);
			}
			else if (argument_name == "note")
			{
				// ParseLDPNote(node);
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
			else if (argument_name == "data")
			{
				// ParseData(node);
			}
		}

		void ParseLDOName(const DLDL_LDOSTRUCT::ast::node::argument* node)
		{
			reference::Access_if<node::VARNAME_EXT>(
				node->GetIndex(2), [this](reference::Access<node::VARNAME_EXT> varname) {
					LdoStruct->SetLDOName(varname.GetContent()[0]->GetText());
				});
		}

		void ParseLDPType(const DLDL_LDOSTRUCT::ast::node::argument* node)
		{
			reference::Access_if<node::VARNAME_EXT>(
				node->GetIndex(2), [this](reference::Access<node::VARNAME_EXT> varname) {
					const auto type = ToLower(varname.GetContent()[0]->GetText());
					LdoStruct->SetLDOType(GetLDOType(type));
				});
		}

		void ParseLDPDescription(const DLDL_LDOSTRUCT::ast::node::argument* node)
		{
			bool finished = false;
			reference::Access_if<node::VARNAME_EXT>(
				node->GetIndex(2), [this, &](reference::Access<node::VARNAME_EXT> varname) {
					finished = true;
					LdoStruct->SetDescription(varname.GetContent()[0]->GetText());
				});

			if (finished)
			{
				return;
			}

			// Get minimal indentation, this will be the base indentation to remove
			// This allows more formatting options by the user
			bool changed = false;
			std::size_t minimal_count = std::numeric_limits<std::size_t>::max();
			reference::Access(node).argument_block().argument_stmt().for_all(
				[this, &](reference::Access<node::argument_stmt> ref_) {
					const auto ref = ref_.GetContent()[0]->GetIndex(0);
					changed = false;
					std::size_t tmp_count = 0;
					reference::Access_if<node::INDENTED_VALUE>(
						ref, [this, &](reference::Access<node::INDENTED_VALUE> value) {
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

			// Construct description
			std::string description;
			reference::Access(node).argument_block().argument_stmt().for_all(
				[this, &](reference::Access<node::argument_stmt> ref_) {
					const auto ref = ref_.GetContent()[0]->GetIndex(0);
					reference::Access_if<node::INDENTED_VALUE>(
						ref, [this, &](reference::Access<node::INDENTED_VALUE> value) {
							const auto text =
								value.GetContent()[0]->GetText().erase(0, minimal_count);
							description += text;
							if (text[text.size() - 1] == '\r')
							{
								description += '\n';
							}
						});
					reference::Access_if<node::VARNAME_EXT>(
						ref, [this, &](reference::Access<node::VARNAME_EXT> value) {
							const auto text = value.GetContent()[0]->GetText();
							description += text + '\n';
						});
					reference::Access_if<node::VARNAME>(
						ref, [this, &](reference::Access<node::VARNAME> value) {
							const auto text = value.GetContent()[0]->GetText();
							description += text + '\n';
						});
				});

			LdoStruct->SetDescription(description);
		}

		void ParseLdoForwardDeclarations(const DLDL_LDOSTRUCT::ast::node::argument* node)
		{
		}

	public:
		DLDL::ir::LdoStruct* GetLdoStruct() const
		{
			return LdoStruct;
		}

	private:
		std::string ToLower(std::string str)
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

			auto iter = mapStrToType.find(name);
			if (iter == mapStrToType.end())
			{
				return DLDL::ir::LDOType::tool;
			}

			return iter->second;
		}
	};
}

#endif // DLDL_LDOSTRUCT_AST_LISTENER_USER_LDOSTRUCT_H
