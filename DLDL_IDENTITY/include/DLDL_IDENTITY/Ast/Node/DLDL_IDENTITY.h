#ifndef DLDL_IDENTITY_AST_NODE_DLDL_IDENTITY_H
#define DLDL_IDENTITY_AST_NODE_DLDL_IDENTITY_H

#include <Deamer/External/Cpp/Ast/TemplateNodeBase.h>

namespace DLDL_IDENTITY { namespace ast { namespace node {

	template<typename Derived>
	class DLDL_IDENTITY : public ::deamer::external::cpp::ast::TemplateNodeBase<DLDL_IDENTITY<Derived>, Derived>
	{
	private:
		
	public:
		DLDL_IDENTITY() = default;
		
		DLDL_IDENTITY(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_ = {}, std::vector<size_t> baseValues_ = {})
		: deamer::external::cpp::ast::TemplateNodeBase<DLDL_IDENTITY<Derived>, Derived>(information_, nodes_, baseValues_)
		{
		}
	};

}}}

#endif // DLDL_IDENTITY_AST_NODE_DLDL_IDENTITY_H
