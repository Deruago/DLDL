#ifndef DLDL_LPDDEF_DF_AST_NODE_STRING_H
#define DLDL_LPDDEF_DF_AST_NODE_STRING_H

#include "DLDL_LPDDEF_DF/Ast/Node/DLDL_LPDDEF_DF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF_DF { namespace ast { namespace node {

	class STRING : public DLDL_LPDDEF_DF<STRING>
	{
	private:
	public:
		STRING(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LPDDEF_DF<STRING>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_DF_AST_NODE_STRING_H
