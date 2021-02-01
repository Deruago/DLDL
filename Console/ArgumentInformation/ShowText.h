#ifndef DLDL_CONSOLE_ARGUMENTINFORMATION_SHOWTEXT_H
#define DLDL_CONSOLE_ARGUMENTINFORMATION_SHOWTEXT_H
#include <string>
#include <vector>
#include <Console/ArgumentInformation/ArgumentInformation.h>

#include "ArgumentInformation.h"

namespace DLDL {
	class ShowText : public ArgumentInformation
	{
	public:
		std::string GetHelpInformationContent() override
		{
			return "Used to show text.";
		}

		std::string GetArgumentName() override
		{
			return "show-text";
		}

		std::vector<std::string> GetArgumentNames() override
		{
			return {
				"show-text",
			};
		}

		DLDL::ArgumentType_t GetArgumentType() override
		{
			return DLDL::ArgumentType_t::showtext;
		}
	};
}

#endif //DLDL_CONSOLE_ARGUMENTINFORMATION_SHOWTEXT_H