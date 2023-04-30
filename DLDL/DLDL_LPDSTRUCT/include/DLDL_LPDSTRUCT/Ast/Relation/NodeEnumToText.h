#ifndef DLDL_LPDSTRUCT_AST_RELATION_NODEENUMTOTEXT_H
#define DLDL_LPDSTRUCT_AST_RELATION_NODEENUMTOTEXT_H

#include "DLDL_LPDSTRUCT/Ast/Enum/Type.h"

namespace DLDL_LPDSTRUCT { namespace ast { namespace relation { 

	static constexpr const char* ConvertEnumToText(::DLDL_LPDSTRUCT::ast::Type type)
	{
		switch(type)
		{
			
	case ::DLDL_LPDSTRUCT::ast::Type::program: {
		return "program";
	}
	

	case ::DLDL_LPDSTRUCT::ast::Type::deamerreserved_star__stmt__: {
		return "deamerreserved_star__stmt__";
	}
	

	case ::DLDL_LPDSTRUCT::ast::Type::stmt: {
		return "stmt";
	}
	

	case ::DLDL_LPDSTRUCT::ast::Type::argument: {
		return "argument";
	}
	

	case ::DLDL_LPDSTRUCT::ast::Type::argument_name: {
		return "argument_name";
	}
	

	case ::DLDL_LPDSTRUCT::ast::Type::argument_block: {
		return "argument_block";
	}
	

	case ::DLDL_LPDSTRUCT::ast::Type::deamerreserved_long_60: {
		return "deamerreserved_long_60";
	}
	

	case ::DLDL_LPDSTRUCT::ast::Type::deamerreserved_long_63: {
		return "deamerreserved_long_63";
	}
	

	case ::DLDL_LPDSTRUCT::ast::Type::deamerreserved_long_66: {
		return "deamerreserved_long_66";
	}
	

	case ::DLDL_LPDSTRUCT::ast::Type::COLON: {
		return "COLON";
	}
	

	case ::DLDL_LPDSTRUCT::ast::Type::LEFT_ANGLE_BRACKET: {
		return "LEFT_ANGLE_BRACKET";
	}
	

	case ::DLDL_LPDSTRUCT::ast::Type::RIGHT_ANGLE_BRACKET: {
		return "RIGHT_ANGLE_BRACKET";
	}
	

	case ::DLDL_LPDSTRUCT::ast::Type::VARNAME: {
		return "VARNAME";
	}
	

	case ::DLDL_LPDSTRUCT::ast::Type::VARNAME_EXT: {
		return "VARNAME_EXT";
	}
	

	case ::DLDL_LPDSTRUCT::ast::Type::INDENTED_VALUE: {
		return "INDENTED_VALUE";
	}
	

	case ::DLDL_LPDSTRUCT::ast::Type::ESCAPE_CHARS: {
		return "ESCAPE_CHARS";
	}
	

		}
		
		return "";
	}

}}}

#endif // DLDL_LPDSTRUCT_AST_RELATION_NODEENUMTOTEXT_H