#ifndef DLDL_PRECEDENCE_AST_NODE_ESCAPE_CHARS_H
#define DLDL_PRECEDENCE_AST_NODE_ESCAPE_CHARS_H

#include "DLDL_PRECEDENCE/Ast/Node/DLDL_PRECEDENCE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_PRECEDENCE { namespace ast { namespace node {

	class ESCAPE_CHARS : public DLDL_PRECEDENCE<ESCAPE_CHARS>
	{
	private:
	public:
		ESCAPE_CHARS(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_PRECEDENCE<ESCAPE_CHARS>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_PRECEDENCE_AST_NODE_ESCAPE_CHARS_H
