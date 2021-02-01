#ifndef DLDL_CONSOLE_ARGUMENTINFORMATION_AUTOCOMPILE_H
#define DLDL_CONSOLE_ARGUMENTINFORMATION_AUTOCOMPILE_H
#include <string>
#include <vector>
#include <Console/ArgumentInformation/ArgumentInformation.h>

#include "ArgumentInformation.h"

namespace DLDL {
	class AutoCompile : public ArgumentInformation
	{
	public:
		std::string GetHelpInformationContent() override
		{
			return "Auto compiles the generated output";
		}

		std::string GetArgumentName() override
		{
			return "auto-compile";
		}

		std::vector<std::string> GetArgumentNames() override
		{
			return {
				"auto-compile",
			};
		}

		DLDL::ArgumentType_t GetArgumentType() override
		{
			return DLDL::ArgumentType_t::autoCompile;
		}
	};
}

#endif //DLDL_CONSOLE_ARGUMENTINFORMATION_AUTOCOMPILE_H