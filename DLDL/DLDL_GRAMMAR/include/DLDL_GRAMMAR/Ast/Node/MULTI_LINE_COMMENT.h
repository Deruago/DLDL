#ifndef DLDL_GRAMMAR_AST_NODE_MULTI_LINE_COMMENT_H
#define DLDL_GRAMMAR_AST_NODE_MULTI_LINE_COMMENT_H

#include "DLDL_GRAMMAR/Ast/Node/DLDL_GRAMMAR.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GRAMMAR { namespace ast { namespace node {

	class MULTI_LINE_COMMENT : public DLDL_GRAMMAR<MULTI_LINE_COMMENT>
	{
	private:
	public:
		MULTI_LINE_COMMENT(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_GRAMMAR<MULTI_LINE_COMMENT>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_GRAMMAR_AST_NODE_MULTI_LINE_COMMENT_H
