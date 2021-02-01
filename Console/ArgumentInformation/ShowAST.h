#ifndef DLDL_CONSOLE_ARGUMENTINFORMATION_SHOWAST_H
#define DLDL_CONSOLE_ARGUMENTINFORMATION_SHOWAST_H
#include <string>
#include <vector>
#include <Console/ArgumentInformation/ArgumentInformation.h>

#include "ArgumentInformation.h"

namespace DLDL {
	class ShowAST : public ArgumentInformation
	{
	public:
		std::string GetHelpInformationContent() override
		{
			return "show the DLDL AST created from the DLDL file";
		}

		std::string GetArgumentName() override
		{
			return "show-ast";
		}

		std::vector<std::string> GetArgumentNames() override
		{
			return {
				"show-ast",
			};
		}

		DLDL::ArgumentType_t GetArgumentType() override
		{
			return DLDL::ArgumentType_t::showAST;
		}
	};
}

#endif //DLDL_CONSOLE_ARGUMENTINFORMATION_SHOWAST_H