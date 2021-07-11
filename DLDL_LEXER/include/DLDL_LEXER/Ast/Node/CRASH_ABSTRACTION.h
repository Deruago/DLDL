#ifndef DLDL_LEXER_AST_NODE_CRASH_ABSTRACTION_H
#define DLDL_LEXER_AST_NODE_CRASH_ABSTRACTION_H

#include "DLDL_LEXER/Ast/Node/DLDL_LEXER.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LEXER { namespace ast { namespace node {

	class CRASH_ABSTRACTION : public DLDL_LEXER<CRASH_ABSTRACTION>
	{
	private:
	public:
		CRASH_ABSTRACTION(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LEXER<CRASH_ABSTRACTION>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LEXER_AST_NODE_CRASH_ABSTRACTION_H
