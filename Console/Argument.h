#ifndef DLDL_CONSOLE_ARGUMENT_H
#define DLDL_CONSOLE_ARGUMENT_H

#include <Console/ArgumentType_t.h>

namespace DLDL {
	struct Argument
	{
		const ArgumentType_t type;
		const bool activated;
		
		Argument(const ArgumentType_t type_, const bool activated_)
		: type(type_), activated(activated_)
		{
		}
	};	
}

#endif //DLDL_CONSOLE_ARGUMENT_H