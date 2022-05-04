#ifndef DLDL_LDOSTRUCT_AST_NODE_RIGHT_ANGLE_BRACKET_H
#define DLDL_LDOSTRUCT_AST_NODE_RIGHT_ANGLE_BRACKET_H

#include "DLDL_LDOSTRUCT/Ast/Node/DLDL_LDOSTRUCT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LDOSTRUCT { namespace ast { namespace node {

	class RIGHT_ANGLE_BRACKET : public DLDL_LDOSTRUCT<RIGHT_ANGLE_BRACKET>
	{
	private:
	public:
		RIGHT_ANGLE_BRACKET(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_LDOSTRUCT<RIGHT_ANGLE_BRACKET>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_LDOSTRUCT_AST_NODE_RIGHT_ANGLE_BRACKET_H
