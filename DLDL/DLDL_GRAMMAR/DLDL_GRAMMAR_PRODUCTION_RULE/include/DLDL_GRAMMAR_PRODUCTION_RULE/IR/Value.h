#ifndef DLDL_GRAMMAR_PRODUCTIONRULE_VALUE_H
#define DLDL_GRAMMAR_PRODUCTIONRULE_VALUE_H

#include <string>
#include <utility>

namespace DLDL_GRAMMAR_PRODUCTION_RULE::ir
{
	enum class ValueType
	{
		standard,
		generated,
	};

	/*!
	 * \class Value
	 *
	 */
	struct Value
	{
		std::string name;
		ValueType vt;
		Value(std::string name_, ValueType vt_) : name(std::move(name_)), vt(vt_)
		{
		}

		bool operator==(const Value& rhs) const
		{
			return this->name == rhs.name && this->vt == rhs.vt;
		}

		bool operator!=(const Value& rhs) const
		{
			return !operator==(rhs);
		}
	};
}

#endif // DLDL_GRAMMAR_PRODUCTIONRULE_VALUE_H
