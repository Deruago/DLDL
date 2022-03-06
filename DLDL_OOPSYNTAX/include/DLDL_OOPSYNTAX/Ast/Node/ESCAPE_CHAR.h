#ifndef DLDL_OOPSYNTAX_AST_NODE_ESCAPE_CHAR_H
#define DLDL_OOPSYNTAX_AST_NODE_ESCAPE_CHAR_H

#include "DLDL_OOPSYNTAX/Ast/Node/DLDL_OOPSYNTAX.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_OOPSYNTAX { namespace ast { namespace node {

	class ESCAPE_CHAR : public DLDL_OOPSYNTAX<ESCAPE_CHAR>
	{
	private:
	public:
		ESCAPE_CHAR(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_OOPSYNTAX<ESCAPE_CHAR>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_OOPSYNTAX_AST_NODE_ESCAPE_CHAR_H
