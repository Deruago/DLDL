#ifndef DLDL_LEXER_AST_RELATION_NODEISTERMINAL_H
#define DLDL_LEXER_AST_RELATION_NODEISTERMINAL_H

#include "DLDL_LEXER/Ast/Enum/Type.h"

namespace DLDL_LEXER { namespace ast { namespace relation { 

	constexpr static bool NodeIsTerminal(::DLDL_LEXER::ast::Type t)
	{
		
		if (t == ::DLDL_LEXER::ast::Type::DELETE_ABSTRACTION)
		{
			return true;
		}

		if (t == ::DLDL_LEXER::ast::Type::IGNORE_ABSTRACTION)
		{
			return true;
		}

		if (t == ::DLDL_LEXER::ast::Type::NOVALUE_ABSTRACTION)
		{
			return true;
		}

		if (t == ::DLDL_LEXER::ast::Type::CRASH_ABSTRACTION)
		{
			return true;
		}

		if (t == ::DLDL_LEXER::ast::Type::STANDARD_ABSTRACTION)
		{
			return true;
		}

		if (t == ::DLDL_LEXER::ast::Type::UNKNOWN_ABSTRACTION)
		{
			return true;
		}

		if (t == ::DLDL_LEXER::ast::Type::TERMINAL)
		{
			return true;
		}

		if (t == ::DLDL_LEXER::ast::Type::REGEX)
		{
			return true;
		}

		if (t == ::DLDL_LEXER::ast::Type::ESCAPE_CHARS)
		{
			return true;
		}

		if (t == ::DLDL_LEXER::ast::Type::COMMENT)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_LEXER_AST_RELATION_NODEISTERMINAL_H