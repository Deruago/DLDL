#ifndef DLDL_LEXER_AST_NODE_DLDL_LEXER_H
#define DLDL_LEXER_AST_NODE_DLDL_LEXER_H

#include <Deamer/External/Cpp/Ast/TemplateNodeBase.h>

namespace DLDL_LEXER { namespace ast { namespace node {

	template<typename Derived>
	class DLDL_LEXER : public ::deamer::external::cpp::ast::TemplateNodeBase<DLDL_LEXER<Derived>, Derived>
	{
	private:
		
	public:
		DLDL_LEXER() = default;
		
		DLDL_LEXER(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_ = {}, std::vector<size_t> baseValues_ = {})
		: deamer::external::cpp::ast::TemplateNodeBase<DLDL_LEXER<Derived>, Derived>(information_, nodes_, baseValues_)
		{
		}
	};

}}}

#endif // DLDL_LEXER_AST_NODE_DLDL_LEXER_H
