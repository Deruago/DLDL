#ifndef DLDL_LEXER_AST_NODE_abstraction_H
#define DLDL_LEXER_AST_NODE_abstraction_H

#include "DLDL_LEXER/Ast/Node/DLDL_LEXER.h"
#include "DLDL_LEXER/Ast/Common/Node/abstraction.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LEXER { namespace ast { namespace node { 

	class abstraction : public DLDL_LEXER<abstraction>, public ::DLDL_LEXER::ast::common::node::abstraction
	{
	private:
	public:
		abstraction(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_LEXER<abstraction>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_LEXER_AST_NODE_abstraction_H
