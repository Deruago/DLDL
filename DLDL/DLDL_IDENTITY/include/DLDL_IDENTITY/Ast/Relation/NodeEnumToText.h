#ifndef DLDL_IDENTITY_AST_RELATION_NODEENUMTOTEXT_H
#define DLDL_IDENTITY_AST_RELATION_NODEENUMTOTEXT_H

#include "DLDL_IDENTITY/Ast/Enum/Type.h"

namespace DLDL_IDENTITY { namespace ast { namespace relation { 

	static constexpr const char* ConvertEnumToText(::DLDL_IDENTITY::ast::Type type)
	{
		switch(type)
		{
			
	case ::DLDL_IDENTITY::ast::Type::program: {
		return "program";
	}
	

	case ::DLDL_IDENTITY::ast::Type::stmts: {
		return "stmts";
	}
	

	case ::DLDL_IDENTITY::ast::Type::stmt: {
		return "stmt";
	}
	

	case ::DLDL_IDENTITY::ast::Type::name_declaration: {
		return "name_declaration";
	}
	

	case ::DLDL_IDENTITY::ast::Type::NAME: {
		return "NAME";
	}
	

	case ::DLDL_IDENTITY::ast::Type::VALUE: {
		return "VALUE";
	}
	

	case ::DLDL_IDENTITY::ast::Type::SYMBOLS: {
		return "SYMBOLS";
	}
	

	case ::DLDL_IDENTITY::ast::Type::ESCAPE_CHARS: {
		return "ESCAPE_CHARS";
	}
	

		}
		
		return "";
	}

}}}

#endif // DLDL_IDENTITY_AST_RELATION_NODEENUMTOTEXT_H