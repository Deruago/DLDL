#ifndef DLDL_GENERATION_AST_NODE_DLDL_GENERATION_H
#define DLDL_GENERATION_AST_NODE_DLDL_GENERATION_H

#include <Deamer/External/Cpp/Ast/TemplateNodeBase.h>

namespace DLDL_GENERATION { namespace ast { namespace node {

	template<typename Derived>
	class DLDL_GENERATION : public ::deamer::external::cpp::ast::TemplateNodeBase<DLDL_GENERATION<Derived>, Derived>
	{
	private:
		
	public:
		DLDL_GENERATION() = default;
		
		DLDL_GENERATION(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_ = {}, std::vector<size_t> baseValues_ = {})
		: deamer::external::cpp::ast::TemplateNodeBase<DLDL_GENERATION<Derived>, Derived>(information_, nodes_, baseValues_)
		{
		}
	};

}}}

#endif // DLDL_GENERATION_AST_NODE_DLDL_GENERATION_H
