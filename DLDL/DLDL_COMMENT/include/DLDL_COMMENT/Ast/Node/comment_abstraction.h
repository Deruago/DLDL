#ifndef DLDL_COMMENT_AST_NODE_comment_abstraction_H
#define DLDL_COMMENT_AST_NODE_comment_abstraction_H

#include "DLDL_COMMENT/Ast/Node/DLDL_COMMENT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_COMMENT { namespace ast { namespace node { 

	class comment_abstraction : public DLDL_COMMENT<comment_abstraction>
	{
	private:
	public:
		comment_abstraction(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_COMMENT<comment_abstraction>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_COMMENT_AST_NODE_comment_abstraction_H
