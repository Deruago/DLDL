#ifndef DLDL_LPDDEF_DF_AST_NODE_RSB_H
#define DLDL_LPDDEF_DF_AST_NODE_RSB_H

#include "DLDL_LPDDEF_DF/Ast/Node/DLDL_LPDDEF_DF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF_DF { namespace ast { namespace node {

	class RSB : public DLDL_LPDDEF_DF<RSB>
	{
	private:
	public:
		RSB(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LPDDEF_DF<RSB>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_DF_AST_NODE_RSB_H
