#ifndef DLDL_IMPORT_AST_RELATION_NODETYPETOENUM_H
#define DLDL_IMPORT_AST_RELATION_NODETYPETOENUM_H

#include "DLDL_IMPORT/Ast/Enum/Type.h"

namespace DLDL_IMPORT { namespace ast { namespace node {

class program;
class deamerreserved_star__stmt__;
class stmt;
class import_declaration;
class deamerreserved_arrow__import_context__;
class deamerreserved_long_40;
class deamerreserved_long_43;
class specialization;
class import_abstraction;
class value;
class deamerreserved_optional__VARNAME__;
class abstraction;
class import_context;
class import_rule_name;
class SINGLE_COMMENT;
class MULTI_COMMENT;
class LEFT_PARANTHESIS;
class RIGHT_PARANTHESIS;
class LEFT_SQUARE_BRACKET;
class RIGHT_SQUARE_BRACKET;
class COLON;
class DOT;
class IMPORT_FILE;
class IMPORT_MODULE;
class IMPORT;
class TEXT;
class VARNAME;
class ESCAPE_CHARS;

}}}

namespace DLDL_IMPORT { namespace ast { namespace relation { 

	template<typename T>
	struct NodeTypeToEnum
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::deamerreserved_unknown;
		using type = void;
	};


	template<>
	struct NodeTypeToEnum<::DLDL_IMPORT::ast::node::program>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::program;
		using type = ::DLDL_IMPORT::ast::node::program;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_IMPORT::ast::node::deamerreserved_star__stmt__>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::deamerreserved_star__stmt__;
		using type = ::DLDL_IMPORT::ast::node::deamerreserved_star__stmt__;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_IMPORT::ast::node::stmt>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::stmt;
		using type = ::DLDL_IMPORT::ast::node::stmt;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_IMPORT::ast::node::import_declaration>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::import_declaration;
		using type = ::DLDL_IMPORT::ast::node::import_declaration;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_IMPORT::ast::node::deamerreserved_arrow__import_context__>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::deamerreserved_arrow__import_context__;
		using type = ::DLDL_IMPORT::ast::node::deamerreserved_arrow__import_context__;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_IMPORT::ast::node::deamerreserved_long_40>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::deamerreserved_long_40;
		using type = ::DLDL_IMPORT::ast::node::deamerreserved_long_40;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_IMPORT::ast::node::deamerreserved_long_43>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::deamerreserved_long_43;
		using type = ::DLDL_IMPORT::ast::node::deamerreserved_long_43;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_IMPORT::ast::node::specialization>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::specialization;
		using type = ::DLDL_IMPORT::ast::node::specialization;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_IMPORT::ast::node::import_abstraction>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::import_abstraction;
		using type = ::DLDL_IMPORT::ast::node::import_abstraction;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_IMPORT::ast::node::value>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::value;
		using type = ::DLDL_IMPORT::ast::node::value;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_IMPORT::ast::node::deamerreserved_optional__VARNAME__>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::deamerreserved_optional__VARNAME__;
		using type = ::DLDL_IMPORT::ast::node::deamerreserved_optional__VARNAME__;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_IMPORT::ast::node::abstraction>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::abstraction;
		using type = ::DLDL_IMPORT::ast::node::abstraction;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_IMPORT::ast::node::import_context>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::import_context;
		using type = ::DLDL_IMPORT::ast::node::import_context;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_IMPORT::ast::node::import_rule_name>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::import_rule_name;
		using type = ::DLDL_IMPORT::ast::node::import_rule_name;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_IMPORT::ast::node::SINGLE_COMMENT>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::SINGLE_COMMENT;
		using type = ::DLDL_IMPORT::ast::node::SINGLE_COMMENT;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_IMPORT::ast::node::MULTI_COMMENT>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::MULTI_COMMENT;
		using type = ::DLDL_IMPORT::ast::node::MULTI_COMMENT;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_IMPORT::ast::node::LEFT_PARANTHESIS>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::LEFT_PARANTHESIS;
		using type = ::DLDL_IMPORT::ast::node::LEFT_PARANTHESIS;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_IMPORT::ast::node::RIGHT_PARANTHESIS>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::RIGHT_PARANTHESIS;
		using type = ::DLDL_IMPORT::ast::node::RIGHT_PARANTHESIS;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_IMPORT::ast::node::LEFT_SQUARE_BRACKET>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::LEFT_SQUARE_BRACKET;
		using type = ::DLDL_IMPORT::ast::node::LEFT_SQUARE_BRACKET;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_IMPORT::ast::node::RIGHT_SQUARE_BRACKET>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::RIGHT_SQUARE_BRACKET;
		using type = ::DLDL_IMPORT::ast::node::RIGHT_SQUARE_BRACKET;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_IMPORT::ast::node::COLON>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::COLON;
		using type = ::DLDL_IMPORT::ast::node::COLON;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_IMPORT::ast::node::DOT>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::DOT;
		using type = ::DLDL_IMPORT::ast::node::DOT;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_IMPORT::ast::node::IMPORT_FILE>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::IMPORT_FILE;
		using type = ::DLDL_IMPORT::ast::node::IMPORT_FILE;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_IMPORT::ast::node::IMPORT_MODULE>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::IMPORT_MODULE;
		using type = ::DLDL_IMPORT::ast::node::IMPORT_MODULE;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_IMPORT::ast::node::IMPORT>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::IMPORT;
		using type = ::DLDL_IMPORT::ast::node::IMPORT;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_IMPORT::ast::node::TEXT>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::TEXT;
		using type = ::DLDL_IMPORT::ast::node::TEXT;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_IMPORT::ast::node::VARNAME>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::VARNAME;
		using type = ::DLDL_IMPORT::ast::node::VARNAME;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_IMPORT::ast::node::ESCAPE_CHARS>
	{
		constexpr static auto value = ::DLDL_IMPORT::ast::Type::ESCAPE_CHARS;
		using type = ::DLDL_IMPORT::ast::node::ESCAPE_CHARS;
	};


template<typename T>
constexpr static auto NodeTypeToEnum_v = ::DLDL_IMPORT::ast::relation::NodeTypeToEnum<T>::value;

template<typename T>
using NodeTypeToEnum_t = typename ::DLDL_IMPORT::ast::relation::NodeTypeToEnum<T>::type;

}}}

#endif // DLDL_IMPORT_AST_RELATION_NODETYPETOENUM_H