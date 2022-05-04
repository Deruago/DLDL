#ifndef DLDL_LPDDEF_EF_AST_NODE_COMMENT_H
#define DLDL_LPDDEF_EF_AST_NODE_COMMENT_H

#include "DLDL_LPDDEF_EF/Ast/Node/DLDL_LPDDEF_EF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF_EF { namespace ast { namespace node {

	class COMMENT : public DLDL_LPDDEF_EF<COMMENT>
	{
	private:
	public:
		COMMENT(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LPDDEF_EF<COMMENT>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_EF_AST_NODE_COMMENT_H
