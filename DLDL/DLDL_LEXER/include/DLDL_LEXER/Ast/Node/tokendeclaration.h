#ifndef DLDL_LEXER_AST_NODE_tokendeclaration_H
#define DLDL_LEXER_AST_NODE_tokendeclaration_H

#include "DLDL_LEXER/Ast/Node/DLDL_LEXER.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LEXER { namespace ast { namespace node { 

	class tokendeclaration : public DLDL_LEXER<tokendeclaration>
	{
	private:
	public:
		tokendeclaration(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_LEXER<tokendeclaration>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_LEXER_AST_NODE_tokendeclaration_H
