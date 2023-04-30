#ifndef DLDL_LEXER_AST_NODE_REGEX_H
#define DLDL_LEXER_AST_NODE_REGEX_H

#include "DLDL_LEXER/Ast/Node/DLDL_LEXER.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LEXER { namespace ast { namespace node {

	class REGEX : public DLDL_LEXER<REGEX>
	{
	private:
	public:
		REGEX(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LEXER<REGEX>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LEXER_AST_NODE_REGEX_H
