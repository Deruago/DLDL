#ifndef DLDL_LPDDEF_EF_AST_RELATION_NODETEXTTOENUM_H
#define DLDL_LPDDEF_EF_AST_RELATION_NODETEXTTOENUM_H

#include "DLDL_LPDDEF_EF/Ast/Enum/Type.h"
#include <string>
#include <map>

namespace DLDL_LPDDEF_EF { namespace ast { namespace relation { 

	static constexpr ::DLDL_LPDDEF_EF::ast::Type ConvertTextToEnum(const std::string& text)
	{
		static const std::map<std::string, ::DLDL_LPDDEF_EF::ast::Type> mapTextWithType = {
			{"", ::DLDL_LPDDEF_EF::ast::Type::deamerreserved_unknown },
			
		{ "program", ::DLDL_LPDDEF_EF::ast::Type::program },
	

		{ "deamerreserved_star__stmt__", ::DLDL_LPDDEF_EF::ast::Type::deamerreserved_star__stmt__ },
	

		{ "stmt", ::DLDL_LPDDEF_EF::ast::Type::stmt },
	

		{ "comment_line", ::DLDL_LPDDEF_EF::ast::Type::comment_line },
	

		{ "standard_variant", ::DLDL_LPDDEF_EF::ast::Type::standard_variant },
	

		{ "standard_variant_specific_number", ::DLDL_LPDDEF_EF::ast::Type::standard_variant_specific_number },
	

		{ "value", ::DLDL_LPDDEF_EF::ast::Type::value },
	

		{ "enum_name", ::DLDL_LPDDEF_EF::ast::Type::enum_name },
	

		{ "COMMENT", ::DLDL_LPDDEF_EF::ast::Type::COMMENT },
	

		{ "VARNAME", ::DLDL_LPDDEF_EF::ast::Type::VARNAME },
	

		{ "NUMBER", ::DLDL_LPDDEF_EF::ast::Type::NUMBER },
	

		{ "COLON", ::DLDL_LPDDEF_EF::ast::Type::COLON },
	

		{ "SEMICOLON", ::DLDL_LPDDEF_EF::ast::Type::SEMICOLON },
	

		{ "ESCAPE_CHARS", ::DLDL_LPDDEF_EF::ast::Type::ESCAPE_CHARS },
	

		};

		return mapTextWithType[text];
	}

}}}

#endif // DLDL_LPDDEF_EF_AST_RELATION_NODETEXTTOENUM_H