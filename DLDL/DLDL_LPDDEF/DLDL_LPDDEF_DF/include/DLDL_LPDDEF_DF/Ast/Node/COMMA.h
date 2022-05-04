#ifndef DLDL_LPDDEF_DF_AST_NODE_COMMA_H
#define DLDL_LPDDEF_DF_AST_NODE_COMMA_H

#include "DLDL_LPDDEF_DF/Ast/Node/DLDL_LPDDEF_DF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF_DF { namespace ast { namespace node {

	class COMMA : public DLDL_LPDDEF_DF<COMMA>
	{
	private:
	public:
		COMMA(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LPDDEF_DF<COMMA>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_DF_AST_NODE_COMMA_H
