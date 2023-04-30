#ifndef DLDL_GRAMMAR_PRODUCTION_RULE_AST_NODE_nested_group_H
#define DLDL_GRAMMAR_PRODUCTION_RULE_AST_NODE_nested_group_H

#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/DLDL_GRAMMAR_PRODUCTION_RULE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GRAMMAR_PRODUCTION_RULE { namespace ast { namespace node { 

	class nested_group : public DLDL_GRAMMAR_PRODUCTION_RULE<nested_group>
	{
	private:
	public:
		nested_group(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_GRAMMAR_PRODUCTION_RULE<nested_group>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_GRAMMAR_PRODUCTION_RULE_AST_NODE_nested_group_H
