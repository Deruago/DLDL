#ifndef DLDL_IR_IR_CONFIG_H
#define DLDL_IR_IR_CONFIG_H

#include "DLDL/IR/Type.h"

namespace DLDL::ir
{
	class IR_Config
	{
	private:
		Type type;
	public:
		IR_Config(Type type_) : type(type_)
		{
		}
	public:

		Type GetType() const
		{
			return type;
		}
	};
}

#endif // DLDL_IR_IR_CONFIG_H