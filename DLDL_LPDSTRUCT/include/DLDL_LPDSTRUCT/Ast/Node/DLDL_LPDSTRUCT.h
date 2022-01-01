#ifndef DLDL_LPDSTRUCT_AST_NODE_DLDL_LPDSTRUCT_H
#define DLDL_LPDSTRUCT_AST_NODE_DLDL_LPDSTRUCT_H

#include <Deamer/External/Cpp/Ast/TemplateNodeBase.h>

namespace DLDL_LPDSTRUCT { namespace ast { namespace node {

	template<typename Derived>
	class DLDL_LPDSTRUCT : public ::deamer::external::cpp::ast::TemplateNodeBase<DLDL_LPDSTRUCT<Derived>, Derived>
	{
	private:
		
	public:
		DLDL_LPDSTRUCT() = default;
		
		DLDL_LPDSTRUCT(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_ = {}, std::vector<size_t> baseValues_ = {})
		: deamer::external::cpp::ast::TemplateNodeBase<DLDL_LPDSTRUCT<Derived>, Derived>(information_, nodes_, baseValues_)
		{
		}
	};

}}}

#endif // DLDL_LPDSTRUCT_AST_NODE_DLDL_LPDSTRUCT_H
