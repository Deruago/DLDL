#ifndef DLDL_GRAMMAR_PRODUCTIONRULE_STARGROUP_H
#define DLDL_GRAMMAR_PRODUCTIONRULE_STARGROUP_H

#include "DLDL_GRAMMAR_PRODUCTION_RULE/IR/ReservedGroup.h"
#include <utility>

namespace DLDL_GRAMMAR_PRODUCTION_RULE::ir
{
	/*!
	 * \class StarGroup
	 *
	 * \brief Represents a group that can be used 0 or more times.
	 */
	class StarGroup : public ReservedGroup
	{
	public:
		StarGroup(std::vector<Group*> subgroups = {})
			: ReservedGroup("star", std::move(subgroups), false)
		{
		}

		std::vector<ProductionRule> RetrieveEnvironment(Environment& currentEnvironment,
														const ProductionRule& productionRule,
														DLDL::ir::Grammar* grammar) override
		{
			std::vector<ProductionRule> currentStage = {ProductionRule()};
			for (auto* const subgroup : subgroups)
			{
				std::vector<ProductionRule> nextStage;
				for (const auto& currentProductionRule : currentStage)
				{
					const auto& newProductionRules = subgroup->RetrieveEnvironment(
						currentEnvironment, currentProductionRule, grammar);
					for (const auto& newProductionRule : newProductionRules)
					{
						nextStage.push_back(newProductionRule);
					}
				}
				currentStage = nextStage;
			}

			for (auto& newProductionRule : currentStage)
			{
				newProductionRule.values.push_back(GetValue());
			}
			currentStage.emplace_back();

			currentEnvironment.AddNonTerminal(GetReferenceName(), currentStage);

			ProductionRule copyProductionRule(productionRule);
			copyProductionRule.values.push_back(GetValue());

			return {copyProductionRule};
		}
	};
}

#endif // DLDL_GRAMMAR_PRODUCTIONRULE_STARGROUP_H
