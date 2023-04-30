#ifndef DLDL_COMMENT_AST_NODE__H
#define DLDL_COMMENT_AST_NODE__H

#include "DLDL_COMMENT/Ast/Node/DLDL_COMMENT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_COMMENT { namespace ast { namespace node { 

	class  : public DLDL_COMMENT<>
	{
	private:
	public:
		(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_COMMENT<>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_COMMENT_AST_NODE__H
