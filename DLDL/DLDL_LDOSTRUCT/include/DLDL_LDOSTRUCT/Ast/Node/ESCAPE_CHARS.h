#ifndef DLDL_LDOSTRUCT_AST_NODE_ESCAPE_CHARS_H
#define DLDL_LDOSTRUCT_AST_NODE_ESCAPE_CHARS_H

#include "DLDL_LDOSTRUCT/Ast/Node/DLDL_LDOSTRUCT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LDOSTRUCT { namespace ast { namespace node {

	class ESCAPE_CHARS : public DLDL_LDOSTRUCT<ESCAPE_CHARS>
	{
	private:
	public:
		ESCAPE_CHARS(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LDOSTRUCT<ESCAPE_CHARS>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LDOSTRUCT_AST_NODE_ESCAPE_CHARS_H
