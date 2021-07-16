#ifndef DLDL_GRAMMAR_PRODUCTION_RULE_AST_RELATION_NODEISNONTERMINAL_H
#define DLDL_GRAMMAR_PRODUCTION_RULE_AST_RELATION_NODEISNONTERMINAL_H

#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Enum/Type.h"

namespace DLDL_GRAMMAR_PRODUCTION_RULE { namespace ast { namespace relation { 

	constexpr static bool NodeIsNonTerminal(::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type t)
	{
		
		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::program)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::stmts)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::stmt)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::group)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::nested_group)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::optional_group)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::zero_or_more_group)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::one_or_more_group)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::or_group)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::min_max_group)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::extension_group)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_GRAMMAR_PRODUCTION_RULE_AST_RELATION_NODEISNONTERMINAL_H