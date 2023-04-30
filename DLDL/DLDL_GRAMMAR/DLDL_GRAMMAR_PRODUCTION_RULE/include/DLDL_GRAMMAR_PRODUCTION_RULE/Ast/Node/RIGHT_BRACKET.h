#ifndef DLDL_GRAMMAR_PRODUCTION_RULE_AST_NODE_RIGHT_BRACKET_H
#define DLDL_GRAMMAR_PRODUCTION_RULE_AST_NODE_RIGHT_BRACKET_H

#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/DLDL_GRAMMAR_PRODUCTION_RULE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GRAMMAR_PRODUCTION_RULE { namespace ast { namespace node {

	class RIGHT_BRACKET : public DLDL_GRAMMAR_PRODUCTION_RULE<RIGHT_BRACKET>
	{
	private:
	public:
		RIGHT_BRACKET(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_GRAMMAR_PRODUCTION_RULE<RIGHT_BRACKET>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_GRAMMAR_PRODUCTION_RULE_AST_NODE_RIGHT_BRACKET_H
