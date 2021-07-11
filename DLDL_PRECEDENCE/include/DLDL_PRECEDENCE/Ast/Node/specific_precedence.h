#ifndef DLDL_PRECEDENCE_AST_NODE_specific_precedence_H
#define DLDL_PRECEDENCE_AST_NODE_specific_precedence_H

#include "DLDL_PRECEDENCE/Ast/Node/DLDL_PRECEDENCE.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_PRECEDENCE { namespace ast { namespace node { 

	class specific_precedence : public DLDL_PRECEDENCE<specific_precedence>
	{
	private:
	public:
		specific_precedence(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_PRECEDENCE<specific_precedence>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_PRECEDENCE_AST_NODE_specific_precedence_H
