#ifndef DLDL_IMPORT_AST_NODE_stmt_H
#define DLDL_IMPORT_AST_NODE_stmt_H

#include "DLDL_IMPORT/Ast/Node/DLDL_IMPORT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_IMPORT { namespace ast { namespace node { 

	class stmt : public DLDL_IMPORT<stmt>
	{
	private:
	public:
		stmt(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_IMPORT<stmt>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_IMPORT_AST_NODE_stmt_H
