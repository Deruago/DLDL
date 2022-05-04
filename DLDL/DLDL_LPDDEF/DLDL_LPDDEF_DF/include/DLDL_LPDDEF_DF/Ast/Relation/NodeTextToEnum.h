#ifndef DLDL_LPDDEF_DF_AST_RELATION_NODETEXTTOENUM_H
#define DLDL_LPDDEF_DF_AST_RELATION_NODETEXTTOENUM_H

#include "DLDL_LPDDEF_DF/Ast/Enum/Type.h"
#include <string>
#include <map>

namespace DLDL_LPDDEF_DF { namespace ast { namespace relation { 

	static constexpr ::DLDL_LPDDEF_DF::ast::Type ConvertTextToEnum(const std::string& text)
	{
		static const std::map<std::string, ::DLDL_LPDDEF_DF::ast::Type> mapTextWithType = {
			{"", ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_unknown },
			
		{ "program", ::DLDL_LPDDEF_DF::ast::Type::program },
	

		{ "deamerreserved_star__stmt__", ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__stmt__ },
	

		{ "stmt", ::DLDL_LPDDEF_DF::ast::Type::stmt },
	

		{ "comment_line", ::DLDL_LPDDEF_DF::ast::Type::comment_line },
	

		{ "vector_variant", ::DLDL_LPDDEF_DF::ast::Type::vector_variant },
	

		{ "optional_variant", ::DLDL_LPDDEF_DF::ast::Type::optional_variant },
	

		{ "value_part", ::DLDL_LPDDEF_DF::ast::Type::value_part },
	

		{ "standard_variant", ::DLDL_LPDDEF_DF::ast::Type::standard_variant },
	

		{ "value", ::DLDL_LPDDEF_DF::ast::Type::value },
	

		{ "value_type", ::DLDL_LPDDEF_DF::ast::Type::value_type },
	

		{ "deamerreserved_arrow__value_type__", ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_arrow__value_type__ },
	

		{ "deamerreserved_star__COMMA__value_type__", ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COMMA__value_type__ },
	

		{ "var_type", ::DLDL_LPDDEF_DF::ast::Type::var_type },
	

		{ "deamerreserved_arrow__VARNAME__", ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_arrow__VARNAME__ },
	

		{ "deamerreserved_star__COLON__VARNAME__", ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COLON__VARNAME__ },
	

		{ "var_name", ::DLDL_LPDDEF_DF::ast::Type::var_name },
	

		{ "LAB", ::DLDL_LPDDEF_DF::ast::Type::LAB },
	

		{ "RAB", ::DLDL_LPDDEF_DF::ast::Type::RAB },
	

		{ "LSB", ::DLDL_LPDDEF_DF::ast::Type::LSB },
	

		{ "RSB", ::DLDL_LPDDEF_DF::ast::Type::RSB },
	

		{ "EQ", ::DLDL_LPDDEF_DF::ast::Type::EQ },
	

		{ "COLON", ::DLDL_LPDDEF_DF::ast::Type::COLON },
	

		{ "LB", ::DLDL_LPDDEF_DF::ast::Type::LB },
	

		{ "RB", ::DLDL_LPDDEF_DF::ast::Type::RB },
	

		{ "COMMA", ::DLDL_LPDDEF_DF::ast::Type::COMMA },
	

		{ "OPTIONAL", ::DLDL_LPDDEF_DF::ast::Type::OPTIONAL },
	

		{ "VECTOR", ::DLDL_LPDDEF_DF::ast::Type::VECTOR },
	

		{ "DEAMER_VARNAME", ::DLDL_LPDDEF_DF::ast::Type::DEAMER_VARNAME },
	

		{ "COMMENT", ::DLDL_LPDDEF_DF::ast::Type::COMMENT },
	

		{ "VARNAME", ::DLDL_LPDDEF_DF::ast::Type::VARNAME },
	

		{ "NUMBER", ::DLDL_LPDDEF_DF::ast::Type::NUMBER },
	

		{ "STRING", ::DLDL_LPDDEF_DF::ast::Type::STRING },
	

		{ "SEMICOLON", ::DLDL_LPDDEF_DF::ast::Type::SEMICOLON },
	

		{ "ESCAPE_CHARS", ::DLDL_LPDDEF_DF::ast::Type::ESCAPE_CHARS },
	

		};

		return mapTextWithType[text];
	}

}}}

#endif // DLDL_LPDDEF_DF_AST_RELATION_NODETEXTTOENUM_H