#ifndef DLDL_VALUE_IR_VALUEABSTRACTIONTYPE_H
#define DLDL_VALUE_IR_VALUEABSTRACTIONTYPE_H

namespace DLDL::ir
{
	enum class ValueAbstractionType
	{
		Unknown,

		IsString,
		Start,
		End,
		Escape,

		IsVector,
		IsInteger,
		IsDecimal,
		IsValue,

		Wildcard,
	};
}

#endif // DLDL_VALUE_IR_VALUEABSTRACTIONTYPE_H
