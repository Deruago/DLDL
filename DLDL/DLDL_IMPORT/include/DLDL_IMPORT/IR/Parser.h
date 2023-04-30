#ifndef DLDL_IMPORT_IR_PARSER_H
#define DLDL_IMPORT_IR_PARSER_H

#include "DLDL/IR/Parser.h"
#include "DLDL_IMPORT/Ast/Listener/User/Import.h"
#include "DLDL_IMPORT/Bison/Parser.h"
#include <Deamer/External/Cpp/Ast/Tree.h>
#include <Deamer/File/Tool/OSType.h>
#include <memory>
#include <string>

namespace DLDL::ir::import
{
	class Parser : public ::DLDL::ir::Parser
	{
	public:
		Parser(::deamer::file::tool::OSType os_);

	public:
		DLDL::ir::IR* GetIR(std::string text) override;
	};
}

#endif // DLDL_IMPORT_IR_PARSER_H
