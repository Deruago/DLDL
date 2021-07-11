#ifndef DLDL_PRECEDENCE_AST_NODE_program_H
#define DLDL_PRECEDENCE_AST_NODE_program_H

#include "DLDL_PRECEDENCE/Ast/Node/DLDL_PRECEDENCE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_PRECEDENCE { namespace ast { namespace node { 

	class program : public DLDL_PRECEDENCE<program>
	{
	private:
	public:
		program(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_PRECEDENCE<program>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_PRECEDENCE_AST_NODE_program_H
