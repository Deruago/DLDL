#ifndef DLDL_LPDDEF_DF_AST_RELATION_NODEENUMTOTEXT_H
#define DLDL_LPDDEF_DF_AST_RELATION_NODEENUMTOTEXT_H

#include "DLDL_LPDDEF_DF/Ast/Enum/Type.h"

namespace DLDL_LPDDEF_DF { namespace ast { namespace relation { 

	static constexpr const char* ConvertEnumToText(::DLDL_LPDDEF_DF::ast::Type type)
	{
		switch(type)
		{
			
	case ::DLDL_LPDDEF_DF::ast::Type::program: {
		return "program";
	}
	

	case ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__stmt__: {
		return "deamerreserved_star__stmt__";
	}
	

	case ::DLDL_LPDDEF_DF::ast::Type::stmt: {
		return "stmt";
	}
	

	case ::DLDL_LPDDEF_DF::ast::Type::comment_line: {
		return "comment_line";
	}
	

	case ::DLDL_LPDDEF_DF::ast::Type::vector_variant: {
		return "vector_variant";
	}
	

	case ::DLDL_LPDDEF_DF::ast::Type::optional_variant: {
		return "optional_variant";
	}
	

	case ::DLDL_LPDDEF_DF::ast::Type::value_part: {
		return "value_part";
	}
	

	case ::DLDL_LPDDEF_DF::ast::Type::standard_variant: {
		return "standard_variant";
	}
	

	case ::DLDL_LPDDEF_DF::ast::Type::value: {
		return "value";
	}
	

	case ::DLDL_LPDDEF_DF::ast::Type::value_type: {
		return "value_type";
	}
	

	case ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_arrow__value_type__: {
		return "deamerreserved_arrow__value_type__";
	}
	

	case ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COMMA__value_type__: {
		return "deamerreserved_star__COMMA__value_type__";
	}
	

	case ::DLDL_LPDDEF_DF::ast::Type::var_type: {
		return "var_type";
	}
	

	case ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_arrow__VARNAME__: {
		return "deamerreserved_arrow__VARNAME__";
	}
	

	case ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COLON__VARNAME__: {
		return "deamerreserved_star__COLON__VARNAME__";
	}
	

	case ::DLDL_LPDDEF_DF::ast::Type::var_name: {
		return "var_name";
	}
	

	case ::DLDL_LPDDEF_DF::ast::Type::LAB: {
		return "LAB";
	}
	

	case ::DLDL_LPDDEF_DF::ast::Type::RAB: {
		return "RAB";
	}
	

	case ::DLDL_LPDDEF_DF::ast::Type::LSB: {
		return "LSB";
	}
	

	case ::DLDL_LPDDEF_DF::ast::Type::RSB: {
		return "RSB";
	}
	

	case ::DLDL_LPDDEF_DF::ast::Type::EQ: {
		return "EQ";
	}
	

	case ::DLDL_LPDDEF_DF::ast::Type::COLON: {
		return "COLON";
	}
	

	case ::DLDL_LPDDEF_DF::ast::Type::LB: {
		return "LB";
	}
	

	case ::DLDL_LPDDEF_DF::ast::Type::RB: {
		return "RB";
	}
	

	case ::DLDL_LPDDEF_DF::ast::Type::COMMA: {
		return "COMMA";
	}
	

	case ::DLDL_LPDDEF_DF::ast::Type::OPTIONAL: {
		return "OPTIONAL";
	}
	

	case ::DLDL_LPDDEF_DF::ast::Type::VECTOR: {
		return "VECTOR";
	}
	

	case ::DLDL_LPDDEF_DF::ast::Type::DEAMER_VARNAME: {
		return "DEAMER_VARNAME";
	}
	

	case ::DLDL_LPDDEF_DF::ast::Type::COMMENT: {
		return "COMMENT";
	}
	

	case ::DLDL_LPDDEF_DF::ast::Type::VARNAME: {
		return "VARNAME";
	}
	

	case ::DLDL_LPDDEF_DF::ast::Type::NUMBER: {
		return "NUMBER";
	}
	

	case ::DLDL_LPDDEF_DF::ast::Type::STRING: {
		return "STRING";
	}
	

	case ::DLDL_LPDDEF_DF::ast::Type::SEMICOLON: {
		return "SEMICOLON";
	}
	

	case ::DLDL_LPDDEF_DF::ast::Type::ESCAPE_CHARS: {
		return "ESCAPE_CHARS";
	}
	

		}
		
		return "";
	}

}}}

#endif // DLDL_LPDDEF_DF_AST_RELATION_NODEENUMTOTEXT_H