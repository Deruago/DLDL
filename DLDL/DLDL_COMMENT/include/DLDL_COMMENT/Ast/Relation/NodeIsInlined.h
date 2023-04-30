#ifndef DLDL_COMMENT_AST_RELATION_NODEISINLINED_H
#define DLDL_COMMENT_AST_RELATION_NODEISINLINED_H

#include "DLDL_COMMENT/Ast/Enum/Type.h"

namespace DLDL_COMMENT { namespace ast { namespace relation { 

	constexpr static bool NodeIsInlined(::DLDL_COMMENT::ast::Type t)
	{
		
		if (t == ::DLDL_COMMENT::ast::Type::program)
		{
			return false;
		}

		if (t == ::DLDL_COMMENT::ast::Type::deamerreserved_star__stmt__)
		{
			return true;
		}

		if (t == ::DLDL_COMMENT::ast::Type::stmt)
		{
			return false;
		}

		if (t == ::DLDL_COMMENT::ast::Type::comment_value_declaration)
		{
			return false;
		}

		if (t == ::DLDL_COMMENT::ast::Type::deamerreserved_long_3)
		{
			return true;
		}

		if (t == ::DLDL_COMMENT::ast::Type::deamerreserved_long_6)
		{
			return true;
		}

		if (t == ::DLDL_COMMENT::ast::Type::comment_abstraction)
		{
			return false;
		}

		if (t == ::DLDL_COMMENT::ast::Type::start_abstraction)
		{
			return false;
		}

		if (t == ::DLDL_COMMENT::ast::Type::end_abstraction)
		{
			return false;
		}

		if (t == ::DLDL_COMMENT::ast::Type::start_sequence)
		{
			return false;
		}

		if (t == ::DLDL_COMMENT::ast::Type::end_sequence)
		{
			return false;
		}

		if (t == ::DLDL_COMMENT::ast::Type::sequence)
		{
			return false;
		}

		if (t == ::DLDL_COMMENT::ast::Type::syntactic_reference)
		{
			return false;
		}


		return false;
	}


}}}

#endif // DLDL_COMMENT_AST_RELATION_NODEISINLINED_H