#ifndef DLDL_LPDDEF_DF_AST_RELATION_NODETYPETOENUM_H
#define DLDL_LPDDEF_DF_AST_RELATION_NODETYPETOENUM_H

#include "DLDL_LPDDEF_DF/Ast/Enum/Type.h"

namespace DLDL_LPDDEF_DF { namespace ast { namespace node {

class program;
class deamerreserved_star__stmt__;
class stmt;
class comment_line;
class vector_variant;
class deamerreserved_optional__value_part__;
class optional_variant;
class value_part;
class standard_variant;
class value;
class value_type;
class deamerreserved_arrow__value_type__;
class deamerreserved_star__COMMA__value_type__;
class deamerreserved_long_54;
class var_type;
class deamerreserved_arrow__VARNAME__;
class deamerreserved_star__COLON__VARNAME__;
class var_name;
class LAB;
class RAB;
class LSB;
class RSB;
class EQ;
class COLON;
class LB;
class RB;
class COMMA;
class OPTIONAL;
class VECTOR;
class DEAMER_VARNAME;
class COMMENT;
class VARNAME;
class NUMBER;
class STRING;
class SEMICOLON;
class ESCAPE_CHARS;

}}}

namespace DLDL_LPDDEF_DF { namespace ast { namespace relation { 

	template<typename T>
	struct NodeTypeToEnum
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_unknown;
		using type = void;
	};


	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::program>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::program;
		using type = ::DLDL_LPDDEF_DF::ast::node::program;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__stmt__;
		using type = ::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::stmt>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::stmt;
		using type = ::DLDL_LPDDEF_DF::ast::node::stmt;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::comment_line>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::comment_line;
		using type = ::DLDL_LPDDEF_DF::ast::node::comment_line;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::vector_variant>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::vector_variant;
		using type = ::DLDL_LPDDEF_DF::ast::node::vector_variant;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::deamerreserved_optional__value_part__>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_optional__value_part__;
		using type = ::DLDL_LPDDEF_DF::ast::node::deamerreserved_optional__value_part__;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::optional_variant>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::optional_variant;
		using type = ::DLDL_LPDDEF_DF::ast::node::optional_variant;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::value_part>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::value_part;
		using type = ::DLDL_LPDDEF_DF::ast::node::value_part;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::standard_variant>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::standard_variant;
		using type = ::DLDL_LPDDEF_DF::ast::node::standard_variant;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::value>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::value;
		using type = ::DLDL_LPDDEF_DF::ast::node::value;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::value_type>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::value_type;
		using type = ::DLDL_LPDDEF_DF::ast::node::value_type;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_arrow__value_type__;
		using type = ::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COMMA__value_type__;
		using type = ::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::deamerreserved_long_54>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_long_54;
		using type = ::DLDL_LPDDEF_DF::ast::node::deamerreserved_long_54;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::var_type>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::var_type;
		using type = ::DLDL_LPDDEF_DF::ast::node::var_type;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_arrow__VARNAME__;
		using type = ::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COLON__VARNAME__;
		using type = ::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::var_name>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::var_name;
		using type = ::DLDL_LPDDEF_DF::ast::node::var_name;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::LAB>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::LAB;
		using type = ::DLDL_LPDDEF_DF::ast::node::LAB;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::RAB>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::RAB;
		using type = ::DLDL_LPDDEF_DF::ast::node::RAB;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::LSB>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::LSB;
		using type = ::DLDL_LPDDEF_DF::ast::node::LSB;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::RSB>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::RSB;
		using type = ::DLDL_LPDDEF_DF::ast::node::RSB;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::EQ>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::EQ;
		using type = ::DLDL_LPDDEF_DF::ast::node::EQ;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::COLON>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::COLON;
		using type = ::DLDL_LPDDEF_DF::ast::node::COLON;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::LB>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::LB;
		using type = ::DLDL_LPDDEF_DF::ast::node::LB;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::RB>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::RB;
		using type = ::DLDL_LPDDEF_DF::ast::node::RB;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::COMMA>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::COMMA;
		using type = ::DLDL_LPDDEF_DF::ast::node::COMMA;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::OPTIONAL>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::OPTIONAL;
		using type = ::DLDL_LPDDEF_DF::ast::node::OPTIONAL;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::VECTOR>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::VECTOR;
		using type = ::DLDL_LPDDEF_DF::ast::node::VECTOR;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::DEAMER_VARNAME;
		using type = ::DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::COMMENT>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::COMMENT;
		using type = ::DLDL_LPDDEF_DF::ast::node::COMMENT;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::VARNAME>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::VARNAME;
		using type = ::DLDL_LPDDEF_DF::ast::node::VARNAME;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::NUMBER>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::NUMBER;
		using type = ::DLDL_LPDDEF_DF::ast::node::NUMBER;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::STRING>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::STRING;
		using type = ::DLDL_LPDDEF_DF::ast::node::STRING;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::SEMICOLON>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::SEMICOLON;
		using type = ::DLDL_LPDDEF_DF::ast::node::SEMICOLON;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LPDDEF_DF::ast::node::ESCAPE_CHARS>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::ESCAPE_CHARS;
		using type = ::DLDL_LPDDEF_DF::ast::node::ESCAPE_CHARS;
	};


template<typename T>
constexpr static auto NodeTypeToEnum_v = ::DLDL_LPDDEF_DF::ast::relation::NodeTypeToEnum<T>::value;

template<typename T>
using NodeTypeToEnum_t = typename ::DLDL_LPDDEF_DF::ast::relation::NodeTypeToEnum<T>::type;

}}}

#endif // DLDL_LPDDEF_DF_AST_RELATION_NODETYPETOENUM_H