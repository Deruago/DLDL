#ifndef DLDL_GRAMMAR_PRODUCTIONRULE_NONTERMINAL_H
#define DLDL_GRAMMAR_PRODUCTIONRULE_NONTERMINAL_H

#include "DLDL_GRAMMAR_PRODUCTION_RULE/IR/ProductionRule.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/IR/Value.h"
#include <utility>

namespace DLDL_GRAMMAR_PRODUCTION_RULE::ir
{
	/*!
	 * \class NonTerminal
	 *
	 */
	struct NonTerminal : public Value
	{
		std::vector<ProductionRule> productionRules;

		NonTerminal(const std::string& name_, ValueType valueType_,
					std::vector<ProductionRule> productionRules_)
			: Value(name_, valueType_),
			  productionRules(std::move(productionRules_))
		{
		}

		void Print() const
		{
			std::cout << "NT: " + name + "\n";
			for (const auto& productionRule : productionRules)
			{
				productionRule.Print();
			}
		}

		bool operator==(const NonTerminal& rhs) const
		{
			if (this == &rhs)
			{
				return true;
			}

			if (this->productionRules.size() != rhs.productionRules.size())
			{
				return false;
			}

			for (auto i = 0; i < this->productionRules.size(); i++)
			{
				if (this->productionRules[i] != rhs.productionRules[i])
				{
					return false;
				}
			}

			return true;
		}
		
		bool operator!=(const NonTerminal& rhs) const
		{
			return !operator==(rhs);
		}
	};
}

#endif // DLDL_GRAMMAR_PRODUCTIONRULE_NONTERMINAL_H
