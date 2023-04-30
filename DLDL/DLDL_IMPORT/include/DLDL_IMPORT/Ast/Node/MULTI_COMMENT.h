#ifndef DLDL_IMPORT_AST_NODE_MULTI_COMMENT_H
#define DLDL_IMPORT_AST_NODE_MULTI_COMMENT_H

#include "DLDL_IMPORT/Ast/Node/DLDL_IMPORT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_IMPORT { namespace ast { namespace node {

	class MULTI_COMMENT : public DLDL_IMPORT<MULTI_COMMENT>
	{
	private:
	public:
		MULTI_COMMENT(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_IMPORT<MULTI_COMMENT>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_IMPORT_AST_NODE_MULTI_COMMENT_H
