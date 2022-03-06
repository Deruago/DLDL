#ifndef DLDL_OOPSYNTAX_AST_NODE_COMMENT_H
#define DLDL_OOPSYNTAX_AST_NODE_COMMENT_H

#include "DLDL_OOPSYNTAX/Ast/Node/DLDL_OOPSYNTAX.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_OOPSYNTAX { namespace ast { namespace node {

	class COMMENT : public DLDL_OOPSYNTAX<COMMENT>
	{
	private:
	public:
		COMMENT(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_OOPSYNTAX<COMMENT>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_OOPSYNTAX_AST_NODE_COMMENT_H
