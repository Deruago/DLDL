#ifndef DLDL_LPDDEF_DF_AST_NODE_SEMICOLON_H
#define DLDL_LPDDEF_DF_AST_NODE_SEMICOLON_H

#include "DLDL_LPDDEF_DF/Ast/Node/DLDL_LPDDEF_DF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF_DF { namespace ast { namespace node {

	class SEMICOLON : public DLDL_LPDDEF_DF<SEMICOLON>
	{
	private:
	public:
		SEMICOLON(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LPDDEF_DF<SEMICOLON>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_DF_AST_NODE_SEMICOLON_H
