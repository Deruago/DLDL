#ifndef DLDL_GRAMMAR_PRODUCTION_RULE_AST_RELATION_NODETEXTTOENUM_H
#define DLDL_GRAMMAR_PRODUCTION_RULE_AST_RELATION_NODETEXTTOENUM_H

#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Enum/Type.h"
#include <string>
#include <map>

namespace DLDL_GRAMMAR_PRODUCTION_RULE { namespace ast { namespace relation { 

	static constexpr ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type ConvertTextToEnum(const std::string& text)
	{
		static const std::map<std::string, ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type> mapTextWithType = {
			{"", ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::deamerreserved_unknown },
			
		{ "program", ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::program },
	

		{ "stmts", ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::stmts },
	

		{ "stmt", ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::stmt },
	

		{ "group", ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::group },
	

		{ "nested_group", ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::nested_group },
	

		{ "optional_group", ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::optional_group },
	

		{ "zero_or_more_group", ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::zero_or_more_group },
	

		{ "one_or_more_group", ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::one_or_more_group },
	

		{ "or_group", ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::or_group },
	

		{ "min_max_group", ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::min_max_group },
	

		{ "extension_group", ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::extension_group },
	

		{ "ENDING_USELESS_SYMBOLS", ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::ENDING_USELESS_SYMBOLS },
	

		{ "VERTICAL_SLASH", ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::VERTICAL_SLASH },
	

		{ "LEFT_PARANTHESIS", ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_PARANTHESIS },
	

		{ "RIGHT_PARANTHESIS", ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_PARANTHESIS },
	

		{ "LEFT_BRACKET", ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_BRACKET },
	

		{ "RIGHT_BRACKET", ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_BRACKET },
	

		{ "LEFT_SQUARE_BRACKET", ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_SQUARE_BRACKET },
	

		{ "RIGHT_SQUARE_BRACKET", ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_SQUARE_BRACKET },
	

		{ "QUESTION_MARK", ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::QUESTION_MARK },
	

		{ "EXCLAMATION_MARK", ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::EXCLAMATION_MARK },
	

		{ "ARROW", ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::ARROW },
	

		{ "STAR", ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::STAR },
	

		{ "PLUS", ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::PLUS },
	

		{ "MINUS", ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::MINUS },
	

		{ "VALUE", ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::VALUE },
	

		{ "NUMBER", ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::NUMBER },
	

		{ "SINGLE_LINE_COMMENT", ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::SINGLE_LINE_COMMENT },
	

		{ "MULTI_LINE_COMMENT", ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::MULTI_LINE_COMMENT },
	

		{ "SYMBOLS", ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::SYMBOLS },
	

		{ "ESCAPE_CHARS", ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::ESCAPE_CHARS },
	

		};

		return mapTextWithType[text];
	}

}}}

#endif // DLDL_GRAMMAR_PRODUCTION_RULE_AST_RELATION_NODETEXTTOENUM_H