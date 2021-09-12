#ifndef DLDL_GRAMMAR_PRODUCTIONRULE_VALUEGROUP_H
#define DLDL_GRAMMAR_PRODUCTIONRULE_VALUEGROUP_H

#include "DLDL_GRAMMAR_PRODUCTION_RULE/IR/Group.h"

namespace DLDL_GRAMMAR_PRODUCTION_RULE::ir
{
	/*!
	 * \class ValueGroup
	 *
	 * \brief Represents a value group, this contains a (non)terminal.
	 */
	class ValueGroup : public Group
	{
		Value* value;

	public:
		ValueGroup(std::string name) : Group(), value(new Value(name, ValueType::standard))
		{
		}

		~ValueGroup() override
		{
			delete value;
		}

		std::string GetReferenceName() const override
		{
			return value->name;
		}

		std::vector<ProductionRule>
		RetrieveEnvironment(Environment& currentEnvironment,
							const ProductionRule& productionRule) override
		{
			ProductionRule newProductionRule = productionRule.values;
			newProductionRule.values.emplace_back(value);

			return {newProductionRule};
		}
	};
}

#endif // DLDL_GRAMMAR_PRODUCTIONRULE_VALUEGROUP_H
