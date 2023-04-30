#ifndef DLDL_LPDDEF_AST_NODE_RIGHT_ANGLE_BRACKET_H
#define DLDL_LPDDEF_AST_NODE_RIGHT_ANGLE_BRACKET_H

#include "DLDL_LPDDEF/Ast/Node/DLDL_LPDDEF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF { namespace ast { namespace node {

	class RIGHT_ANGLE_BRACKET : public DLDL_LPDDEF<RIGHT_ANGLE_BRACKET>
	{
	private:
	public:
		RIGHT_ANGLE_BRACKET(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LPDDEF<RIGHT_ANGLE_BRACKET>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_AST_NODE_RIGHT_ANGLE_BRACKET_H
