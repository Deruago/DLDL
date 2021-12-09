#ifndef DLDL_AST_RELATION_NODEENUMTOTEXT_H
#define DLDL_AST_RELATION_NODEENUMTOTEXT_H

#include "DLDL/Ast/Enum/Type.h"

namespace DLDL { namespace ast { namespace relation { 

	static constexpr const char* ConvertEnumToText(::DLDL::ast::Type type)
	{
		switch(type)
		{
			
	case ::DLDL::ast::Type::program: {
		return "program";
	}
	

	case ::DLDL::ast::Type::stmts: {
		return "stmts";
	}
	

	case ::DLDL::ast::Type::stmt: {
		return "stmt";
	}
	

	case ::DLDL::ast::Type::ANY: {
		return "ANY";
	}
	

		}
		
		return "";
	}

}}}

#endif // DLDL_AST_RELATION_NODEENUMTOTEXT_H