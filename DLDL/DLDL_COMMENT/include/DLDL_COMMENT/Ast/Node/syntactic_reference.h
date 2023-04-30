#ifndef DLDL_COMMENT_AST_NODE_syntactic_reference_H
#define DLDL_COMMENT_AST_NODE_syntactic_reference_H

#include "DLDL_COMMENT/Ast/Node/DLDL_COMMENT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_COMMENT { namespace ast { namespace node { 

	class syntactic_reference : public DLDL_COMMENT<syntactic_reference>
	{
	private:
	public:
		syntactic_reference(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_COMMENT<syntactic_reference>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_COMMENT_AST_NODE_syntactic_reference_H
