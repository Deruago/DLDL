#ifndef DLDL_VALUE_IR_PARSER_H
#define DLDL_VALUE_IR_PARSER_H

#include "DLDL/IR/Parser.h"
#include "DLDL_VALUE/Ast/Listener/User/Value.h"
#include "DLDL_VALUE/Bison/Parser.h"
#include <Deamer/External/Cpp/Ast/Tree.h>
#include <Deamer/File/Tool/OSType.h>
#include <memory>
#include <string>

namespace DLDL::ir::value
{
	class Parser : public ::DLDL::ir::Parser
	{
	public:
		Parser(::deamer::file::tool::OSType os_);

	public:
		DLDL::ir::IR* GetIR(std::string text) override;
	};
}

#endif // DLDL_VALUE_IR_PARSER_H
