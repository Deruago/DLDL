#ifndef DLDL_GRAMMAR_PRODUCTIONRULE_PLUSGROUP_H
#define DLDL_GRAMMAR_PRODUCTIONRULE_PLUSGROUP_H

#include "DLDL_GRAMMAR_PRODUCTION_RULE/IR/ReservedGroup.h"
#include <utility>

namespace DLDL_GRAMMAR_PRODUCTION_RULE::ir
{
	/*!
	 * \class PlusGroup
	 *
	 * \brief Represents a group that can be used 1 or more times.
	 */
	class PlusGroup : public ReservedGroup
	{
	public:
		PlusGroup(std::vector<Group*> subgroups = {})
			: ReservedGroup("plus", std::move(subgroups), false)
		{
		}

		std::vector<ProductionRule>
		RetrieveEnvironment(Environment& currentEnvironment,
							const ProductionRule& productionRule) override
		{
			std::vector<ProductionRule> currentStage = {ProductionRule()};
			for (auto* const subgroup : subgroups)
			{
				std::vector<ProductionRule> nextStage;
				for (const auto& currentProductionRule : currentStage)
				{
					const auto& newProductionRules =
						subgroup->RetrieveEnvironment(currentEnvironment, currentProductionRule);
					for (const auto& newProductionRule : newProductionRules)
					{
						nextStage.push_back(newProductionRule);
					}
				}
				currentStage = nextStage;
			}
			auto currentStageCopy = currentStage;
			for (auto& newProductionRule : currentStageCopy)
			{
				newProductionRule.values.push_back(GetValue());
				currentStage.push_back(newProductionRule);
			}

			currentEnvironment.AddNonTerminal(GetReferenceName(), currentStage);

			ProductionRule copyProductionRule(productionRule);
			copyProductionRule.values.push_back(GetValue());

			return {copyProductionRule};
		}
	};
}

#endif // DLDL_GRAMMAR_PRODUCTIONRULE_PLUSGROUP_H
