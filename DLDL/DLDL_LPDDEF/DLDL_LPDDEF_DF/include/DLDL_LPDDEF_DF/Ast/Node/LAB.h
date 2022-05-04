#ifndef DLDL_LPDDEF_DF_AST_NODE_LAB_H
#define DLDL_LPDDEF_DF_AST_NODE_LAB_H

#include "DLDL_LPDDEF_DF/Ast/Node/DLDL_LPDDEF_DF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF_DF { namespace ast { namespace node {

	class LAB : public DLDL_LPDDEF_DF<LAB>
	{
	private:
	public:
		LAB(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LPDDEF_DF<LAB>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_DF_AST_NODE_LAB_H
