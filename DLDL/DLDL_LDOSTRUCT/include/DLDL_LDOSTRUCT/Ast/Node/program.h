#ifndef DLDL_LDOSTRUCT_AST_NODE_program_H
#define DLDL_LDOSTRUCT_AST_NODE_program_H

#include "DLDL_LDOSTRUCT/Ast/Node/DLDL_LDOSTRUCT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LDOSTRUCT { namespace ast { namespace node { 

	class program : public DLDL_LDOSTRUCT<program>
	{
	private:
	public:
		program(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_LDOSTRUCT<program>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_LDOSTRUCT_AST_NODE_program_H
