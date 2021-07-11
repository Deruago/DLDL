#ifndef DLDL_GRAMMAR_AST_NODE_PRODUCTION_RULE_H
#define DLDL_GRAMMAR_AST_NODE_PRODUCTION_RULE_H

#include "DLDL_GRAMMAR/Ast/Node/DLDL_GRAMMAR.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GRAMMAR { namespace ast { namespace node {

	class PRODUCTION_RULE : public DLDL_GRAMMAR<PRODUCTION_RULE>
	{
	private:
	public:
		PRODUCTION_RULE(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_GRAMMAR<PRODUCTION_RULE>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_GRAMMAR_AST_NODE_PRODUCTION_RULE_H
