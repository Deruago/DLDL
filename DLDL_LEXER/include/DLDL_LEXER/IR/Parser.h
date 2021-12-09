#ifndef DLDL_LEXER_IR_PARSER_H
#define DLDL_LEXER_IR_PARSER_H

#include "DLDL/IR/Parser.h"
#include "DLDL_LEXER/Ast/Listener/User/Lexicon.h"
#include "DLDL_LEXER/Bison/Parser.h"
#include <memory>
#include <string>

namespace DLDL::ir::lexer
{
	class Parser : public ::DLDL::ir::Parser
	{
	public:
		Parser() : ::DLDL::ir::Parser(Type::Lexicon)
		{
		}

	public:
		DLDL::ir::IR* GetIR(std::string text) override
		{
			const auto parser = DLDL_LEXER::parser::Parser();
			auto tree = std::unique_ptr<deamer::external::cpp::ast::Tree>(parser.Parse(text));
			if (tree == nullptr || tree->GetStartNode() == nullptr)
			{
				return new DLDL::ir::Lexicon();
			}

			auto lexiconListener = DLDL_LEXER::ast::listener::user::Lexicon();

			lexiconListener.Dispatch(tree->GetStartNode());

			auto* lexiconIr = lexiconListener.GetLexicon();

			return lexiconIr;
		}
	};
}

#endif // DLDL_LEXER_IR_PARSER_H
