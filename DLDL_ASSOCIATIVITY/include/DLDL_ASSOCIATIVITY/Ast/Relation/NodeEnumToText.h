#ifndef DLDL_ASSOCIATIVITY_AST_RELATION_NODEENUMTOTEXT_H
#define DLDL_ASSOCIATIVITY_AST_RELATION_NODEENUMTOTEXT_H

#include "DLDL_ASSOCIATIVITY/Ast/Enum/Type.h"

namespace DLDL_ASSOCIATIVITY { namespace ast { namespace relation { 

	static constexpr const char* ConvertEnumToText(::DLDL_ASSOCIATIVITY::ast::Type type)
	{
		switch(type)
		{
			
	case ::DLDL_ASSOCIATIVITY::ast::Type::program: {
		return "program";
	}
	

	case ::DLDL_ASSOCIATIVITY::ast::Type::stmts: {
		return "stmts";
	}
	

	case ::DLDL_ASSOCIATIVITY::ast::Type::stmt: {
		return "stmt";
	}
	

	case ::DLDL_ASSOCIATIVITY::ast::Type::ASSOCIATIVITY: {
		return "ASSOCIATIVITY";
	}
	

		}
		
		return "";
	}

}}}

#endif // DLDL_ASSOCIATIVITY_AST_RELATION_NODEENUMTOTEXT_H