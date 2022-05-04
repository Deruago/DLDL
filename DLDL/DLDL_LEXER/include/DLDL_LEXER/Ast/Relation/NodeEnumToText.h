#ifndef DLDL_LEXER_AST_RELATION_NODEENUMTOTEXT_H
#define DLDL_LEXER_AST_RELATION_NODEENUMTOTEXT_H

#include "DLDL_LEXER/Ast/Enum/Type.h"

namespace DLDL_LEXER { namespace ast { namespace relation { 

	static constexpr const char* ConvertEnumToText(::DLDL_LEXER::ast::Type type)
	{
		switch(type)
		{
			
	case ::DLDL_LEXER::ast::Type::program: {
		return "program";
	}
	

	case ::DLDL_LEXER::ast::Type::stmts: {
		return "stmts";
	}
	

	case ::DLDL_LEXER::ast::Type::stmt: {
		return "stmt";
	}
	

	case ::DLDL_LEXER::ast::Type::tokendeclaration: {
		return "tokendeclaration";
	}
	

	case ::DLDL_LEXER::ast::Type::abstraction: {
		return "abstraction";
	}
	

	case ::DLDL_LEXER::ast::Type::DELETE_ABSTRACTION: {
		return "DELETE_ABSTRACTION";
	}
	

	case ::DLDL_LEXER::ast::Type::IGNORE_ABSTRACTION: {
		return "IGNORE_ABSTRACTION";
	}
	

	case ::DLDL_LEXER::ast::Type::NOVALUE_ABSTRACTION: {
		return "NOVALUE_ABSTRACTION";
	}
	

	case ::DLDL_LEXER::ast::Type::CRASH_ABSTRACTION: {
		return "CRASH_ABSTRACTION";
	}
	

	case ::DLDL_LEXER::ast::Type::STANDARD_ABSTRACTION: {
		return "STANDARD_ABSTRACTION";
	}
	

	case ::DLDL_LEXER::ast::Type::UNKNOWN_ABSTRACTION: {
		return "UNKNOWN_ABSTRACTION";
	}
	

	case ::DLDL_LEXER::ast::Type::TERMINAL: {
		return "TERMINAL";
	}
	

	case ::DLDL_LEXER::ast::Type::REGEX: {
		return "REGEX";
	}
	

	case ::DLDL_LEXER::ast::Type::ESCAPE_CHARS: {
		return "ESCAPE_CHARS";
	}
	

	case ::DLDL_LEXER::ast::Type::COMMENT: {
		return "COMMENT";
	}
	

		}
		
		return "";
	}

}}}

#endif // DLDL_LEXER_AST_RELATION_NODEENUMTOTEXT_H