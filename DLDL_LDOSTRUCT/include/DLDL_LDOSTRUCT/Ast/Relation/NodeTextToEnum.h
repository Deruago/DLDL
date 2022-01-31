#ifndef DLDL_LDOSTRUCT_AST_RELATION_NODETEXTTOENUM_H
#define DLDL_LDOSTRUCT_AST_RELATION_NODETEXTTOENUM_H

#include "DLDL_LDOSTRUCT/Ast/Enum/Type.h"
#include <string>
#include <map>

namespace DLDL_LDOSTRUCT { namespace ast { namespace relation { 

	static constexpr ::DLDL_LDOSTRUCT::ast::Type ConvertTextToEnum(const std::string& text)
	{
		static const std::map<std::string, ::DLDL_LDOSTRUCT::ast::Type> mapTextWithType = {
			{"", ::DLDL_LDOSTRUCT::ast::Type::deamerreserved_unknown },
			
		{ "program", ::DLDL_LDOSTRUCT::ast::Type::program },
	

		{ "deamerreserved_star__stmt__", ::DLDL_LDOSTRUCT::ast::Type::deamerreserved_star__stmt__ },
	

		{ "stmt", ::DLDL_LDOSTRUCT::ast::Type::stmt },
	

		{ "argument", ::DLDL_LDOSTRUCT::ast::Type::argument },
	

		{ "argument_name", ::DLDL_LDOSTRUCT::ast::Type::argument_name },
	

		{ "argument_block", ::DLDL_LDOSTRUCT::ast::Type::argument_block },
	

		{ "deamerreserved_star__argument_stmt__", ::DLDL_LDOSTRUCT::ast::Type::deamerreserved_star__argument_stmt__ },
	

		{ "argument_stmt", ::DLDL_LDOSTRUCT::ast::Type::argument_stmt },
	

		{ "COLON", ::DLDL_LDOSTRUCT::ast::Type::COLON },
	

		{ "LEFT_ANGLE_BRACKET", ::DLDL_LDOSTRUCT::ast::Type::LEFT_ANGLE_BRACKET },
	

		{ "RIGHT_ANGLE_BRACKET", ::DLDL_LDOSTRUCT::ast::Type::RIGHT_ANGLE_BRACKET },
	

		{ "VARNAME", ::DLDL_LDOSTRUCT::ast::Type::VARNAME },
	

		{ "VARNAME_EXT", ::DLDL_LDOSTRUCT::ast::Type::VARNAME_EXT },
	

		{ "INDENTED_VALUE", ::DLDL_LDOSTRUCT::ast::Type::INDENTED_VALUE },
	

		{ "ESCAPE_CHARS", ::DLDL_LDOSTRUCT::ast::Type::ESCAPE_CHARS },
	

		};

		return mapTextWithType[text];
	}

}}}

#endif // DLDL_LDOSTRUCT_AST_RELATION_NODETEXTTOENUM_H