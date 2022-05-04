#ifndef DLDL_LPDDEF_AST_NODE_VARNAME_EXT_H
#define DLDL_LPDDEF_AST_NODE_VARNAME_EXT_H

#include "DLDL_LPDDEF/Ast/Node/DLDL_LPDDEF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF { namespace ast { namespace node {

	class VARNAME_EXT : public DLDL_LPDDEF<VARNAME_EXT>
	{
	private:
	public:
		VARNAME_EXT(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LPDDEF<VARNAME_EXT>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_AST_NODE_VARNAME_EXT_H
