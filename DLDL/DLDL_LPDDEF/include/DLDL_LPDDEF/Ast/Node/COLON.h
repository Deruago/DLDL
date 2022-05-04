#ifndef DLDL_LPDDEF_AST_NODE_COLON_H
#define DLDL_LPDDEF_AST_NODE_COLON_H

#include "DLDL_LPDDEF/Ast/Node/DLDL_LPDDEF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF { namespace ast { namespace node {

	class COLON : public DLDL_LPDDEF<COLON>
	{
	private:
	public:
		COLON(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LPDDEF<COLON>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_AST_NODE_COLON_H
