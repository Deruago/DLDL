#ifndef DLDL_LEXER_AST_NODE_stmt_H
#define DLDL_LEXER_AST_NODE_stmt_H

#include "DLDL_LEXER/Ast/Node/DLDL_LEXER.h"
#include "DLDL_LEXER/Ast/Common/Node/stmt.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LEXER { namespace ast { namespace node { 

	class stmt : public DLDL_LEXER<stmt>, public ::DLDL_LEXER::ast::common::node::stmt
	{
	private:
	public:
		stmt(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_LEXER<stmt>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_LEXER_AST_NODE_stmt_H
