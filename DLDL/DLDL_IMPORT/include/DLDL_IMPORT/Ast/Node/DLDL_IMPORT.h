#ifndef DLDL_IMPORT_AST_NODE_DLDL_IMPORT_H
#define DLDL_IMPORT_AST_NODE_DLDL_IMPORT_H

#include <Deamer/External/Cpp/Ast/TemplateNodeBase.h>

namespace DLDL_IMPORT { namespace ast { namespace node {

	template<typename Derived>
	class DLDL_IMPORT : public ::deamer::external::cpp::ast::TemplateNodeBase<DLDL_IMPORT<Derived>, Derived>
	{
	private:
		
	public:
		DLDL_IMPORT() = default;
		
		DLDL_IMPORT(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_ = {}, std::vector<size_t> baseValues_ = {})
		: deamer::external::cpp::ast::TemplateNodeBase<DLDL_IMPORT<Derived>, Derived>(information_, nodes_, baseValues_)
		{
		}
	};

}}}

#endif // DLDL_IMPORT_AST_NODE_DLDL_IMPORT_H
