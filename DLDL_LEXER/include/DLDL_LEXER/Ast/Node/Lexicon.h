#ifndef DLDL_LEXER_AST_LISTENER_USER_LEXICON_H
#define DLDL_LEXER_AST_LISTENER_USER_LEXICON_H

#include "DLDL_LEXER/Ast/Listener/Listener.h"
#include "DLDL_LEXER/IR/Lexicon.h"

namespace DLDL_LEXER::ast::listener::user
{
	class Lexicon : public ::DLDL_LEXER::ast::listener::Listener
	{
	private:
		mutable DLDL::ir::Lexicon lexicon;

	public:
		Lexicon() = default;
		~Lexicon() override = default;

	public:
		void Listen(const DLDL_LEXER::ast::node::tokendeclaration* node) const override
		{
			auto abstraction = node->Get(DLDL_LEXER::ast::Type::abstraction);
			if (abstraction.empty())
			{
			}
		}
	};
}

#endif // DLDL_LEXER_AST_LISTENER_USER_LEXICON_H
