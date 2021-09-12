#ifndef DLDL_PRECEDENCE_AST_RELATION_NODEISNONTERMINAL_H
#define DLDL_PRECEDENCE_AST_RELATION_NODEISNONTERMINAL_H

#include "DLDL_PRECEDENCE/Ast/Enum/Type.h"

namespace DLDL_PRECEDENCE { namespace ast { namespace relation { 

	constexpr static bool NodeIsNonTerminal(::DLDL_PRECEDENCE::ast::Type t)
	{
		
		if (t == ::DLDL_PRECEDENCE::ast::Type::program)
		{
			return true;
		}

		if (t == ::DLDL_PRECEDENCE::ast::Type::stmts)
		{
			return true;
		}

		if (t == ::DLDL_PRECEDENCE::ast::Type::stmt)
		{
			return true;
		}

		if (t == ::DLDL_PRECEDENCE::ast::Type::localized_precedence)
		{
			return true;
		}

		if (t == ::DLDL_PRECEDENCE::ast::Type::specific_precedence)
		{
			return true;
		}

		if (t == ::DLDL_PRECEDENCE::ast::Type::terminal_one_or_more)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_PRECEDENCE_AST_RELATION_NODEISNONTERMINAL_H