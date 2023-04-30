#ifndef DLDL_VALUE_AST_NODE_value_rule_name_H
#define DLDL_VALUE_AST_NODE_value_rule_name_H

#include "DLDL_VALUE/Ast/Node/DLDL_VALUE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_VALUE { namespace ast { namespace node { 

	class value_rule_name : public DLDL_VALUE<value_rule_name>
	{
	private:
	public:
		value_rule_name(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_VALUE<value_rule_name>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_VALUE_AST_NODE_value_rule_name_H
