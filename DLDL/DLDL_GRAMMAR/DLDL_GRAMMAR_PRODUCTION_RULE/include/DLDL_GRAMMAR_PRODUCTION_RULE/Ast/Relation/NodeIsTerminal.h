#ifndef DLDL_GRAMMAR_PRODUCTION_RULE_AST_RELATION_NODEISTERMINAL_H
#define DLDL_GRAMMAR_PRODUCTION_RULE_AST_RELATION_NODEISTERMINAL_H

#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Enum/Type.h"

namespace DLDL_GRAMMAR_PRODUCTION_RULE { namespace ast { namespace relation { 

	constexpr static bool NodeIsTerminal(::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type t)
	{
		
		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::ENDING_USELESS_SYMBOLS)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::VERTICAL_SLASH)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_PARANTHESIS)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_PARANTHESIS)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_BRACKET)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_BRACKET)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_SQUARE_BRACKET)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_SQUARE_BRACKET)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::QUESTION_MARK)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::EXCLAMATION_MARK)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::TILDE)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::ARROW)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::STAR)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::PLUS)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::MINUS)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::VALUE)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::NUMBER)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::SINGLE_LINE_COMMENT)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::MULTI_LINE_COMMENT)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::SYMBOLS)
		{
			return true;
		}

		if (t == ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::ESCAPE_CHARS)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DLDL_GRAMMAR_PRODUCTION_RULE_AST_RELATION_NODEISTERMINAL_H