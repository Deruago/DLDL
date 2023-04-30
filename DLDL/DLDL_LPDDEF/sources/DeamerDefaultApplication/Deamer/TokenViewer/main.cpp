#include "DLDL_LPDDEF/Flex/Lexer.h"
#include "DLDL_LPDDEF/Bison/Parser.h"
#include "DLDL_LPDDEF/Ast/Relation/NodeEnumToText.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

std::string ReadInFile(const std::string& file)
{
	const std::ifstream inputFile(file);

	std::ostringstream sstr;
	sstr << inputFile.rdbuf();

	std::string input = sstr.str();

	return input;
}

int main(int argc, const char* argv[])
{
	std::vector<std::string> filenames = {"./test.txt"};

	for (auto i = 1; i < argc; i++)
	{
		filenames.push_back(argv[1]);
	}

	for (const auto& filename : filenames)
	{
		std::string text = ReadInFile(filename);

		std::cout << "File: " << filename << "\n";
		std::cout << text << "\n";
		std::cout << "\n";

		auto lexer = DLDL_LPDDEF::flex::lexer::Lexer();
		auto tokens = lexer.Tokenize(text);
		DLDL_LPDDEF::bison::parser::Parser();

		std::cout << "Tokens:\n";
		for (auto token : tokens)
		{
			std::cout << "\tTokenName: " << DLDL_LPDDEF::ast::relation::ConvertEnumToText(static_cast<DLDL_LPDDEF::ast::Type>(token->Type)) << "\n";
			std::cout << "\t\tValue: " << token->Value << "\n";
			std::cout << "\t\tLine: " << std::to_string(token->LineNumber) << "\n";
			std::cout << "\t\tColumn: " << std::to_string(token->ColumnNumber) << "\n";
			std::cout << "\n";

			delete token;
		}
	}

	std::cout << "Compilation succeeded!\n";
	return 0;
}