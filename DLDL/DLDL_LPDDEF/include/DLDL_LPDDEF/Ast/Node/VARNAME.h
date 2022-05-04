#ifndef DLDL_LPDDEF_AST_NODE_VARNAME_H
#define DLDL_LPDDEF_AST_NODE_VARNAME_H

#include "DLDL_LPDDEF/Ast/Node/DLDL_LPDDEF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF { namespace ast { namespace node {

	class VARNAME : public DLDL_LPDDEF<VARNAME>
	{
	private:
	public:
		VARNAME(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LPDDEF<VARNAME>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_AST_NODE_VARNAME_H
