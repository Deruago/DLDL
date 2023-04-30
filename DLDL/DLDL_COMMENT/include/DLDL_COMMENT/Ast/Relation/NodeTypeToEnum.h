#ifndef DLDL_COMMENT_AST_RELATION_NODETYPETOENUM_H
#define DLDL_COMMENT_AST_RELATION_NODETYPETOENUM_H

#include "DLDL_COMMENT/Ast/Enum/Type.h"

namespace DLDL_COMMENT { namespace ast { namespace node {

class program;
class deamerreserved_star__stmt__;
class stmt;
class comment_value_declaration;
class deamerreserved_long_3;
class deamerreserved_long_6;
class comment_abstraction;
class start_abstraction;
class end_abstraction;
class start_sequence;
class end_sequence;
class sequence;
class syntactic_reference;
class SINGLE_COMMENT;
class MULTI_COMMENT;
class COMMENT_VALUE;
class LEFT_SQUARE_BRACKET;
class RIGHT_SQUARE_BRACKET;
class START;
class END;
class TEXT;
class VARNAME;
class ESCAPE_CHARS;

}}}

namespace DLDL_COMMENT { namespace ast { namespace relation { 

	template<typename T>
	struct NodeTypeToEnum
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::deamerreserved_unknown;
		using type = void;
	};


	template<>
	struct NodeTypeToEnum<::DLDL_COMMENT::ast::node::program>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::program;
		using type = ::DLDL_COMMENT::ast::node::program;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_COMMENT::ast::node::deamerreserved_star__stmt__>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::deamerreserved_star__stmt__;
		using type = ::DLDL_COMMENT::ast::node::deamerreserved_star__stmt__;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_COMMENT::ast::node::stmt>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::stmt;
		using type = ::DLDL_COMMENT::ast::node::stmt;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_COMMENT::ast::node::comment_value_declaration>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::comment_value_declaration;
		using type = ::DLDL_COMMENT::ast::node::comment_value_declaration;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_COMMENT::ast::node::deamerreserved_long_3>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::deamerreserved_long_3;
		using type = ::DLDL_COMMENT::ast::node::deamerreserved_long_3;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_COMMENT::ast::node::deamerreserved_long_6>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::deamerreserved_long_6;
		using type = ::DLDL_COMMENT::ast::node::deamerreserved_long_6;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_COMMENT::ast::node::comment_abstraction>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::comment_abstraction;
		using type = ::DLDL_COMMENT::ast::node::comment_abstraction;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_COMMENT::ast::node::start_abstraction>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::start_abstraction;
		using type = ::DLDL_COMMENT::ast::node::start_abstraction;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_COMMENT::ast::node::end_abstraction>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::end_abstraction;
		using type = ::DLDL_COMMENT::ast::node::end_abstraction;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_COMMENT::ast::node::start_sequence>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::start_sequence;
		using type = ::DLDL_COMMENT::ast::node::start_sequence;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_COMMENT::ast::node::end_sequence>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::end_sequence;
		using type = ::DLDL_COMMENT::ast::node::end_sequence;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_COMMENT::ast::node::sequence>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::sequence;
		using type = ::DLDL_COMMENT::ast::node::sequence;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_COMMENT::ast::node::syntactic_reference>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::syntactic_reference;
		using type = ::DLDL_COMMENT::ast::node::syntactic_reference;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_COMMENT::ast::node::SINGLE_COMMENT>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::SINGLE_COMMENT;
		using type = ::DLDL_COMMENT::ast::node::SINGLE_COMMENT;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_COMMENT::ast::node::MULTI_COMMENT>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::MULTI_COMMENT;
		using type = ::DLDL_COMMENT::ast::node::MULTI_COMMENT;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_COMMENT::ast::node::COMMENT_VALUE>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::COMMENT_VALUE;
		using type = ::DLDL_COMMENT::ast::node::COMMENT_VALUE;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_COMMENT::ast::node::LEFT_SQUARE_BRACKET>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::LEFT_SQUARE_BRACKET;
		using type = ::DLDL_COMMENT::ast::node::LEFT_SQUARE_BRACKET;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_COMMENT::ast::node::RIGHT_SQUARE_BRACKET>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::RIGHT_SQUARE_BRACKET;
		using type = ::DLDL_COMMENT::ast::node::RIGHT_SQUARE_BRACKET;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_COMMENT::ast::node::START>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::START;
		using type = ::DLDL_COMMENT::ast::node::START;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_COMMENT::ast::node::END>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::END;
		using type = ::DLDL_COMMENT::ast::node::END;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_COMMENT::ast::node::TEXT>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::TEXT;
		using type = ::DLDL_COMMENT::ast::node::TEXT;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_COMMENT::ast::node::VARNAME>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::VARNAME;
		using type = ::DLDL_COMMENT::ast::node::VARNAME;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_COMMENT::ast::node::ESCAPE_CHARS>
	{
		constexpr static auto value = ::DLDL_COMMENT::ast::Type::ESCAPE_CHARS;
		using type = ::DLDL_COMMENT::ast::node::ESCAPE_CHARS;
	};


template<typename T>
constexpr static auto NodeTypeToEnum_v = ::DLDL_COMMENT::ast::relation::NodeTypeToEnum<T>::value;

template<typename T>
using NodeTypeToEnum_t = typename ::DLDL_COMMENT::ast::relation::NodeTypeToEnum<T>::type;

}}}

#endif // DLDL_COMMENT_AST_RELATION_NODETYPETOENUM_H