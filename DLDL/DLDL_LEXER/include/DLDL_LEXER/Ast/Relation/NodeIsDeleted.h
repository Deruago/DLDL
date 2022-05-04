#ifndef DLDL_LEXER_AST_RELATION_NODEISDELETED_H
#define DLDL_LEXER_AST_RELATION_NODEISDELETED_H

#include "DLDL_LEXER/Ast/Enum/Type.h"

namespace DLDL_LEXER { namespace ast { namespace relation { 

	constexpr static bool NodeIsDeleted(::DLDL_LEXER::ast::Type t)
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
			return true;
		}

		if (t == ::DLDL_LEXER::ast::Type::COMMENT)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_LEXER_AST_RELATION_NODEISDELETED_H