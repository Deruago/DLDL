#ifndef DLDL_GRAMMAR_PRODUCTION_RULE_AST_NODE_MINUS_H
#define DLDL_GRAMMAR_PRODUCTION_RULE_AST_NODE_MINUS_H

#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/DLDL_GRAMMAR_PRODUCTION_RULE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GRAMMAR_PRODUCTION_RULE { namespace ast { namespace node {

	class MINUS : public DLDL_GRAMMAR_PRODUCTION_RULE<MINUS>
	{
	private:
	public:
		MINUS(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_GRAMMAR_PRODUCTION_RULE<MINUS>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_GRAMMAR_PRODUCTION_RULE_AST_NODE_MINUS_H
