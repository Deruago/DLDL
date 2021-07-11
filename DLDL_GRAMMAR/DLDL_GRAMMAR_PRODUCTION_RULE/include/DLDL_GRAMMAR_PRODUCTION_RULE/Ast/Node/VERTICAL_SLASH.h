#ifndef DLDL_GRAMMAR_PRODUCTION_RULE_AST_NODE_VERTICAL_SLASH_H
#define DLDL_GRAMMAR_PRODUCTION_RULE_AST_NODE_VERTICAL_SLASH_H

#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/DLDL_GRAMMAR_PRODUCTION_RULE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GRAMMAR_PRODUCTION_RULE { namespace ast { namespace node {

	class VERTICAL_SLASH : public DLDL_GRAMMAR_PRODUCTION_RULE<VERTICAL_SLASH>
	{
	private:
	public:
		VERTICAL_SLASH(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_GRAMMAR_PRODUCTION_RULE<VERTICAL_SLASH>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_GRAMMAR_PRODUCTION_RULE_AST_NODE_VERTICAL_SLASH_H
