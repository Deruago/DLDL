#ifndef DLDL_VALUE_AST_RELATION_NODEISIGNORED_H
#define DLDL_VALUE_AST_RELATION_NODEISIGNORED_H

#include "DLDL_VALUE/Ast/Enum/Type.h"

namespace DLDL_VALUE { namespace ast { namespace relation { 

	constexpr static bool NodeIsIgnored(::DLDL_VALUE::ast::Type t)
	{
		
		if (t == ::DLDL_VALUE::ast::Type::SINGLE_COMMENT)
		{
			return false;
		}

		if (t == ::DLDL_VALUE::ast::Type::MULTI_COMMENT)
		{
			return false;
		}

		if (t == ::DLDL_VALUE::ast::Type::LEFT_PARANTHESIS)
		{
			return false;
		}

		if (t == ::DLDL_VALUE::ast::Type::RIGHT_PARANTHESIS)
		{
			return false;
		}

		if (t == ::DLDL_VALUE::ast::Type::LEFT_BRACKET)
		{
			return false;
		}

		if (t == ::DLDL_VALUE::ast::Type::RIGHT_BRACKET)
		{
			return false;
		}

		if (t == ::DLDL_VALUE::ast::Type::LEFT_SQUARE_BRACKET)
		{
			return false;
		}

		if (t == ::DLDL_VALUE::ast::Type::RIGHT_SQUARE_BRACKET)
		{
			return false;
		}

		if (t == ::DLDL_VALUE::ast::Type::DOT)
		{
			return false;
		}

		if (t == ::DLDL_VALUE::ast::Type::VALUE_CHARACTERISTIC)
		{
			return false;
		}

		if (t == ::DLDL_VALUE::ast::Type::VALUE_RULE)
		{
			return false;
		}

		if (t == ::DLDL_VALUE::ast::Type::NUMBER)
		{
			return false;
		}

		if (t == ::DLDL_VALUE::ast::Type::TEXT)
		{
			return false;
		}

		if (t == ::DLDL_VALUE::ast::Type::VARNAME)
		{
			return false;
		}

		if (t == ::DLDL_VALUE::ast::Type::ESCAPE_CHARS)
		{
			return false;
		}


		return false;
	}


}}}

#endif // DLDL_VALUE_AST_RELATION_NODEISIGNORED_H