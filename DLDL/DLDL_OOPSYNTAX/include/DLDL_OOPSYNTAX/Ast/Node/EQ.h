#ifndef DLDL_OOPSYNTAX_AST_NODE_EQ_H
#define DLDL_OOPSYNTAX_AST_NODE_EQ_H

#include "DLDL_OOPSYNTAX/Ast/Node/DLDL_OOPSYNTAX.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_OOPSYNTAX { namespace ast { namespace node {

	class EQ : public DLDL_OOPSYNTAX<EQ>
	{
	private:
	public:
		EQ(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_OOPSYNTAX<EQ>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_OOPSYNTAX_AST_NODE_EQ_H
