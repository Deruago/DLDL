#ifndef DLDL_IR_SPECIALDEFINITION_THREAT_H
#define DLDL_IR_SPECIALDEFINITION_THREAT_H

#include "DLDL/IR/IR.h"
#include <string>

namespace DLDL::ir::special
{
	class Threat : public IR
	{
	private:
		std::string name;

	public:
		Threat();
		~Threat() override = default;

	public:
	};
}

#endif // DLDL_IR_SPECIALDEFINITION_THREAT_H
