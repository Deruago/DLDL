#ifndef DLDL_LPDDEF_EF_AST_RELATION_NODEENUMTOTYPE_H
#define DLDL_LPDDEF_EF_AST_RELATION_NODEENUMTOTYPE_H

#include "DLDL_LPDDEF_EF/Ast/Enum/Type.h"

#include "DLDL_LPDDEF_EF/Ast/Node/program.h"
#include "DLDL_LPDDEF_EF/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_LPDDEF_EF/Ast/Node/stmt.h"
#include "DLDL_LPDDEF_EF/Ast/Node/comment_line.h"
#include "DLDL_LPDDEF_EF/Ast/Node/standard_variant.h"
#include "DLDL_LPDDEF_EF/Ast/Node/standard_variant_specific_number.h"
#include "DLDL_LPDDEF_EF/Ast/Node/value.h"
#include "DLDL_LPDDEF_EF/Ast/Node/enum_name.h"
#include "DLDL_LPDDEF_EF/Ast/Node/COMMENT.h"
#include "DLDL_LPDDEF_EF/Ast/Node/VARNAME.h"
#include "DLDL_LPDDEF_EF/Ast/Node/NUMBER.h"
#include "DLDL_LPDDEF_EF/Ast/Node/COLON.h"
#include "DLDL_LPDDEF_EF/Ast/Node/SEMICOLON.h"
#include "DLDL_LPDDEF_EF/Ast/Node/ESCAPE_CHARS.h"


namespace DLDL_LPDDEF_EF { namespace ast { namespace relation { 

	template<::DLDL_LPDDEF_EF::ast::Type T>
	struct NodeEnumToType
	{
		constexpr static auto value = T;
		using type = void;
	};


	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_EF::ast::Type::program>
	{
		constexpr static auto value = ::DLDL_LPDDEF_EF::ast::Type::program;
		using type = ::DLDL_LPDDEF_EF::ast::node::program;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_EF::ast::Type::deamerreserved_star__stmt__>
	{
		constexpr static auto value = ::DLDL_LPDDEF_EF::ast::Type::deamerreserved_star__stmt__;
		using type = ::DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_EF::ast::Type::stmt>
	{
		constexpr static auto value = ::DLDL_LPDDEF_EF::ast::Type::stmt;
		using type = ::DLDL_LPDDEF_EF::ast::node::stmt;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_EF::ast::Type::comment_line>
	{
		constexpr static auto value = ::DLDL_LPDDEF_EF::ast::Type::comment_line;
		using type = ::DLDL_LPDDEF_EF::ast::node::comment_line;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_EF::ast::Type::standard_variant>
	{
		constexpr static auto value = ::DLDL_LPDDEF_EF::ast::Type::standard_variant;
		using type = ::DLDL_LPDDEF_EF::ast::node::standard_variant;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_EF::ast::Type::standard_variant_specific_number>
	{
		constexpr static auto value = ::DLDL_LPDDEF_EF::ast::Type::standard_variant_specific_number;
		using type = ::DLDL_LPDDEF_EF::ast::node::standard_variant_specific_number;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_EF::ast::Type::value>
	{
		constexpr static auto value = ::DLDL_LPDDEF_EF::ast::Type::value;
		using type = ::DLDL_LPDDEF_EF::ast::node::value;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_EF::ast::Type::enum_name>
	{
		constexpr static auto value = ::DLDL_LPDDEF_EF::ast::Type::enum_name;
		using type = ::DLDL_LPDDEF_EF::ast::node::enum_name;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_EF::ast::Type::COMMENT>
	{
		constexpr static auto value = ::DLDL_LPDDEF_EF::ast::Type::COMMENT;
		using type = ::DLDL_LPDDEF_EF::ast::node::COMMENT;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_EF::ast::Type::VARNAME>
	{
		constexpr static auto value = ::DLDL_LPDDEF_EF::ast::Type::VARNAME;
		using type = ::DLDL_LPDDEF_EF::ast::node::VARNAME;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_EF::ast::Type::NUMBER>
	{
		constexpr static auto value = ::DLDL_LPDDEF_EF::ast::Type::NUMBER;
		using type = ::DLDL_LPDDEF_EF::ast::node::NUMBER;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_EF::ast::Type::COLON>
	{
		constexpr static auto value = ::DLDL_LPDDEF_EF::ast::Type::COLON;
		using type = ::DLDL_LPDDEF_EF::ast::node::COLON;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_EF::ast::Type::SEMICOLON>
	{
		constexpr static auto value = ::DLDL_LPDDEF_EF::ast::Type::SEMICOLON;
		using type = ::DLDL_LPDDEF_EF::ast::node::SEMICOLON;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_EF::ast::Type::ESCAPE_CHARS>
	{
		constexpr static auto value = ::DLDL_LPDDEF_EF::ast::Type::ESCAPE_CHARS;
		using type = ::DLDL_LPDDEF_EF::ast::node::ESCAPE_CHARS;
	};


template<::DLDL_LPDDEF_EF::ast::Type T>
constexpr static auto NodeEnumToType_v = ::DLDL_LPDDEF_EF::ast::relation::NodeEnumToType<T>::value;

template<::DLDL_LPDDEF_EF::ast::Type T>
using NodeEnumToType_t = typename ::DLDL_LPDDEF_EF::ast::relation::NodeEnumToType<T>::type;

}}}

#endif // DLDL_LPDDEF_EF_AST_RELATION_NODEENUMTOTYPE_H