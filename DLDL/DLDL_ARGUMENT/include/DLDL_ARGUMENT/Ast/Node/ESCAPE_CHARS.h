#ifndef DLDL_ARGUMENT_AST_NODE_ESCAPE_CHARS_H
#define DLDL_ARGUMENT_AST_NODE_ESCAPE_CHARS_H

#include "DLDL_ARGUMENT/Ast/Node/DLDL_ARGUMENT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_ARGUMENT { namespace ast { namespace node {

	class ESCAPE_CHARS : public DLDL_ARGUMENT<ESCAPE_CHARS>
	{
	private:
	public:
		ESCAPE_CHARS(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_ARGUMENT<ESCAPE_CHARS>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_ARGUMENT_AST_NODE_ESCAPE_CHARS_H
