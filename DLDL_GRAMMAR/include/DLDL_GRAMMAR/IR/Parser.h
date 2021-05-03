#ifndef DLDL_GRAMMAR_IR_PARSER_H
#define DLDL_GRAMMAR_IR_PARSER_H

#include "DLDL_GRAMMAR/Ast/Listener/User/Grammar.h"
#include "DLDL_GRAMMAR/Bison/Parser.h"
#include "DLDL/IR/Parser.h"
#include <string>

namespace DLDL::ir::grammar
{
	class Parser : public ::DLDL::ir::Parser
	{
	public:
		Parser() : ::DLDL::ir::Parser(Type::Grammar)
		{
		}

	public:
		DLDL::ir::IR* GetIR(std::string text) override
		{
			const auto parser = DLDL_GRAMMAR::parser::Parser();
			auto* tree = parser.Parse(text);

			const auto grammarListener = DLDL_GRAMMAR::ast::listener::user::Grammar();
			grammarListener.Dispatch(tree->GetStartNode());

			auto* grammarIr = grammarListener.GetGrammar();

			return grammarIr;
		}
	};
}

#endif // DLDL_GRAMMAR_IR_PARSER_H