#ifndef DLDL_COMMENT_AST_NODE_ESCAPE_CHARS_H
#define DLDL_COMMENT_AST_NODE_ESCAPE_CHARS_H

#include "DLDL_COMMENT/Ast/Node/DLDL_COMMENT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_COMMENT { namespace ast { namespace node {

	class ESCAPE_CHARS : public DLDL_COMMENT<ESCAPE_CHARS>
	{
	private:
	public:
		ESCAPE_CHARS(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_COMMENT<ESCAPE_CHARS>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_COMMENT_AST_NODE_ESCAPE_CHARS_H
