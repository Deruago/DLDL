#include "DLDL_OOPSYNTAX/IR/OopSyntax.h"

DLDL::ir::OopSyntax::OopSyntax() : IR(Type::OopSyntax)
{
}

void DLDL::ir::OopSyntax::AddOopProperty(std::unique_ptr<OopProperty> newOopProperty)
{
	oopProperties.push_back(std::move(newOopProperty));
}

void DLDL::ir::OopSyntax::AddOopProperties(
	std::vector<std::unique_ptr<OopProperty>> newOopProperties)
{
	oopProperties = std::move(newOopProperties);
}

const std::vector<std::unique_ptr<DLDL::ir::OopProperty>>&
DLDL::ir::OopSyntax::GetOopProperties() const
{
	return oopProperties;
}
