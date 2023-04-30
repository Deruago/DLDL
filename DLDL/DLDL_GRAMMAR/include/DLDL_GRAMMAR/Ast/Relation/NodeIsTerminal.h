#ifndef DLDL_GRAMMAR_AST_RELATION_NODEISTERMINAL_H
#define DLDL_GRAMMAR_AST_RELATION_NODEISTERMINAL_H

#include "DLDL_GRAMMAR/Ast/Enum/Type.h"

namespace DLDL_GRAMMAR { namespace ast { namespace relation { 

	constexpr static bool NodeIsTerminal(::DLDL_GRAMMAR::ast::Type t)
	{
		
		if (t == ::DLDL_GRAMMAR::ast::Type::COMMENT)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR::ast::Type::START_ABSTRACTION)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR::ast::Type::GROUP_ABSTRACTION)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR::ast::Type::INLINE_ABSTRACTION)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR::ast::Type::INLINE_GROUP_ABSTRACTION)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR::ast::Type::UNKNOWN_ABSTRACTION)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR::ast::Type::NONTERMINAL)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR::ast::Type::PRODUCTION_RULE)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR::ast::Type::ESCAPE_CHARS)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_GRAMMAR_AST_RELATION_NODEISTERMINAL_H