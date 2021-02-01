#ifndef DLDL_CONSOLE_ARGUMENTINFORMATION_SHOWTEXTAFTERPREPROCESSOR_H
#define DLDL_CONSOLE_ARGUMENTINFORMATION_SHOWTEXTAFTERPREPROCESSOR_H
#include <string>
#include <vector>
#include <Console/ArgumentInformation/ArgumentInformation.h>

#include "ArgumentInformation.h"

namespace DLDL {
	class ShowTextAfterPreProcessor : public ArgumentInformation
	{
	public:
		std::string GetHelpInformationContent() override
		{
			return "Show text from after pre processor";
		}

		std::string GetArgumentName() override
		{
			return "show-text-after-pre-processor";
		}

		std::vector<std::string> GetArgumentNames() override
		{
			return {
				"show-text-after-pre-processor",
			};
		}

		DLDL::ArgumentType_t GetArgumentType() override
		{
			return DLDL::ArgumentType_t::showTextAfterFilePreProcessor;
		}
	};
}

#endif //DLDL_CONSOLE_ARGUMENTINFORMATION_SHOWTEXTAFTERPREPROCESSOR_H