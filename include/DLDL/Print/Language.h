#ifndef DLDL_PRINT_LANGUAGE_H
#define DLDL_PRINT_LANGUAGE_H

#include "DLDL/IR/Language.h"
#include <iostream>


#include "DLDL_GRAMMAR/IR/Grammar.h"
#include "DLDL_LEXER/IR/Lexicon.h"

namespace DLDL::print
{
	class Language
	{
	private:
		std::vector<::DLDL::ir::Language*> languages;
	public:
		Language(std::vector<::DLDL::ir::Language*> languages_) : languages(languages_)
		{
		}
	public:
		void Print()
		{
			for (auto* language : languages)
			{
				Print(language, 0);
			}
		}

		std::string GetTabDepth(size_t size)
		{
			std::string output;
			for (int i = 0; i < size; i++)
			{
				output += '\t';
			}
			return output;
		}

		void Print(DLDL::ir::Language* language, size_t offset = 0)
		{
			std::cout << GetTabDepth(offset) << "Language: " << language->GetName() << '\n';
			for (auto* IR : language->GetIRs())
			{
				std::cout << GetTabDepth(offset + 1) << "Type: " << static_cast<size_t>(IR->GetType())
						  << '\n';
				switch (IR->GetType())
				{
				case ir::Type::Unknown:
					break;
				case ir::Type::Lexicon:
					Print(static_cast<ir::Lexicon*>(IR), offset + 2);
					break;
				case ir::Type::Grammar:
					Print(static_cast<ir::Grammar*>(IR), offset + 2);
					break;
				case ir::Type::Precedence:
					break;
				case ir::Type::Associativity:
					break;
				case ir::Type::Generation:
					break;
				case ir::Type::Identity:
					break;
				case ir::Type::AstOptimization:
					break;
				case ir::Type::AstTranslation:
					break;
				case ir::Type::Coloring:
					break;
				case ir::Type::Formatting:
					break;
				case ir::Type::Documentation:
					break;
				default:
					break;
				}
			}
			
			for (auto* child : language->GetChildren())
			{
				Print(child, offset + 1);
			}
		}

		void Print(ir::Lexicon* ir, size_t size)
		{
			std::cout << GetTabDepth(size) << "Terminals:\n";
			for (auto terminal : ir->GetTerminals())
			{
				std::cout << GetTabDepth(size + 1) << "Terminal:\n";
				std::cout << GetTabDepth(size + 2) << "Name: " << terminal.Name << '\n';
				std::cout << GetTabDepth(size + 2) << "Regex: " << terminal.Regex << '\n';
				std::cout << GetTabDepth(size + 2)
						  << "Special: " << static_cast<size_t>(terminal.Special) << '\n';
			}
		}

		void Print(ir::Grammar* ir, size_t size)
		{
			std::cout << GetTabDepth(size) << "NonTerminals:\n";
			for (const auto& nonterminal : ir->GetNonTerminals())
			{
				std::cout << GetTabDepth(size + 1) << "NonTerminal:\n";
				std::cout << GetTabDepth(size + 2) << "Name: " << nonterminal.name << '\n';
				std::cout << GetTabDepth(size + 2) << "Abstraction: " << static_cast<size_t>(nonterminal.abstraction) << '\n';
				std::cout << GetTabDepth(size + 2) << "Production rules:\n";
				for (auto& productionrule : nonterminal.productionRules)
				{
					std::cout << GetTabDepth(size + 3) << "Rule: ";
					for (auto& token : productionrule.tokens)
					{
						std::cout << token << " ";
					}
					std::cout << "\n";
				}
			}

			std::cout << GetTabDepth(size) << "Production rules:\n";
			for (const auto& productionrule : ir->GetProductionRules())
			{
				std::cout << GetTabDepth(size + 1) << "Production rule: ";
				for (auto& token : productionrule.tokens)
				{
					std::cout << token << " ";
				}
				std::cout << "\n";
			}
		}
	};
}

#endif // DLDL_PRINT_LANGUAGE_H