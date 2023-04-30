#ifndef DLDL_GRAMMAR_AST_RELATION_NODETYPETOENUM_H
#define DLDL_GRAMMAR_AST_RELATION_NODETYPETOENUM_H

#include "DLDL_GRAMMAR/Ast/Enum/Type.h"

namespace DLDL_GRAMMAR { namespace ast { namespace node {

class program;
class stmts;
class stmt;
class abstraction_declaration;
class abstraction;
class definition;
class production_rules;
class COMMENT;
class START_ABSTRACTION;
class GROUP_ABSTRACTION;
class INLINE_ABSTRACTION;
class INLINE_GROUP_ABSTRACTION;
class UNKNOWN_ABSTRACTION;
class NONTERMINAL;
class PRODUCTION_RULE;
class ESCAPE_CHARS;

}}}

namespace DLDL_GRAMMAR { namespace ast { namespace relation { 

	template<typename T>
	struct NodeTypeToEnum
	{
		constexpr static auto value = ::DLDL_GRAMMAR::ast::Type::deamerreserved_unknown;
		using type = void;
	};


	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR::ast::node::program>
	{
		constexpr static auto value = ::DLDL_GRAMMAR::ast::Type::program;
		using type = ::DLDL_GRAMMAR::ast::node::program;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR::ast::node::stmts>
	{
		constexpr static auto value = ::DLDL_GRAMMAR::ast::Type::stmts;
		using type = ::DLDL_GRAMMAR::ast::node::stmts;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR::ast::node::stmt>
	{
		constexpr static auto value = ::DLDL_GRAMMAR::ast::Type::stmt;
		using type = ::DLDL_GRAMMAR::ast::node::stmt;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR::ast::node::abstraction_declaration>
	{
		constexpr static auto value = ::DLDL_GRAMMAR::ast::Type::abstraction_declaration;
		using type = ::DLDL_GRAMMAR::ast::node::abstraction_declaration;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR::ast::node::abstraction>
	{
		constexpr static auto value = ::DLDL_GRAMMAR::ast::Type::abstraction;
		using type = ::DLDL_GRAMMAR::ast::node::abstraction;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR::ast::node::definition>
	{
		constexpr static auto value = ::DLDL_GRAMMAR::ast::Type::definition;
		using type = ::DLDL_GRAMMAR::ast::node::definition;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR::ast::node::production_rules>
	{
		constexpr static auto value = ::DLDL_GRAMMAR::ast::Type::production_rules;
		using type = ::DLDL_GRAMMAR::ast::node::production_rules;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR::ast::node::COMMENT>
	{
		constexpr static auto value = ::DLDL_GRAMMAR::ast::Type::COMMENT;
		using type = ::DLDL_GRAMMAR::ast::node::COMMENT;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR::ast::node::START_ABSTRACTION>
	{
		constexpr static auto value = ::DLDL_GRAMMAR::ast::Type::START_ABSTRACTION;
		using type = ::DLDL_GRAMMAR::ast::node::START_ABSTRACTION;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR::ast::node::GROUP_ABSTRACTION>
	{
		constexpr static auto value = ::DLDL_GRAMMAR::ast::Type::GROUP_ABSTRACTION;
		using type = ::DLDL_GRAMMAR::ast::node::GROUP_ABSTRACTION;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR::ast::node::INLINE_ABSTRACTION>
	{
		constexpr static auto value = ::DLDL_GRAMMAR::ast::Type::INLINE_ABSTRACTION;
		using type = ::DLDL_GRAMMAR::ast::node::INLINE_ABSTRACTION;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR::ast::node::INLINE_GROUP_ABSTRACTION>
	{
		constexpr static auto value = ::DLDL_GRAMMAR::ast::Type::INLINE_GROUP_ABSTRACTION;
		using type = ::DLDL_GRAMMAR::ast::node::INLINE_GROUP_ABSTRACTION;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR::ast::node::UNKNOWN_ABSTRACTION>
	{
		constexpr static auto value = ::DLDL_GRAMMAR::ast::Type::UNKNOWN_ABSTRACTION;
		using type = ::DLDL_GRAMMAR::ast::node::UNKNOWN_ABSTRACTION;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR::ast::node::NONTERMINAL>
	{
		constexpr static auto value = ::DLDL_GRAMMAR::ast::Type::NONTERMINAL;
		using type = ::DLDL_GRAMMAR::ast::node::NONTERMINAL;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR::ast::node::PRODUCTION_RULE>
	{
		constexpr static auto value = ::DLDL_GRAMMAR::ast::Type::PRODUCTION_RULE;
		using type = ::DLDL_GRAMMAR::ast::node::PRODUCTION_RULE;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_GRAMMAR::ast::node::ESCAPE_CHARS>
	{
		constexpr static auto value = ::DLDL_GRAMMAR::ast::Type::ESCAPE_CHARS;
		using type = ::DLDL_GRAMMAR::ast::node::ESCAPE_CHARS;
	};


template<typename T>
constexpr static auto NodeTypeToEnum_v = ::DLDL_GRAMMAR::ast::relation::NodeTypeToEnum<T>::value;

template<typename T>
using NodeTypeToEnum_t = typename ::DLDL_GRAMMAR::ast::relation::NodeTypeToEnum<T>::type;

}}}

#endif // DLDL_GRAMMAR_AST_RELATION_NODETYPETOENUM_H