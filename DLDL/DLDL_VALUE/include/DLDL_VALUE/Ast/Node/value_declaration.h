#ifndef DLDL_VALUE_AST_NODE_value_declaration_H
#define DLDL_VALUE_AST_NODE_value_declaration_H

#include "DLDL_VALUE/Ast/Node/DLDL_VALUE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_VALUE { namespace ast { namespace node { 

	class value_declaration : public DLDL_VALUE<value_declaration>
	{
	private:
	public:
		value_declaration(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_VALUE<value_declaration>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_VALUE_AST_NODE_value_declaration_H
