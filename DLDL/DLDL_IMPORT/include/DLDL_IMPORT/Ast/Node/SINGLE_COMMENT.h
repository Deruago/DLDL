#ifndef DLDL_IMPORT_AST_NODE_SINGLE_COMMENT_H
#define DLDL_IMPORT_AST_NODE_SINGLE_COMMENT_H

#include "DLDL_IMPORT/Ast/Node/DLDL_IMPORT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_IMPORT { namespace ast { namespace node {

	class SINGLE_COMMENT : public DLDL_IMPORT<SINGLE_COMMENT>
	{
	private:
	public:
		SINGLE_COMMENT(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_IMPORT<SINGLE_COMMENT>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_IMPORT_AST_NODE_SINGLE_COMMENT_H
