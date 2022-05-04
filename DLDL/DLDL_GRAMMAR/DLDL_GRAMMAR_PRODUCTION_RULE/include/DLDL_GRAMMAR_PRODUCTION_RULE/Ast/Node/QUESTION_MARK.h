#ifndef DLDL_GRAMMAR_PRODUCTION_RULE_AST_NODE_QUESTION_MARK_H
#define DLDL_GRAMMAR_PRODUCTION_RULE_AST_NODE_QUESTION_MARK_H

#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/DLDL_GRAMMAR_PRODUCTION_RULE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GRAMMAR_PRODUCTION_RULE { namespace ast { namespace node {

	class QUESTION_MARK : public DLDL_GRAMMAR_PRODUCTION_RULE<QUESTION_MARK>
	{
	private:
	public:
		QUESTION_MARK(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_GRAMMAR_PRODUCTION_RULE<QUESTION_MARK>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_GRAMMAR_PRODUCTION_RULE_AST_NODE_QUESTION_MARK_H
