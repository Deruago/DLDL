#ifndef DLDL_IMPORT_AST_NODE_program_H
#define DLDL_IMPORT_AST_NODE_program_H

#include "DLDL_IMPORT/Ast/Node/DLDL_IMPORT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_IMPORT { namespace ast { namespace node { 

	class program : public DLDL_IMPORT<program>
	{
	private:
	public:
		program(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_IMPORT<program>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_IMPORT_AST_NODE_program_H
