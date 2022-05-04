#ifndef DLDL_GRAMMAR_PRODUCTION_RULE_AST_NODE_LEFT_BRACKET_H
#define DLDL_GRAMMAR_PRODUCTION_RULE_AST_NODE_LEFT_BRACKET_H

#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/DLDL_GRAMMAR_PRODUCTION_RULE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GRAMMAR_PRODUCTION_RULE { namespace ast { namespace node {

	class LEFT_BRACKET : public DLDL_GRAMMAR_PRODUCTION_RULE<LEFT_BRACKET>
	{
	private:
	public:
		LEFT_BRACKET(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_GRAMMAR_PRODUCTION_RULE<LEFT_BRACKET>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_GRAMMAR_PRODUCTION_RULE_AST_NODE_LEFT_BRACKET_H
