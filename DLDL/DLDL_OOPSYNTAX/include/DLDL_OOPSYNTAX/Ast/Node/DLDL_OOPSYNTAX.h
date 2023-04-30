#ifndef DLDL_OOPSYNTAX_AST_NODE_DLDL_OOPSYNTAX_H
#define DLDL_OOPSYNTAX_AST_NODE_DLDL_OOPSYNTAX_H

#include <Deamer/External/Cpp/Ast/TemplateNodeBase.h>

namespace DLDL_OOPSYNTAX { namespace ast { namespace node {

	template<typename Derived>
	class DLDL_OOPSYNTAX : public ::deamer::external::cpp::ast::TemplateNodeBase<DLDL_OOPSYNTAX<Derived>, Derived>
	{
	private:
		
	public:
		DLDL_OOPSYNTAX() = default;
		
		DLDL_OOPSYNTAX(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_ = {}, std::vector<size_t> baseValues_ = {})
		: deamer::external::cpp::ast::TemplateNodeBase<DLDL_OOPSYNTAX<Derived>, Derived>(information_, nodes_, baseValues_)
		{
		}
	};

}}}

#endif // DLDL_OOPSYNTAX_AST_NODE_DLDL_OOPSYNTAX_H
