#ifndef DLDL_IMPORT_AST_NODE_RIGHT_SQUARE_BRACKET_H
#define DLDL_IMPORT_AST_NODE_RIGHT_SQUARE_BRACKET_H

#include "DLDL_IMPORT/Ast/Node/DLDL_IMPORT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_IMPORT { namespace ast { namespace node {

	class RIGHT_SQUARE_BRACKET : public DLDL_IMPORT<RIGHT_SQUARE_BRACKET>
	{
	private:
	public:
		RIGHT_SQUARE_BRACKET(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_IMPORT<RIGHT_SQUARE_BRACKET>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_IMPORT_AST_NODE_RIGHT_SQUARE_BRACKET_H
