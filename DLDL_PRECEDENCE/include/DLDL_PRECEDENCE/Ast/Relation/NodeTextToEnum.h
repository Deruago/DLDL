#ifndef DLDL_PRECEDENCE_AST_RELATION_NODETEXTTOENUM_H
#define DLDL_PRECEDENCE_AST_RELATION_NODETEXTTOENUM_H

#include "DLDL_PRECEDENCE/Ast/Enum/Type.h"

namespace DLDL_PRECEDENCE { namespace ast { namespace relation { 

	static constexpr ::DLDL_PRECEDENCE::ast::Type ConvertEnumToText(const std::string& text)
	{
		static const std::map<std::string, ::DLDL_PRECEDENCE::ast::Type> mapTextWithType = {
			{"", ::DLDL_PRECEDENCE::ast::Type::deamerreserved_unknown },
			
		{ "program", ::DLDL_PRECEDENCE::ast::Type::program },
	

		{ "stmts", ::DLDL_PRECEDENCE::ast::Type::stmts },
	

		{ "stmt", ::DLDL_PRECEDENCE::ast::Type::stmt },
	

		{ "localized_precedence", ::DLDL_PRECEDENCE::ast::Type::localized_precedence },
	

		{ "specific_precedence", ::DLDL_PRECEDENCE::ast::Type::specific_precedence },
	

		{ "terminal_one_or_more", ::DLDL_PRECEDENCE::ast::Type::terminal_one_or_more },
	

		{ "PRECEDENCE", ::DLDL_PRECEDENCE::ast::Type::PRECEDENCE },
	

		{ "NUMBER", ::DLDL_PRECEDENCE::ast::Type::NUMBER },
	

		{ "TERMINAL", ::DLDL_PRECEDENCE::ast::Type::TERMINAL },
	

		{ "SYMBOLS", ::DLDL_PRECEDENCE::ast::Type::SYMBOLS },
	

		{ "ESCAPE_CHARS", ::DLDL_PRECEDENCE::ast::Type::ESCAPE_CHARS },
	

		};

		return mapTextWithType[text];
	}

}}}

#endif // DLDL_PRECEDENCE_AST_RELATION_NODETEXTTOENUM_H