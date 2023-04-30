#ifndef DLDL_IMPORT_AST_NODE_TEXT_H
#define DLDL_IMPORT_AST_NODE_TEXT_H

#include "DLDL_IMPORT/Ast/Node/DLDL_IMPORT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_IMPORT { namespace ast { namespace node {

	class TEXT : public DLDL_IMPORT<TEXT>
	{
	private:
	public:
		TEXT(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_IMPORT<TEXT>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_IMPORT_AST_NODE_TEXT_H
