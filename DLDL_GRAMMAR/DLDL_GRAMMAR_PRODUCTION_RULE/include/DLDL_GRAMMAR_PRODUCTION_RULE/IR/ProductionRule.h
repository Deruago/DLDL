#ifndef DLDL_GRAMMAR_PRODUCTIONRULE_PRODUCTIONRULE_H
#define DLDL_GRAMMAR_PRODUCTIONRULE_PRODUCTIONRULE_H

#include "DLDL_GRAMMAR_PRODUCTION_RULE/IR/Value.h"
#include <utility>
#include <vector>

namespace DLDL_GRAMMAR_PRODUCTION_RULE::ir
{
	/*!
	 * \class ProductionRule
	 *
	 * \brief Contains several (non)terminals.
	 */
	struct ProductionRule
	{
		std::vector<Value*> values;

		ProductionRule(std::vector<Value*> values_ = {}) : values(std::move(values_))
		{
		}

		void Print() const
		{
			for (const auto* const value : values)
			{
				std::cout << value->name + " ";
			}
			std::cout << "\n";
		}

		bool operator==(const ProductionRule& rhs) const
		{
			if (this == &rhs)
			{
				return true;
			}

			if (this->values.size() != rhs.values.size())
			{
				return false;
			}

			for (auto i = 0; i < this->values.size(); i++)
			{
				if ((this->values[i] != rhs.values[i]) && (*this->values[i] != *rhs.values[i]))
				{
					return false;
				}
			}

			return true;
		}

		bool operator!=(const ProductionRule& rhs) const
		{
			return !operator==(rhs);
		}
	};
}

#endif // DLDL_GRAMMAR_PRODUCTIONRULE_PRODUCTIONRULE_H
