#ifndef DLDL_IR_SPECIALDEFINITION_IDENTITY_H
#define DLDL_IR_SPECIALDEFINITION_IDENTITY_H

#include "DLDL/IR/IR.h"
#include <string>

namespace DLDL::ir::special
{
	class Identity : public IR
	{
	private:
		std::string name;

	public:
		Identity(std::string name_);
		~Identity() override = default;

	public:
		std::string GetName() const;
	};
}

#endif // DLDL_IR_SPECIALDEFINITION_IDENTITY_H
