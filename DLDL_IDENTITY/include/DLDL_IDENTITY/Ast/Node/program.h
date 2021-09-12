#ifndef DLDL_IDENTITY_AST_NODE_program_H
#define DLDL_IDENTITY_AST_NODE_program_H

#include "DLDL_IDENTITY/Ast/Node/DLDL_IDENTITY.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_IDENTITY { namespace ast { namespace node { 

	class program : public DLDL_IDENTITY<program>
	{
	private:
	public:
		program(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_IDENTITY<program>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_IDENTITY_AST_NODE_program_H
