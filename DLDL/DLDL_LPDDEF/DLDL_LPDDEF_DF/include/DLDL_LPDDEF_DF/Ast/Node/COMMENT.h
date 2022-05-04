#ifndef DLDL_LPDDEF_DF_AST_NODE_COMMENT_H
#define DLDL_LPDDEF_DF_AST_NODE_COMMENT_H

#include "DLDL_LPDDEF_DF/Ast/Node/DLDL_LPDDEF_DF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF_DF { namespace ast { namespace node {

	class COMMENT : public DLDL_LPDDEF_DF<COMMENT>
	{
	private:
	public:
		COMMENT(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LPDDEF_DF<COMMENT>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_DF_AST_NODE_COMMENT_H
