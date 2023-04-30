#ifndef DLDL_LPDDEF_DF_AST_NODE_RAB_H
#define DLDL_LPDDEF_DF_AST_NODE_RAB_H

#include "DLDL_LPDDEF_DF/Ast/Node/DLDL_LPDDEF_DF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF_DF { namespace ast { namespace node {

	class RAB : public DLDL_LPDDEF_DF<RAB>
	{
	private:
	public:
		RAB(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LPDDEF_DF<RAB>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_DF_AST_NODE_RAB_H
