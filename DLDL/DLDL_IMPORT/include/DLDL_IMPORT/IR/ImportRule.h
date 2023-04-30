#ifndef DLDL_IMPORT_IR_IMPORTRULE_H
#define DLDL_IMPORT_IR_IMPORTRULE_H

#include "DLDL_IMPORT/IR/ImportRuleType.h"
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace DLDL::ir
{
	class ImportRule
	{
	private:
		std::string importRuleName;
		std::vector<std::string> syntacticRelations;

		std::optional<std::string> fileTarget;
		std::optional<std::string> moduleTarget;
		std::optional<std::string> objectTarget;

	public:
		ImportRule(const std::string& importRuleName_);
		~ImportRule() = default;

	public:
		void AddSyntacticRelation(const std::string& syntacticRelation);

		void AddFileTarget(std::optional<std::string> fileTarget_);
		void AddObjectTarget(std::optional<std::string> objectTarget_);
		void AddModuleTarget(std::optional<std::string> moduleTarget_);

	public:
		// Given the Import Targets, deduces the type of import rule this rule represents
		ImportRuleType GetImportRuleType();
		std::vector<std::string> GetSyntacticRelations();

		std::optional<std::string> GetFileTarget();
		std::optional<std::string> GetObjectTarget();
		std::optional<std::string> GetModuleTarget();

		std::string GetImportRuleName();
	};
}

#endif // DLDL_IMPORT_IR_IMPORTRULE_H
