#ifndef DLDL_LPDSTRUCT_AST_NODE_LEFT_ANGLE_BRACKET_H
#define DLDL_LPDSTRUCT_AST_NODE_LEFT_ANGLE_BRACKET_H

#include "DLDL_LPDSTRUCT/Ast/Node/DLDL_LPDSTRUCT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDSTRUCT { namespace ast { namespace node {

	class LEFT_ANGLE_BRACKET : public DLDL_LPDSTRUCT<LEFT_ANGLE_BRACKET>
	{
	private:
	public:
		LEFT_ANGLE_BRACKET(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LPDSTRUCT<LEFT_ANGLE_BRACKET>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LPDSTRUCT_AST_NODE_LEFT_ANGLE_BRACKET_H
