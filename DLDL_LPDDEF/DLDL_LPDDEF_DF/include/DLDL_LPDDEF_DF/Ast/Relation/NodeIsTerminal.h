#ifndef DLDL_LPDDEF_DF_AST_RELATION_NODEISTERMINAL_H
#define DLDL_LPDDEF_DF_AST_RELATION_NODEISTERMINAL_H

#include "DLDL_LPDDEF_DF/Ast/Enum/Type.h"

namespace DLDL_LPDDEF_DF { namespace ast { namespace relation { 

	constexpr static bool NodeIsTerminal(::DLDL_LPDDEF_DF::ast::Type t)
	{
		
		if (t == ::DLDL_LPDDEF_DF::ast::Type::LAB)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::RAB)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::LSB)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::RSB)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::EQ)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::COLON)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::LB)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::RB)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::COMMA)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::OPTIONAL)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::VECTOR)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::DEAMER_VARNAME)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::COMMENT)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::VARNAME)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::NUMBER)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::STRING)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::SEMICOLON)
		{
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::ESCAPE_CHARS)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_LPDDEF_DF_AST_RELATION_NODEISTERMINAL_H