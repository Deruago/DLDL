#ifndef DLDL_GRAMMAR_AST_RELATION_NODETEXTTOENUM_H
#define DLDL_GRAMMAR_AST_RELATION_NODETEXTTOENUM_H

#include "DLDL_GRAMMAR/Ast/Enum/Type.h"

namespace DLDL_GRAMMAR { namespace ast { namespace relation { 

	static constexpr ::DLDL_GRAMMAR::ast::Type ConvertEnumToText(const std::string& text)
	{
		static const std::map<std::string, ::DLDL_GRAMMAR::ast::Type> mapTextWithType = {
			{"", ::DLDL_GRAMMAR::ast::Type::deamerreserved_unknown },
			
		{ "program", ::DLDL_GRAMMAR::ast::Type::program },
	

		{ "stmts", ::DLDL_GRAMMAR::ast::Type::stmts },
	

		{ "stmt", ::DLDL_GRAMMAR::ast::Type::stmt },
	

		{ "abstraction_declaration", ::DLDL_GRAMMAR::ast::Type::abstraction_declaration },
	

		{ "abstraction", ::DLDL_GRAMMAR::ast::Type::abstraction },
	

		{ "definition", ::DLDL_GRAMMAR::ast::Type::definition },
	

		{ "production_rules", ::DLDL_GRAMMAR::ast::Type::production_rules },
	

		{ "COMMENT", ::DLDL_GRAMMAR::ast::Type::COMMENT },
	

		{ "START_ABSTRACTION", ::DLDL_GRAMMAR::ast::Type::START_ABSTRACTION },
	

		{ "GROUP_ABSTRACTION", ::DLDL_GRAMMAR::ast::Type::GROUP_ABSTRACTION },
	

		{ "INLINE_ABSTRACTION", ::DLDL_GRAMMAR::ast::Type::INLINE_ABSTRACTION },
	

		{ "INLINE_GROUP_ABSTRACTION", ::DLDL_GRAMMAR::ast::Type::INLINE_GROUP_ABSTRACTION },
	

		{ "UNKNOWN_ABSTRACTION", ::DLDL_GRAMMAR::ast::Type::UNKNOWN_ABSTRACTION },
	

		{ "NONTERMINAL", ::DLDL_GRAMMAR::ast::Type::NONTERMINAL },
	

		{ "PRODUCTION_RULE", ::DLDL_GRAMMAR::ast::Type::PRODUCTION_RULE },
	

		{ "ESCAPE_CHARS", ::DLDL_GRAMMAR::ast::Type::ESCAPE_CHARS },
	

		};

		return mapTextWithType[text];
	}

}}}

#endif // DLDL_GRAMMAR_AST_RELATION_NODETEXTTOENUM_H