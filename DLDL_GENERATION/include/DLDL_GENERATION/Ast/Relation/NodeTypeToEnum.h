#ifndef DLDL_GENERATION_AST_RELATION_NODETYPETOENUM_H
#define DLDL_GENERATION_AST_RELATION_NODETYPETOENUM_H

#include "DLDL_GENERATION/Ast/Enum/Type.h"

namespace DLDL_GENERATION { namespace ast { namespace node {

class program;
class stmts;
class stmt;
class generate_declaration;
class integrate_declaration;
class argument_declaration;
class type;
class tool;
class argument_data;
class GENERATE;
class INTEGRATE;
class ARGUMENT;
class VALUE;
class SYMBOLS;
class ESCAPE_CHARS;

}}}

namespace DLDL_GENERATION { namespace ast { namespace relation { 

	template<typename T>
	struct NodeTypeToEnum
	{
		constexpr static auto value = ::DLDL_GENERATION::ast::Type::deamerreserved_unknown;
		using type = void;
	};


	template<>
	struct NodeTypeToEnum<::DLDL_GENERATION::ast::node::program>
	{
		constexpr static auto value = ::DLDL_GENERATION::ast::Type::program;
		using type = ::DLDL_GENERATION::ast::node::program;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GENERATION::ast::node::stmts>
	{
		constexpr static auto value = ::DLDL_GENERATION::ast::Type::stmts;
		using type = ::DLDL_GENERATION::ast::node::stmts;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GENERATION::ast::node::stmt>
	{
		constexpr static auto value = ::DLDL_GENERATION::ast::Type::stmt;
		using type = ::DLDL_GENERATION::ast::node::stmt;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GENERATION::ast::node::generate_declaration>
	{
		constexpr static auto value = ::DLDL_GENERATION::ast::Type::generate_declaration;
		using type = ::DLDL_GENERATION::ast::node::generate_declaration;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GENERATION::ast::node::integrate_declaration>
	{
		constexpr static auto value = ::DLDL_GENERATION::ast::Type::integrate_declaration;
		using type = ::DLDL_GENERATION::ast::node::integrate_declaration;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GENERATION::ast::node::argument_declaration>
	{
		constexpr static auto value = ::DLDL_GENERATION::ast::Type::argument_declaration;
		using type = ::DLDL_GENERATION::ast::node::argument_declaration;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GENERATION::ast::node::type>
	{
		constexpr static auto value = ::DLDL_GENERATION::ast::Type::type;
		using type = ::DLDL_GENERATION::ast::node::type;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GENERATION::ast::node::tool>
	{
		constexpr static auto value = ::DLDL_GENERATION::ast::Type::tool;
		using type = ::DLDL_GENERATION::ast::node::tool;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GENERATION::ast::node::argument_data>
	{
		constexpr static auto value = ::DLDL_GENERATION::ast::Type::argument_data;
		using type = ::DLDL_GENERATION::ast::node::argument_data;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GENERATION::ast::node::GENERATE>
	{
		constexpr static auto value = ::DLDL_GENERATION::ast::Type::GENERATE;
		using type = ::DLDL_GENERATION::ast::node::GENERATE;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GENERATION::ast::node::INTEGRATE>
	{
		constexpr static auto value = ::DLDL_GENERATION::ast::Type::INTEGRATE;
		using type = ::DLDL_GENERATION::ast::node::INTEGRATE;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GENERATION::ast::node::ARGUMENT>
	{
		constexpr static auto value = ::DLDL_GENERATION::ast::Type::ARGUMENT;
		using type = ::DLDL_GENERATION::ast::node::ARGUMENT;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GENERATION::ast::node::VALUE>
	{
		constexpr static auto value = ::DLDL_GENERATION::ast::Type::VALUE;
		using type = ::DLDL_GENERATION::ast::node::VALUE;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GENERATION::ast::node::SYMBOLS>
	{
		constexpr static auto value = ::DLDL_GENERATION::ast::Type::SYMBOLS;
		using type = ::DLDL_GENERATION::ast::node::SYMBOLS;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GENERATION::ast::node::ESCAPE_CHARS>
	{
		constexpr static auto value = ::DLDL_GENERATION::ast::Type::ESCAPE_CHARS;
		using type = ::DLDL_GENERATION::ast::node::ESCAPE_CHARS;
	};


template<typename T>
constexpr static auto NodeTypeToEnum_v = ::DLDL_GENERATION::ast::relation::NodeTypeToEnum<T>::value;

template<typename T>
using NodeTypeToEnum_t = typename ::DLDL_GENERATION::ast::relation::NodeTypeToEnum<T>::type;

}}}

#endif // DLDL_GENERATION_AST_RELATION_NODETYPETOENUM_H