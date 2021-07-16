#ifndef DLDL_AST_RELATION_NODETYPETOENUM_H
#define DLDL_AST_RELATION_NODETYPETOENUM_H

#include "DLDL/Ast/Enum/Type.h"

namespace DLDL { namespace ast { namespace node {

class program;
class stmts;
class stmt;
class ANY;

}}}

namespace DLDL { namespace ast { namespace relation { 

	template<typename T>
	struct NodeTypeToEnum
	{
		constexpr static auto value = ::DLDL::ast::Type::deamerreserved_unknown;
		using type = void;
	};


	template<>
	struct NodeTypeToEnum<::DLDL::ast::node::program>
	{
		constexpr static auto value = ::DLDL::ast::Type::program;
		using type = ::DLDL::ast::node::program;
	};

	template<>
	struct NodeTypeToEnum<::DLDL::ast::node::stmts>
	{
		constexpr static auto value = ::DLDL::ast::Type::stmts;
		using type = ::DLDL::ast::node::stmts;
	};

	template<>
	struct NodeTypeToEnum<::DLDL::ast::node::stmt>
	{
		constexpr static auto value = ::DLDL::ast::Type::stmt;
		using type = ::DLDL::ast::node::stmt;
	};

	template<>
	struct NodeTypeToEnum<::DLDL::ast::node::ANY>
	{
		constexpr static auto value = ::DLDL::ast::Type::ANY;
		using type = ::DLDL::ast::node::ANY;
	};


template<typename T>
constexpr static auto NodeTypeToEnum_v = ::DLDL::ast::relation::NodeTypeToEnum<T>::value;

template<typename T>
using NodeTypeToEnum_t = typename ::DLDL::ast::relation::NodeTypeToEnum<T>::type;

}}}

#endif // DLDL_AST_RELATION_NODETYPETOENUM_H