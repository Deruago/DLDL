#ifndef DLDL_LPDDEF_DF_AST_NODE_DEAMER_VARNAME_H
#define DLDL_LPDDEF_DF_AST_NODE_DEAMER_VARNAME_H

#include "DLDL_LPDDEF_DF/Ast/Node/DLDL_LPDDEF_DF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF_DF { namespace ast { namespace node {

	class DEAMER_VARNAME : public DLDL_LPDDEF_DF<DEAMER_VARNAME>
	{
	private:
	public:
		DEAMER_VARNAME(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LPDDEF_DF<DEAMER_VARNAME>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_DF_AST_NODE_DEAMER_VARNAME_H
