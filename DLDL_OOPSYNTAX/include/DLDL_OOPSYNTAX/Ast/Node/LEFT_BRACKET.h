#ifndef DLDL_OOPSYNTAX_AST_NODE_LEFT_BRACKET_H
#define DLDL_OOPSYNTAX_AST_NODE_LEFT_BRACKET_H

#include "DLDL_OOPSYNTAX/Ast/Node/DLDL_OOPSYNTAX.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_OOPSYNTAX { namespace ast { namespace node {

	class LEFT_BRACKET : public DLDL_OOPSYNTAX<LEFT_BRACKET>
	{
	private:
	public:
		LEFT_BRACKET(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_OOPSYNTAX<LEFT_BRACKET>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_OOPSYNTAX_AST_NODE_LEFT_BRACKET_H
