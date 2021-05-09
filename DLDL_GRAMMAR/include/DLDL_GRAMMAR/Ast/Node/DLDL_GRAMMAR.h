#ifndef DLDL_GRAMMAR_AST_NODE_DLDL_GRAMMAR_H
#define DLDL_GRAMMAR_AST_NODE_DLDL_GRAMMAR_H

#include <Deamer/External/Cpp/Ast/TemplateNodeBase.h>

namespace DLDL_GRAMMAR { namespace ast { namespace node {

	template<typename Derived>
	class DLDL_GRAMMAR : public ::deamer::external::cpp::ast::TemplateNodeBase<DLDL_GRAMMAR<Derived>, Derived>
	{
	private:
		
	public:
		DLDL_GRAMMAR() = default;
		
		DLDL_GRAMMAR(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_ = {}, std::vector<size_t> baseValues_ = {})
		: deamer::external::cpp::ast::TemplateNodeBase<DLDL_GRAMMAR<Derived>, Derived>(information_, nodes_, baseValues_)
		{
		}
	};

}}}

#endif // DLDL_GRAMMAR_AST_NODE_DLDL_GRAMMAR_H
