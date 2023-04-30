#ifndef DLDL_LDOSTRUCT_AST_NODE_DLDL_LDOSTRUCT_H
#define DLDL_LDOSTRUCT_AST_NODE_DLDL_LDOSTRUCT_H

#include <Deamer/External/Cpp/Ast/TemplateNodeBase.h>

namespace DLDL_LDOSTRUCT { namespace ast { namespace node {

	template<typename Derived>
	class DLDL_LDOSTRUCT : public ::deamer::external::cpp::ast::TemplateNodeBase<DLDL_LDOSTRUCT<Derived>, Derived>
	{
	private:
		
	public:
		DLDL_LDOSTRUCT() = default;
		
		DLDL_LDOSTRUCT(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_ = {}, std::vector<size_t> baseValues_ = {})
		: deamer::external::cpp::ast::TemplateNodeBase<DLDL_LDOSTRUCT<Derived>, Derived>(information_, nodes_, baseValues_)
		{
		}
	};

}}}

#endif // DLDL_LDOSTRUCT_AST_NODE_DLDL_LDOSTRUCT_H
