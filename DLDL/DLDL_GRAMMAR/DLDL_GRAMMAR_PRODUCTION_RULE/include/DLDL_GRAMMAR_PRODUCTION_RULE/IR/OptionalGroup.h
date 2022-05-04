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
		OptionalGroup(std::vector<Group*> subgroups_ = {}, bool inlineExtension_ = true)
			: ReservedGroup("optional", std::move(subgroups_), inlineExtension_)
		{
		}

		std::vector<ProductionRule> RetrieveEnvironment(Environment& currentEnvironment, const ProductionRule& productionRule) override
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
							currentEnvironment, currentProductionRule);
						
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
					filledProductionRule.values.push_back(subgroup->GetValue());
				}

				currentEnvironment.AddNonTerminal(GetReferenceName(),
												  {filledProductionRule, emptyProductionRule});

				return {};
			}
		}
	};
}

#endif // DLDL_GRAMMAR_PRODUCTIONRULE_OPTIONALGROUP_H
