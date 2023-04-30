#include "DLDL_IMPORT/IR/ImportRule.h"
#include <map>
#include <tuple>

DLDL::ir::ImportRule::ImportRule(const std::string& importRuleName_)
	: importRuleName(importRuleName_)
{
}

void DLDL::ir::ImportRule::AddSyntacticRelation(const std::string& syntacticRelation)
{
	syntacticRelations.push_back(syntacticRelation);
}

void DLDL::ir::ImportRule::AddFileTarget(std::optional<std::string> fileTarget_)
{
	fileTarget = fileTarget_;
}

void DLDL::ir::ImportRule::AddObjectTarget(std::optional<std::string> objectTarget_)
{
	objectTarget = objectTarget_;
}

void DLDL::ir::ImportRule::AddModuleTarget(std::optional<std::string> moduleTarget_)
{
	moduleTarget = moduleTarget_;
}

DLDL::ir::ImportRuleType DLDL::ir::ImportRule::GetImportRuleType()
{
	static std::map<std::tuple<bool, bool, bool>, ImportRuleType> mapTargetsWithImportRuleType = {
		{{false, false, false}, ImportRuleType::Unknown},
		{{true, false, false}, ImportRuleType::FileImport},
		{{false, false, true}, ImportRuleType::ModuleImport},
		{{true, false, true}, ImportRuleType::FileModuleImport},
		{{true, true, false}, ImportRuleType::FileObjectImport},
		{{true, true, true}, ImportRuleType::FileModuleObjectImport},
		{{false, true, true}, ImportRuleType::ModuleObjectImport},
	};

	auto iter = mapTargetsWithImportRuleType.find(
		{fileTarget.has_value(), objectTarget.has_value(), moduleTarget.has_value()});
	if (iter == mapTargetsWithImportRuleType.end())
	{
		return ImportRuleType::Unknown;
	}

	return iter->second;
}

std::vector<std::string> DLDL::ir::ImportRule::GetSyntacticRelations()
{
	return syntacticRelations;
}

std::optional<std::string> DLDL::ir::ImportRule::GetFileTarget()
{
	return fileTarget;
}

std::optional<std::string> DLDL::ir::ImportRule::GetObjectTarget()
{
	return objectTarget;
}

std::optional<std::string> DLDL::ir::ImportRule::GetModuleTarget()
{
	return moduleTarget;
}

std::string DLDL::ir::ImportRule::GetImportRuleName()
{
	return importRuleName;
}
