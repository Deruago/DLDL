#include "DLDL_GRAMMAR/Ast/Listener/User/Grammar.h"
#include "DLDL_GRAMMAR/Bison/Parser.h"
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
	const auto parser = DLDL_GRAMMAR::bison::parser::Parser();
	auto* tree = parser.Parse(ReadInFile("Grammar.dldl"));

	auto grammarListener = DLDL_GRAMMAR::ast::listener::user::Grammar();
	grammarListener.Dispatch(tree->GetStartNode());

	auto* grammarIr = grammarListener.GetGrammar();

	for (const auto& nonterminal : grammarIr->GetNonTerminals())
	{
		std::cout << "Nonterminal:\n"
				  << "\tName: " << nonterminal.name << "\n\tAbstraction: " << static_cast<size_t>(nonterminal.abstraction);
		std::cout << "\n\tProduction rules:\n";
		for (auto& productionrule : nonterminal.productionRules)
		{
			std::cout << "\t\tRule: ";
			for (auto& token : productionrule.tokens)
			{
				std::cout << token <<" ";
			}
			std::cout << "\n";
		}
	}

	for (const auto& productionrule : grammarIr->GetProductionRules())
	{
		std::cout << "Production rule:\n";
		std::cout << "\tRule: ";
		for (auto& token : productionrule.tokens)
		{
			std::cout << token << " ";
		}
		std::cout << "\n";
	}
	
	return 0;
}
