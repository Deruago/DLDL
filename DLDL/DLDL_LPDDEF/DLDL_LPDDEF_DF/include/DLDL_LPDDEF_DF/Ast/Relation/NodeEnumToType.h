#ifndef DLDL_LPDDEF_DF_AST_RELATION_NODEENUMTOTYPE_H
#define DLDL_LPDDEF_DF_AST_RELATION_NODEENUMTOTYPE_H

#include "DLDL_LPDDEF_DF/Ast/Enum/Type.h"

#include "DLDL_LPDDEF_DF/Ast/Node/program.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/stmt.h"
#include "DLDL_LPDDEF_DF/Ast/Node/comment_line.h"
#include "DLDL_LPDDEF_DF/Ast/Node/vector_variant.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_optional__value_part__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/optional_variant.h"
#include "DLDL_LPDDEF_DF/Ast/Node/value_part.h"
#include "DLDL_LPDDEF_DF/Ast/Node/standard_variant.h"
#include "DLDL_LPDDEF_DF/Ast/Node/value.h"
#include "DLDL_LPDDEF_DF/Ast/Node/value_type.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_arrow__value_type__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_star__COMMA__value_type__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_long_54.h"
#include "DLDL_LPDDEF_DF/Ast/Node/var_type.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_arrow__VARNAME__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_star__COLON__VARNAME__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/var_name.h"
#include "DLDL_LPDDEF_DF/Ast/Node/LAB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/RAB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/LSB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/RSB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/EQ.h"
#include "DLDL_LPDDEF_DF/Ast/Node/COLON.h"
#include "DLDL_LPDDEF_DF/Ast/Node/LB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/RB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/COMMA.h"
#include "DLDL_LPDDEF_DF/Ast/Node/OPTIONAL.h"
#include "DLDL_LPDDEF_DF/Ast/Node/VECTOR.h"
#include "DLDL_LPDDEF_DF/Ast/Node/DEAMER_VARNAME.h"
#include "DLDL_LPDDEF_DF/Ast/Node/COMMENT.h"
#include "DLDL_LPDDEF_DF/Ast/Node/VARNAME.h"
#include "DLDL_LPDDEF_DF/Ast/Node/NUMBER.h"
#include "DLDL_LPDDEF_DF/Ast/Node/STRING.h"
#include "DLDL_LPDDEF_DF/Ast/Node/SEMICOLON.h"
#include "DLDL_LPDDEF_DF/Ast/Node/ESCAPE_CHARS.h"


namespace DLDL_LPDDEF_DF { namespace ast { namespace relation { 

	template<::DLDL_LPDDEF_DF::ast::Type T>
	struct NodeEnumToType
	{
		constexpr static auto value = T;
		using type = void;
	};


	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::program>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::program;
		using type = ::DLDL_LPDDEF_DF::ast::node::program;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__stmt__>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__stmt__;
		using type = ::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::stmt>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::stmt;
		using type = ::DLDL_LPDDEF_DF::ast::node::stmt;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::comment_line>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::comment_line;
		using type = ::DLDL_LPDDEF_DF::ast::node::comment_line;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::vector_variant>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::vector_variant;
		using type = ::DLDL_LPDDEF_DF::ast::node::vector_variant;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::deamerreserved_optional__value_part__>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_optional__value_part__;
		using type = ::DLDL_LPDDEF_DF::ast::node::deamerreserved_optional__value_part__;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::optional_variant>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::optional_variant;
		using type = ::DLDL_LPDDEF_DF::ast::node::optional_variant;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::value_part>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::value_part;
		using type = ::DLDL_LPDDEF_DF::ast::node::value_part;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::standard_variant>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::standard_variant;
		using type = ::DLDL_LPDDEF_DF::ast::node::standard_variant;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::value>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::value;
		using type = ::DLDL_LPDDEF_DF::ast::node::value;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::value_type>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::value_type;
		using type = ::DLDL_LPDDEF_DF::ast::node::value_type;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::deamerreserved_arrow__value_type__>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_arrow__value_type__;
		using type = ::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COMMA__value_type__>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COMMA__value_type__;
		using type = ::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::deamerreserved_long_54>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_long_54;
		using type = ::DLDL_LPDDEF_DF::ast::node::deamerreserved_long_54;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::var_type>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::var_type;
		using type = ::DLDL_LPDDEF_DF::ast::node::var_type;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::deamerreserved_arrow__VARNAME__>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_arrow__VARNAME__;
		using type = ::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COLON__VARNAME__>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COLON__VARNAME__;
		using type = ::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::var_name>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::var_name;
		using type = ::DLDL_LPDDEF_DF::ast::node::var_name;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::LAB>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::LAB;
		using type = ::DLDL_LPDDEF_DF::ast::node::LAB;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::RAB>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::RAB;
		using type = ::DLDL_LPDDEF_DF::ast::node::RAB;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::LSB>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::LSB;
		using type = ::DLDL_LPDDEF_DF::ast::node::LSB;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::RSB>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::RSB;
		using type = ::DLDL_LPDDEF_DF::ast::node::RSB;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::EQ>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::EQ;
		using type = ::DLDL_LPDDEF_DF::ast::node::EQ;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::COLON>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::COLON;
		using type = ::DLDL_LPDDEF_DF::ast::node::COLON;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::LB>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::LB;
		using type = ::DLDL_LPDDEF_DF::ast::node::LB;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::RB>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::RB;
		using type = ::DLDL_LPDDEF_DF::ast::node::RB;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::COMMA>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::COMMA;
		using type = ::DLDL_LPDDEF_DF::ast::node::COMMA;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::OPTIONAL>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::OPTIONAL;
		using type = ::DLDL_LPDDEF_DF::ast::node::OPTIONAL;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::VECTOR>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::VECTOR;
		using type = ::DLDL_LPDDEF_DF::ast::node::VECTOR;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::DEAMER_VARNAME>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::DEAMER_VARNAME;
		using type = ::DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::COMMENT>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::COMMENT;
		using type = ::DLDL_LPDDEF_DF::ast::node::COMMENT;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::VARNAME>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::VARNAME;
		using type = ::DLDL_LPDDEF_DF::ast::node::VARNAME;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::NUMBER>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::NUMBER;
		using type = ::DLDL_LPDDEF_DF::ast::node::NUMBER;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::STRING>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::STRING;
		using type = ::DLDL_LPDDEF_DF::ast::node::STRING;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::SEMICOLON>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::SEMICOLON;
		using type = ::DLDL_LPDDEF_DF::ast::node::SEMICOLON;
	};

	template<>
	struct NodeEnumToType<::DLDL_LPDDEF_DF::ast::Type::ESCAPE_CHARS>
	{
		constexpr static auto value = ::DLDL_LPDDEF_DF::ast::Type::ESCAPE_CHARS;
		using type = ::DLDL_LPDDEF_DF::ast::node::ESCAPE_CHARS;
	};


template<::DLDL_LPDDEF_DF::ast::Type T>
constexpr static auto NodeEnumToType_v = ::DLDL_LPDDEF_DF::ast::relation::NodeEnumToType<T>::value;

template<::DLDL_LPDDEF_DF::ast::Type T>
using NodeEnumToType_t = typename ::DLDL_LPDDEF_DF::ast::relation::NodeEnumToType<T>::type;

}}}

#endif // DLDL_LPDDEF_DF_AST_RELATION_NODEENUMTOTYPE_H