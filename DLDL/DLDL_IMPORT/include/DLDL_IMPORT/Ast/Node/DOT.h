#ifndef DLDL_IMPORT_AST_NODE_DOT_H
#define DLDL_IMPORT_AST_NODE_DOT_H

#include "DLDL_IMPORT/Ast/Node/DLDL_IMPORT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_IMPORT { namespace ast { namespace node {

	class DOT : public DLDL_IMPORT<DOT>
	{
	private:
	public:
		DOT(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_IMPORT<DOT>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_IMPORT_AST_NODE_DOT_H
