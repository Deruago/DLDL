#ifndef DLDL_LPDDEF_DF_AST_NODE_RB_H
#define DLDL_LPDDEF_DF_AST_NODE_RB_H

#include "DLDL_LPDDEF_DF/Ast/Node/DLDL_LPDDEF_DF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF_DF { namespace ast { namespace node {

	class RB : public DLDL_LPDDEF_DF<RB>
	{
	private:
	public:
		RB(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LPDDEF_DF<RB>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_DF_AST_NODE_RB_H
