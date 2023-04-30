#ifndef DLDL_AST_NODE_program_H
#define DLDL_AST_NODE_program_H

#include "DLDL/Ast/Node/DLDL.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL { namespace ast { namespace node { 

	class program : public DLDL<program>
	{
	private:
	public:
		program(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL<program>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_AST_NODE_program_H
