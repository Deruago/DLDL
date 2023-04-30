#ifndef DLDL_VALUE_AST_RELATION_NODETEXTTOENUM_H
#define DLDL_VALUE_AST_RELATION_NODETEXTTOENUM_H

#include "DLDL_VALUE/Ast/Enum/Type.h"
#include <string>
#include <map>

namespace DLDL_VALUE { namespace ast { namespace relation { 

	static constexpr ::DLDL_VALUE::ast::Type ConvertTextToEnum(const std::string& text)
	{
		static const std::map<std::string, ::DLDL_VALUE::ast::Type> mapTextWithType = {
			{"", ::DLDL_VALUE::ast::Type::deamerreserved_unknown },
			
		{ "program", ::DLDL_VALUE::ast::Type::program },
	

		{ "deamerreserved_star__stmt__", ::DLDL_VALUE::ast::Type::deamerreserved_star__stmt__ },
	

		{ "stmt", ::DLDL_VALUE::ast::Type::stmt },
	

		{ "value_charactersitic_declaration", ::DLDL_VALUE::ast::Type::value_charactersitic_declaration },
	

		{ "deamerreserved_long_82", ::DLDL_VALUE::ast::Type::deamerreserved_long_82 },
	

		{ "deamerreserved_long_85", ::DLDL_VALUE::ast::Type::deamerreserved_long_85 },
	

		{ "deamerreserved_long_88", ::DLDL_VALUE::ast::Type::deamerreserved_long_88 },
	

		{ "value_declaration", ::DLDL_VALUE::ast::Type::value_declaration },
	

		{ "deamerreserved_long_91", ::DLDL_VALUE::ast::Type::deamerreserved_long_91 },
	

		{ "value_characteristic_abstraction", ::DLDL_VALUE::ast::Type::value_characteristic_abstraction },
	

		{ "value_declaration_abstraction", ::DLDL_VALUE::ast::Type::value_declaration_abstraction },
	

		{ "value_abstraction", ::DLDL_VALUE::ast::Type::value_abstraction },
	

		{ "deamerreserved_star__value_abstraction__", ::DLDL_VALUE::ast::Type::deamerreserved_star__value_abstraction__ },
	

		{ "deamerreserved_long_96", ::DLDL_VALUE::ast::Type::deamerreserved_long_96 },
	

		{ "value", ::DLDL_VALUE::ast::Type::value },
	

		{ "syntactic_context", ::DLDL_VALUE::ast::Type::syntactic_context },
	

		{ "abstraction_name", ::DLDL_VALUE::ast::Type::abstraction_name },
	

		{ "value_rule_name", ::DLDL_VALUE::ast::Type::value_rule_name },
	

		{ "SINGLE_COMMENT", ::DLDL_VALUE::ast::Type::SINGLE_COMMENT },
	

		{ "MULTI_COMMENT", ::DLDL_VALUE::ast::Type::MULTI_COMMENT },
	

		{ "LEFT_PARANTHESIS", ::DLDL_VALUE::ast::Type::LEFT_PARANTHESIS },
	

		{ "RIGHT_PARANTHESIS", ::DLDL_VALUE::ast::Type::RIGHT_PARANTHESIS },
	

		{ "LEFT_BRACKET", ::DLDL_VALUE::ast::Type::LEFT_BRACKET },
	

		{ "RIGHT_BRACKET", ::DLDL_VALUE::ast::Type::RIGHT_BRACKET },
	

		{ "LEFT_SQUARE_BRACKET", ::DLDL_VALUE::ast::Type::LEFT_SQUARE_BRACKET },
	

		{ "RIGHT_SQUARE_BRACKET", ::DLDL_VALUE::ast::Type::RIGHT_SQUARE_BRACKET },
	

		{ "DOT", ::DLDL_VALUE::ast::Type::DOT },
	

		{ "VALUE_CHARACTERISTIC", ::DLDL_VALUE::ast::Type::VALUE_CHARACTERISTIC },
	

		{ "VALUE_RULE", ::DLDL_VALUE::ast::Type::VALUE_RULE },
	

		{ "NUMBER", ::DLDL_VALUE::ast::Type::NUMBER },
	

		{ "TEXT", ::DLDL_VALUE::ast::Type::TEXT },
	

		{ "VARNAME", ::DLDL_VALUE::ast::Type::VARNAME },
	

		{ "ESCAPE_CHARS", ::DLDL_VALUE::ast::Type::ESCAPE_CHARS },
	

		};

		return mapTextWithType[text];
	}

}}}

#endif // DLDL_VALUE_AST_RELATION_NODETEXTTOENUM_H