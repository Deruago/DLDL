#ifndef DLDL_ASSOCIATIVITY_AST_RELATION_NODEENUMTOTYPE_H
#define DLDL_ASSOCIATIVITY_AST_RELATION_NODEENUMTOTYPE_H

#include "DLDL_ASSOCIATIVITY/Ast/Enum/Type.h"

#include "DLDL_ASSOCIATIVITY/Ast/Node/program.h"
#include "DLDL_ASSOCIATIVITY/Ast/Node/stmts.h"
#include "DLDL_ASSOCIATIVITY/Ast/Node/stmt.h"
#include "DLDL_ASSOCIATIVITY/Ast/Node/ASSOCIATIVITY.h"


namespace DLDL_ASSOCIATIVITY { namespace ast { namespace relation { 

	template<::DLDL_ASSOCIATIVITY::ast::Type T>
	struct NodeEnumToType
	{
		constexpr static auto value = T;
		using type = void;
	};


	template<>
	struct NodeEnumToType<::DLDL_ASSOCIATIVITY::ast::Type::program>
	{
		constexpr static auto value = ::DLDL_ASSOCIATIVITY::ast::Type::program;
		using type = ::DLDL_ASSOCIATIVITY::ast::node::program;
	};

	template<>
	struct NodeEnumToType<::DLDL_ASSOCIATIVITY::ast::Type::stmts>
	{
		constexpr static auto value = ::DLDL_ASSOCIATIVITY::ast::Type::stmts;
		using type = ::DLDL_ASSOCIATIVITY::ast::node::stmts;
	};

	template<>
	struct NodeEnumToType<::DLDL_ASSOCIATIVITY::ast::Type::stmt>
	{
		constexpr static auto value = ::DLDL_ASSOCIATIVITY::ast::Type::stmt;
		using type = ::DLDL_ASSOCIATIVITY::ast::node::stmt;
	};

	template<>
	struct NodeEnumToType<::DLDL_ASSOCIATIVITY::ast::Type::ASSOCIATIVITY>
	{
		constexpr static auto value = ::DLDL_ASSOCIATIVITY::ast::Type::ASSOCIATIVITY;
		using type = ::DLDL_ASSOCIATIVITY::ast::node::ASSOCIATIVITY;
	};


template<::DLDL_ASSOCIATIVITY::ast::Type T>
constexpr static auto NodeEnumToType_v = ::DLDL_ASSOCIATIVITY::ast::relation::NodeEnumToType<T>::value;

template<::DLDL_ASSOCIATIVITY::ast::Type T>
using NodeEnumToType_t = typename ::DLDL_ASSOCIATIVITY::ast::relation::NodeEnumToType<T>::type;

}}}

#endif // DLDL_ASSOCIATIVITY_AST_RELATION_NODEENUMTOTYPE_H