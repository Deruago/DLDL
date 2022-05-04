#ifndef DLDL_GRAMMAR_AST_RELATION_NODEISNONTERMINAL_H
#define DLDL_GRAMMAR_AST_RELATION_NODEISNONTERMINAL_H

#include "DLDL_GRAMMAR/Ast/Enum/Type.h"

namespace DLDL_GRAMMAR { namespace ast { namespace relation { 

	constexpr static bool NodeIsNonTerminal(::DLDL_GRAMMAR::ast::Type t)
	{
		
		if (t == ::DLDL_GRAMMAR::ast::Type::program)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR::ast::Type::stmts)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR::ast::Type::stmt)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR::ast::Type::abstraction_declaration)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR::ast::Type::abstraction)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR::ast::Type::definition)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR::ast::Type::production_rules)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_GRAMMAR_AST_RELATION_NODEISNONTERMINAL_H