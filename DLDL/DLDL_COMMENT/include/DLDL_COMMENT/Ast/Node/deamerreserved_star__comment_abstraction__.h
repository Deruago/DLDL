#ifndef DLDL_COMMENT_AST_NODE_deamerreserved_star__comment_abstraction___H
#define DLDL_COMMENT_AST_NODE_deamerreserved_star__comment_abstraction___H

#include "DLDL_COMMENT/Ast/Node/DLDL_COMMENT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_COMMENT { namespace ast { namespace node { 

	class deamerreserved_star__comment_abstraction__ : public DLDL_COMMENT<deamerreserved_star__comment_abstraction__>
	{
	private:
	public:
		deamerreserved_star__comment_abstraction__(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_COMMENT<deamerreserved_star__comment_abstraction__>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_COMMENT_AST_NODE_deamerreserved_star__comment_abstraction___H
