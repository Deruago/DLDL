#ifndef DLDL_IDENTITY_AST_RELATION_NODETYPETOENUM_H
#define DLDL_IDENTITY_AST_RELATION_NODETYPETOENUM_H

#include "DLDL_IDENTITY/Ast/Enum/Type.h"

namespace DLDL_IDENTITY { namespace ast { namespace node {

class program;
class stmts;
class stmt;
class name_declaration;
class NAME;
class VALUE;
class SYMBOLS;
class ESCAPE_CHARS;

}}}

namespace DLDL_IDENTITY { namespace ast { namespace relation { 

	template<typename T>
	struct NodeTypeToEnum
	{
		constexpr static auto value = ::DLDL_IDENTITY::ast::Type::deamerreserved_unknown;
		using type = void;
	};


	template<>
	struct NodeTypeToEnum<::DLDL_IDENTITY::ast::node::program>
	{
		constexpr static auto value = ::DLDL_IDENTITY::ast::Type::program;
		using type = ::DLDL_IDENTITY::ast::node::program;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_IDENTITY::ast::node::stmts>
	{
		constexpr static auto value = ::DLDL_IDENTITY::ast::Type::stmts;
		using type = ::DLDL_IDENTITY::ast::node::stmts;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_IDENTITY::ast::node::stmt>
	{
		constexpr static auto value = ::DLDL_IDENTITY::ast::Type::stmt;
		using type = ::DLDL_IDENTITY::ast::node::stmt;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_IDENTITY::ast::node::name_declaration>
	{
		constexpr static auto value = ::DLDL_IDENTITY::ast::Type::name_declaration;
		using type = ::DLDL_IDENTITY::ast::node::name_declaration;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_IDENTITY::ast::node::NAME>
	{
		constexpr static auto value = ::DLDL_IDENTITY::ast::Type::NAME;
		using type = ::DLDL_IDENTITY::ast::node::NAME;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_IDENTITY::ast::node::VALUE>
	{
		constexpr static auto value = ::DLDL_IDENTITY::ast::Type::VALUE;
		using type = ::DLDL_IDENTITY::ast::node::VALUE;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_IDENTITY::ast::node::SYMBOLS>
	{
		constexpr static auto value = ::DLDL_IDENTITY::ast::Type::SYMBOLS;
		using type = ::DLDL_IDENTITY::ast::node::SYMBOLS;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_IDENTITY::ast::node::ESCAPE_CHARS>
	{
		constexpr static auto value = ::DLDL_IDENTITY::ast::Type::ESCAPE_CHARS;
		using type = ::DLDL_IDENTITY::ast::node::ESCAPE_CHARS;
	};


template<typename T>
constexpr static auto NodeTypeToEnum_v = ::DLDL_IDENTITY::ast::relation::NodeTypeToEnum<T>::value;

template<typename T>
using NodeTypeToEnum_t = typename ::DLDL_IDENTITY::ast::relation::NodeTypeToEnum<T>::type;

}}}

#endif // DLDL_IDENTITY_AST_RELATION_NODETYPETOENUM_H