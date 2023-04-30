#ifndef DLDL_IMPORT_AST_LISTENER_USER_IMPORT_H
#define DLDL_IMPORT_AST_LISTENER_USER_IMPORT_H

#include "DLDL_IMPORT/Ast/Listener/EnterExitListener.h"
#include "DLDL_IMPORT/Ast/Reference/Access.h"
#include "DLDL_IMPORT/IR/Import.h"

namespace DLDL_IMPORT::ast::listener::user
{
	class Import : public ::DLDL_IMPORT::ast::listener::EnterExitListener
	{
	private:
		DLDL::ir::Import* ImportLpd;
		DLDL::ir::ImportRule* currentImportRule = nullptr;

	public:
		Import()
		{
			ImportLpd = new ::DLDL::ir::Import();
		}
		~Import() override = default;

	public:
		void ListenEntry(const DLDL_IMPORT::ast::node::import_declaration* node) override
		{
			auto acc = reference::Access(node);
			auto newImportRule = std::make_unique<DLDL::ir::ImportRule>(
				acc.import_rule_name().GetContent()[0]->GetText());
			currentImportRule = newImportRule.get();

			acc.import_context().for_all(
				[&](reference::Access<node::import_context> import_context_) {
					newImportRule->AddSyntacticRelation(import_context_.GetContent()[0]->GetText());
				});

			ImportLpd->AddImportRule(std::move(newImportRule));
		}

		void ListenEntry(const DLDL_IMPORT::ast::node::import_abstraction* node) override
		{
			auto acc = reference::Access(node);
			auto abstraction = acc.abstraction().GetContent()[0]->GetText();
			auto target = acc.value().GetContent()[0]->GetText();

			std::string lowered_abstraction;
			for (auto character : abstraction)
			{
				if (std::isalpha(character))
				{
					lowered_abstraction += std::tolower(character);
				}
				else
				{
					lowered_abstraction += character;
				}
			}

			if (lowered_abstraction == "filetarget" || lowered_abstraction == "file_target")
			{
				currentImportRule->AddFileTarget(target);
			}
			else if (lowered_abstraction == "objecttarget" ||
					 lowered_abstraction == "object_target")
			{
				currentImportRule->AddObjectTarget(target);
			}
			else if (lowered_abstraction == "moduletarget" ||
					 lowered_abstraction == "module_target")
			{
				currentImportRule->AddModuleTarget(target);
			}
		}

	public:
		DLDL::ir::Import* GetImport()
		{
			return ImportLpd;
		}
	};
}

#endif // DLDL_IMPORT_AST_LISTENER_USER_IMPORT_H
