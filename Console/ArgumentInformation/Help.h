#ifndef DLDL_CONSOLE_ARGUMENTINFORMATION_HELP_H
#define DLDL_CONSOLE_ARGUMENTINFORMATION_HELP_H
#include <string>
#include <vector>
#include <Console/ArgumentInformation/ArgumentInformation.h>

#include "ArgumentInformation.h"

namespace DLDL {
	class Help : public ArgumentInformation
	{
	public:
		std::string GetHelpInformationContent() override
		{
			return "Is used to call this screen, showing information about all arguments.";
		}

		std::string GetArgumentName() override
		{
			return "help";
		}
		
		std::vector<std::string> GetArgumentNames() override
		{
			return {
				"h",
				"help",
				"show-help",
			};
		}
		
		DLDL::ArgumentType_t GetArgumentType() override
		{
			return DLDL::ArgumentType_t::help;
		}
	};
}

#endif //DLDL_CONSOLE_ARGUMENTINFORMATION_HELP_H