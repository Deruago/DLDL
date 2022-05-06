#ifndef DLDL_IR_IRPARSER_H
#define DLDL_IR_IRPARSER_H

#include <Deamer/File/Tool/OSType.h>
#include "DLDL/IR/IR.h"

namespace DLDL::ir
{
	class IRParser
	{
	public:
		IRParser() = default;
		~IRParser() = default;
		static IR* Parse(const Type type, const std::string& fileContent,
						 ::deamer::file::tool::OSType os);
	public:
	};
}

#endif // DLDL_IR_IRPARSER_H