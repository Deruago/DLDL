#ifndef DLDL_GRAMMAR_AST_NODE_INLINE_GROUP_ABSTRACTION_H
#define DLDL_GRAMMAR_AST_NODE_INLINE_GROUP_ABSTRACTION_H

#include "DLDL_GRAMMAR/Ast/Node/DLDL_GRAMMAR.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace DLDL_GRAMMAR { namespace ast { namespace node {

	class INLINE_GROUP_ABSTRACTION : public DLDL_GRAMMAR<INLINE_GROUP_ABSTRACTION>
	{
	private:
	public:
		INLINE_GROUP_ABSTRACTION(deamer::external::cpp::ast::NodeInformation information_)
		: DLDL_GRAMMAR<INLINE_GROUP_ABSTRACTION>(information_, {}, {})
		{
		}
	};

}}}

#endif // DLDL_GRAMMAR_AST_NODE_INLINE_GROUP_ABSTRACTION_H
