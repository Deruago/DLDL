#ifndef DLDL_ARGUMENT_AST_NODE_program_H
#define DLDL_ARGUMENT_AST_NODE_program_H

#include "DLDL_ARGUMENT/Ast/Node/DLDL_ARGUMENT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_ARGUMENT { namespace ast { namespace node { 

	class program : public DLDL_ARGUMENT<program>
	{
	private:
	public:
		program(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_ARGUMENT<program>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_ARGUMENT_AST_NODE_program_H
