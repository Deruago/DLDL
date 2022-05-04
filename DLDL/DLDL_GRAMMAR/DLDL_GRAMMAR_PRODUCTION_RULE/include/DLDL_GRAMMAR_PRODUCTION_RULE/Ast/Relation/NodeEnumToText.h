#ifndef DLDL_GRAMMAR_PRODUCTION_RULE_AST_RELATION_NODEENUMTOTEXT_H
#define DLDL_GRAMMAR_PRODUCTION_RULE_AST_RELATION_NODEENUMTOTEXT_H

#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Enum/Type.h"

namespace DLDL_GRAMMAR_PRODUCTION_RULE { namespace ast { namespace relation { 

	static constexpr const char* ConvertEnumToText(::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type type)
	{
		switch(type)
		{
			
	case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::program: {
		return "program";
	}
	

	case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::stmts: {
		return "stmts";
	}
	

	case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::stmt: {
		return "stmt";
	}
	

	case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::group: {
		return "group";
	}
	

	case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::nested_group: {
		return "nested_group";
	}
	

	case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::optional_group: {
		return "optional_group";
	}
	

	case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::zero_or_more_group: {
		return "zero_or_more_group";
	}
	

	case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::one_or_more_group: {
		return "one_or_more_group";
	}
	

	case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::or_group: {
		return "or_group";
	}
	

	case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::min_max_group: {
		return "min_max_group";
	}
	

	case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::extension_group: {
		return "extension_group";
	}
	

	case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::ENDING_USELESS_SYMBOLS: {
		return "ENDING_USELESS_SYMBOLS";
	}
	

	case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::VERTICAL_SLASH: {
		return "VERTICAL_SLASH";
	}
	

	case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_PARANTHESIS: {
		return "LEFT_PARANTHESIS";
	}
	

	case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_PARANTHESIS: {
		return "RIGHT_PARANTHESIS";
	}
	

	case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_BRACKET: {
		return "LEFT_BRACKET";
	}
	

	case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_BRACKET: {
		return "RIGHT_BRACKET";
	}
	

	case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_SQUARE_BRACKET: {
		return "LEFT_SQUARE_BRACKET";
	}
	

	case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_SQUARE_BRACKET: {
		return "RIGHT_SQUARE_BRACKET";
	}
	

	case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::QUESTION_MARK: {
		return "QUESTION_MARK";
	}
	

	case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::EXCLAMATION_MARK: {
		return "EXCLAMATION_MARK";
	}
	

	case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::ARROW: {
		return "ARROW";
	}
	

	case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::STAR: {
		return "STAR";
	}
	

	case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::PLUS: {
		return "PLUS";
	}
	

	case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::MINUS: {
		return "MINUS";
	}
	

	case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::VALUE: {
		return "VALUE";
	}
	

	case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::NUMBER: {
		return "NUMBER";
	}
	

	case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::SINGLE_LINE_COMMENT: {
		return "SINGLE_LINE_COMMENT";
	}
	

	case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::MULTI_LINE_COMMENT: {
		return "MULTI_LINE_COMMENT";
	}
	

	case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::SYMBOLS: {
		return "SYMBOLS";
	}
	

	case ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::ESCAPE_CHARS: {
		return "ESCAPE_CHARS";
	}
	

		}
		
		return "";
	}

}}}

#endif // DLDL_GRAMMAR_PRODUCTION_RULE_AST_RELATION_NODEENUMTOTEXT_H