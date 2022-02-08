#ifndef DLDL_LPDDEF_AST_RELATION_NODETEXTTOENUM_H
#define DLDL_LPDDEF_AST_RELATION_NODETEXTTOENUM_H

#include "DLDL_LPDDEF/Ast/Enum/Type.h"
#include <string>
#include <map>

namespace DLDL_LPDDEF { namespace ast { namespace relation { 

	static constexpr ::DLDL_LPDDEF::ast::Type ConvertTextToEnum(const std::string& text)
	{
		static const std::map<std::string, ::DLDL_LPDDEF::ast::Type> mapTextWithType = {
			{"", ::DLDL_LPDDEF::ast::Type::deamerreserved_unknown },
			
		{ "program", ::DLDL_LPDDEF::ast::Type::program },
	

		{ "deamerreserved_star__stmt__", ::DLDL_LPDDEF::ast::Type::deamerreserved_star__stmt__ },
	

		{ "stmt", ::DLDL_LPDDEF::ast::Type::stmt },
	

		{ "argument", ::DLDL_LPDDEF::ast::Type::argument },
	

		{ "argument_name", ::DLDL_LPDDEF::ast::Type::argument_name },
	

		{ "argument_block", ::DLDL_LPDDEF::ast::Type::argument_block },
	

		{ "deamerreserved_star__argument_stmt__", ::DLDL_LPDDEF::ast::Type::deamerreserved_star__argument_stmt__ },
	

		{ "argument_stmt", ::DLDL_LPDDEF::ast::Type::argument_stmt },
	

		{ "COLON", ::DLDL_LPDDEF::ast::Type::COLON },
	

		{ "LEFT_ANGLE_BRACKET", ::DLDL_LPDDEF::ast::Type::LEFT_ANGLE_BRACKET },
	

		{ "RIGHT_ANGLE_BRACKET", ::DLDL_LPDDEF::ast::Type::RIGHT_ANGLE_BRACKET },
	

		{ "VARNAME", ::DLDL_LPDDEF::ast::Type::VARNAME },
	

		{ "INDENTED_VALUE", ::DLDL_LPDDEF::ast::Type::INDENTED_VALUE },
	

		{ "ESCAPE_CHARS", ::DLDL_LPDDEF::ast::Type::ESCAPE_CHARS },
	

		};

		return mapTextWithType[text];
	}

}}}

#endif // DLDL_LPDDEF_AST_RELATION_NODETEXTTOENUM_H