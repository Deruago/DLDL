#ifndef DLDL_GRAMMAR_PRODUCTION_RULE_AST_RELATION_NODEISINLINED_H
#define DLDL_GRAMMAR_PRODUCTION_RULE_AST_RELATION_NODEISINLINED_H

#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Enum/Type.h"

namespace DLDL_GRAMMAR_PRODUCTION_RULE { namespace ast { namespace relation { 

	constexpr static bool NodeIsInlined(::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type t)
	{
		
		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::program)
		{
			return false;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::stmts)
		{
			return false;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::stmt)
		{
			return false;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::group)
		{
			return false;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::nested_group)
		{
			return false;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::optional_group)
		{
			return false;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::zero_or_more_group)
		{
			return false;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::one_or_more_group)
		{
			return false;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::or_group)
		{
			return false;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::min_max_group)
		{
			return false;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::extension_group)
		{
			return false;
		}


		return false;
	}


}}}

#endif // DLDL_GRAMMAR_PRODUCTION_RULE_AST_RELATION_NODEISINLINED_H