#ifndef DLDL_GRAMMAR_AST_RELATION_NODEENUMTOTEXT_H
#define DLDL_GRAMMAR_AST_RELATION_NODEENUMTOTEXT_H

#include "DLDL_GRAMMAR/Ast/Enum/Type.h"

namespace DLDL_GRAMMAR { namespace ast { namespace relation { 

	static constexpr const char* ConvertEnumToText(::DLDL_GRAMMAR::ast::Type type)
	{
		switch(type)
		{
			
	case ::DLDL_GRAMMAR::ast::Type::program: {
		return "program";
	}
	

	case ::DLDL_GRAMMAR::ast::Type::stmts: {
		return "stmts";
	}
	

	case ::DLDL_GRAMMAR::ast::Type::stmt: {
		return "stmt";
	}
	

	case ::DLDL_GRAMMAR::ast::Type::abstraction_declaration: {
		return "abstraction_declaration";
	}
	

	case ::DLDL_GRAMMAR::ast::Type::abstraction: {
		return "abstraction";
	}
	

	case ::DLDL_GRAMMAR::ast::Type::definition: {
		return "definition";
	}
	

	case ::DLDL_GRAMMAR::ast::Type::production_rules: {
		return "production_rules";
	}
	

	case ::DLDL_GRAMMAR::ast::Type::COMMENT: {
		return "COMMENT";
	}
	

	case ::DLDL_GRAMMAR::ast::Type::START_ABSTRACTION: {
		return "START_ABSTRACTION";
	}
	

	case ::DLDL_GRAMMAR::ast::Type::GROUP_ABSTRACTION: {
		return "GROUP_ABSTRACTION";
	}
	

	case ::DLDL_GRAMMAR::ast::Type::INLINE_ABSTRACTION: {
		return "INLINE_ABSTRACTION";
	}
	

	case ::DLDL_GRAMMAR::ast::Type::INLINE_GROUP_ABSTRACTION: {
		return "INLINE_GROUP_ABSTRACTION";
	}
	

	case ::DLDL_GRAMMAR::ast::Type::UNKNOWN_ABSTRACTION: {
		return "UNKNOWN_ABSTRACTION";
	}
	

	case ::DLDL_GRAMMAR::ast::Type::NONTERMINAL: {
		return "NONTERMINAL";
	}
	

	case ::DLDL_GRAMMAR::ast::Type::PRODUCTION_RULE: {
		return "PRODUCTION_RULE";
	}
	

	case ::DLDL_GRAMMAR::ast::Type::ESCAPE_CHARS: {
		return "ESCAPE_CHARS";
	}
	

		}
		
		return "";
	}

}}}

#endif // DLDL_GRAMMAR_AST_RELATION_NODEENUMTOTEXT_H