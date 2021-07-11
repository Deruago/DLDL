#ifndef DLDL_GRAMMAR_PRODUCTION_RULE_AST_NODE_DLDL_GRAMMAR_PRODUCTION_RULE_H
#define DLDL_GRAMMAR_PRODUCTION_RULE_AST_NODE_DLDL_GRAMMAR_PRODUCTION_RULE_H

#include <Deamer/External/Cpp/Ast/TemplateNodeBase.h>

namespace DLDL_GRAMMAR_PRODUCTION_RULE { namespace ast { namespace node {

	template<typename Derived>
	class DLDL_GRAMMAR_PRODUCTION_RULE : public ::deamer::external::cpp::ast::TemplateNodeBase<DLDL_GRAMMAR_PRODUCTION_RULE<Derived>, Derived>
	{
	private:
		
	public:
		DLDL_GRAMMAR_PRODUCTION_RULE() = default;
		
		DLDL_GRAMMAR_PRODUCTION_RULE(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_ = {}, std::vector<size_t> baseValues_ = {})
		: deamer::external::cpp::ast::TemplateNodeBase<DLDL_GRAMMAR_PRODUCTION_RULE<Derived>, Derived>(information_, nodes_, baseValues_)
		{
		}
	};

}}}

#endif // DLDL_GRAMMAR_PRODUCTION_RULE_AST_NODE_DLDL_GRAMMAR_PRODUCTION_RULE_H
