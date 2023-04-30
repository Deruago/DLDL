#ifndef DLDL_LPDSTRUCT_AST_NODE_program_H
#define DLDL_LPDSTRUCT_AST_NODE_program_H

#include "DLDL_LPDSTRUCT/Ast/Node/DLDL_LPDSTRUCT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDSTRUCT { namespace ast { namespace node { 

	class program : public DLDL_LPDSTRUCT<program>
	{
	private:
	public:
		program(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_LPDSTRUCT<program>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_LPDSTRUCT_AST_NODE_program_H
