#ifndef DLDL_OOPSYNTAX_AST_NODE_DOT_H
#define DLDL_OOPSYNTAX_AST_NODE_DOT_H

#include "DLDL_OOPSYNTAX/Ast/Node/DLDL_OOPSYNTAX.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_OOPSYNTAX { namespace ast { namespace node {

	class DOT : public DLDL_OOPSYNTAX<DOT>
	{
	private:
	public:
		DOT(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_OOPSYNTAX<DOT>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_OOPSYNTAX_AST_NODE_DOT_H
