#ifndef DLDL_LPDSTRUCT_AST_RELATION_NODETEXTTOENUM_H
#define DLDL_LPDSTRUCT_AST_RELATION_NODETEXTTOENUM_H

#include "DLDL_LPDSTRUCT/Ast/Enum/Type.h"
#include <string>
#include <map>

namespace DLDL_LPDSTRUCT { namespace ast { namespace relation { 

	static constexpr ::DLDL_LPDSTRUCT::ast::Type ConvertTextToEnum(const std::string& text)
	{
		static const std::map<std::string, ::DLDL_LPDSTRUCT::ast::Type> mapTextWithType = {
			{"", ::DLDL_LPDSTRUCT::ast::Type::deamerreserved_unknown },
			
		{ "program", ::DLDL_LPDSTRUCT::ast::Type::program },
	

		{ "deamerreserved_star__stmt__", ::DLDL_LPDSTRUCT::ast::Type::deamerreserved_star__stmt__ },
	

		{ "stmt", ::DLDL_LPDSTRUCT::ast::Type::stmt },
	

		{ "argument", ::DLDL_LPDSTRUCT::ast::Type::argument },
	

		{ "argument_name", ::DLDL_LPDSTRUCT::ast::Type::argument_name },
	

		{ "argument_block", ::DLDL_LPDSTRUCT::ast::Type::argument_block },
	

		{ "deamerreserved_long_60", ::DLDL_LPDSTRUCT::ast::Type::deamerreserved_long_60 },
	

		{ "deamerreserved_long_63", ::DLDL_LPDSTRUCT::ast::Type::deamerreserved_long_63 },
	

		{ "deamerreserved_long_66", ::DLDL_LPDSTRUCT::ast::Type::deamerreserved_long_66 },
	

		{ "COLON", ::DLDL_LPDSTRUCT::ast::Type::COLON },
	

		{ "LEFT_ANGLE_BRACKET", ::DLDL_LPDSTRUCT::ast::Type::LEFT_ANGLE_BRACKET },
	

		{ "RIGHT_ANGLE_BRACKET", ::DLDL_LPDSTRUCT::ast::Type::RIGHT_ANGLE_BRACKET },
	

		{ "VARNAME", ::DLDL_LPDSTRUCT::ast::Type::VARNAME },
	

		{ "VARNAME_EXT", ::DLDL_LPDSTRUCT::ast::Type::VARNAME_EXT },
	

		{ "INDENTED_VALUE", ::DLDL_LPDSTRUCT::ast::Type::INDENTED_VALUE },
	

		{ "ESCAPE_CHARS", ::DLDL_LPDSTRUCT::ast::Type::ESCAPE_CHARS },
	

		};

		return mapTextWithType[text];
	}

}}}

#endif // DLDL_LPDSTRUCT_AST_RELATION_NODETEXTTOENUM_H