#ifndef DLDL_GRAMMAR_IR_GRAMMAR_H
#define DLDL_GRAMMAR_IR_GRAMMAR_H

#include "DLDL/IR/IR.h"
#include <Deamer/Language/Type/Definition/Property/Main/Grammar.h>
#include <deque>
#include <optional>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace DLDL_GRAMMAR_PRODUCTION_RULE
{
	namespace ir
	{
		struct ProductionRule;
	}
}

namespace DLDL::ir
{
	class Language;

	struct ProductionRule
	{
		std::string nonterminal;
		std::vector<std::string> tokens;

		ProductionRule(std::string nonterminal_, std::vector<std::string> tokens_)
			: nonterminal(nonterminal_),
			  tokens(std::move(tokens_))
		{
		}

		ProductionRule(std::string nonterminal_,
					   const DLDL_GRAMMAR_PRODUCTION_RULE::ir::ProductionRule& productionRule);

		bool operator==(const ProductionRule& rhs) const
		{
			if (this == &rhs)
			{
				return true;
			}

			if (this->nonterminal != rhs.nonterminal)
			{
				return false;
			}

			if (this->tokens.size() != rhs.tokens.size())
			{
				return false;
			}

			for (auto i = 0; i < this->tokens.size(); i++)
			{
				if (this->tokens[i] != rhs.tokens[i])
				{
					return false;
				}
			}

			return true;
		}
	};

	struct NonTerminal
	{
		std::string name;
		std::vector<ProductionRule> productionRules;
		deamer::language::type::definition::object::main::NonTerminalAbstraction abstraction;
		bool inlineNonTerminal;

		NonTerminal(
			const std::string& name_,
			deamer::language::type::definition::object::main::NonTerminalAbstraction abstraction_ =
				deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard,
			bool inlineNonTerminal_ = false)
			: name(name_),
			  abstraction(abstraction_),
			  inlineNonTerminal(inlineNonTerminal_)
		{
		}

		void AddProduction(const ProductionRule& productionRule)
		{
			for (const auto& ourProductionRule : productionRules)
			{
				if (ourProductionRule == productionRule)
				{
					return;
				}
			}

			productionRules.push_back(productionRule);
		}

		bool operator==(const NonTerminal& rhs) const
		{
			if (this == &rhs)
			{
				return true;
			}

			return this->name == rhs.name;
		}
	};

	class Grammar : public DLDL::ir::IR
	{
	private:
		std::deque<NonTerminal> nonterminals;
		std::vector<ProductionRule> productionRules;
		std::vector<std::string> unknownReferences;

	public:
		Grammar();

	public:
		void AddNonTerminal(
			const std::string& name,
			deamer::language::type::definition::object::main::NonTerminalAbstraction abstraction =
				deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard,
			bool inlineNonTerminal = false);

		NonTerminal& GetNonTerminal(const std::string& name);

		void SetAbstraction(
			const std::string& name,
			deamer::language::type::definition::object::main::NonTerminalAbstraction abstraction);

		void SetInline(const std::string& name, bool inlineNonTerminal);

		std::optional<std::vector<DLDL::ir::ProductionRule>>
		ConvertToProductionRule(std::string text, std::string nonterminal);

		void AddProductionRules(const std::string& nonterminal, const std::string& productionrule);

		std::deque<NonTerminal> GetNonTerminals() const;

		std::vector<ProductionRule> GetProductionRules() const;

		std::vector<std::string> GetUnknownReferences() const;

		void SetStartType(const std::string& name);

		bool DoesProductionRuleExist(const ProductionRule& ourProductionRule) const;

		bool DoesNonTerminalExist(const NonTerminal& ourNonTerminal) const;

		void FillInUnknownReferences(DLDL::ir::Language* language) override;
	};
}

#endif // DLDL_GRAMMAR_IR_GRAMMAR_H
