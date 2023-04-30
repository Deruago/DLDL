#ifndef DLDL_OOPSYNTAX_IR_PARSER_H
#define DLDL_OOPSYNTAX_IR_PARSER_H

#include "DLDL/IR/Parser.h"
#include "DLDL_OOPSYNTAX/Ast/Listener/User/OopSyntax.h"
#include "DLDL_OOPSYNTAX/Bison/Parser.h"
#include <Deamer/External/Cpp/Ast/Tree.h>
#include <Deamer/File/Tool/OSType.h>
#include <memory>
#include <string>

namespace DLDL::ir::oopsyntax
{
	class Parser : public ::DLDL::ir::Parser
	{
	public:
		Parser(::deamer::file::tool::OSType os_);

	public:
		DLDL::ir::IR* GetIR(std::string text) override;
	};
}

#endif // DLDL_OOPSYNTAX_IR_PARSER_H
