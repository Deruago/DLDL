#ifndef DLDL_IMPORT_AST_NODE_IMPORT_FILE_H
#define DLDL_IMPORT_AST_NODE_IMPORT_FILE_H

#include "DLDL_IMPORT/Ast/Node/DLDL_IMPORT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_IMPORT { namespace ast { namespace node {

	class IMPORT_FILE : public DLDL_IMPORT<IMPORT_FILE>
	{
	private:
	public:
		IMPORT_FILE(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_IMPORT<IMPORT_FILE>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_IMPORT_AST_NODE_IMPORT_FILE_H
