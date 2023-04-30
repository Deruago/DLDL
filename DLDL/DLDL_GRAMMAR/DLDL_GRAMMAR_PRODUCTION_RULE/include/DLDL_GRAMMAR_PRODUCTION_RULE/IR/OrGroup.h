#ifndef DLDL_GRAMMAR_PRODUCTIONRULE_ORGROUP_H
#define DLDL_GRAMMAR_PRODUCTIONRULE_ORGROUP_H

#include "DLDL_GRAMMAR_PRODUCTION_RULE/IR/ReservedGroup.h"
#include <utility>

namespace DLDL_GRAMMAR_PRODUCTION_RULE::ir
{
	/*!
	 * \class OrGroup
	 *
	 * \brief Represents a collection of choices between groups
	 */
	class OrGroup : public ReservedGroup
	{
	public:
		OrGroup(std::vector<Group*> subgroups = {}, bool inlineExtension_ = false)
			: ReservedGroup("or", std::move(subgroups), inlineExtension_)
		{
		}

		std::vector<ProductionRule> RetrieveEnvironment(Environment& currentEnvironment,
														const ProductionRule& productionRule,
														DLDL::ir::Grammar* grammar) override
		{
			if (inlineExtension)
			{
				std::vector<ProductionRule> productionRules;
				for (auto* const subgroup : subgroups)
				{
					for (const auto& newProductionRule :
						 subgroup->RetrieveEnvironment(currentEnvironment, productionRule, grammar))
					{
						productionRules.push_back(newProductionRule);
					}
				}

				return productionRules;
			}
			else
			{
				std::vector<ProductionRule> productionRules;
				for (auto* const subgroup : subgroups)
				{
					for (auto production : subgroup->RetrieveEnvironment(currentEnvironment,
																		 ProductionRule{}, grammar))
					{
						productionRules.push_back(production);
					}
				}
				currentEnvironment.AddNonTerminal(GetReferenceName(), productionRules);

				ProductionRule newProductionRule = productionRule.values;
				newProductionRule.values.emplace_back(GetValue());

				return {newProductionRule};
			}
		}
	};
}

#endif // DLDL_GRAMMAR_PRODUCTIONRULE_ORGROUP_H
