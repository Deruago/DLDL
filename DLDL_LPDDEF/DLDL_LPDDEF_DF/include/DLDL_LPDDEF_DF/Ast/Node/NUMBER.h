#ifndef DLDL_LPDDEF_DF_AST_NODE_NUMBER_H
#define DLDL_LPDDEF_DF_AST_NODE_NUMBER_H

#include "DLDL_LPDDEF_DF/Ast/Node/DLDL_LPDDEF_DF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF_DF { namespace ast { namespace node {

	class NUMBER : public DLDL_LPDDEF_DF<NUMBER>
	{
	private:
	public:
		NUMBER(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LPDDEF_DF<NUMBER>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_DF_AST_NODE_NUMBER_H
