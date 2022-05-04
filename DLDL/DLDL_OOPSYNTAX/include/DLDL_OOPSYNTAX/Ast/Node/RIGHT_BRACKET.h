#ifndef DLDL_OOPSYNTAX_AST_NODE_RIGHT_BRACKET_H
#define DLDL_OOPSYNTAX_AST_NODE_RIGHT_BRACKET_H

#include "DLDL_OOPSYNTAX/Ast/Node/DLDL_OOPSYNTAX.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_OOPSYNTAX { namespace ast { namespace node {

	class RIGHT_BRACKET : public DLDL_OOPSYNTAX<RIGHT_BRACKET>
	{
	private:
	public:
		RIGHT_BRACKET(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_OOPSYNTAX<RIGHT_BRACKET>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_OOPSYNTAX_AST_NODE_RIGHT_BRACKET_H
