#ifndef DLDL_GENERATION_AST_NODE_program_H
#define DLDL_GENERATION_AST_NODE_program_H

#include "DLDL_GENERATION/Ast/Node/DLDL_GENERATION.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GENERATION { namespace ast { namespace node { 

	class program : public DLDL_GENERATION<program>
	{
	private:
	public:
		program(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_GENERATION<program>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_GENERATION_AST_NODE_program_H
