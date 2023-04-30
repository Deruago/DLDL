#include "DLDL_VALUE/IR/ValueCharacteristic.h"

DLDL::ir::ValueCharacteristic::ValueCharacteristic(const std::string& ruleName_)
	: ruleName(ruleName_)
{
}

void DLDL::ir::ValueCharacteristic::AddSyntaxContent(const std::string& syntacticContext_)
{
	syntacticContexts.push_back(syntacticContext_);
}

void DLDL::ir::ValueCharacteristic::AddUnderlyingAbstraction(
	ValueAbstraction* underlyingAbstraction)
{
	underlyingAbstractions.push_back(underlyingAbstraction);
}

std::string DLDL::ir::ValueCharacteristic::GetRuleName()
{
	return ruleName;
}

std::vector<std::string> DLDL::ir::ValueCharacteristic::GetSyntacticContexts()
{
	return syntacticContexts;
}

std::vector<DLDL::ir::ValueAbstraction*> DLDL::ir::ValueCharacteristic::GetUnderlyingAbstraction()
{
	return underlyingAbstractions;
}
