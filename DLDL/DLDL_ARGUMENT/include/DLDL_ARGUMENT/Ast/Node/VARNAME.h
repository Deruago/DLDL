#ifndef DLDL_ARGUMENT_AST_NODE_VARNAME_H
#define DLDL_ARGUMENT_AST_NODE_VARNAME_H

#include "DLDL_ARGUMENT/Ast/Node/DLDL_ARGUMENT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_ARGUMENT { namespace ast { namespace node {

	class VARNAME : public DLDL_ARGUMENT<VARNAME>
	{
	private:
	public:
		VARNAME(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_ARGUMENT<VARNAME>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_ARGUMENT_AST_NODE_VARNAME_H
