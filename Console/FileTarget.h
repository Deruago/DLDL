#ifndef DLDL_CONSOLE_FILETARGET_H
#define DLDL_CONSOLE_FILETARGET_H

#include <Console/DefinitionType_t.h>
#include <string>

namespace DLDL {
	struct FileTarget
	{
		const DLDL::DefinitionType_t definitionType;
		const std::string fileLocation;
		FileTarget(const std::string& fileLocation_, const DLDL::DefinitionType_t& definitionType_) :
			definitionType(definitionType_),
			fileLocation(fileLocation_)
		{
		}
	};
}

#endif //DLDL_CONSOLE_FILETARGET_H