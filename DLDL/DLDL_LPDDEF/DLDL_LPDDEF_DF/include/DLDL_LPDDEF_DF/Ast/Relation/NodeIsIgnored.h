#ifndef DLDL_LPDDEF_DF_AST_RELATION_NODEISIGNORED_H
#define DLDL_LPDDEF_DF_AST_RELATION_NODEISIGNORED_H

#include "DLDL_LPDDEF_DF/Ast/Enum/Type.h"

namespace DLDL_LPDDEF_DF { namespace ast { namespace relation { 

	constexpr static bool NodeIsIgnored(::DLDL_LPDDEF_DF::ast::Type t)
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
			return false;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::LB)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::RB)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::COMMA)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::OPTIONAL)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::VECTOR)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::DEAMER_VARNAME)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::COMMENT)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::VARNAME)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::NUMBER)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::STRING)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::SEMICOLON)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::ESCAPE_CHARS)
		{
			return false;
		}


		return false;
	}


}}}

#endif // DLDL_LPDDEF_DF_AST_RELATION_NODEISIGNORED_H