#ifndef DLDL_LEXER_AST_RELATION_NODEISINLINED_H
#define DLDL_LEXER_AST_RELATION_NODEISINLINED_H

#include "DLDL_LEXER/Ast/Enum/Type.h"

namespace DLDL_LEXER { namespace ast { namespace relation { 

	constexpr static bool NodeIsInlined(::DLDL_LEXER::ast::Type t)
	{
		
		if (t == ::DLDL_LEXER::ast::Type::program)
		{
			return false;
		}

		if (t == ::DLDL_LEXER::ast::Type::stmts)
		{
			return false;
		}

		if (t == ::DLDL_LEXER::ast::Type::stmt)
		{
			return false;
		}

		if (t == ::DLDL_LEXER::ast::Type::tokendeclaration)
		{
			return false;
		}

		if (t == ::DLDL_LEXER::ast::Type::abstraction)
		{
			return false;
		}


		return false;
	}


}}}

#endif // DLDL_LEXER_AST_RELATION_NODEISINLINED_H