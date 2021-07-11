#ifndef DLDL_GRAMMAR_AST_NODE_COMMENT_H
#define DLDL_GRAMMAR_AST_NODE_COMMENT_H

#include "DLDL_GRAMMAR/Ast/Node/DLDL_GRAMMAR.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GRAMMAR { namespace ast { namespace node {

	class COMMENT : public DLDL_GRAMMAR<COMMENT>
	{
	private:
	public:
		COMMENT(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_GRAMMAR<COMMENT>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_GRAMMAR_AST_NODE_COMMENT_H
