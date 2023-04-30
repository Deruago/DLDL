#ifndef DLDL_PRECEDENCE_AST_NODE_DLDL_PRECEDENCE_H
#define DLDL_PRECEDENCE_AST_NODE_DLDL_PRECEDENCE_H

#include <Deamer/External/Cpp/Ast/TemplateNodeBase.h>

namespace DLDL_PRECEDENCE { namespace ast { namespace node {

	template<typename Derived>
	class DLDL_PRECEDENCE : public ::deamer::external::cpp::ast::TemplateNodeBase<DLDL_PRECEDENCE<Derived>, Derived>
	{
	private:
		
	public:
		DLDL_PRECEDENCE() = default;
		
		DLDL_PRECEDENCE(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_ = {}, std::vector<size_t> baseValues_ = {})
		: deamer::external::cpp::ast::TemplateNodeBase<DLDL_PRECEDENCE<Derived>, Derived>(information_, nodes_, baseValues_)
		{
		}
	};

}}}

#endif // DLDL_PRECEDENCE_AST_NODE_DLDL_PRECEDENCE_H
