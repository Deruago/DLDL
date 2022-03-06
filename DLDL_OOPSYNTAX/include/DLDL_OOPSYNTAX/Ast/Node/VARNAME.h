#ifndef DLDL_OOPSYNTAX_AST_NODE_VARNAME_H
#define DLDL_OOPSYNTAX_AST_NODE_VARNAME_H

#include "DLDL_OOPSYNTAX/Ast/Node/DLDL_OOPSYNTAX.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_OOPSYNTAX { namespace ast { namespace node {

	class VARNAME : public DLDL_OOPSYNTAX<VARNAME>
	{
	private:
	public:
		VARNAME(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_OOPSYNTAX<VARNAME>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_OOPSYNTAX_AST_NODE_VARNAME_H
