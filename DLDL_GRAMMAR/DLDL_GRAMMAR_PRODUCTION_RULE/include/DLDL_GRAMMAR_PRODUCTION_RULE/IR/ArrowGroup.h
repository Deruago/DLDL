#ifndef DLDL_GRAMMAR_PRODUCTIONRULE_ARROWGROUP_H
#define DLDL_GRAMMAR_PRODUCTIONRULE_ARROWGROUP_H

#include "DLDL_GRAMMAR_PRODUCTION_RULE/IR/ReservedGroup.h"
#include "StarGroup.h"
#include <utility>

namespace DLDL_GRAMMAR_PRODUCTION_RULE::ir
{
	/*!
	 * \class ArrowGroup
	 *
	 * \brief Represents an abstraction for "A (B)*", simplified: "A -> B"
	 */
	class ArrowGroup : public ReservedGroup
	{
	private:
		StarGroup starGroup;

	public:
		ArrowGroup(std::vector<Group*> subgroups = {}, bool inlineExtension_ = false)
			: ReservedGroup("arrow", {subgroups[0]}, inlineExtension_),
			  starGroup({subgroups[1]})
		{
		}

		std::vector<ProductionRule>
		RetrieveEnvironment(Environment& currentEnvironment,
							const ProductionRule& productionRule) override
		{
			if (inlineExtension)
			{
				std::vector<ProductionRule> newProductionRules =
					subgroups[0]->RetrieveEnvironment(currentEnvironment, productionRule);

				for (auto& newProductionRule : newProductionRules)
				{
					newProductionRule.values.push_back(starGroup.GetValue());
				}

				return newProductionRules;
			}
			else
			{
				std::vector<ProductionRule> currentStage =
					subgroups[0]->RetrieveEnvironment(currentEnvironment, ProductionRule());
				currentStage[0].values.push_back(starGroup.GetValue());

				currentEnvironment.AddNonTerminal(GetReferenceName(), currentStage);

				starGroup.RetrieveEnvironment(currentEnvironment, ProductionRule());

				ProductionRule copyProductionRule(productionRule);
				copyProductionRule.values.push_back(GetValue());

				return {copyProductionRule};
			}
		}
	};
}

#endif // DLDL_GRAMMAR_PRODUCTIONRULE_ARROWGROUP_H
