#ifndef DLDL_LPDDEF_DF_AST_NODE_DLDL_LPDDEF_DF_H
#define DLDL_LPDDEF_DF_AST_NODE_DLDL_LPDDEF_DF_H

#include <Deamer/External/Cpp/Ast/TemplateNodeBase.h>

namespace DLDL_LPDDEF_DF { namespace ast { namespace node {

	template<typename Derived>
	class DLDL_LPDDEF_DF : public ::deamer::external::cpp::ast::TemplateNodeBase<DLDL_LPDDEF_DF<Derived>, Derived>
	{
	private:
		
	public:
		DLDL_LPDDEF_DF() = default;
		
		DLDL_LPDDEF_DF(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_ = {}, std::vector<size_t> baseValues_ = {})
		: deamer::external::cpp::ast::TemplateNodeBase<DLDL_LPDDEF_DF<Derived>, Derived>(information_, nodes_, baseValues_)
		{
		}
	};

}}}

#endif // DLDL_LPDDEF_DF_AST_NODE_DLDL_LPDDEF_DF_H
