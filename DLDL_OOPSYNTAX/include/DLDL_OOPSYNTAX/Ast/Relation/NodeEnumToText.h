#ifndef DLDL_OOPSYNTAX_AST_RELATION_NODEENUMTOTEXT_H
#define DLDL_OOPSYNTAX_AST_RELATION_NODEENUMTOTEXT_H

#include "DLDL_OOPSYNTAX/Ast/Enum/Type.h"

namespace DLDL_OOPSYNTAX { namespace ast { namespace relation { 

	static constexpr const char* ConvertEnumToText(::DLDL_OOPSYNTAX::ast::Type type)
	{
		switch(type)
		{
			
	case ::DLDL_OOPSYNTAX::ast::Type::program: {
		return "program";
	}
	

	case ::DLDL_OOPSYNTAX::ast::Type::deamerreserved_star__stmt__: {
		return "deamerreserved_star__stmt__";
	}
	

	case ::DLDL_OOPSYNTAX::ast::Type::stmt: {
		return "stmt";
	}
	

	case ::DLDL_OOPSYNTAX::ast::Type::nonterminal_conversion: {
		return "nonterminal_conversion";
	}
	

	case ::DLDL_OOPSYNTAX::ast::Type::deamerreserved_star__production_rule_conversion__: {
		return "deamerreserved_star__production_rule_conversion__";
	}
	

	case ::DLDL_OOPSYNTAX::ast::Type::production_rule_conversion: {
		return "production_rule_conversion";
	}
	

	case ::DLDL_OOPSYNTAX::ast::Type::numbered_pr_convert: {
		return "numbered_pr_convert";
	}
	

	case ::DLDL_OOPSYNTAX::ast::Type::deamerreserved_star__property_assignment__: {
		return "deamerreserved_star__property_assignment__";
	}
	

	case ::DLDL_OOPSYNTAX::ast::Type::property_assignment: {
		return "property_assignment";
	}
	

	case ::DLDL_OOPSYNTAX::ast::Type::direct_property_assignment: {
		return "direct_property_assignment";
	}
	

	case ::DLDL_OOPSYNTAX::ast::Type::direct_any_property_assignment: {
		return "direct_any_property_assignment";
	}
	

	case ::DLDL_OOPSYNTAX::ast::Type::embedded_assignment: {
		return "embedded_assignment";
	}
	

	case ::DLDL_OOPSYNTAX::ast::Type::nonterminal_name: {
		return "nonterminal_name";
	}
	

	case ::DLDL_OOPSYNTAX::ast::Type::oop_type: {
		return "oop_type";
	}
	

	case ::DLDL_OOPSYNTAX::ast::Type::property: {
		return "property";
	}
	

	case ::DLDL_OOPSYNTAX::ast::Type::terminal_name: {
		return "terminal_name";
	}
	

	case ::DLDL_OOPSYNTAX::ast::Type::ARROW: {
		return "ARROW";
	}
	

	case ::DLDL_OOPSYNTAX::ast::Type::LEFT_BRACKET: {
		return "LEFT_BRACKET";
	}
	

	case ::DLDL_OOPSYNTAX::ast::Type::RIGHT_BRACKET: {
		return "RIGHT_BRACKET";
	}
	

	case ::DLDL_OOPSYNTAX::ast::Type::DOT: {
		return "DOT";
	}
	

	case ::DLDL_OOPSYNTAX::ast::Type::EQ: {
		return "EQ";
	}
	

	case ::DLDL_OOPSYNTAX::ast::Type::STAR: {
		return "STAR";
	}
	

	case ::DLDL_OOPSYNTAX::ast::Type::VARNAME: {
		return "VARNAME";
	}
	

	case ::DLDL_OOPSYNTAX::ast::Type::NUMBER: {
		return "NUMBER";
	}
	

	case ::DLDL_OOPSYNTAX::ast::Type::COMMENT: {
		return "COMMENT";
	}
	

	case ::DLDL_OOPSYNTAX::ast::Type::ESCAPE_CHAR: {
		return "ESCAPE_CHAR";
	}
	

		}
		
		return "";
	}

}}}

#endif // DLDL_OOPSYNTAX_AST_RELATION_NODEENUMTOTEXT_H