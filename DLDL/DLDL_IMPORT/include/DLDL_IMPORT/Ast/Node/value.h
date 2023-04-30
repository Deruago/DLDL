#ifndef DLDL_IMPORT_AST_NODE_value_H
#define DLDL_IMPORT_AST_NODE_value_H

#include "DLDL_IMPORT/Ast/Node/DLDL_IMPORT.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_IMPORT { namespace ast { namespace node { 

	class value : public DLDL_IMPORT<value>
	{
	private:
	public:
		value(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_IMPORT<value>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_IMPORT_AST_NODE_value_H
