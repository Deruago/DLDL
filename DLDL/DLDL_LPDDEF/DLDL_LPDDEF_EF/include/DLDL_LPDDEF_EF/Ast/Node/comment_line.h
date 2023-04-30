#ifndef DLDL_LPDDEF_EF_AST_NODE_comment_line_H
#define DLDL_LPDDEF_EF_AST_NODE_comment_line_H

#include "DLDL_LPDDEF_EF/Ast/Node/DLDL_LPDDEF_EF.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_LPDDEF_EF { namespace ast { namespace node { 

	class comment_line : public DLDL_LPDDEF_EF<comment_line>
	{
	private:
	public:
		comment_line(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: DLDL_LPDDEF_EF<comment_line>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_EF_AST_NODE_comment_line_H
