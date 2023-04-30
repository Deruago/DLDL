#ifndef DLDL_ARGUMENT_AST_RELATION_NODETYPETOENUM_H
#define DLDL_ARGUMENT_AST_RELATION_NODETYPETOENUM_H

#include "DLDL_ARGUMENT/Ast/Enum/Type.h"

namespace DLDL_ARGUMENT { namespace ast { namespace node {

class program;
class SINGLE_COMMENT;
class MULTI_COMMENT;
class TEXT;
class VARNAME;
class ESCAPE_CHARS;

}}}

namespace DLDL_ARGUMENT { namespace ast { namespace relation { 

	template<typename T>
	struct NodeTypeToEnum
	{
		constexpr static auto value = ::DLDL_ARGUMENT::ast::Type::deamerreserved_unknown;
		using type = void;
	};


	template<>
	struct NodeTypeToEnum<::DLDL_ARGUMENT::ast::node::program>
	{
		constexpr static auto value = ::DLDL_ARGUMENT::ast::Type::program;
		using type = ::DLDL_ARGUMENT::ast::node::program;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_ARGUMENT::ast::node::SINGLE_COMMENT>
	{
		constexpr static auto value = ::DLDL_ARGUMENT::ast::Type::SINGLE_COMMENT;
		using type = ::DLDL_ARGUMENT::ast::node::SINGLE_COMMENT;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_ARGUMENT::ast::node::MULTI_COMMENT>
	{
		constexpr static auto value = ::DLDL_ARGUMENT::ast::Type::MULTI_COMMENT;
		using type = ::DLDL_ARGUMENT::ast::node::MULTI_COMMENT;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_ARGUMENT::ast::node::TEXT>
	{
		constexpr static auto value = ::DLDL_ARGUMENT::ast::Type::TEXT;
		using type = ::DLDL_ARGUMENT::ast::node::TEXT;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_ARGUMENT::ast::node::VARNAME>
	{
		constexpr static auto value = ::DLDL_ARGUMENT::ast::Type::VARNAME;
		using type = ::DLDL_ARGUMENT::ast::node::VARNAME;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_ARGUMENT::ast::node::ESCAPE_CHARS>
	{
		constexpr static auto value = ::DLDL_ARGUMENT::ast::Type::ESCAPE_CHARS;
		using type = ::DLDL_ARGUMENT::ast::node::ESCAPE_CHARS;
	};


template<typename T>
constexpr static auto NodeTypeToEnum_v = ::DLDL_ARGUMENT::ast::relation::NodeTypeToEnum<T>::value;

template<typename T>
using NodeTypeToEnum_t = typename ::DLDL_ARGUMENT::ast::relation::NodeTypeToEnum<T>::type;

}}}

#endif // DLDL_ARGUMENT_AST_RELATION_NODETYPETOENUM_H