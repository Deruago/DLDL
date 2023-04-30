#include "DLDL_GRAMMAR/IR/Grammar.h"
#include "DLDL/IR/Language.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Listener/User/FillGroup.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Bison/Parser.h"
#include "DLDL_LEXER/IR/Lexicon.h"

DLDL::ir::ProductionRule::ProductionRule(
	std::string nonterminal_,
	const DLDL_GRAMMAR_PRODUCTION_RULE::ir::ProductionRule& productionRule)
	: ProductionRule(nonterminal_, productionRule.GetStringRepresentation())
{
}

::DLDL::ir::Grammar::Grammar() : IR(DLDL::ir::Type::Grammar)
{
}

void DLDL::ir::Grammar::AddNonTerminal(
	const std::string& name,
	deamer::language::type::definition::object::main::NonTerminalAbstraction abstraction,
	bool inlineNonTerminal)
{
	for (NonTerminal& nonterminal : nonterminals)
	{
		if (nonterminal.name == name)
		{
			nonterminal.inlineNonTerminal = inlineNonTerminal;

			if (nonterminal.abstraction ==
				deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard)
			{
				nonterminal.abstraction = abstraction;
				return;
			}
		}
	}

	nonterminals.emplace_back(name, abstraction, inlineNonTerminal);
}

void DLDL::ir::Grammar::SetAbstraction(
	const std::string& name,
	deamer::language::type::definition::object::main::NonTerminalAbstraction abstraction)
{
	if (GetNonTerminal(name).abstraction ==
		deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard)
	{
		GetNonTerminal(name).abstraction = abstraction;
	}
}

void DLDL::ir::Grammar::SetInline(const std::string& name, bool inlineNonTerminal)
{
	GetNonTerminal(name).inlineNonTerminal = inlineNonTerminal;
}

bool DLDL::ir::Grammar::DoesProductionRuleExist(const ProductionRule& ourProductionRule) const
{
	for (const auto& productionRule : productionRules)
	{
		if (productionRule == ourProductionRule)
		{
			return true;
		}
	}

	return false;
}

bool DLDL::ir::Grammar::DoesNonTerminalExist(const std::string& name_) const
{
	for (const auto& nonterminal : nonterminals)
	{
		if (nonterminal.name == name_)
		{
			return true;
		}
	}

	return false;
}

bool DLDL::ir::Grammar::DoesNonTerminalExist(const NonTerminal& ourNonTerminal) const
{
	for (const auto& nonterminal : nonterminals)
	{
		if (nonterminal == ourNonTerminal)
		{
			return true;
		}
	}

	return false;
}

void DLDL::ir::Grammar::FillInUnknownReferences(DLDL::ir::Language* language)
{
	std::set<std::string> knownReferences;
	for (auto nonterminal : nonterminals)
	{
		knownReferences.insert(nonterminal.name);
	}

	if (language == nullptr)
	{
		return;
	}

	DLDL::ir::Lexicon* lexicon =
		static_cast<DLDL::ir::Lexicon*>(language->GetIRIfExists(Type::Lexicon));
	if (lexicon == nullptr)
	{
		return;
	}

	for (auto terminal : lexicon->GetTerminals())
	{
		knownReferences.insert(terminal.Name);
	}

	for (auto terminal : lexicon->GetImportedTerminals())
	{
		knownReferences.insert(terminal.Name);
	}

	for (auto productionRule : productionRules)
	{
		for (auto token : productionRule.tokens)
		{
			if (knownReferences.find(token) == knownReferences.end())
			{
				auto alreadyFound =
					std::find(std::cbegin(unknownReferences), std::cend(unknownReferences),
							  token) != std::cend(unknownReferences);
				if (!alreadyFound)
				{
					unknownReferences.push_back(token);
				}
			}
		}
	}
}

bool DLDL::ir::Grammar::IsUnknownReference(const std::string& nonterminal)
{
	for (auto unknownReference : GetUnknownReferences())
	{
		if (unknownReference == nonterminal)
		{
			return true;
		}
	}

	return false;
}

std::optional<std::vector<DLDL::ir::ProductionRule>>
DLDL::ir::Grammar::ConvertToProductionRule(std::string text, std::string nonterminal,
										   const std::vector<std::string>& terminals)
{
	if (text.empty())
	{
		return {};
	}

	char currentCharacter = text[0];
	while (::isspace(currentCharacter) || currentCharacter == '|' // Starting with a | is useless
		   || currentCharacter == ';'							  // Starting with a ; is useless
	)
	{
		text.erase(0, 1);
		if (text.empty())
		{
			return {};
		}

		currentCharacter = text[0];
	}

	std::vector<std::string> tokens;

	const auto parser = DLDL_GRAMMAR_PRODUCTION_RULE::bison::parser::Parser();
	const auto* const ast = parser.Parse(text);
	if (ast == nullptr || ast->GetStartNode() == nullptr)
	{
		delete ast;
		return {};
	}

	auto fillGroup = DLDL_GRAMMAR_PRODUCTION_RULE::ast::listener::user::FillGroup(terminals);
	fillGroup.Dispatch(ast->GetStartNode());

	auto* const group = fillGroup.GetGroup();
	const auto environment = group->GetEnvironment(this);

	for (const auto& generatedNonTerminal : environment.nonterminals)
	{
		if (DoesNonTerminalExist(NonTerminal(generatedNonTerminal.name)))
		{
			continue;
		}

		AddNonTerminal(
			generatedNonTerminal.name,
			deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard,
			generatedNonTerminal.vt == DLDL_GRAMMAR_PRODUCTION_RULE::ir::ValueType::generated);
		NonTerminal& currentNonTerminal = GetNonTerminal(generatedNonTerminal.name);

		for (const auto& productionRule : generatedNonTerminal.productionRules)
		{
			const ProductionRule convertedProductionRule(generatedNonTerminal.name, productionRule);
			currentNonTerminal.AddProduction(convertedProductionRule);
			productionRules.emplace_back(convertedProductionRule);
		}
	}

	std::vector<ProductionRule> newProductionRules;
	for (const auto& productionRule : environment.currentProductionRules)
	{
		newProductionRules.emplace_back(nonterminal, productionRule);
	}

	delete ast;
	delete group;

	return {newProductionRules};
}

void DLDL::ir::Grammar::AddProductionRules(const std::string& nonterminal,
										   const std::string& productionrule)
{
	const auto productionRulesConverted = ConvertToProductionRule(productionrule, nonterminal);
	if (!productionRulesConverted.has_value())
	{
		return;
	}

	for (const auto& productionRule : productionRulesConverted.value())
	{
		if (DoesProductionRuleExist(productionRule))
		{
			continue;
		}

		GetNonTerminal(nonterminal).AddProduction(productionRule);
		productionRules.push_back(productionRule);
	}
}

std::deque<DLDL::ir::NonTerminal> DLDL::ir::Grammar::GetNonTerminals() const
{
	return nonterminals;
}

std::vector<DLDL::ir::ProductionRule> DLDL::ir::Grammar::GetProductionRules() const
{
	return productionRules;
}

std::vector<std::string> DLDL::ir::Grammar::GetUnknownReferences() const
{
	return unknownReferences;
}

void DLDL::ir::Grammar::SetStartType(const std::string& name)
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

DLDL::ir::NonTerminal& DLDL::ir::Grammar::GetNonTerminal(const std::string& name)
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
