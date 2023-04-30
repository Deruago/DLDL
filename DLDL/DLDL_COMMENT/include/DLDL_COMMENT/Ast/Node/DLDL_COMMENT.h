#ifndef DLDL_COMMENT_AST_NODE_DLDL_COMMENT_H
#define DLDL_COMMENT_AST_NODE_DLDL_COMMENT_H

#include <Deamer/External/Cpp/Ast/TemplateNodeBase.h>

namespace DLDL_COMMENT { namespace ast { namespace node {

	template<typename Derived>
	class DLDL_COMMENT : public ::deamer::external::cpp::ast::TemplateNodeBase<DLDL_COMMENT<Derived>, Derived>
	{
	private:
		
	public:
		DLDL_COMMENT() = default;
		
		DLDL_COMMENT(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_ = {}, std::vector<size_t> baseValues_ = {})
		: deamer::external::cpp::ast::TemplateNodeBase<DLDL_COMMENT<Derived>, Derived>(information_, nodes_, baseValues_)
		{
		}
	};

}}}

#endif // DLDL_COMMENT_AST_NODE_DLDL_COMMENT_H
