#ifndef DLDL_OOPSYNTAX_AST_NODE_deamerreserved_arrow__property___H
#define DLDL_OOPSYNTAX_AST_NODE_deamerreserved_arrow__property___H

#include "DLDL_OOPSYNTAX/Ast/Node/DLDL_OOPSYNTAX.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_OOPSYNTAX { namespace ast { namespace node { 

	class deamerreserved_arrow__property__ : public DLDL_OOPSYNTAX<deamerreserved_arrow__property__>
	{
	private:
	public:
		deamerreserved_arrow__property__(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_OOPSYNTAX<deamerreserved_arrow__property__>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_OOPSYNTAX_AST_NODE_deamerreserved_arrow__property___H
