#ifndef DLDL_LPDDEF_DF_AST_NODE_COLON_H
#define DLDL_LPDDEF_DF_AST_NODE_COLON_H

#include "DLDL_LPDDEF_DF/Ast/Node/DLDL_LPDDEF_DF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF_DF { namespace ast { namespace node {

	class COLON : public DLDL_LPDDEF_DF<COLON>
	{
	private:
	public:
		COLON(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LPDDEF_DF<COLON>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_DF_AST_NODE_COLON_H
