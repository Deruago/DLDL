#ifndef DLDL_GRAMMAR_AST_NODE_ESCAPE_CHARS_H
#define DLDL_GRAMMAR_AST_NODE_ESCAPE_CHARS_H

#include "DLDL_GRAMMAR/Ast/Node/DLDL_GRAMMAR.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GRAMMAR { namespace ast { namespace node {

	class ESCAPE_CHARS : public DLDL_GRAMMAR<ESCAPE_CHARS>
	{
	private:
	public:
		ESCAPE_CHARS(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_GRAMMAR<ESCAPE_CHARS>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_GRAMMAR_AST_NODE_ESCAPE_CHARS_H
