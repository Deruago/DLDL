#ifndef DLDL_GENERATION_AST_NODE_ESCAPE_CHARS_H
#define DLDL_GENERATION_AST_NODE_ESCAPE_CHARS_H

#include "DLDL_GENERATION/Ast/Node/DLDL_GENERATION.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GENERATION { namespace ast { namespace node {

	class ESCAPE_CHARS : public DLDL_GENERATION<ESCAPE_CHARS>
	{
	private:
	public:
		ESCAPE_CHARS(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_GENERATION<ESCAPE_CHARS>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_GENERATION_AST_NODE_ESCAPE_CHARS_H
