#ifndef DLDL_VALUE_AST_NODE_VALUE_RULE_H
#define DLDL_VALUE_AST_NODE_VALUE_RULE_H

#include "DLDL_VALUE/Ast/Node/DLDL_VALUE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_VALUE { namespace ast { namespace node {

	class VALUE_RULE : public DLDL_VALUE<VALUE_RULE>
	{
	private:
	public:
		VALUE_RULE(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_VALUE<VALUE_RULE>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_VALUE_AST_NODE_VALUE_RULE_H
