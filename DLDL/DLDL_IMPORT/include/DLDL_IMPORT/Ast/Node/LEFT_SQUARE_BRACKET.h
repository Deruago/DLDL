#ifndef DLDL_IMPORT_AST_NODE_LEFT_SQUARE_BRACKET_H
#define DLDL_IMPORT_AST_NODE_LEFT_SQUARE_BRACKET_H

#include "DLDL_IMPORT/Ast/Node/DLDL_IMPORT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_IMPORT { namespace ast { namespace node {

	class LEFT_SQUARE_BRACKET : public DLDL_IMPORT<LEFT_SQUARE_BRACKET>
	{
	private:
	public:
		LEFT_SQUARE_BRACKET(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_IMPORT<LEFT_SQUARE_BRACKET>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_IMPORT_AST_NODE_LEFT_SQUARE_BRACKET_H
