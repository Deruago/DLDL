#ifndef DLDL_LPDDEF_DF_AST_NODE_ESCAPE_CHARS_H
#define DLDL_LPDDEF_DF_AST_NODE_ESCAPE_CHARS_H

#include "DLDL_LPDDEF_DF/Ast/Node/DLDL_LPDDEF_DF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF_DF { namespace ast { namespace node {

	class ESCAPE_CHARS : public DLDL_LPDDEF_DF<ESCAPE_CHARS>
	{
	private:
	public:
		ESCAPE_CHARS(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LPDDEF_DF<ESCAPE_CHARS>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_DF_AST_NODE_ESCAPE_CHARS_H
