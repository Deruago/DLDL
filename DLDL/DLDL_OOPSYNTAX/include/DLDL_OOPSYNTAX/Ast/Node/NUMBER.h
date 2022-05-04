#ifndef DLDL_OOPSYNTAX_AST_NODE_NUMBER_H
#define DLDL_OOPSYNTAX_AST_NODE_NUMBER_H

#include "DLDL_OOPSYNTAX/Ast/Node/DLDL_OOPSYNTAX.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_OOPSYNTAX { namespace ast { namespace node {

	class NUMBER : public DLDL_OOPSYNTAX<NUMBER>
	{
	private:
	public:
		NUMBER(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_OOPSYNTAX<NUMBER>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_OOPSYNTAX_AST_NODE_NUMBER_H
