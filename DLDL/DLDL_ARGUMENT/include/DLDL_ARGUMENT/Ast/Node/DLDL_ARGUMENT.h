#ifndef DLDL_ARGUMENT_AST_NODE_DLDL_ARGUMENT_H
#define DLDL_ARGUMENT_AST_NODE_DLDL_ARGUMENT_H

#include <Deamer/External/Cpp/Ast/TemplateNodeBase.h>

namespace DLDL_ARGUMENT { namespace ast { namespace node {

	template<typename Derived>
	class DLDL_ARGUMENT : public ::deamer::external::cpp::ast::TemplateNodeBase<DLDL_ARGUMENT<Derived>, Derived>
	{
	private:
		
	public:
		DLDL_ARGUMENT() = default;
		
		DLDL_ARGUMENT(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_ = {}, std::vector<size_t> baseValues_ = {})
		: deamer::external::cpp::ast::TemplateNodeBase<DLDL_ARGUMENT<Derived>, Derived>(information_, nodes_, baseValues_)
		{
		}
	};

}}}

#endif // DLDL_ARGUMENT_AST_NODE_DLDL_ARGUMENT_H
