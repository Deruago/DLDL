#ifndef DLDL_NAMEREGISTRY_NAMEREGISTRY_H
#define DLDL_NAMEREGISTRY_NAMEREGISTRY_H

#include <map>
#include <string>

namespace DLDL
{
	struct NameRegistry
	{
		static constexpr std::size_t upperBound = 40; // Maximal name length for reserved words
		static std::map<std::string, std::string> mapLongNameWithShortName;
		static std::string GetName(const std::string& lhs);

		NameRegistry() = default;
		~NameRegistry() = default;
	};
}

#endif // DLDL_NAMEREGISTRY_NAMEREGISTRY_H
