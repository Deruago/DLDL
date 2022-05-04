#ifndef DLDL_LPDDEF_DF_AST_NODE_LB_H
#define DLDL_LPDDEF_DF_AST_NODE_LB_H

#include "DLDL_LPDDEF_DF/Ast/Node/DLDL_LPDDEF_DF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF_DF { namespace ast { namespace node {

	class LB : public DLDL_LPDDEF_DF<LB>
	{
	private:
	public:
		LB(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LPDDEF_DF<LB>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_DF_AST_NODE_LB_H
