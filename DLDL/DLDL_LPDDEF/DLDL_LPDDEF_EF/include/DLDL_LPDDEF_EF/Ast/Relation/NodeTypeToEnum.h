#ifndef DLDL_LPDDEF_EF_AST_RELATION_NODETYPETOENUM_H
#define DLDL_LPDDEF_EF_AST_RELATION_NODETYPETOENUM_H

#include "DLDL_LPDDEF_EF/Ast/Enum/Type.h"

namespace DLDL_LPDDEF_EF { namespace ast { namespace node {

class program;
class deamerreserved_star__stmt__;
class stmt;
class comment_line;
class standard_variant;
class standard_variant_specific_number;
class value;
class enum_name;
class COMMENT;
class VARNAME;
class NUMBER;
class COLON;
class SEMICOLON;
class ESCAPE_CHARS;

}}}

namespace DLDL_LPDDEF_EF { namespace ast { namespace relation { 

	template<typename T>
	struct NodeTypeToEnum
	{
		constexpr static auto value = ::DLDL_LPDDEF_EF::ast::Type::deamerreserved_unknown;
		using type = void;
	};


	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_EF::ast::node::program>
	{
		constexpr static auto value = ::DLDL_LPDDEF_EF::ast::Type::program;
		using type = ::DLDL_LPDDEF_EF::ast::node::program;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__>
	{
		constexpr static auto value = ::DLDL_LPDDEF_EF::ast::Type::deamerreserved_star__stmt__;
		using type = ::DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_EF::ast::node::stmt>
	{
		constexpr static auto value = ::DLDL_LPDDEF_EF::ast::Type::stmt;
		using type = ::DLDL_LPDDEF_EF::ast::node::stmt;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_EF::ast::node::comment_line>
	{
		constexpr static auto value = ::DLDL_LPDDEF_EF::ast::Type::comment_line;
		using type = ::DLDL_LPDDEF_EF::ast::node::comment_line;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_EF::ast::node::standard_variant>
	{
		constexpr static auto value = ::DLDL_LPDDEF_EF::ast::Type::standard_variant;
		using type = ::DLDL_LPDDEF_EF::ast::node::standard_variant;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_EF::ast::node::standard_variant_specific_number>
	{
		constexpr static auto value = ::DLDL_LPDDEF_EF::ast::Type::standard_variant_specific_number;
		using type = ::DLDL_LPDDEF_EF::ast::node::standard_variant_specific_number;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_EF::ast::node::value>
	{
		constexpr static auto value = ::DLDL_LPDDEF_EF::ast::Type::value;
		using type = ::DLDL_LPDDEF_EF::ast::node::value;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_EF::ast::node::enum_name>
	{
		constexpr static auto value = ::DLDL_LPDDEF_EF::ast::Type::enum_name;
		using type = ::DLDL_LPDDEF_EF::ast::node::enum_name;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_EF::ast::node::COMMENT>
	{
		constexpr static auto value = ::DLDL_LPDDEF_EF::ast::Type::COMMENT;
		using type = ::DLDL_LPDDEF_EF::ast::node::COMMENT;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_EF::ast::node::VARNAME>
	{
		constexpr static auto value = ::DLDL_LPDDEF_EF::ast::Type::VARNAME;
		using type = ::DLDL_LPDDEF_EF::ast::node::VARNAME;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_EF::ast::node::NUMBER>
	{
		constexpr static auto value = ::DLDL_LPDDEF_EF::ast::Type::NUMBER;
		using type = ::DLDL_LPDDEF_EF::ast::node::NUMBER;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_EF::ast::node::COLON>
	{
		constexpr static auto value = ::DLDL_LPDDEF_EF::ast::Type::COLON;
		using type = ::DLDL_LPDDEF_EF::ast::node::COLON;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_EF::ast::node::SEMICOLON>
	{
		constexpr static auto value = ::DLDL_LPDDEF_EF::ast::Type::SEMICOLON;
		using type = ::DLDL_LPDDEF_EF::ast::node::SEMICOLON;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_EF::ast::node::ESCAPE_CHARS>
	{
		constexpr static auto value = ::DLDL_LPDDEF_EF::ast::Type::ESCAPE_CHARS;
		using type = ::DLDL_LPDDEF_EF::ast::node::ESCAPE_CHARS;
	};


template<typename T>
constexpr static auto NodeTypeToEnum_v = ::DLDL_LPDDEF_EF::ast::relation::NodeTypeToEnum<T>::value;

template<typename T>
using NodeTypeToEnum_t = typename ::DLDL_LPDDEF_EF::ast::relation::NodeTypeToEnum<T>::type;

}}}

#endif // DLDL_LPDDEF_EF_AST_RELATION_NODETYPETOENUM_H