#ifndef DLDL_GRAMMAR_PRODUCTIONRULE_OPTIONALGROUP_H
#define DLDL_GRAMMAR_PRODUCTIONRULE_OPTIONALGROUP_H

#include "DLDL_GRAMMAR_PRODUCTION_RULE/IR/ReservedGroup.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/IR/ValueGroup.h"
#include <utility>

namespace DLDL_GRAMMAR_PRODUCTION_RULE::ir
{
	/*!
	 * \class OptionalGroup
	 *
	 * \brief Represents an optional group.
	 */
	class OptionalGroup : public ReservedGroup
	{
	public:
		OptionalGroup(std::vector<Group*> subgroups_ = {}, bool inlineExtension_ = false)
			: ReservedGroup("optional", std::move(subgroups_), inlineExtension_)
		{
		}

		std::vector<ProductionRule> RetrieveEnvironment(Environment& currentEnvironment,
														const ProductionRule& productionRule,
														DLDL::ir::Grammar* grammar) override
		{
			if (inlineExtension)
			{
				std::vector<ProductionRule> currentProductionRules = {productionRule};

				for (auto* const subgroup : subgroups)
				{
					std::vector<ProductionRule> nextStage;
					for (const auto& currentProductionRule : currentProductionRules)
					{
						const auto newProductionRules = subgroup->RetrieveEnvironment(
							currentEnvironment, currentProductionRule, grammar);

						for (const auto& newProductionRule : newProductionRules)
						{
							nextStage.push_back(newProductionRule);
						}
					}
					currentProductionRules = nextStage;
				}

				currentProductionRules.push_back(productionRule);

				return currentProductionRules;
			}
			else
			{
				const ProductionRule emptyProductionRule;
				ProductionRule filledProductionRule;

				for (const auto& subgroup : subgroups)
				{
					auto result = subgroup->RetrieveEnvironment(currentEnvironment,
																filledProductionRule, grammar);
					filledProductionRule = result[0];
				}

				currentEnvironment.AddNonTerminal(GetReferenceName(),
												  {filledProductionRule, emptyProductionRule});

				ProductionRule newProductionRule = productionRule.values;
				newProductionRule.values.emplace_back(GetValue());

				return {newProductionRule};
			}
		}
	};
}

#endif // DLDL_GRAMMAR_PRODUCTIONRULE_OPTIONALGROUP_H
