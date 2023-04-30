#ifndef DLDL_VALUE_AST_NODE_DLDL_VALUE_H
#define DLDL_VALUE_AST_NODE_DLDL_VALUE_H

#include <Deamer/External/Cpp/Ast/TemplateNodeBase.h>

namespace DLDL_VALUE { namespace ast { namespace node {

	template<typename Derived>
	class DLDL_VALUE : public ::deamer::external::cpp::ast::TemplateNodeBase<DLDL_VALUE<Derived>, Derived>
	{
	private:
		
	public:
		DLDL_VALUE() = default;
		
		DLDL_VALUE(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_ = {}, std::vector<size_t> baseValues_ = {})
		: deamer::external::cpp::ast::TemplateNodeBase<DLDL_VALUE<Derived>, Derived>(information_, nodes_, baseValues_)
		{
		}
	};

}}}

#endif // DLDL_VALUE_AST_NODE_DLDL_VALUE_H
