#ifndef DLDL_LPDDEF_AST_NODE_program_H
#define DLDL_LPDDEF_AST_NODE_program_H

#include "DLDL_LPDDEF/Ast/Node/DLDL_LPDDEF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF { namespace ast { namespace node { 

	class program : public DLDL_LPDDEF<program>
	{
	private:
	public:
		program(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_LPDDEF<program>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_AST_NODE_program_H
