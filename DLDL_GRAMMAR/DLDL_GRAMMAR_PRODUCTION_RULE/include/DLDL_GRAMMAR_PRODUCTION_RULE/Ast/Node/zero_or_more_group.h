#ifndef DLDL_GRAMMAR_PRODUCTION_RULE_AST_NODE_zero_or_more_group_H
#define DLDL_GRAMMAR_PRODUCTION_RULE_AST_NODE_zero_or_more_group_H

#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/DLDL_GRAMMAR_PRODUCTION_RULE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GRAMMAR_PRODUCTION_RULE { namespace ast { namespace node { 

	class zero_or_more_group : public DLDL_GRAMMAR_PRODUCTION_RULE<zero_or_more_group>
	{
	private:
	public:
		zero_or_more_group(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_GRAMMAR_PRODUCTION_RULE<zero_or_more_group>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_GRAMMAR_PRODUCTION_RULE_AST_NODE_zero_or_more_group_H
