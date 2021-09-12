#ifndef DLDL_AST_NODE_DLDL_H
#define DLDL_AST_NODE_DLDL_H

#include <Deamer/External/Cpp/Ast/TemplateNodeBase.h>

namespace DLDL { namespace ast { namespace node {

	template<typename Derived>
	class DLDL : public ::deamer::external::cpp::ast::TemplateNodeBase<DLDL<Derived>, Derived>
	{
	private:
		
	public:
		DLDL() = default;
		
		DLDL(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_ = {}, std::vector<size_t> baseValues_ = {})
		: deamer::external::cpp::ast::TemplateNodeBase<DLDL<Derived>, Derived>(information_, nodes_, baseValues_)
		{
		}
	};

}}}

#endif // DLDL_AST_NODE_DLDL_H
