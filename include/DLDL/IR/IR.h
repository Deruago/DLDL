#ifndef DLDL_IR_IR_H
#define DLDL_IR_IR_H

#include "DLDL/IR/Type.h"

namespace DLDL::ir
{
	class IR
	{
	private:
		Type type;

	public:
		IR(Type type_) : type(type_)
		{
		}
		virtual ~IR() = default;

	public:
		Type GetType() const
		{
			return type;
		}
	};
}

#endif // DLDL_IR_IR_H