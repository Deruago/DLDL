#ifndef DLDL_LPDDEF_AST_NODE_DLDL_LPDDEF_H
#define DLDL_LPDDEF_AST_NODE_DLDL_LPDDEF_H

#include <Deamer/External/Cpp/Ast/TemplateNodeBase.h>

namespace DLDL_LPDDEF { namespace ast { namespace node {

	template<typename Derived>
	class DLDL_LPDDEF : public ::deamer::external::cpp::ast::TemplateNodeBase<DLDL_LPDDEF<Derived>, Derived>
	{
	private:
		
	public:
		DLDL_LPDDEF() = default;
		
		DLDL_LPDDEF(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_ = {}, std::vector<size_t> baseValues_ = {})
		: deamer::external::cpp::ast::TemplateNodeBase<DLDL_LPDDEF<Derived>, Derived>(information_, nodes_, baseValues_)
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_AST_NODE_DLDL_LPDDEF_H
