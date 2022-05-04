#ifndef DLDL_GRAMMAR_PRODUCTIONRULE_ORGROUP_H
#define DLDL_GRAMMAR_PRODUCTIONRULE_ORGROUP_H

#include <utility>


#include "DLDL_GRAMMAR_PRODUCTION_RULE/IR/ReservedGroup.h"

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
		OrGroup(std::vector<Group*> subgroups = {}, bool inlineExtension_ = true)
			: ReservedGroup("or", std::move(subgroups), inlineExtension_)
		{
		}

		std::vector<ProductionRule>
		RetrieveEnvironment(Environment& currentEnvironment,
							const ProductionRule& productionRule) override
		{
			if (inlineExtension)
			{
				std::vector<ProductionRule> productionRules;
				for (auto* const subgroup : subgroups)
				{
					for (const auto& newProductionRule : subgroup->RetrieveEnvironment(currentEnvironment, productionRule))
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
					productionRules.push_back(ProductionRule({subgroup->GetValue()}));
				}
				currentEnvironment.AddNonTerminal(GetReferenceName(), productionRules);

				return {};
			}
			
		}
		
	};
}

#endif // DLDL_GRAMMAR_PRODUCTIONRULE_ORGROUP_H
