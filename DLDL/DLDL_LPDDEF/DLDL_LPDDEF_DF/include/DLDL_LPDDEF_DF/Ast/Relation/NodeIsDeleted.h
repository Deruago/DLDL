#ifndef DLDL_LPDDEF_DF_AST_RELATION_NODEISDELETED_H
#define DLDL_LPDDEF_DF_AST_RELATION_NODEISDELETED_H

#include "DLDL_LPDDEF_DF/Ast/Enum/Type.h"

namespace DLDL_LPDDEF_DF { namespace ast { namespace relation { 

	constexpr static bool NodeIsDeleted(::DLDL_LPDDEF_DF::ast::Type t)
	{
		
		if (t == ::DLDL_LPDDEF_DF::ast::Type::LAB)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::RAB)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::LSB)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::RSB)
		{
			return false;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::EQ)
		{
			return false;
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
			return true;
		}

		if (t == ::DLDL_LPDDEF_DF::ast::Type::ESCAPE_CHARS)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_LPDDEF_DF_AST_RELATION_NODEISDELETED_H