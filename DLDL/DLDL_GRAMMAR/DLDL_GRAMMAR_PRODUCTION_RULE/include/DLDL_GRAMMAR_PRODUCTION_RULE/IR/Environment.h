#ifndef DLDL_GRAMMAR_PRODUCTIONRULE_IR_ENVIRONMENT_H
#define DLDL_GRAMMAR_PRODUCTIONRULE_IR_ENVIRONMENT_H

#include "DLDL_GRAMMAR_PRODUCTION_RULE/IR/NonTerminal.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/IR/ProductionRule.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/IR/Value.h"
#include <memory>
#include <set>
#include <utility>
#include <vector>

namespace DLDL_GRAMMAR_PRODUCTION_RULE::ir
{
	/*!
	 * \class Environment
	 *
	 * \brief Contains an environment for EBNF expansion to BNF
	 */
	class Environment
	{
	public:
		std::vector<ProductionRule> currentProductionRules;
		std::vector<NonTerminal> nonterminals;

	public:
		Environment() = default;
		~Environment() = default;

	public:
		void AddNonTerminal(const std::string& text, std::vector<ProductionRule> productionRules)
		{
			NonTerminal newNonTerminal(text, ValueType::generated, std::move(productionRules));

			for (const auto& nonterminal : nonterminals)
			{
				if (nonterminal == newNonTerminal)
				{
					return;
				}
			}

			nonterminals.emplace_back(newNonTerminal);
		}

	public:
		void Print() const
		{
			for (const auto& productionRule : currentProductionRules)
			{
				productionRule.Print();
			}

			for (const auto& nonterminal : nonterminals)
			{
				nonterminal.Print();
				std::cout << "\n";
			}
		}
	};
}

#endif // DLDL_GRAMMAR_PRODUCTIONRULE_IR_ENVIRONMENT_H
