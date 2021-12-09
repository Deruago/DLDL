#ifndef DLDL_PRECEDENCE_AST_RELATION_NODEENUMTOTEXT_H
#define DLDL_PRECEDENCE_AST_RELATION_NODEENUMTOTEXT_H

#include "DLDL_PRECEDENCE/Ast/Enum/Type.h"

namespace DLDL_PRECEDENCE { namespace ast { namespace relation { 

	static constexpr const char* ConvertEnumToText(::DLDL_PRECEDENCE::ast::Type type)
	{
		switch(type)
		{
			
	case ::DLDL_PRECEDENCE::ast::Type::program: {
		return "program";
	}
	

	case ::DLDL_PRECEDENCE::ast::Type::stmts: {
		return "stmts";
	}
	

	case ::DLDL_PRECEDENCE::ast::Type::stmt: {
		return "stmt";
	}
	

	case ::DLDL_PRECEDENCE::ast::Type::localized_precedence: {
		return "localized_precedence";
	}
	

	case ::DLDL_PRECEDENCE::ast::Type::specific_precedence: {
		return "specific_precedence";
	}
	

	case ::DLDL_PRECEDENCE::ast::Type::terminal_one_or_more: {
		return "terminal_one_or_more";
	}
	

	case ::DLDL_PRECEDENCE::ast::Type::PRECEDENCE: {
		return "PRECEDENCE";
	}
	

	case ::DLDL_PRECEDENCE::ast::Type::NUMBER: {
		return "NUMBER";
	}
	

	case ::DLDL_PRECEDENCE::ast::Type::TERMINAL: {
		return "TERMINAL";
	}
	

	case ::DLDL_PRECEDENCE::ast::Type::SYMBOLS: {
		return "SYMBOLS";
	}
	

	case ::DLDL_PRECEDENCE::ast::Type::ESCAPE_CHARS: {
		return "ESCAPE_CHARS";
	}
	

		}
		
		return "";
	}

}}}

#endif // DLDL_PRECEDENCE_AST_RELATION_NODEENUMTOTEXT_H