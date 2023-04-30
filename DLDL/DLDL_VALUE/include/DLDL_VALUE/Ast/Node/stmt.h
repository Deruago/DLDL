#ifndef DLDL_VALUE_AST_NODE_stmt_H
#define DLDL_VALUE_AST_NODE_stmt_H

#include "DLDL_VALUE/Ast/Node/DLDL_VALUE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_VALUE { namespace ast { namespace node { 

	class stmt : public DLDL_VALUE<stmt>
	{
	private:
	public:
		stmt(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_VALUE<stmt>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_VALUE_AST_NODE_stmt_H
