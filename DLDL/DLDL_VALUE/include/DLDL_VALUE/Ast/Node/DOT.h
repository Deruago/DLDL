#ifndef DLDL_VALUE_AST_NODE_DOT_H
#define DLDL_VALUE_AST_NODE_DOT_H

#include "DLDL_VALUE/Ast/Node/DLDL_VALUE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_VALUE { namespace ast { namespace node {

	class DOT : public DLDL_VALUE<DOT>
	{
	private:
	public:
		DOT(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_VALUE<DOT>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_VALUE_AST_NODE_DOT_H
