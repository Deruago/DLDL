#ifndef DLDL_LPDSTRUCT_AST_NODE_ESCAPE_CHARS_H
#define DLDL_LPDSTRUCT_AST_NODE_ESCAPE_CHARS_H

#include "DLDL_LPDSTRUCT/Ast/Node/DLDL_LPDSTRUCT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDSTRUCT { namespace ast { namespace node {

	class ESCAPE_CHARS : public DLDL_LPDSTRUCT<ESCAPE_CHARS>
	{
	private:
	public:
		ESCAPE_CHARS(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LPDSTRUCT<ESCAPE_CHARS>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LPDSTRUCT_AST_NODE_ESCAPE_CHARS_H
