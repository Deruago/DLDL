#ifndef DLDL_IMPORT_AST_NODE_IMPORT_MODULE_H
#define DLDL_IMPORT_AST_NODE_IMPORT_MODULE_H

#include "DLDL_IMPORT/Ast/Node/DLDL_IMPORT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_IMPORT { namespace ast { namespace node {

	class IMPORT_MODULE : public DLDL_IMPORT<IMPORT_MODULE>
	{
	private:
	public:
		IMPORT_MODULE(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_IMPORT<IMPORT_MODULE>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_IMPORT_AST_NODE_IMPORT_MODULE_H
