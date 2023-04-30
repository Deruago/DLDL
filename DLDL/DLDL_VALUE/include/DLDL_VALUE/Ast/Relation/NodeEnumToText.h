#ifndef DLDL_VALUE_AST_RELATION_NODEENUMTOTEXT_H
#define DLDL_VALUE_AST_RELATION_NODEENUMTOTEXT_H

#include "DLDL_VALUE/Ast/Enum/Type.h"

namespace DLDL_VALUE { namespace ast { namespace relation { 

	static constexpr const char* ConvertEnumToText(::DLDL_VALUE::ast::Type type)
	{
		switch(type)
		{
			
	case ::DLDL_VALUE::ast::Type::program: {
		return "program";
	}
	

	case ::DLDL_VALUE::ast::Type::deamerreserved_star__stmt__: {
		return "deamerreserved_star__stmt__";
	}
	

	case ::DLDL_VALUE::ast::Type::stmt: {
		return "stmt";
	}
	

	case ::DLDL_VALUE::ast::Type::value_charactersitic_declaration: {
		return "value_charactersitic_declaration";
	}
	

	case ::DLDL_VALUE::ast::Type::deamerreserved_long_82: {
		return "deamerreserved_long_82";
	}
	

	case ::DLDL_VALUE::ast::Type::deamerreserved_long_85: {
		return "deamerreserved_long_85";
	}
	

	case ::DLDL_VALUE::ast::Type::deamerreserved_long_88: {
		return "deamerreserved_long_88";
	}
	

	case ::DLDL_VALUE::ast::Type::value_declaration: {
		return "value_declaration";
	}
	

	case ::DLDL_VALUE::ast::Type::deamerreserved_long_91: {
		return "deamerreserved_long_91";
	}
	

	case ::DLDL_VALUE::ast::Type::value_characteristic_abstraction: {
		return "value_characteristic_abstraction";
	}
	

	case ::DLDL_VALUE::ast::Type::value_declaration_abstraction: {
		return "value_declaration_abstraction";
	}
	

	case ::DLDL_VALUE::ast::Type::value_abstraction: {
		return "value_abstraction";
	}
	

	case ::DLDL_VALUE::ast::Type::deamerreserved_star__value_abstraction__: {
		return "deamerreserved_star__value_abstraction__";
	}
	

	case ::DLDL_VALUE::ast::Type::deamerreserved_long_96: {
		return "deamerreserved_long_96";
	}
	

	case ::DLDL_VALUE::ast::Type::value: {
		return "value";
	}
	

	case ::DLDL_VALUE::ast::Type::syntactic_context: {
		return "syntactic_context";
	}
	

	case ::DLDL_VALUE::ast::Type::abstraction_name: {
		return "abstraction_name";
	}
	

	case ::DLDL_VALUE::ast::Type::value_rule_name: {
		return "value_rule_name";
	}
	

	case ::DLDL_VALUE::ast::Type::SINGLE_COMMENT: {
		return "SINGLE_COMMENT";
	}
	

	case ::DLDL_VALUE::ast::Type::MULTI_COMMENT: {
		return "MULTI_COMMENT";
	}
	

	case ::DLDL_VALUE::ast::Type::LEFT_PARANTHESIS: {
		return "LEFT_PARANTHESIS";
	}
	

	case ::DLDL_VALUE::ast::Type::RIGHT_PARANTHESIS: {
		return "RIGHT_PARANTHESIS";
	}
	

	case ::DLDL_VALUE::ast::Type::LEFT_BRACKET: {
		return "LEFT_BRACKET";
	}
	

	case ::DLDL_VALUE::ast::Type::RIGHT_BRACKET: {
		return "RIGHT_BRACKET";
	}
	

	case ::DLDL_VALUE::ast::Type::LEFT_SQUARE_BRACKET: {
		return "LEFT_SQUARE_BRACKET";
	}
	

	case ::DLDL_VALUE::ast::Type::RIGHT_SQUARE_BRACKET: {
		return "RIGHT_SQUARE_BRACKET";
	}
	

	case ::DLDL_VALUE::ast::Type::DOT: {
		return "DOT";
	}
	

	case ::DLDL_VALUE::ast::Type::VALUE_CHARACTERISTIC: {
		return "VALUE_CHARACTERISTIC";
	}
	

	case ::DLDL_VALUE::ast::Type::VALUE_RULE: {
		return "VALUE_RULE";
	}
	

	case ::DLDL_VALUE::ast::Type::NUMBER: {
		return "NUMBER";
	}
	

	case ::DLDL_VALUE::ast::Type::TEXT: {
		return "TEXT";
	}
	

	case ::DLDL_VALUE::ast::Type::VARNAME: {
		return "VARNAME";
	}
	

	case ::DLDL_VALUE::ast::Type::ESCAPE_CHARS: {
		return "ESCAPE_CHARS";
	}
	

		}
		
		return "";
	}

}}}

#endif // DLDL_VALUE_AST_RELATION_NODEENUMTOTEXT_H