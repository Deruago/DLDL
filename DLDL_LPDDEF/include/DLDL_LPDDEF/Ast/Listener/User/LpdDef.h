#ifndef DLDL_LPDDEF_AST_LISTENER_USER_LPDDEF_H
#define DLDL_LPDDEF_AST_LISTENER_USER_LPDDEF_H

#include "DLDL_LPDDEF/Ast/Listener/EnterExitListener.h"
#include "DLDL_LPDDEF/Ast/Reference/Access.h"
#include "DLDL_LPDDEF/IR/LPDDEF.h"

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
				ParseLDPType(node);
			}
			else if (argument_name == "description")
			{
				ParseLDPDescription(node);
			}
			else if (argument_name == "ldo")
			{
				ParseLdoForwardDeclarations(node);
			}
		}

		void ParseLPDName(const DLDL_LPDDEF::ast::node::argument* node)
		{
			reference::Access_if<node::VARNAME_EXT>(
				node->GetIndex(2), [this](reference::Access<node::VARNAME_EXT> varname) {
					lpdDef->SetLPDName(varname.GetContent()[0]->GetText());
				});
		}

		void ParseLDPType(const DLDL_LPDDEF::ast::node::argument* node)
		{
			reference::Access_if<node::VARNAME_EXT>(
				node->GetIndex(2), [this](reference::Access<node::VARNAME_EXT> varname) {
					const auto type = ToLower(varname.GetContent()[0]->GetText());
					lpdDef->SetLPDType(GetLPDType(type));
				});
		}

		void ParseLDPDescription(const DLDL_LPDDEF::ast::node::argument* node)
		{
			bool finished = false;
			reference::Access_if<node::VARNAME_EXT>(
				node->GetIndex(2), [this, &](reference::Access<node::VARNAME_EXT> varname) {
					finished = true;
					lpdDef->SetDescription(varname.GetContent()[0]->GetText());
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

			lpdDef->SetDescription(description);
		}

		void ParseLdoForwardDeclarations(const DLDL_LPDDEF::ast::node::argument* node)
		{
		}

	public:
		DLDL::ir::LpdDef* GetLpdDef() const
		{
			return lpdDef;
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

		DLDL::ir::LPDType GetLPDType(const std::string& name)
		{
			static const std::map<std::string, DLDL::ir::LPDType> mapStrToType = {
				{"", DLDL::ir::LPDType::tool},
				{"main", DLDL::ir::LPDType::main},
				{"special", DLDL::ir::LPDType::special},
				{"tool", DLDL::ir::LPDType::tool},
			};

			auto iter = mapStrToType.find(name);
			if (iter == mapStrToType.end())
			{
				return DLDL::ir::LPDType::tool;
			}

			return iter->second;
		}
	};
}

#endif // DLDL_LPDDEF_AST_LISTENER_USER_LPDDEF_H
