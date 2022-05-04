#ifndef DLDL_ASSOCIATIVITY_AST_NODE_program_H
#define DLDL_ASSOCIATIVITY_AST_NODE_program_H

#include "DLDL_ASSOCIATIVITY/Ast/Node/DLDL_ASSOCIATIVITY.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_ASSOCIATIVITY { namespace ast { namespace node { 

	class program : public DLDL_ASSOCIATIVITY<program>
	{
	private:
	public:
		program(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_ASSOCIATIVITY<program>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_ASSOCIATIVITY_AST_NODE_program_H
