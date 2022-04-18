#ifndef DLDL_LEXER_AST_RELATION_NODEISIGNORED_H
#define DLDL_LEXER_AST_RELATION_NODEISIGNORED_H

#include "DLDL_LEXER/Ast/Enum/Type.h"

namespace DLDL_LEXER { namespace ast { namespace relation { 

	constexpr static bool NodeIsIgnored(::DLDL_LEXER::ast::Type t)
	{
		
		if (t == ::DLDL_LEXER::ast::Type::DELETE_ABSTRACTION)
		{
			return false;
		}

		if (t == ::DLDL_LEXER::ast::Type::IGNORE_ABSTRACTION)
		{
			return false;
		}

		if (t == ::DLDL_LEXER::ast::Type::NOVALUE_ABSTRACTION)
		{
			return false;
		}

		if (t == ::DLDL_LEXER::ast::Type::CRASH_ABSTRACTION)
		{
			return false;
		}

		if (t == ::DLDL_LEXER::ast::Type::STANDARD_ABSTRACTION)
		{
			return false;
		}

		if (t == ::DLDL_LEXER::ast::Type::UNKNOWN_ABSTRACTION)
		{
			return false;
		}

		if (t == ::DLDL_LEXER::ast::Type::TERMINAL)
		{
			return false;
		}

		if (t == ::DLDL_LEXER::ast::Type::REGEX)
		{
			return false;
		}

		if (t == ::DLDL_LEXER::ast::Type::ESCAPE_CHARS)
		{
			return false;
		}

		if (t == ::DLDL_LEXER::ast::Type::COMMENT)
		{
			return false;
		}


		return false;
	}


}}}

#endif // DLDL_LEXER_AST_RELATION_NODEISIGNORED_H