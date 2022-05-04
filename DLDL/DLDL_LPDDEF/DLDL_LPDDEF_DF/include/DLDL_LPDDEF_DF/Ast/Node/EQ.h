#ifndef DLDL_LPDDEF_DF_AST_NODE_EQ_H
#define DLDL_LPDDEF_DF_AST_NODE_EQ_H

#include "DLDL_LPDDEF_DF/Ast/Node/DLDL_LPDDEF_DF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF_DF { namespace ast { namespace node {

	class EQ : public DLDL_LPDDEF_DF<EQ>
	{
	private:
	public:
		EQ(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LPDDEF_DF<EQ>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_DF_AST_NODE_EQ_H
