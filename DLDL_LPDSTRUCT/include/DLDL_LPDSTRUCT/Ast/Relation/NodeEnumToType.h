#ifndef DLDL_LPDSTRUCT_AST_RELATION_NODEENUMTOTYPE_H
#define DLDL_LPDSTRUCT_AST_RELATION_NODEENUMTOTYPE_H

#include "DLDL_LPDSTRUCT/Ast/Enum/Type.h"

#include "DLDL_LPDSTRUCT/Ast/Node/program.h"
#include "DLDL_LPDSTRUCT/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_LPDSTRUCT/Ast/Node/stmt.h"
#include "DLDL_LPDSTRUCT/Ast/Node/argument.h"
#include "DLDL_LPDSTRUCT/Ast/Node/argument_name.h"
#include "DLDL_LPDSTRUCT/Ast/Node/argument_block.h"
#include "DLDL_LPDSTRUCT/Ast/Node/deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______.h"
#include "DLDL_LPDSTRUCT/Ast/Node/COLON.h"
#include "DLDL_LPDSTRUCT/Ast/Node/LEFT_ANGLE_BRACKET.h"
#include "DLDL_LPDSTRUCT/Ast/Node/RIGHT_ANGLE_BRACKET.h"
#include "DLDL_LPDSTRUCT/Ast/Node/VARNAME.h"
#include "DLDL_LPDSTRUCT/Ast/Node/VARNAME_EXT.h"
#include "DLDL_LPDSTRUCT/Ast/Node/INDENTED_VALUE.h"
#include "DLDL_LPDSTRUCT/Ast/Node/ESCAPE_CHARS.h"


namespace DLDL_LPDSTRUCT { namespace ast { namespace relation { 

	template<::DLDL_LPDSTRUCT::ast::Type T>
	struct NodeEnumToType
	{
		constexpr static auto value = T;
		using type = void;
	};


	template<>
	struct NodeEnumToType<::DLDL_LPDSTRUCT::ast::Type::program>
	{
		constexpr static auto value = ::DLDL_LPDSTRUCT::ast::Type::program;
		using type = ::DLDL_LPDSTRUCT::ast::node::program;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDSTRUCT::ast::Type::deamerreserved_star__stmt__>
	{
		constexpr static auto value = ::DLDL_LPDSTRUCT::ast::Type::deamerreserved_star__stmt__;
		using type = ::DLDL_LPDSTRUCT::ast::node::deamerreserved_star__stmt__;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDSTRUCT::ast::Type::stmt>
	{
		constexpr static auto value = ::DLDL_LPDSTRUCT::ast::Type::stmt;
		using type = ::DLDL_LPDSTRUCT::ast::node::stmt;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDSTRUCT::ast::Type::argument>
	{
		constexpr static auto value = ::DLDL_LPDSTRUCT::ast::Type::argument;
		using type = ::DLDL_LPDSTRUCT::ast::node::argument;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDSTRUCT::ast::Type::argument_name>
	{
		constexpr static auto value = ::DLDL_LPDSTRUCT::ast::Type::argument_name;
		using type = ::DLDL_LPDSTRUCT::ast::node::argument_name;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDSTRUCT::ast::Type::argument_block>
	{
		constexpr static auto value = ::DLDL_LPDSTRUCT::ast::Type::argument_block;
		using type = ::DLDL_LPDSTRUCT::ast::node::argument_block;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDSTRUCT::ast::Type::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______>
	{
		constexpr static auto value = ::DLDL_LPDSTRUCT::ast::Type::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______;
		using type = ::DLDL_LPDSTRUCT::ast::node::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDSTRUCT::ast::Type::COLON>
	{
		constexpr static auto value = ::DLDL_LPDSTRUCT::ast::Type::COLON;
		using type = ::DLDL_LPDSTRUCT::ast::node::COLON;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDSTRUCT::ast::Type::LEFT_ANGLE_BRACKET>
	{
		constexpr static auto value = ::DLDL_LPDSTRUCT::ast::Type::LEFT_ANGLE_BRACKET;
		using type = ::DLDL_LPDSTRUCT::ast::node::LEFT_ANGLE_BRACKET;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDSTRUCT::ast::Type::RIGHT_ANGLE_BRACKET>
	{
		constexpr static auto value = ::DLDL_LPDSTRUCT::ast::Type::RIGHT_ANGLE_BRACKET;
		using type = ::DLDL_LPDSTRUCT::ast::node::RIGHT_ANGLE_BRACKET;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDSTRUCT::ast::Type::VARNAME>
	{
		constexpr static auto value = ::DLDL_LPDSTRUCT::ast::Type::VARNAME;
		using type = ::DLDL_LPDSTRUCT::ast::node::VARNAME;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDSTRUCT::ast::Type::VARNAME_EXT>
	{
		constexpr static auto value = ::DLDL_LPDSTRUCT::ast::Type::VARNAME_EXT;
		using type = ::DLDL_LPDSTRUCT::ast::node::VARNAME_EXT;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDSTRUCT::ast::Type::INDENTED_VALUE>
	{
		constexpr static auto value = ::DLDL_LPDSTRUCT::ast::Type::INDENTED_VALUE;
		using type = ::DLDL_LPDSTRUCT::ast::node::INDENTED_VALUE;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDSTRUCT::ast::Type::ESCAPE_CHARS>
	{
		constexpr static auto value = ::DLDL_LPDSTRUCT::ast::Type::ESCAPE_CHARS;
		using type = ::DLDL_LPDSTRUCT::ast::node::ESCAPE_CHARS;
	};


template<::DLDL_LPDSTRUCT::ast::Type T>
constexpr static auto NodeEnumToType_v = ::DLDL_LPDSTRUCT::ast::relation::NodeEnumToType<T>::value;

template<::DLDL_LPDSTRUCT::ast::Type T>
using NodeEnumToType_t = typename ::DLDL_LPDSTRUCT::ast::relation::NodeEnumToType<T>::type;

}}}

#endif // DLDL_LPDSTRUCT_AST_RELATION_NODEENUMTOTYPE_H