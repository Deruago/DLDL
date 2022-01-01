#ifndef DLDL_LDOSTRUCT_AST_RELATION_NODEENUMTOTEXT_H
#define DLDL_LDOSTRUCT_AST_RELATION_NODEENUMTOTEXT_H

#include "DLDL_LDOSTRUCT/Ast/Enum/Type.h"

namespace DLDL_LDOSTRUCT { namespace ast { namespace relation { 

	static constexpr const char* ConvertEnumToText(::DLDL_LDOSTRUCT::ast::Type type)
	{
		switch(type)
		{
			
	case ::DLDL_LDOSTRUCT::ast::Type::program: {
		return "program";
	}
	

	case ::DLDL_LDOSTRUCT::ast::Type::deamerreserved_star__stmt__: {
		return "deamerreserved_star__stmt__";
	}
	

	case ::DLDL_LDOSTRUCT::ast::Type::stmt: {
		return "stmt";
	}
	

	case ::DLDL_LDOSTRUCT::ast::Type::argument: {
		return "argument";
	}
	

	case ::DLDL_LDOSTRUCT::ast::Type::argument_name: {
		return "argument_name";
	}
	

	case ::DLDL_LDOSTRUCT::ast::Type::argument_block: {
		return "argument_block";
	}
	

	case ::DLDL_LDOSTRUCT::ast::Type::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______: {
		return "deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______";
	}
	

	case ::DLDL_LDOSTRUCT::ast::Type::COLON: {
		return "COLON";
	}
	

	case ::DLDL_LDOSTRUCT::ast::Type::LEFT_ANGLE_BRACKET: {
		return "LEFT_ANGLE_BRACKET";
	}
	

	case ::DLDL_LDOSTRUCT::ast::Type::RIGHT_ANGLE_BRACKET: {
		return "RIGHT_ANGLE_BRACKET";
	}
	

	case ::DLDL_LDOSTRUCT::ast::Type::VARNAME: {
		return "VARNAME";
	}
	

	case ::DLDL_LDOSTRUCT::ast::Type::VARNAME_EXT: {
		return "VARNAME_EXT";
	}
	

	case ::DLDL_LDOSTRUCT::ast::Type::INDENTED_VALUE: {
		return "INDENTED_VALUE";
	}
	

	case ::DLDL_LDOSTRUCT::ast::Type::ESCAPE_CHARS: {
		return "ESCAPE_CHARS";
	}
	

		}
		
		return "";
	}

}}}

#endif // DLDL_LDOSTRUCT_AST_RELATION_NODEENUMTOTEXT_H