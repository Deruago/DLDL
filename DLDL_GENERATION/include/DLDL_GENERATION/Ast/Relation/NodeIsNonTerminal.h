#ifndef DLDL_GENERATION_AST_RELATION_NODEISNONTERMINAL_H
#define DLDL_GENERATION_AST_RELATION_NODEISNONTERMINAL_H

#include "DLDL_GENERATION/Ast/Enum/Type.h"

namespace DLDL_GENERATION { namespace ast { namespace relation { 

	constexpr static bool NodeIsNonTerminal(::DLDL_GENERATION::ast::Type t)
	{
		
		if (t == ::DLDL_GENERATION::ast::Type::program)
		{
			return true;
		}

		if (t == ::DLDL_GENERATION::ast::Type::stmts)
		{
			return true;
		}

		if (t == ::DLDL_GENERATION::ast::Type::stmt)
		{
			return true;
		}

		if (t == ::DLDL_GENERATION::ast::Type::generate_declaration)
		{
			return true;
		}

		if (t == ::DLDL_GENERATION::ast::Type::integrate_declaration)
		{
			return true;
		}

		if (t == ::DLDL_GENERATION::ast::Type::argument_declaration)
		{
			return true;
		}

		if (t == ::DLDL_GENERATION::ast::Type::type)
		{
			return true;
		}

		if (t == ::DLDL_GENERATION::ast::Type::tool)
		{
			return true;
		}

		if (t == ::DLDL_GENERATION::ast::Type::argument_data)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_GENERATION_AST_RELATION_NODEISNONTERMINAL_H