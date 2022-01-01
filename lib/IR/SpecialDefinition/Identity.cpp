#include "DLDL/IR/SpecialDefinition/Identity.h"

DLDL::ir::special::Identity::Identity(std::string name_) : IR(Type::Identity), name(name_)
{
}

std::string DLDL::ir::special::Identity::GetName() const
{
	return name;
}
