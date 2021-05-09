#ifndef DLDL_IR_IR_H
#define DLDL_IR_IR_H

#include "DLDL/IR/Type.h"

namespace DLDL::ir
{
	class IR
	{
	private:
		Type type;

		bool isDefaultImplementedByDLDL = false;

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

		bool IsDefaultImplementedByDLDL() const
		{
			return isDefaultImplementedByDLDL;
		}

		void SetAsDefaultImplementedByDLDL()
		{
			isDefaultImplementedByDLDL = true;
		}
	};
}

#endif // DLDL_IR_IR_H