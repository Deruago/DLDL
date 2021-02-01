#ifndef DLDL_CONSOLE_ARGUMENTINFORMATION_THREAT_H
#define DLDL_CONSOLE_ARGUMENTINFORMATION_THREAT_H
#include <string>
#include <vector>
#include <Console/ArgumentInformation/ArgumentInformation.h>

#include "ArgumentInformation.h"

namespace DLDL {
	class Threat : public ArgumentInformation
	{
	public:
		std::string GetHelpInformationContent() override
		{
			return "Adds threat analysis to code";
		}

		std::string GetArgumentName() override
		{
			return "threat";
		}

		std::vector<std::string> GetArgumentNames() override
		{
			return {
				"threat",
			};
		}

		DLDL::ArgumentType_t GetArgumentType() override
		{
			return DLDL::ArgumentType_t::addThreatAnalysis;
		}
	};
}

#endif //DLDL_CONSOLE_ARGUMENTINFORMATION_THREAT_H