#ifndef DLDL_ASSOCIATIVITY_AST_RELATION_NODETYPETOENUM_H
#define DLDL_ASSOCIATIVITY_AST_RELATION_NODETYPETOENUM_H

#include "DLDL_ASSOCIATIVITY/Ast/Enum/Type.h"

namespace DLDL_ASSOCIATIVITY { namespace ast { namespace node {

class program;
class stmts;
class stmt;
class ASSOCIATIVITY;

}}}

namespace DLDL_ASSOCIATIVITY { namespace ast { namespace relation { 

	template<typename T>
	struct NodeTypeToEnum
	{
		constexpr static auto value = ::DLDL_ASSOCIATIVITY::ast::Type::deamerreserved_unknown;
		using type = void;
	};


	template<>
	struct NodeTypeToEnum<::DLDL_ASSOCIATIVITY::ast::node::program>
	{
		constexpr static auto value = ::DLDL_ASSOCIATIVITY::ast::Type::program;
		using type = ::DLDL_ASSOCIATIVITY::ast::node::program;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_ASSOCIATIVITY::ast::node::stmts>
	{
		constexpr static auto value = ::DLDL_ASSOCIATIVITY::ast::Type::stmts;
		using type = ::DLDL_ASSOCIATIVITY::ast::node::stmts;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_ASSOCIATIVITY::ast::node::stmt>
	{
		constexpr static auto value = ::DLDL_ASSOCIATIVITY::ast::Type::stmt;
		using type = ::DLDL_ASSOCIATIVITY::ast::node::stmt;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_ASSOCIATIVITY::ast::node::ASSOCIATIVITY>
	{
		constexpr static auto value = ::DLDL_ASSOCIATIVITY::ast::Type::ASSOCIATIVITY;
		using type = ::DLDL_ASSOCIATIVITY::ast::node::ASSOCIATIVITY;
	};


template<typename T>
constexpr static auto NodeTypeToEnum_v = ::DLDL_ASSOCIATIVITY::ast::relation::NodeTypeToEnum<T>::value;

template<typename T>
using NodeTypeToEnum_t = typename ::DLDL_ASSOCIATIVITY::ast::relation::NodeTypeToEnum<T>::type;

}}}

#endif // DLDL_ASSOCIATIVITY_AST_RELATION_NODETYPETOENUM_H