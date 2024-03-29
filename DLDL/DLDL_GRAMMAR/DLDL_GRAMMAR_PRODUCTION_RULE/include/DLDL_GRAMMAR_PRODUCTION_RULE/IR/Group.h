#ifndef DLDL_GRAMMAR_PRODUCTIONRULE_GROUP_H
#define DLDL_GRAMMAR_PRODUCTIONRULE_GROUP_H

#include "DLDL_GRAMMAR/IR/Grammar.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/IR/Environment.h"
#include <utility>
#include <vector>

namespace DLDL_GRAMMAR_PRODUCTION_RULE::ir
{
	/*!
	 * \class Group
	 *
	 * \brief Represents a collection of (non)terminals.
	 */
	class Group
	{
	private:
		mutable Value* value;

	public:
		bool inlineExtension = true;

	public:
		std::vector<Group*> subgroups;

		Group(std::vector<Group*> subgroups_ = {})
			: value(nullptr),
			  subgroups(std::move(subgroups_))
		{
		}

		virtual ~Group()
		{
			delete value;

			for (auto* const subgroup : subgroups)
			{
				delete subgroup;
			}
		}

		void SetInline(bool inlineExtension_)
		{
			inlineExtension &= inlineExtension_;
			for (auto subGroup : subgroups)
			{
				subGroup->SetInline(inlineExtension_);
			}
		}

		Environment GetEnvironment(DLDL::ir::Grammar* grammar)
		{
			Environment currentEnvironment;

			const auto productionRules =
				RetrieveEnvironment(currentEnvironment, ProductionRule(), grammar);

			std::vector<ProductionRule> recreatedProductionRules;
			for (const auto& productionRule : productionRules)
			{
				bool alreadyFound = false;

				for (const auto& uniqueProductionRule : recreatedProductionRules)
				{
					if (uniqueProductionRule == productionRule && !alreadyFound)
					{
						alreadyFound = true;
					}
				}

				if (!alreadyFound)
				{
					recreatedProductionRules.push_back(productionRule);
				}
			}

			currentEnvironment.currentProductionRules = recreatedProductionRules;

			return std::move(currentEnvironment);
		}

		virtual std::vector<ProductionRule>
		RetrieveEnvironment(Environment& currentEnvironment, const ProductionRule& productionRule,
							DLDL::ir::Grammar* grammar)
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

			return currentProductionRules;
		}

		virtual std::string GetReferenceName() const
		{
			std::string name;
			for (auto* const subgroup : subgroups)
			{
				name += subgroup->GetReferenceName() + "__";
			}

			if (!name.empty())
			{
				name.pop_back();
				name.pop_back();
			}

			return name;
		}

		Value* GetValue() const
		{
			if (value == nullptr)
			{
				value = new Value(this->GetReferenceName(), ValueType::generated);
			}

			return value;
		}

		std::vector<Group*> GetSubGroups() const
		{
			return subgroups;
		}
	};
}

#endif // DLDL_GRAMMAR_PRODUCTIONRULE_GROUP_H
