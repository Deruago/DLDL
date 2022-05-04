#ifndef DLDL_GENERATION_AST_RELATION_NODEISINLINED_H
#define DLDL_GENERATION_AST_RELATION_NODEISINLINED_H

#include "DLDL_GENERATION/Ast/Enum/Type.h"

namespace DLDL_GENERATION { namespace ast { namespace relation { 

	constexpr static bool NodeIsInlined(::DLDL_GENERATION::ast::Type t)
	{
		
		if (t == ::DLDL_GENERATION::ast::Type::program)
		{
			return false;
		}

		if (t == ::DLDL_GENERATION::ast::Type::stmts)
		{
			return false;
		}

		if (t == ::DLDL_GENERATION::ast::Type::stmt)
		{
			return false;
		}

		if (t == ::DLDL_GENERATION::ast::Type::generate_declaration)
		{
			return false;
		}

		if (t == ::DLDL_GENERATION::ast::Type::integrate_declaration)
		{
			return false;
		}

		if (t == ::DLDL_GENERATION::ast::Type::argument_declaration)
		{
			return false;
		}

		if (t == ::DLDL_GENERATION::ast::Type::type)
		{
			return false;
		}

		if (t == ::DLDL_GENERATION::ast::Type::tool)
		{
			return false;
		}

		if (t == ::DLDL_GENERATION::ast::Type::argument_data)
		{
			return false;
		}


		return false;
	}


}}}

#endif // DLDL_GENERATION_AST_RELATION_NODEISINLINED_H