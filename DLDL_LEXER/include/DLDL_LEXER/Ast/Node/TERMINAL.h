#ifndef DLDL_LEXER_AST_NODE_TERMINAL_H
#define DLDL_LEXER_AST_NODE_TERMINAL_H

#include "DLDL_LEXER/Ast/Node/DLDL_LEXER.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LEXER { namespace ast { namespace node {

	class TERMINAL : public DLDL_LEXER<TERMINAL>
	{
	private:
	public:
		TERMINAL(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LEXER<TERMINAL>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LEXER_AST_NODE_TERMINAL_H
