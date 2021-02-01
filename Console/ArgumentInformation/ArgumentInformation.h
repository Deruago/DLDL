#ifndef DLDL_CONSOLE_ARGUMENTINFORMATION_ARGUMENTINFORMATION_H
#define DLDL_CONSOLE_ARGUMENTINFORMATION_ARGUMENTINFORMATION_H
#include <string>

#include "../ArgumentType_t.h"

namespace DLDL
{
	class ArgumentInformation
	{
	public:
		ArgumentInformation() = default;
		virtual ~ArgumentInformation() = default;

		// formats the help information, by adding newline and argument name
		std::string GetHelpInformationFormatted()
		{
			return "\t-" + GetArgumentName() + ": " + GetHelpInformationContent() + "\n";
		}
		
		virtual std::string GetHelpInformationContent() = 0;
		virtual std::string GetArgumentName() = 0;
		virtual std::vector<std::string> GetArgumentNames() = 0;
		virtual DLDL::ArgumentType_t GetArgumentType() = 0;
	};
}

#endif //DLDL_CONSOLE_ARGUMENTINFORMATION_ARGUMENTINFORMATION_H