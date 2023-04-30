#ifndef DLDL_IMPORT_AST_NODE_IMPORT_H
#define DLDL_IMPORT_AST_NODE_IMPORT_H

#include "DLDL_IMPORT/Ast/Node/DLDL_IMPORT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_IMPORT { namespace ast { namespace node {

	class IMPORT : public DLDL_IMPORT<IMPORT>
	{
	private:
	public:
		IMPORT(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_IMPORT<IMPORT>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_IMPORT_AST_NODE_IMPORT_H
