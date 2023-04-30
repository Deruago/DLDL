#ifndef DLDL_LPDDEF_EF_AST_NODE_COLON_H
#define DLDL_LPDDEF_EF_AST_NODE_COLON_H

#include "DLDL_LPDDEF_EF/Ast/Node/DLDL_LPDDEF_EF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF_EF { namespace ast { namespace node {

	class COLON : public DLDL_LPDDEF_EF<COLON>
	{
	private:
	public:
		COLON(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LPDDEF_EF<COLON>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_EF_AST_NODE_COLON_H
