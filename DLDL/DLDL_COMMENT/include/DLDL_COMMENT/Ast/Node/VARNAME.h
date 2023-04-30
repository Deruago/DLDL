#ifndef DLDL_COMMENT_AST_NODE_VARNAME_H
#define DLDL_COMMENT_AST_NODE_VARNAME_H

#include "DLDL_COMMENT/Ast/Node/DLDL_COMMENT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_COMMENT { namespace ast { namespace node {

	class VARNAME : public DLDL_COMMENT<VARNAME>
	{
	private:
	public:
		VARNAME(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_COMMENT<VARNAME>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_COMMENT_AST_NODE_VARNAME_H
