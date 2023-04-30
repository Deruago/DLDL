#ifndef DLDL_COMMENT_AST_RELATION_NODEENUMTOTEXT_H
#define DLDL_COMMENT_AST_RELATION_NODEENUMTOTEXT_H

#include "DLDL_COMMENT/Ast/Enum/Type.h"

namespace DLDL_COMMENT { namespace ast { namespace relation { 

	static constexpr const char* ConvertEnumToText(::DLDL_COMMENT::ast::Type type)
	{
		switch(type)
		{
			
	case ::DLDL_COMMENT::ast::Type::program: {
		return "program";
	}
	

	case ::DLDL_COMMENT::ast::Type::deamerreserved_star__stmt__: {
		return "deamerreserved_star__stmt__";
	}
	

	case ::DLDL_COMMENT::ast::Type::stmt: {
		return "stmt";
	}
	

	case ::DLDL_COMMENT::ast::Type::comment_value_declaration: {
		return "comment_value_declaration";
	}
	

	case ::DLDL_COMMENT::ast::Type::deamerreserved_long_3: {
		return "deamerreserved_long_3";
	}
	

	case ::DLDL_COMMENT::ast::Type::deamerreserved_long_6: {
		return "deamerreserved_long_6";
	}
	

	case ::DLDL_COMMENT::ast::Type::comment_abstraction: {
		return "comment_abstraction";
	}
	

	case ::DLDL_COMMENT::ast::Type::start_abstraction: {
		return "start_abstraction";
	}
	

	case ::DLDL_COMMENT::ast::Type::end_abstraction: {
		return "end_abstraction";
	}
	

	case ::DLDL_COMMENT::ast::Type::start_sequence: {
		return "start_sequence";
	}
	

	case ::DLDL_COMMENT::ast::Type::end_sequence: {
		return "end_sequence";
	}
	

	case ::DLDL_COMMENT::ast::Type::sequence: {
		return "sequence";
	}
	

	case ::DLDL_COMMENT::ast::Type::syntactic_reference: {
		return "syntactic_reference";
	}
	

	case ::DLDL_COMMENT::ast::Type::SINGLE_COMMENT: {
		return "SINGLE_COMMENT";
	}
	

	case ::DLDL_COMMENT::ast::Type::MULTI_COMMENT: {
		return "MULTI_COMMENT";
	}
	

	case ::DLDL_COMMENT::ast::Type::COMMENT_VALUE: {
		return "COMMENT_VALUE";
	}
	

	case ::DLDL_COMMENT::ast::Type::LEFT_SQUARE_BRACKET: {
		return "LEFT_SQUARE_BRACKET";
	}
	

	case ::DLDL_COMMENT::ast::Type::RIGHT_SQUARE_BRACKET: {
		return "RIGHT_SQUARE_BRACKET";
	}
	

	case ::DLDL_COMMENT::ast::Type::START: {
		return "START";
	}
	

	case ::DLDL_COMMENT::ast::Type::END: {
		return "END";
	}
	

	case ::DLDL_COMMENT::ast::Type::TEXT: {
		return "TEXT";
	}
	

	case ::DLDL_COMMENT::ast::Type::VARNAME: {
		return "VARNAME";
	}
	

	case ::DLDL_COMMENT::ast::Type::ESCAPE_CHARS: {
		return "ESCAPE_CHARS";
	}
	

		}
		
		return "";
	}

}}}

#endif // DLDL_COMMENT_AST_RELATION_NODEENUMTOTEXT_H