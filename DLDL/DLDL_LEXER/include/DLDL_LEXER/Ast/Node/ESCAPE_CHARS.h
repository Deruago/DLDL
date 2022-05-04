#ifndef DLDL_LEXER_AST_NODE_ESCAPE_CHARS_H
#define DLDL_LEXER_AST_NODE_ESCAPE_CHARS_H

#include "DLDL_LEXER/Ast/Node/DLDL_LEXER.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LEXER { namespace ast { namespace node {

	class ESCAPE_CHARS : public DLDL_LEXER<ESCAPE_CHARS>
	{
	private:
	public:
		ESCAPE_CHARS(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LEXER<ESCAPE_CHARS>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LEXER_AST_NODE_ESCAPE_CHARS_H
