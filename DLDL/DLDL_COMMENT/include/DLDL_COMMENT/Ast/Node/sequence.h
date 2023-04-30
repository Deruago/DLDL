#ifndef DLDL_COMMENT_AST_NODE_sequence_H
#define DLDL_COMMENT_AST_NODE_sequence_H

#include "DLDL_COMMENT/Ast/Node/DLDL_COMMENT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_COMMENT { namespace ast { namespace node { 

	class sequence : public DLDL_COMMENT<sequence>
	{
	private:
	public:
		sequence(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_COMMENT<sequence>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_COMMENT_AST_NODE_sequence_H
