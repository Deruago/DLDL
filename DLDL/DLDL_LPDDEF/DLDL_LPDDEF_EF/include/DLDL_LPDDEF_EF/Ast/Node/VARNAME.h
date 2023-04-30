#ifndef DLDL_LPDDEF_EF_AST_NODE_VARNAME_H
#define DLDL_LPDDEF_EF_AST_NODE_VARNAME_H

#include "DLDL_LPDDEF_EF/Ast/Node/DLDL_LPDDEF_EF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF_EF { namespace ast { namespace node {

	class VARNAME : public DLDL_LPDDEF_EF<VARNAME>
	{
	private:
	public:
		VARNAME(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LPDDEF_EF<VARNAME>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_EF_AST_NODE_VARNAME_H
