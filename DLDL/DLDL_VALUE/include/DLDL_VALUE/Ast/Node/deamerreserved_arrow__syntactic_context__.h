#ifndef DLDL_VALUE_AST_NODE_deamerreserved_arrow__syntactic_context___H
#define DLDL_VALUE_AST_NODE_deamerreserved_arrow__syntactic_context___H

#include "DLDL_VALUE/Ast/Node/DLDL_VALUE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_VALUE { namespace ast { namespace node { 

	class deamerreserved_arrow__syntactic_context__ : public DLDL_VALUE<deamerreserved_arrow__syntactic_context__>
	{
	private:
	public:
		deamerreserved_arrow__syntactic_context__(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_VALUE<deamerreserved_arrow__syntactic_context__>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_VALUE_AST_NODE_deamerreserved_arrow__syntactic_context___H
