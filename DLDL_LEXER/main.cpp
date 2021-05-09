#include "DLDL_LEXER/Ast/Listener/User/Lexicon.h"
#include "DLDL_LEXER/Bison/Parser.h"
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>

std::string ReadInFile(const std::string& file)
{
	const std::ifstream inputFile(file);

	std::ostringstream sstr;
	sstr << inputFile.rdbuf();

	std::string input = sstr.str();

	return input;
}

int main()
{
	const auto parser = DLDL_LEXER::parser::Parser();
	auto* tree = parser.Parse(ReadInFile("Lexicon.dldl"));

	const auto lexiconListener = DLDL_LEXER::ast::listener::user::Lexicon();
	lexiconListener.Dispatch(tree->GetStartNode());

	auto lexiconIr = lexiconListener.GetLexicon();

	for (const auto& terminal : lexiconIr->GetTerminals())
	{
		std::cout << "Terminal:\n"
				<< "\tName: " << terminal.Name << "\n\tRegex: " << terminal.Regex
				  << "\n\tType: " << static_cast<size_t>(terminal.Special) << "\n";
	}
	
	return 0;
}
