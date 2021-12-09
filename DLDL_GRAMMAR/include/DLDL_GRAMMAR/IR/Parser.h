#ifndef DLDL_GRAMMAR_IR_PARSER_H
#define DLDL_GRAMMAR_IR_PARSER_H

#include "DLDL/IR/Parser.h"
#include "DLDL_GRAMMAR/Ast/Listener/User/Grammar.h"
#include "DLDL_GRAMMAR/Bison/Parser.h"
#include <memory>
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
			auto tree = std::unique_ptr<deamer::external::cpp::ast::Tree>(parser.Parse(text));
			if (tree == nullptr || tree->GetStartNode() == nullptr)
			{
				return new DLDL::ir::Grammar();
			}

			auto grammarListener = DLDL_GRAMMAR::ast::listener::user::Grammar();
			grammarListener.Dispatch(tree->GetStartNode());

			auto* grammarIr = grammarListener.GetGrammar();

			return grammarIr;
		}
	};
}

#endif // DLDL_GRAMMAR_IR_PARSER_H
