#ifndef DLDL_GRAMMAR_PRODUCTION_RULE_AST_NODE_PLUS_H
#define DLDL_GRAMMAR_PRODUCTION_RULE_AST_NODE_PLUS_H

#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/DLDL_GRAMMAR_PRODUCTION_RULE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GRAMMAR_PRODUCTION_RULE { namespace ast { namespace node {

	class PLUS : public DLDL_GRAMMAR_PRODUCTION_RULE<PLUS>
	{
	private:
	public:
		PLUS(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_GRAMMAR_PRODUCTION_RULE<PLUS>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_GRAMMAR_PRODUCTION_RULE_AST_NODE_PLUS_H
