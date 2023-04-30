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

		Value(const std::string& name_ = "", ValueType vt_ = ValueType::generated)
			: name(name_),
			  vt(vt_)
		{
		}

		~Value() = default;

		Value(const Value& rhs) : name(rhs.name), vt(rhs.vt)
		{
		}

		Value(Value&& rhs) noexcept : name(std::move(rhs.name)), vt(std::move(rhs.vt))
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
