#ifndef DLDL_IMPORT_AST_RELATION_NODEENUMTOTEXT_H
#define DLDL_IMPORT_AST_RELATION_NODEENUMTOTEXT_H

#include "DLDL_IMPORT/Ast/Enum/Type.h"

namespace DLDL_IMPORT { namespace ast { namespace relation { 

	static constexpr const char* ConvertEnumToText(::DLDL_IMPORT::ast::Type type)
	{
		switch(type)
		{
			
	case ::DLDL_IMPORT::ast::Type::program: {
		return "program";
	}
	

	case ::DLDL_IMPORT::ast::Type::deamerreserved_star__stmt__: {
		return "deamerreserved_star__stmt__";
	}
	

	case ::DLDL_IMPORT::ast::Type::stmt: {
		return "stmt";
	}
	

	case ::DLDL_IMPORT::ast::Type::import_declaration: {
		return "import_declaration";
	}
	

	case ::DLDL_IMPORT::ast::Type::deamerreserved_arrow__import_context__: {
		return "deamerreserved_arrow__import_context__";
	}
	

	case ::DLDL_IMPORT::ast::Type::deamerreserved_long_40: {
		return "deamerreserved_long_40";
	}
	

	case ::DLDL_IMPORT::ast::Type::deamerreserved_long_43: {
		return "deamerreserved_long_43";
	}
	

	case ::DLDL_IMPORT::ast::Type::specialization: {
		return "specialization";
	}
	

	case ::DLDL_IMPORT::ast::Type::import_abstraction: {
		return "import_abstraction";
	}
	

	case ::DLDL_IMPORT::ast::Type::value: {
		return "value";
	}
	

	case ::DLDL_IMPORT::ast::Type::deamerreserved_optional__VARNAME__: {
		return "deamerreserved_optional__VARNAME__";
	}
	

	case ::DLDL_IMPORT::ast::Type::abstraction: {
		return "abstraction";
	}
	

	case ::DLDL_IMPORT::ast::Type::import_context: {
		return "import_context";
	}
	

	case ::DLDL_IMPORT::ast::Type::import_rule_name: {
		return "import_rule_name";
	}
	

	case ::DLDL_IMPORT::ast::Type::SINGLE_COMMENT: {
		return "SINGLE_COMMENT";
	}
	

	case ::DLDL_IMPORT::ast::Type::MULTI_COMMENT: {
		return "MULTI_COMMENT";
	}
	

	case ::DLDL_IMPORT::ast::Type::LEFT_PARANTHESIS: {
		return "LEFT_PARANTHESIS";
	}
	

	case ::DLDL_IMPORT::ast::Type::RIGHT_PARANTHESIS: {
		return "RIGHT_PARANTHESIS";
	}
	

	case ::DLDL_IMPORT::ast::Type::LEFT_SQUARE_BRACKET: {
		return "LEFT_SQUARE_BRACKET";
	}
	

	case ::DLDL_IMPORT::ast::Type::RIGHT_SQUARE_BRACKET: {
		return "RIGHT_SQUARE_BRACKET";
	}
	

	case ::DLDL_IMPORT::ast::Type::COLON: {
		return "COLON";
	}
	

	case ::DLDL_IMPORT::ast::Type::DOT: {
		return "DOT";
	}
	

	case ::DLDL_IMPORT::ast::Type::IMPORT_FILE: {
		return "IMPORT_FILE";
	}
	

	case ::DLDL_IMPORT::ast::Type::IMPORT_MODULE: {
		return "IMPORT_MODULE";
	}
	

	case ::DLDL_IMPORT::ast::Type::IMPORT: {
		return "IMPORT";
	}
	

	case ::DLDL_IMPORT::ast::Type::TEXT: {
		return "TEXT";
	}
	

	case ::DLDL_IMPORT::ast::Type::VARNAME: {
		return "VARNAME";
	}
	

	case ::DLDL_IMPORT::ast::Type::ESCAPE_CHARS: {
		return "ESCAPE_CHARS";
	}
	

		}
		
		return "";
	}

}}}

#endif // DLDL_IMPORT_AST_RELATION_NODEENUMTOTEXT_H