#ifndef DLDL_GRAMMAR_IR_GRAMMAR_H
#define DLDL_GRAMMAR_IR_GRAMMAR_H

#include "DLDL/IR/IR.h"
#include <Deamer/Language/Type/Definition/Property/Main/Grammar.h>
#include <deque>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace DLDL::ir
{
	struct ProductionRule
	{
		std::string nonterminal;
		std::vector<std::string> tokens;

		ProductionRule(std::string nonterminal_, std::vector<std::string> tokens_)
			: nonterminal(nonterminal_), tokens(std::move(tokens_))
		{
		}
	};
	
	struct NonTerminal
	{
		std::string name;
		std::vector<ProductionRule> productionRules;
		deamer::language::type::definition::object::main::NonTerminalAbstraction abstraction;

		NonTerminal(const std::string& name_, deamer::language::type::definition::object::main::NonTerminalAbstraction abstraction_ = deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard)
			: name(name_), abstraction(abstraction_)
		{
		}
		
		void AddProduction(const ProductionRule& productionRule)
		{
			productionRules.push_back(productionRule);
		}
	};
	
	class Grammar : public DLDL::ir::IR
	{
	private:
		std::deque<NonTerminal> nonterminals;
		std::vector<ProductionRule> productionRules;
		
	public:
		Grammar() : IR(DLDL::ir::Type::Grammar)
		{
		}

	public:
		void
		AddNonTerminal(const std::string& name,
		               deamer::language::type::definition::object::main::NonTerminalAbstraction abstraction = deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard)
		{
			for (NonTerminal& nonterminal : nonterminals)
			{
				if (nonterminal.name == name)
				{
					if (nonterminal.abstraction == deamer::language::type::definition::object::
													   main::NonTerminalAbstraction::Standard)
					{
						nonterminal.abstraction = abstraction;
						return;
					}
				}
			}
			
			nonterminals.emplace_back(name, abstraction);
		}

		NonTerminal& GetNonTerminal(const std::string& name)
		{
			for (auto& nonterminal : nonterminals)
			{
				if (nonterminal.name == name)
				{
					return nonterminal;
				}
			}

			AddNonTerminal(name);
			return GetNonTerminal(name);
		}

		void SetAbstraction(const std::string& name, deamer::language::type::definition::object::main::NonTerminalAbstraction abstraction)
		{
			if (GetNonTerminal(name).abstraction == deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard)
			{
				GetNonTerminal(name).abstraction = abstraction;
			}
		}

		ProductionRule ConvertToProductionRule(std::string text, std::string nonterminal)
		{
			std::vector<std::string> tokens;

			std::string tmp;

			char currentcharacter = text[0];
			while (currentcharacter == ' ' || currentcharacter == '\t')
			{
				text.erase(0, 1);
				if (text.empty())
				{
					throw std::logic_error("It is not a production rule!");
				}
				currentcharacter = text[0];
			}

			std::string textLowered;
			for (auto character : text)
			{
				textLowered += ::tolower(character);
			}

			// DLDL way for defining nothing is using empty, but epsilon may also be used.
			if (textLowered == "empty" || textLowered == "epsilon")
			{
				return ProductionRule(nonterminal, {});
			}
			std::cout << "\n\n\n\n\n\t\t\tText: " << text << "\n\n\n\n\n\n\n\n";
			for (auto character : text)
			{
				switch (character)
				{
				case ' ':
				case '\t':
					if (!tmp.empty())
					{
						tokens.push_back(tmp);					
					}
					tmp.clear();
					break;
				default:
					tmp += character;
					break;
				}
			}

			if (!tmp.empty())
			{
				tokens.push_back(tmp);
				tmp.clear();
			}

			return ProductionRule(nonterminal, tokens);
		}

		void AddProductionRules(const std::string& nonterminal, const std::string& productionrule)
		{
			// If the input line is not a production rule it internally throws an error.
			try
			{
				const auto productionRuleConverted = ConvertToProductionRule(productionrule, nonterminal);

				GetNonTerminal(nonterminal).AddProduction(productionRuleConverted);
				productionRules.push_back(productionRuleConverted);
			}
			catch(std::logic_error)
			{
				return;
			}
		}

		std::deque<NonTerminal> GetNonTerminals() const
		{
			return nonterminals;
		}

		std::vector<ProductionRule> GetProductionRules() const
		{
			return productionRules;
		}

		void SetStartType(const std::string& name)
		{
			size_t index = 0;
			bool found = false;
			for (const auto& nonterminal : nonterminals)
			{
				if (nonterminal.name == name)
				{
					found = true;
					break;
				}
				index++;
			}

			if (found)
			{
				const auto& nonterminal = nonterminals[index];
				nonterminals.erase(nonterminals.begin() + index);
				nonterminals.push_front(nonterminal);
			}
			else
			{
				nonterminals.emplace_front(name);
			}
		}
	};
}

#endif // DLDL_GRAMMAR_IR_GRAMMAR_H
