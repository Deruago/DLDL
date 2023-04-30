#ifndef DLDL_OOPSYNTAX_AST_NODE_STAR_H
#define DLDL_OOPSYNTAX_AST_NODE_STAR_H

#include "DLDL_OOPSYNTAX/Ast/Node/DLDL_OOPSYNTAX.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_OOPSYNTAX { namespace ast { namespace node {

	class STAR : public DLDL_OOPSYNTAX<STAR>
	{
	private:
	public:
		STAR(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_OOPSYNTAX<STAR>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_OOPSYNTAX_AST_NODE_STAR_H
