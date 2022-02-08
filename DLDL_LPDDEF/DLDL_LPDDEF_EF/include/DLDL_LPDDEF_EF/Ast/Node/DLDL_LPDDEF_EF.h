#ifndef DLDL_LPDDEF_EF_AST_NODE_DLDL_LPDDEF_EF_H
#define DLDL_LPDDEF_EF_AST_NODE_DLDL_LPDDEF_EF_H

#include <Deamer/External/Cpp/Ast/TemplateNodeBase.h>

namespace DLDL_LPDDEF_EF { namespace ast { namespace node {

	template<typename Derived>
	class DLDL_LPDDEF_EF : public ::deamer::external::cpp::ast::TemplateNodeBase<DLDL_LPDDEF_EF<Derived>, Derived>
	{
	private:
		
	public:
		DLDL_LPDDEF_EF() = default;
		
		DLDL_LPDDEF_EF(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_ = {}, std::vector<size_t> baseValues_ = {})
		: deamer::external::cpp::ast::TemplateNodeBase<DLDL_LPDDEF_EF<Derived>, Derived>(information_, nodes_, baseValues_)
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_EF_AST_NODE_DLDL_LPDDEF_EF_H
