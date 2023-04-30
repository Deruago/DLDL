#ifndef DLDL_GENERATION_AST_RELATION_NODEENUMTOTEXT_H
#define DLDL_GENERATION_AST_RELATION_NODEENUMTOTEXT_H

#include "DLDL_GENERATION/Ast/Enum/Type.h"

namespace DLDL_GENERATION { namespace ast { namespace relation { 

	static constexpr const char* ConvertEnumToText(::DLDL_GENERATION::ast::Type type)
	{
		switch(type)
		{
			
	case ::DLDL_GENERATION::ast::Type::program: {
		return "program";
	}
	

	case ::DLDL_GENERATION::ast::Type::stmts: {
		return "stmts";
	}
	

	case ::DLDL_GENERATION::ast::Type::stmt: {
		return "stmt";
	}
	

	case ::DLDL_GENERATION::ast::Type::generate_declaration: {
		return "generate_declaration";
	}
	

	case ::DLDL_GENERATION::ast::Type::integrate_declaration: {
		return "integrate_declaration";
	}
	

	case ::DLDL_GENERATION::ast::Type::argument_declaration: {
		return "argument_declaration";
	}
	

	case ::DLDL_GENERATION::ast::Type::type: {
		return "type";
	}
	

	case ::DLDL_GENERATION::ast::Type::tool: {
		return "tool";
	}
	

	case ::DLDL_GENERATION::ast::Type::argument_data: {
		return "argument_data";
	}
	

	case ::DLDL_GENERATION::ast::Type::GENERATE: {
		return "GENERATE";
	}
	

	case ::DLDL_GENERATION::ast::Type::INTEGRATE: {
		return "INTEGRATE";
	}
	

	case ::DLDL_GENERATION::ast::Type::ARGUMENT: {
		return "ARGUMENT";
	}
	

	case ::DLDL_GENERATION::ast::Type::VALUE: {
		return "VALUE";
	}
	

	case ::DLDL_GENERATION::ast::Type::SYMBOLS: {
		return "SYMBOLS";
	}
	

	case ::DLDL_GENERATION::ast::Type::ESCAPE_CHARS: {
		return "ESCAPE_CHARS";
	}
	

		}
		
		return "";
	}

}}}

#endif // DLDL_GENERATION_AST_RELATION_NODEENUMTOTEXT_H