#ifndef DLDL_GRAMMAR_AST_NODE_program_H
#define DLDL_GRAMMAR_AST_NODE_program_H

#include "DLDL_GRAMMAR/Ast/Node/DLDL_GRAMMAR.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GRAMMAR { namespace ast { namespace node { 

	class program : public DLDL_GRAMMAR<program>
	{
	private:
	public:
		program(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_GRAMMAR<program>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_GRAMMAR_AST_NODE_program_H
