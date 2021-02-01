#ifndef DLDL_CONSOLE_ARGUMENTINFORMATION_ALLARGUMENTS_H
#define DLDL_CONSOLE_ARGUMENTINFORMATION_ALLARGUMENTS_H
#include <string>
#include <vector>
#include <Console/ArgumentInformation/ArgumentInformation.h>

#include "ArgumentInformation.h"

namespace DLDL {
	class AllArguments : public ArgumentInformation
	{
	public:
		std::string GetHelpInformationContent() override
		{
			return "Enables all possible arguments";
		}

		std::string GetArgumentName() override
		{
			return "all-arguments";
		}

		std::vector<std::string> GetArgumentNames() override
		{
			return {
				"all-arguments",
			};
		}

		DLDL::ArgumentType_t GetArgumentType() override
		{
			return DLDL::ArgumentType_t::allArguments;
		}
	};
}

#endif //DLDL_CONSOLE_ARGUMENTINFORMATION_ALLARGUMENTS_H