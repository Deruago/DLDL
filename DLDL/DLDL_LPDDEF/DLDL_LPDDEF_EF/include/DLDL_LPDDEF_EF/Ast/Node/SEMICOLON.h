#ifndef DLDL_LPDDEF_EF_AST_NODE_SEMICOLON_H
#define DLDL_LPDDEF_EF_AST_NODE_SEMICOLON_H

#include "DLDL_LPDDEF_EF/Ast/Node/DLDL_LPDDEF_EF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF_EF { namespace ast { namespace node {

	class SEMICOLON : public DLDL_LPDDEF_EF<SEMICOLON>
	{
	private:
	public:
		SEMICOLON(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LPDDEF_EF<SEMICOLON>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_EF_AST_NODE_SEMICOLON_H
