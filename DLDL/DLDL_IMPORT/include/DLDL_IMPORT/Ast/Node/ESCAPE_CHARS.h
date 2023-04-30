#ifndef DLDL_IMPORT_AST_NODE_ESCAPE_CHARS_H
#define DLDL_IMPORT_AST_NODE_ESCAPE_CHARS_H

#include "DLDL_IMPORT/Ast/Node/DLDL_IMPORT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_IMPORT { namespace ast { namespace node {

	class ESCAPE_CHARS : public DLDL_IMPORT<ESCAPE_CHARS>
	{
	private:
	public:
		ESCAPE_CHARS(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_IMPORT<ESCAPE_CHARS>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_IMPORT_AST_NODE_ESCAPE_CHARS_H
