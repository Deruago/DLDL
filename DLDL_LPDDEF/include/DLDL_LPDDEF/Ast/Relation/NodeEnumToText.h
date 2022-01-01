#ifndef DLDL_LPDDEF_AST_RELATION_NODEENUMTOTEXT_H
#define DLDL_LPDDEF_AST_RELATION_NODEENUMTOTEXT_H

#include "DLDL_LPDDEF/Ast/Enum/Type.h"

namespace DLDL_LPDDEF { namespace ast { namespace relation { 

	static constexpr const char* ConvertEnumToText(::DLDL_LPDDEF::ast::Type type)
	{
		switch(type)
		{
			
	case ::DLDL_LPDDEF::ast::Type::program: {
		return "program";
	}
	

	case ::DLDL_LPDDEF::ast::Type::deamerreserved_star__stmt__: {
		return "deamerreserved_star__stmt__";
	}
	

	case ::DLDL_LPDDEF::ast::Type::stmt: {
		return "stmt";
	}
	

	case ::DLDL_LPDDEF::ast::Type::argument: {
		return "argument";
	}
	

	case ::DLDL_LPDDEF::ast::Type::argument_name: {
		return "argument_name";
	}
	

	case ::DLDL_LPDDEF::ast::Type::argument_block: {
		return "argument_block";
	}
	

	case ::DLDL_LPDDEF::ast::Type::deamerreserved_star__argument_stmt__: {
		return "deamerreserved_star__argument_stmt__";
	}
	

	case ::DLDL_LPDDEF::ast::Type::argument_stmt: {
		return "argument_stmt";
	}
	

	case ::DLDL_LPDDEF::ast::Type::COLON: {
		return "COLON";
	}
	

	case ::DLDL_LPDDEF::ast::Type::LEFT_ANGLE_BRACKET: {
		return "LEFT_ANGLE_BRACKET";
	}
	

	case ::DLDL_LPDDEF::ast::Type::RIGHT_ANGLE_BRACKET: {
		return "RIGHT_ANGLE_BRACKET";
	}
	

	case ::DLDL_LPDDEF::ast::Type::VARNAME: {
		return "VARNAME";
	}
	

	case ::DLDL_LPDDEF::ast::Type::VARNAME_EXT: {
		return "VARNAME_EXT";
	}
	

	case ::DLDL_LPDDEF::ast::Type::INDENTED_VALUE: {
		return "INDENTED_VALUE";
	}
	

	case ::DLDL_LPDDEF::ast::Type::ESCAPE_CHARS: {
		return "ESCAPE_CHARS";
	}
	

		}
		
		return "";
	}

}}}

#endif // DLDL_LPDDEF_AST_RELATION_NODEENUMTOTEXT_H