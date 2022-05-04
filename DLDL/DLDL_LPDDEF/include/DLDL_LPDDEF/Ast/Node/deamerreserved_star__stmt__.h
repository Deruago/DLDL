#ifndef DLDL_LPDDEF_AST_NODE_deamerreserved_star__stmt___H
#define DLDL_LPDDEF_AST_NODE_deamerreserved_star__stmt___H

#include "DLDL_LPDDEF/Ast/Node/DLDL_LPDDEF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF { namespace ast { namespace node { 

	class deamerreserved_star__stmt__ : public DLDL_LPDDEF<deamerreserved_star__stmt__>
	{
	private:
	public:
		deamerreserved_star__stmt__(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_LPDDEF<deamerreserved_star__stmt__>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_AST_NODE_deamerreserved_star__stmt___H
