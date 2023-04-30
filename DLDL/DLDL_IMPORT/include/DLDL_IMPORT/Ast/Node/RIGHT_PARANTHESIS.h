#ifndef DLDL_IMPORT_AST_NODE_RIGHT_PARANTHESIS_H
#define DLDL_IMPORT_AST_NODE_RIGHT_PARANTHESIS_H

#include "DLDL_IMPORT/Ast/Node/DLDL_IMPORT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_IMPORT { namespace ast { namespace node {

	class RIGHT_PARANTHESIS : public DLDL_IMPORT<RIGHT_PARANTHESIS>
	{
	private:
	public:
		RIGHT_PARANTHESIS(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_IMPORT<RIGHT_PARANTHESIS>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_IMPORT_AST_NODE_RIGHT_PARANTHESIS_H
