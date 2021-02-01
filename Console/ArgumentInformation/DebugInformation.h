#ifndef DLDL_CONSOLE_ARGUMENTINFORMATION_DEBUGINFORMATION_H
#define DLDL_CONSOLE_ARGUMENTINFORMATION_DEBUGINFORMATION_H
#include <string>
#include <vector>
#include <Console/ArgumentInformation/ArgumentInformation.h>

#include "ArgumentInformation.h"

namespace DLDL {
	class DebugInformation : public ArgumentInformation
	{
	public:
		std::string GetHelpInformationContent() override
		{
			return "Shows debug information.";
		}

		std::string GetArgumentName() override
		{
			return "debug-information";
		}

		std::vector<std::string> GetArgumentNames() override
		{
			return {
				"debug-information",
			};
		}

		DLDL::ArgumentType_t GetArgumentType() override
		{
			return DLDL::ArgumentType_t::debugInformation;
		}
	};
}

#endif //DLDL_CONSOLE_ARGUMENTINFORMATION_DEBUGINFORMATION_H