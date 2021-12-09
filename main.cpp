#include "DLDL/Argument/Interpreter.h"
#include "DLDL/Flex/Lexer.h"
#include "DLDL/Bison/Parser.h"

int main(int argc, const char* argv[])
{
	auto lexer = DLDL::lexer::Lexer();
	auto tokens = lexer.Tokenize("aaaa");
	for (auto token : tokens)
	{
		token->Print();
	}
	
	auto parser = DLDL::parser::Parser();
	auto tree = parser.Parse("a a a a");
	if (tree == nullptr)
	{
		return -1;
	}
	else
	{
		
	}
	
	
	DLDL::argument::Interpreter interpreter(argc, argv);
	return interpreter.Run();
}
