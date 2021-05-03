#include "DLDL_LEXER/Flex/Lexer.h"
#include <iostream>
#include <string>

int main(int argc, char** argv)
{
	std::string test_lexer_in;

	for (auto i = 1; i < argc; i++)
	{
		test_lexer_in += argv[i];

		if (i < argc)
		{
			test_lexer_in += ' ';
		}
	}

	std::cout << "Setting up lexer\n";
	auto lexer = DLDL_LEXER::lexer::Lexer();
	std::cout << "Done\n";

	std::cout << "Running the lexer with given input: ";
	auto tokens = lexer.Tokenize(test_lexer_in);
	std::cout << "Done\n";

	std::cout << "Now printing the lexemes:\n";
	for (auto* token : tokens)
	{
		token->Print();
		delete token;
	}
	std::cout << "Done\n";
}
