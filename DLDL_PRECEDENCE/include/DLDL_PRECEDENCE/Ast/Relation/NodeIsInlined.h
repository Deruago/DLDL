#ifndef DLDL_PRECEDENCE_AST_RELATION_NODEISINLINED_H
#define DLDL_PRECEDENCE_AST_RELATION_NODEISINLINED_H

#include "DLDL_PRECEDENCE/Ast/Enum/Type.h"

namespace DLDL_PRECEDENCE { namespace ast { namespace relation { 

	constexpr static bool NodeIsInlined(::DLDL_PRECEDENCE::ast::Type t)
	{
		
		if (t == ::DLDL_PRECEDENCE::ast::Type::program)
		{
			return false;
		}

		if (t == ::DLDL_PRECEDENCE::ast::Type::stmts)
		{
			return false;
		}

		if (t == ::DLDL_PRECEDENCE::ast::Type::stmt)
		{
			return false;
		}

		if (t == ::DLDL_PRECEDENCE::ast::Type::localized_precedence)
		{
			return false;
		}

		if (t == ::DLDL_PRECEDENCE::ast::Type::specific_precedence)
		{
			return false;
		}

		if (t == ::DLDL_PRECEDENCE::ast::Type::terminal_one_or_more)
		{
			return false;
		}


		return false;
	}


}}}

#endif // DLDL_PRECEDENCE_AST_RELATION_NODEISINLINED_H