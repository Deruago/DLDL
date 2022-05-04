#ifndef DLDL_LEXER_AST_RELATION_NODEISNONTERMINAL_H
#define DLDL_LEXER_AST_RELATION_NODEISNONTERMINAL_H

#include "DLDL_LEXER/Ast/Enum/Type.h"

namespace DLDL_LEXER { namespace ast { namespace relation { 

	constexpr static bool NodeIsNonTerminal(::DLDL_LEXER::ast::Type t)
	{
		
		if (t == ::DLDL_LEXER::ast::Type::program)
		{
			return true;
		}

		if (t == ::DLDL_LEXER::ast::Type::stmts)
		{
			return true;
		}

		if (t == ::DLDL_LEXER::ast::Type::stmt)
		{
			return true;
		}

		if (t == ::DLDL_LEXER::ast::Type::tokendeclaration)
		{
			return true;
		}

		if (t == ::DLDL_LEXER::ast::Type::abstraction)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_LEXER_AST_RELATION_NODEISNONTERMINAL_H