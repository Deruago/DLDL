#ifndef DLDL_LPDDEF_EF_AST_RELATION_NODEENUMTOTEXT_H
#define DLDL_LPDDEF_EF_AST_RELATION_NODEENUMTOTEXT_H

#include "DLDL_LPDDEF_EF/Ast/Enum/Type.h"

namespace DLDL_LPDDEF_EF { namespace ast { namespace relation { 

	static constexpr const char* ConvertEnumToText(::DLDL_LPDDEF_EF::ast::Type type)
	{
		switch(type)
		{
			
	case ::DLDL_LPDDEF_EF::ast::Type::program: {
		return "program";
	}
	

	case ::DLDL_LPDDEF_EF::ast::Type::deamerreserved_star__stmt__: {
		return "deamerreserved_star__stmt__";
	}
	

	case ::DLDL_LPDDEF_EF::ast::Type::stmt: {
		return "stmt";
	}
	

	case ::DLDL_LPDDEF_EF::ast::Type::comment_line: {
		return "comment_line";
	}
	

	case ::DLDL_LPDDEF_EF::ast::Type::standard_variant: {
		return "standard_variant";
	}
	

	case ::DLDL_LPDDEF_EF::ast::Type::standard_variant_specific_number: {
		return "standard_variant_specific_number";
	}
	

	case ::DLDL_LPDDEF_EF::ast::Type::value: {
		return "value";
	}
	

	case ::DLDL_LPDDEF_EF::ast::Type::enum_name: {
		return "enum_name";
	}
	

	case ::DLDL_LPDDEF_EF::ast::Type::COMMENT: {
		return "COMMENT";
	}
	

	case ::DLDL_LPDDEF_EF::ast::Type::VARNAME: {
		return "VARNAME";
	}
	

	case ::DLDL_LPDDEF_EF::ast::Type::NUMBER: {
		return "NUMBER";
	}
	

	case ::DLDL_LPDDEF_EF::ast::Type::COLON: {
		return "COLON";
	}
	

	case ::DLDL_LPDDEF_EF::ast::Type::SEMICOLON: {
		return "SEMICOLON";
	}
	

	case ::DLDL_LPDDEF_EF::ast::Type::ESCAPE_CHARS: {
		return "ESCAPE_CHARS";
	}
	

		}
		
		return "";
	}

}}}

#endif // DLDL_LPDDEF_EF_AST_RELATION_NODEENUMTOTEXT_H