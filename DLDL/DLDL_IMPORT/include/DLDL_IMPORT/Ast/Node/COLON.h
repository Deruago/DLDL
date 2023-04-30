#ifndef DLDL_IMPORT_AST_NODE_COLON_H
#define DLDL_IMPORT_AST_NODE_COLON_H

#include "DLDL_IMPORT/Ast/Node/DLDL_IMPORT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_IMPORT { namespace ast { namespace node {

	class COLON : public DLDL_IMPORT<COLON>
	{
	private:
	public:
		COLON(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_IMPORT<COLON>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_IMPORT_AST_NODE_COLON_H
