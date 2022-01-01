#ifndef DLDL_GRAMMAR_AST_LISTENER_USER_GRAMMAR_H
#define DLDL_GRAMMAR_AST_LISTENER_USER_GRAMMAR_H

#include "DLDL_GRAMMAR/Ast/Listener/Listener.h"
#include "DLDL_GRAMMAR/IR/Grammar.h"

namespace DLDL_GRAMMAR::ast::listener::user
{
	class Grammar : public ::DLDL_GRAMMAR::ast::listener::Listener
	{
	private:
		mutable DLDL::ir::Grammar* grammar;
		mutable std::string currentNonTerminal;

	public:
		Grammar()
		{
			grammar = new ::DLDL::ir::Grammar();
		}
		~Grammar() override = default;

	public:
		void Listen(const DLDL_GRAMMAR::ast::node::abstraction_declaration* node) override
		{
			const auto name = node->Get(Type::NONTERMINAL)[0]->GetValue();
			const auto abstraction = node->Get(Type::abstraction)[0]->GetNodes()[0]->GetType();
			const auto abstraction_downcast = static_cast<Type>(abstraction);
			::deamer::language::type::definition::object::main::NonTerminalAbstraction
				abstractionType = deamer::language::type::definition::object::main::
					NonTerminalAbstraction::Standard;
			bool inlineNonTerminal = false;
			switch (abstraction_downcast)
			{
			case Type::GROUP_ABSTRACTION:
				abstractionType =
					deamer::language::type::definition::object::main::NonTerminalAbstraction::Group;
				break;
			case Type::START_ABSTRACTION:
				grammar->SetStartType(name);
				break;
			case Type::INLINE_ABSTRACTION:
				inlineNonTerminal = true;
				break;
			case Type::INLINE_GROUP_ABSTRACTION:
				inlineNonTerminal = true;
				abstractionType =
					deamer::language::type::definition::object::main::NonTerminalAbstraction::Group;
				break;
			case Type::UNKNOWN_ABSTRACTION:
				abstractionType = deamer::language::type::definition::object::main::
					NonTerminalAbstraction::Standard;
				break;
			}

			grammar->SetAbstraction(name, abstractionType);
			grammar->SetInline(name, inlineNonTerminal);
		}

		void Listen(const DLDL_GRAMMAR::ast::node::definition* node) override
		{
			const auto name = node->Get(Type::NONTERMINAL)[0]->GetValue();
			const auto abstraction_ = node->Get(Type::abstraction);
			deamer::language::type::definition::object::main::NonTerminalAbstraction
				abstractionType = deamer::language::type::definition::object::main::
					NonTerminalAbstraction::Standard;
			bool inlineNonTerminal = false;

			if (!abstraction_.empty())
			{
				const auto abstraction_downcast =
					static_cast<Type>(abstraction_[0]->GetNodes()[0]->GetType());
				switch (abstraction_downcast)
				{
				case Type::GROUP_ABSTRACTION:
					abstractionType = deamer::language::type::definition::object::main::
						NonTerminalAbstraction::Group;
					break;
				case Type::START_ABSTRACTION:
					grammar->SetStartType(name);
					break;
				case Type::INLINE_ABSTRACTION:
					inlineNonTerminal = true;
					break;
				case Type::INLINE_GROUP_ABSTRACTION:
					inlineNonTerminal = true;
					abstractionType = deamer::language::type::definition::object::main::
						NonTerminalAbstraction::Group;
					break;
				case Type::UNKNOWN_ABSTRACTION:
					abstractionType = deamer::language::type::definition::object::main::
						NonTerminalAbstraction::Standard;
					break;
				}
			}

			grammar->SetAbstraction(name, abstractionType);
			grammar->SetInline(name, inlineNonTerminal);

			currentNonTerminal = name;
		}

		void Listen(const DLDL_GRAMMAR::ast::node::PRODUCTION_RULE* node) override
		{
			grammar->AddProductionRules(currentNonTerminal, node->GetValue());
		}

		DLDL::ir::Grammar* GetGrammar(DLDL::ir::Language* language = nullptr) const
		{
			grammar->FillInUnknownReferences(language);
			return grammar;
		}
	};
}

#endif // DLDL_GRAMMAR_AST_LISTENER_USER_GRAMMAR_H
