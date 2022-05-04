#ifndef DLDL_OOPSYNTAX_AST_NODE_production_rule_conversion_H
#define DLDL_OOPSYNTAX_AST_NODE_production_rule_conversion_H

#include "DLDL_OOPSYNTAX/Ast/Node/DLDL_OOPSYNTAX.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_OOPSYNTAX { namespace ast { namespace node { 

	class production_rule_conversion : public DLDL_OOPSYNTAX<production_rule_conversion>
	{
	private:
	public:
		production_rule_conversion(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_OOPSYNTAX<production_rule_conversion>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_OOPSYNTAX_AST_NODE_production_rule_conversion_H
