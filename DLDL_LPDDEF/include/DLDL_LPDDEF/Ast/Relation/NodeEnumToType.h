#ifndef DLDL_LPDDEF_AST_RELATION_NODEENUMTOTYPE_H
#define DLDL_LPDDEF_AST_RELATION_NODEENUMTOTYPE_H

#include "DLDL_LPDDEF/Ast/Enum/Type.h"

#include "DLDL_LPDDEF/Ast/Node/program.h"
#include "DLDL_LPDDEF/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_LPDDEF/Ast/Node/stmt.h"
#include "DLDL_LPDDEF/Ast/Node/argument.h"
#include "DLDL_LPDDEF/Ast/Node/argument_name.h"
#include "DLDL_LPDDEF/Ast/Node/argument_block.h"
#include "DLDL_LPDDEF/Ast/Node/deamerreserved_star__argument_stmt__.h"
#include "DLDL_LPDDEF/Ast/Node/argument_stmt.h"
#include "DLDL_LPDDEF/Ast/Node/COLON.h"
#include "DLDL_LPDDEF/Ast/Node/LEFT_ANGLE_BRACKET.h"
#include "DLDL_LPDDEF/Ast/Node/RIGHT_ANGLE_BRACKET.h"
#include "DLDL_LPDDEF/Ast/Node/VARNAME.h"
#include "DLDL_LPDDEF/Ast/Node/INDENTED_VALUE.h"
#include "DLDL_LPDDEF/Ast/Node/ESCAPE_CHARS.h"


namespace DLDL_LPDDEF { namespace ast { namespace relation { 

	template<::DLDL_LPDDEF::ast::Type T>
	struct NodeEnumToType
	{
		constexpr static auto value = T;
		using type = void;
	};


	template<>
	struct NodeEnumToType<::DLDL_LPDDEF::ast::Type::program>
	{
		constexpr static auto value = ::DLDL_LPDDEF::ast::Type::program;
		using type = ::DLDL_LPDDEF::ast::node::program;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF::ast::Type::deamerreserved_star__stmt__>
	{
		constexpr static auto value = ::DLDL_LPDDEF::ast::Type::deamerreserved_star__stmt__;
		using type = ::DLDL_LPDDEF::ast::node::deamerreserved_star__stmt__;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF::ast::Type::stmt>
	{
		constexpr static auto value = ::DLDL_LPDDEF::ast::Type::stmt;
		using type = ::DLDL_LPDDEF::ast::node::stmt;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF::ast::Type::argument>
	{
		constexpr static auto value = ::DLDL_LPDDEF::ast::Type::argument;
		using type = ::DLDL_LPDDEF::ast::node::argument;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF::ast::Type::argument_name>
	{
		constexpr static auto value = ::DLDL_LPDDEF::ast::Type::argument_name;
		using type = ::DLDL_LPDDEF::ast::node::argument_name;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF::ast::Type::argument_block>
	{
		constexpr static auto value = ::DLDL_LPDDEF::ast::Type::argument_block;
		using type = ::DLDL_LPDDEF::ast::node::argument_block;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF::ast::Type::deamerreserved_star__argument_stmt__>
	{
		constexpr static auto value = ::DLDL_LPDDEF::ast::Type::deamerreserved_star__argument_stmt__;
		using type = ::DLDL_LPDDEF::ast::node::deamerreserved_star__argument_stmt__;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF::ast::Type::argument_stmt>
	{
		constexpr static auto value = ::DLDL_LPDDEF::ast::Type::argument_stmt;
		using type = ::DLDL_LPDDEF::ast::node::argument_stmt;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF::ast::Type::COLON>
	{
		constexpr static auto value = ::DLDL_LPDDEF::ast::Type::COLON;
		using type = ::DLDL_LPDDEF::ast::node::COLON;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF::ast::Type::LEFT_ANGLE_BRACKET>
	{
		constexpr static auto value = ::DLDL_LPDDEF::ast::Type::LEFT_ANGLE_BRACKET;
		using type = ::DLDL_LPDDEF::ast::node::LEFT_ANGLE_BRACKET;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF::ast::Type::RIGHT_ANGLE_BRACKET>
	{
		constexpr static auto value = ::DLDL_LPDDEF::ast::Type::RIGHT_ANGLE_BRACKET;
		using type = ::DLDL_LPDDEF::ast::node::RIGHT_ANGLE_BRACKET;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF::ast::Type::VARNAME>
	{
		constexpr static auto value = ::DLDL_LPDDEF::ast::Type::VARNAME;
		using type = ::DLDL_LPDDEF::ast::node::VARNAME;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF::ast::Type::INDENTED_VALUE>
	{
		constexpr static auto value = ::DLDL_LPDDEF::ast::Type::INDENTED_VALUE;
		using type = ::DLDL_LPDDEF::ast::node::INDENTED_VALUE;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF::ast::Type::ESCAPE_CHARS>
	{
		constexpr static auto value = ::DLDL_LPDDEF::ast::Type::ESCAPE_CHARS;
		using type = ::DLDL_LPDDEF::ast::node::ESCAPE_CHARS;
	};


template<::DLDL_LPDDEF::ast::Type T>
constexpr static auto NodeEnumToType_v = ::DLDL_LPDDEF::ast::relation::NodeEnumToType<T>::value;

template<::DLDL_LPDDEF::ast::Type T>
using NodeEnumToType_t = typename ::DLDL_LPDDEF::ast::relation::NodeEnumToType<T>::type;

}}}

#endif // DLDL_LPDDEF_AST_RELATION_NODEENUMTOTYPE_H