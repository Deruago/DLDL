#ifndef DLDL_COMMENT_AST_NODE_start_abstraction_H
#define DLDL_COMMENT_AST_NODE_start_abstraction_H

#include "DLDL_COMMENT/Ast/Node/DLDL_COMMENT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_COMMENT { namespace ast { namespace node { 

	class start_abstraction : public DLDL_COMMENT<start_abstraction>
	{
	private:
	public:
		start_abstraction(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_COMMENT<start_abstraction>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_COMMENT_AST_NODE_start_abstraction_H
