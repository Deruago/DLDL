#include "DLDL_IMPORT/IR/Import.h"

DLDL::ir::Import::Import() : IR(Type::Import)
{
}

void DLDL::ir::Import::AddImportRule(std::unique_ptr<ImportRule> importRule_)
{
	importRules.push_back(std::move(importRule_));
}

std::vector<DLDL::ir::ImportRule*> DLDL::ir::Import::GetImportRules()
{
	std::vector<DLDL::ir::ImportRule*> result;
	for (auto& importRule : importRules)
	{
		result.push_back(importRule.get());
	}
	return result;
}
