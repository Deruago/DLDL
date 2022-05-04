#ifndef DLDL_LPDDEF_DF_AST_NODE_NAMESPACED_VARNAME_H
#define DLDL_LPDDEF_DF_AST_NODE_NAMESPACED_VARNAME_H

#include "DLDL_LPDDEF_DF/Ast/Node/DLDL_LPDDEF_DF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF_DF { namespace ast { namespace node {

	class NAMESPACED_VARNAME : public DLDL_LPDDEF_DF<NAMESPACED_VARNAME>
	{
	private:
	public:
		NAMESPACED_VARNAME(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LPDDEF_DF<NAMESPACED_VARNAME>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_DF_AST_NODE_NAMESPACED_VARNAME_H
