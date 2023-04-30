#include "DLDL_VALUE/IR/ValueRule.h"

DLDL::ir::ValueRule::ValueRule(const std::string& ruleName_) : ruleName(ruleName_)
{
}

void DLDL::ir::ValueRule::AddSyntaxContent(const std::string& syntacticContext_)
{
	syntacticContexts.push_back(syntacticContext_);
}

void DLDL::ir::ValueRule::AddUnderlyingAbstraction(ValueAbstraction* underlyingAbstraction)
{
	underlyingAbstractions.push_back(underlyingAbstraction);
}

std::string DLDL::ir::ValueRule::GetRuleName()
{
	return ruleName;
}

std::vector<std::string> DLDL::ir::ValueRule::GetSyntacticContexts()
{
	return syntacticContexts;
}

std::vector<DLDL::ir::ValueAbstraction*> DLDL::ir::ValueRule::GetUnderlyingAbstraction()
{
	return underlyingAbstractions;
}
