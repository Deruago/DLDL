#ifndef DLDL_VALUE_AST_ENUM_TYPE_H
#define DLDL_VALUE_AST_ENUM_TYPE_H

#include <cstddef>

namespace DLDL_VALUE { namespace ast { 

	enum class Type : std::size_t
	{
		// Reserved
		deamerreserved_unknown,

		// Terminal
		SINGLE_COMMENT,
		MULTI_COMMENT,
		LEFT_PARANTHESIS,
		RIGHT_PARANTHESIS,
		LEFT_BRACKET,
		RIGHT_BRACKET,
		LEFT_SQUARE_BRACKET,
		RIGHT_SQUARE_BRACKET,
		DOT,
		VALUE_CHARACTERISTIC,
		VALUE_RULE,
		NUMBER,
		TEXT,
		VARNAME,
		ESCAPE_CHARS,


		// NonTerminal
		program,
		deamerreserved_star__stmt__,
		stmt,
		value_charactersitic_declaration,
		deamerreserved_long_82,
		deamerreserved_long_85,
		deamerreserved_long_88,
		value_declaration,
		deamerreserved_long_91,
		value_characteristic_abstraction,
		value_declaration_abstraction,
		value_abstraction,
		deamerreserved_star__value_abstraction__,
		deamerreserved_long_96,
		value,
		syntactic_context,
		abstraction_name,
		value_rule_name,

	};

	static inline bool operator==(std::size_t lhs, ::DLDL_VALUE::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::DLDL_VALUE::ast::Type lhs, std::size_t rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}

	static inline bool operator==(int lhs, ::DLDL_VALUE::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::DLDL_VALUE::ast::Type lhs, int rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}
}}

#endif // DLDL_VALUE_AST_ENUM_TYPE_H