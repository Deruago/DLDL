#ifndef DLDL_ARGUMENT_AST_RELATION_NODEENUMTOTEXT_H
#define DLDL_ARGUMENT_AST_RELATION_NODEENUMTOTEXT_H

#include "DLDL_ARGUMENT/Ast/Enum/Type.h"

namespace DLDL_ARGUMENT { namespace ast { namespace relation { 

	static constexpr const char* ConvertEnumToText(::DLDL_ARGUMENT::ast::Type type)
	{
		switch(type)
		{
			
	case ::DLDL_ARGUMENT::ast::Type::program: {
		return "program";
	}
	

	case ::DLDL_ARGUMENT::ast::Type::SINGLE_COMMENT: {
		return "SINGLE_COMMENT";
	}
	

	case ::DLDL_ARGUMENT::ast::Type::MULTI_COMMENT: {
		return "MULTI_COMMENT";
	}
	

	case ::DLDL_ARGUMENT::ast::Type::TEXT: {
		return "TEXT";
	}
	

	case ::DLDL_ARGUMENT::ast::Type::VARNAME: {
		return "VARNAME";
	}
	

	case ::DLDL_ARGUMENT::ast::Type::ESCAPE_CHARS: {
		return "ESCAPE_CHARS";
	}
	

		}
		
		return "";
	}

}}}

#endif // DLDL_ARGUMENT_AST_RELATION_NODEENUMTOTEXT_H