#ifndef DLDL_LEXER_AST_RELATION_NODETEXTTOENUM_H
#define DLDL_LEXER_AST_RELATION_NODETEXTTOENUM_H

#include "DLDL_LEXER/Ast/Enum/Type.h"
#include <string>
#include <map>

namespace DLDL_LEXER { namespace ast { namespace relation { 

	static constexpr ::DLDL_LEXER::ast::Type ConvertTextToEnum(const std::string& text)
	{
		static const std::map<std::string, ::DLDL_LEXER::ast::Type> mapTextWithType = {
			{"", ::DLDL_LEXER::ast::Type::deamerreserved_unknown },
			
		{ "program", ::DLDL_LEXER::ast::Type::program },
	

		{ "stmts", ::DLDL_LEXER::ast::Type::stmts },
	

		{ "stmt", ::DLDL_LEXER::ast::Type::stmt },
	

		{ "tokendeclaration", ::DLDL_LEXER::ast::Type::tokendeclaration },
	

		{ "abstraction", ::DLDL_LEXER::ast::Type::abstraction },
	

		{ "DELETE_ABSTRACTION", ::DLDL_LEXER::ast::Type::DELETE_ABSTRACTION },
	

		{ "IGNORE_ABSTRACTION", ::DLDL_LEXER::ast::Type::IGNORE_ABSTRACTION },
	

		{ "NOVALUE_ABSTRACTION", ::DLDL_LEXER::ast::Type::NOVALUE_ABSTRACTION },
	

		{ "CRASH_ABSTRACTION", ::DLDL_LEXER::ast::Type::CRASH_ABSTRACTION },
	

		{ "STANDARD_ABSTRACTION", ::DLDL_LEXER::ast::Type::STANDARD_ABSTRACTION },
	

		{ "UNKNOWN_ABSTRACTION", ::DLDL_LEXER::ast::Type::UNKNOWN_ABSTRACTION },
	

		{ "TERMINAL", ::DLDL_LEXER::ast::Type::TERMINAL },
	

		{ "REGEX", ::DLDL_LEXER::ast::Type::REGEX },
	

		{ "ESCAPE_CHARS", ::DLDL_LEXER::ast::Type::ESCAPE_CHARS },
	

		{ "COMMENT", ::DLDL_LEXER::ast::Type::COMMENT },
	

		};

		return mapTextWithType[text];
	}

}}}

#endif // DLDL_LEXER_AST_RELATION_NODETEXTTOENUM_H