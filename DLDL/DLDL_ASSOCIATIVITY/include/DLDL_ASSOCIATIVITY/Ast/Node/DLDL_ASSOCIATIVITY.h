#ifndef DLDL_ASSOCIATIVITY_AST_NODE_DLDL_ASSOCIATIVITY_H
#define DLDL_ASSOCIATIVITY_AST_NODE_DLDL_ASSOCIATIVITY_H

#include <Deamer/External/Cpp/Ast/TemplateNodeBase.h>

namespace DLDL_ASSOCIATIVITY { namespace ast { namespace node {

	template<typename Derived>
	class DLDL_ASSOCIATIVITY : public ::deamer::external::cpp::ast::TemplateNodeBase<DLDL_ASSOCIATIVITY<Derived>, Derived>
	{
	private:
		
	public:
		DLDL_ASSOCIATIVITY() = default;
		
		DLDL_ASSOCIATIVITY(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_ = {}, std::vector<size_t> baseValues_ = {})
		: deamer::external::cpp::ast::TemplateNodeBase<DLDL_ASSOCIATIVITY<Derived>, Derived>(information_, nodes_, baseValues_)
		{
		}
	};

}}}

#endif // DLDL_ASSOCIATIVITY_AST_NODE_DLDL_ASSOCIATIVITY_H
