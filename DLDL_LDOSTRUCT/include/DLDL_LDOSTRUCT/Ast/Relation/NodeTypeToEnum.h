#ifndef DLDL_LDOSTRUCT_AST_RELATION_NODETYPETOENUM_H
#define DLDL_LDOSTRUCT_AST_RELATION_NODETYPETOENUM_H

#include "DLDL_LDOSTRUCT/Ast/Enum/Type.h"

namespace DLDL_LDOSTRUCT { namespace ast { namespace node {

class program;
class deamerreserved_star__stmt__;
class stmt;
class argument;
class argument_name;
class argument_block;
class deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______;
class COLON;
class LEFT_ANGLE_BRACKET;
class RIGHT_ANGLE_BRACKET;
class VARNAME;
class VARNAME_EXT;
class INDENTED_VALUE;
class ESCAPE_CHARS;

}}}

namespace DLDL_LDOSTRUCT { namespace ast { namespace relation { 

	template<typename T>
	struct NodeTypeToEnum
	{
		constexpr static auto value = ::DLDL_LDOSTRUCT::ast::Type::deamerreserved_unknown;
		using type = void;
	};


	template<>
	struct NodeTypeToEnum<::DLDL_LDOSTRUCT::ast::node::program>
	{
		constexpr static auto value = ::DLDL_LDOSTRUCT::ast::Type::program;
		using type = ::DLDL_LDOSTRUCT::ast::node::program;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__stmt__>
	{
		constexpr static auto value = ::DLDL_LDOSTRUCT::ast::Type::deamerreserved_star__stmt__;
		using type = ::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__stmt__;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LDOSTRUCT::ast::node::stmt>
	{
		constexpr static auto value = ::DLDL_LDOSTRUCT::ast::Type::stmt;
		using type = ::DLDL_LDOSTRUCT::ast::node::stmt;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LDOSTRUCT::ast::node::argument>
	{
		constexpr static auto value = ::DLDL_LDOSTRUCT::ast::Type::argument;
		using type = ::DLDL_LDOSTRUCT::ast::node::argument;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LDOSTRUCT::ast::node::argument_name>
	{
		constexpr static auto value = ::DLDL_LDOSTRUCT::ast::Type::argument_name;
		using type = ::DLDL_LDOSTRUCT::ast::node::argument_name;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LDOSTRUCT::ast::node::argument_block>
	{
		constexpr static auto value = ::DLDL_LDOSTRUCT::ast::Type::argument_block;
		using type = ::DLDL_LDOSTRUCT::ast::node::argument_block;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______>
	{
		constexpr static auto value = ::DLDL_LDOSTRUCT::ast::Type::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______;
		using type = ::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__deamerreserved_or__INDENTED_VALUE__deamerreserved_or__VARNAME_EXT__VARNAME______;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LDOSTRUCT::ast::node::COLON>
	{
		constexpr static auto value = ::DLDL_LDOSTRUCT::ast::Type::COLON;
		using type = ::DLDL_LDOSTRUCT::ast::node::COLON;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LDOSTRUCT::ast::node::LEFT_ANGLE_BRACKET>
	{
		constexpr static auto value = ::DLDL_LDOSTRUCT::ast::Type::LEFT_ANGLE_BRACKET;
		using type = ::DLDL_LDOSTRUCT::ast::node::LEFT_ANGLE_BRACKET;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LDOSTRUCT::ast::node::RIGHT_ANGLE_BRACKET>
	{
		constexpr static auto value = ::DLDL_LDOSTRUCT::ast::Type::RIGHT_ANGLE_BRACKET;
		using type = ::DLDL_LDOSTRUCT::ast::node::RIGHT_ANGLE_BRACKET;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LDOSTRUCT::ast::node::VARNAME>
	{
		constexpr static auto value = ::DLDL_LDOSTRUCT::ast::Type::VARNAME;
		using type = ::DLDL_LDOSTRUCT::ast::node::VARNAME;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LDOSTRUCT::ast::node::VARNAME_EXT>
	{
		constexpr static auto value = ::DLDL_LDOSTRUCT::ast::Type::VARNAME_EXT;
		using type = ::DLDL_LDOSTRUCT::ast::node::VARNAME_EXT;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LDOSTRUCT::ast::node::INDENTED_VALUE>
	{
		constexpr static auto value = ::DLDL_LDOSTRUCT::ast::Type::INDENTED_VALUE;
		using type = ::DLDL_LDOSTRUCT::ast::node::INDENTED_VALUE;
	};

	template<>
	struct NodeTypeToEnum<::DLDL_LDOSTRUCT::ast::node::ESCAPE_CHARS>
	{
		constexpr static auto value = ::DLDL_LDOSTRUCT::ast::Type::ESCAPE_CHARS;
		using type = ::DLDL_LDOSTRUCT::ast::node::ESCAPE_CHARS;
	};


template<typename T>
constexpr static auto NodeTypeToEnum_v = ::DLDL_LDOSTRUCT::ast::relation::NodeTypeToEnum<T>::value;

template<typename T>
using NodeTypeToEnum_t = typename ::DLDL_LDOSTRUCT::ast::relation::NodeTypeToEnum<T>::type;

}}}

#endif // DLDL_LDOSTRUCT_AST_RELATION_NODETYPETOENUM_H