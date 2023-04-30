#ifndef DLDL_IMPORT_AST_NODE_LEFT_PARANTHESIS_H
#define DLDL_IMPORT_AST_NODE_LEFT_PARANTHESIS_H

#include "DLDL_IMPORT/Ast/Node/DLDL_IMPORT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_IMPORT { namespace ast { namespace node {

	class LEFT_PARANTHESIS : public DLDL_IMPORT<LEFT_PARANTHESIS>
	{
	private:
	public:
		LEFT_PARANTHESIS(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_IMPORT<LEFT_PARANTHESIS>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_IMPORT_AST_NODE_LEFT_PARANTHESIS_H
