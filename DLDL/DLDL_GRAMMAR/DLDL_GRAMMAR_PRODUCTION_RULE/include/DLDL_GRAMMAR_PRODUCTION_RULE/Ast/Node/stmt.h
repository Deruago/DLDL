#ifndef DLDL_GRAMMAR_PRODUCTION_RULE_AST_NODE_stmt_H
#define DLDL_GRAMMAR_PRODUCTION_RULE_AST_NODE_stmt_H

#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/DLDL_GRAMMAR_PRODUCTION_RULE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GRAMMAR_PRODUCTION_RULE { namespace ast { namespace node { 

	class stmt : public DLDL_GRAMMAR_PRODUCTION_RULE<stmt>
	{
	private:
	public:
		stmt(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_GRAMMAR_PRODUCTION_RULE<stmt>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_GRAMMAR_PRODUCTION_RULE_AST_NODE_stmt_H
