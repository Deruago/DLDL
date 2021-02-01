#ifndef DLDL_CONSOLE_ARGUMENTINFORMATION_SHOWSTRUCTURE_H
#define DLDL_CONSOLE_ARGUMENTINFORMATION_SHOWSTRUCTURE_H
#include <string>
#include <vector>
#include <Console/ArgumentInformation/ArgumentInformation.h>

#include "ArgumentInformation.h"

namespace DLDL {
	class ShowStructure : public ArgumentInformation
	{
	public:
		std::string GetHelpInformationContent() override
		{
			return "Shows the structure of the Context Free Grammar";
		}

		std::string GetArgumentName() override
		{
			return "show-structure";
		}

		std::vector<std::string> GetArgumentNames() override
		{
			return {
				"show-structure",
			};
		}

		DLDL::ArgumentType_t GetArgumentType() override
		{
			return DLDL::ArgumentType_t::showstructure;
		}
	};
}

#endif //DLDL_CONSOLE_ARGUMENTINFORMATION_SHOWSTRUCTURE_H