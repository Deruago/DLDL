#ifndef DLDL_VALUE_IR_VALUERULE_H
#define DLDL_VALUE_IR_VALUERULE_H

#include "DLDL_VALUE/IR/ValueAbstraction.h"
#include <deque>
#include <memory>
#include <optional>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace DLDL::ir
{
	class ValueRule
	{
	private:
		std::string ruleName;
		std::vector<std::string>
			syntacticContexts; // Needs to be resolved to nonterminal* [terminal] sequences
		std::vector<ValueAbstraction*> underlyingAbstractions;

	public:
		ValueRule(const std::string& ruleName_);

	public:
		void AddSyntaxContent(const std::string& syntacticContext_);
		void AddUnderlyingAbstraction(ValueAbstraction* underlyingAbstraction);

	public:
		std::string GetRuleName();
		std::vector<std::string> GetSyntacticContexts();
		std::vector<ValueAbstraction*> GetUnderlyingAbstraction();
	};
}

#endif // DLDL_VALUE_IR_VALUERULE_H
