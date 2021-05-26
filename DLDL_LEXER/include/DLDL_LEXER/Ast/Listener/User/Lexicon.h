#ifndef DLDL_LEXER_AST_LISTENER_USER_LEXICON_H
#define DLDL_LEXER_AST_LISTENER_USER_LEXICON_H

#include "DLDL_LEXER/Ast/Listener/Listener.h"
#include "DLDL_LEXER/IR/Lexicon.h"

namespace DLDL_LEXER::ast::listener::user
{
	class Lexicon : public ::DLDL_LEXER::ast::listener::Listener
	{
	private:
		mutable DLDL::ir::Lexicon* lexicon;

	public:
		Lexicon()
		{
			lexicon = new ::DLDL::ir::Lexicon();
		}
		~Lexicon() override = default;

	public:
		std::string FilterRegex(const std::string& unfilteredRegex_) const
		{
			std::string unfilteredRegex = unfilteredRegex_;
			unfilteredRegex.erase(0, 1);

			char currentChar = unfilteredRegex[0];
			while (currentChar == ' ' || currentChar == '\t')
			{
				unfilteredRegex.erase(0, 1);
				currentChar = unfilteredRegex[0];
			}
			
			std::string newRegex;

			for (auto character : unfilteredRegex)
			{
				switch (character)
				{
				case '\\':
					newRegex += "\\";
					newRegex += character;
					break;
				default:
					newRegex += character;
					break;
				}
			}

			return newRegex;
		}

		void Listen(const DLDL_LEXER::ast::node::tokendeclaration* node) override
		{
			deamer::language::type::definition::object::main::SpecialType abstractionType;
			auto abstraction = node->Get(DLDL_LEXER::ast::Type::abstraction);

			if (abstraction.empty())
			{
				abstractionType =
					deamer::language::type::definition::object::main::SpecialType::Standard;
			}
			else
			{
				const auto abstraction_downcast = static_cast<Type>(abstraction[0]->GetNodes()[0]->GetType());
				switch (abstraction_downcast)
				{
				case Type::DELETE_ABSTRACTION:
				{
					abstractionType =
						deamer::language::type::definition::object::main::SpecialType::Delete;
					break;
				}
				case Type::CRASH_ABSTRACTION:
				{
					abstractionType =
						deamer::language::type::definition::object::main::SpecialType::Crash;
					break;
				}
				case Type::IGNORE_ABSTRACTION:
				{
					abstractionType =
						deamer::language::type::definition::object::main::SpecialType::Ignore;
					break;
				}
				case Type::NOVALUE_ABSTRACTION:
				{
					abstractionType =
						deamer::language::type::definition::object::main::SpecialType::NoValue;
					break;
				}
				case Type::STANDARD_ABSTRACTION:
				{
					abstractionType =
						deamer::language::type::definition::object::main::SpecialType::Standard;
					break;
				}
				case Type::UNKNOWN_ABSTRACTION:
				{
					abstractionType =
						deamer::language::type::definition::object::main::SpecialType::Standard;
					break;
				}
				}
			}

			const std::string name = node->Get(Type::TERMINAL)[0]->GetValue();
			const std::string regex = FilterRegex(node->Get(Type::REGEX)[0]->GetValue());

			lexicon->AddTerminal(name, regex, abstractionType);
		}

		DLDL::ir::Lexicon* GetLexicon() const
		{
			return lexicon;
		}
	};
}

#endif // DLDL_LEXER_AST_LISTENER_USER_LEXICON_H
