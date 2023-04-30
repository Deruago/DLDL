#ifndef DLDL_GRAMMAR_AST_RELATION_NODEISINLINED_H
#define DLDL_GRAMMAR_AST_RELATION_NODEISINLINED_H

#include "DLDL_GRAMMAR/Ast/Enum/Type.h"

namespace DLDL_GRAMMAR { namespace ast { namespace relation { 

	constexpr static bool NodeIsInlined(::DLDL_GRAMMAR::ast::Type t)
	{
		
		if (t == ::DLDL_GRAMMAR::ast::Type::program)
		{
			return false;
		}

		if (t == ::DLDL_GRAMMAR::ast::Type::stmts)
		{
			return false;
		}

		if (t == ::DLDL_GRAMMAR::ast::Type::stmt)
		{
			return false;
		}

		if (t == ::DLDL_GRAMMAR::ast::Type::abstraction_declaration)
		{
			return false;
		}

		if (t == ::DLDL_GRAMMAR::ast::Type::abstraction)
		{
			return false;
		}

		if (t == ::DLDL_GRAMMAR::ast::Type::definition)
		{
			return false;
		}

		if (t == ::DLDL_GRAMMAR::ast::Type::production_rules)
		{
			return false;
		}


		return false;
	}


}}}

#endif // DLDL_GRAMMAR_AST_RELATION_NODEISINLINED_H