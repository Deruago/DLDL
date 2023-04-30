#ifndef DLDL_VALUE_AST_NODE_ESCAPE_CHARS_H
#define DLDL_VALUE_AST_NODE_ESCAPE_CHARS_H

#include "DLDL_VALUE/Ast/Node/DLDL_VALUE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_VALUE { namespace ast { namespace node {

	class ESCAPE_CHARS : public DLDL_VALUE<ESCAPE_CHARS>
	{
	private:
	public:
		ESCAPE_CHARS(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_VALUE<ESCAPE_CHARS>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_VALUE_AST_NODE_ESCAPE_CHARS_H
