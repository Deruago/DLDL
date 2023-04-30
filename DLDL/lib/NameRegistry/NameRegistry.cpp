#include "DLDL/NameRegistry/NameRegistry.h"

std::map<std::string, std::string> DLDL::NameRegistry::mapLongNameWithShortName;

std::string DLDL::NameRegistry::GetName(const std::string& lhs)
{
	if (lhs.find("deamerreserved_") != 0)
	{
		// Verify that it is a reserved word
		return lhs;
	}

	if (lhs.size() <= upperBound)
	{
		return lhs;
	}

	auto iter = mapLongNameWithShortName.find(lhs);
	if (iter != mapLongNameWithShortName.end())
	{
		// Already registered
		return iter->second;
	}

	std::string newName = "deamerreserved_long_" + std::to_string(mapLongNameWithShortName.size());
	mapLongNameWithShortName.insert({lhs, newName});
	return newName;
}
