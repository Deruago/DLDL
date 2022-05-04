#ifndef DLDL_OOPSYNTAX_AST_NODE_ARROW_H
#define DLDL_OOPSYNTAX_AST_NODE_ARROW_H

#include "DLDL_OOPSYNTAX/Ast/Node/DLDL_OOPSYNTAX.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_OOPSYNTAX { namespace ast { namespace node {

	class ARROW : public DLDL_OOPSYNTAX<ARROW>
	{
	private:
	public:
		ARROW(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_OOPSYNTAX<ARROW>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_OOPSYNTAX_AST_NODE_ARROW_H
