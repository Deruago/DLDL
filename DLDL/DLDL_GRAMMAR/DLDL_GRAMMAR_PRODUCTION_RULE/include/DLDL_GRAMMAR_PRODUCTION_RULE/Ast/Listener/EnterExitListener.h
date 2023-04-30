#ifndef DLDL_GRAMMAR_PRODUCTION_RULE_AST_LISTENER_ENTEREXITLISTENER_H
#define DLDL_GRAMMAR_PRODUCTION_RULE_AST_LISTENER_ENTEREXITLISTENER_H

#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/DLDL_GRAMMAR_PRODUCTION_RULE.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Enum/Type.h"

#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/ENDING_USELESS_SYMBOLS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/VERTICAL_SLASH.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/LEFT_PARANTHESIS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/RIGHT_PARANTHESIS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/LEFT_BRACKET.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/RIGHT_BRACKET.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/LEFT_SQUARE_BRACKET.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/RIGHT_SQUARE_BRACKET.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/QUESTION_MARK.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/EXCLAMATION_MARK.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/TILDE.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/ARROW.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/STAR.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/PLUS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/MINUS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/VALUE.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/NUMBER.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/SINGLE_LINE_COMMENT.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/MULTI_LINE_COMMENT.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/SYMBOLS.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/ESCAPE_CHARS.h"


#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/program.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/stmts.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/stmt.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/nested_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/optional_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/zero_or_more_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/not_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/one_or_more_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/or_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/min_max_group.h"
#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Node/extension_group.h"

#include <Deamer/External/Cpp/Ast/Listener.h>
#include <Deamer/Algorithm/Tree/DFS.h>

namespace DLDL_GRAMMAR_PRODUCTION_RULE { namespace ast { namespace listener { 

	class EnterExitListener : public ::deamer::external::cpp::ast::Listener
	{
	private:
	public:
		EnterExitListener() = default;
		~EnterExitListener() override = default;

	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node)  override
		{
			::deamer::algorithm::tree::DFS::Execute::Heap::Search(node,
				&::deamer::external::cpp::ast::Node::GetParent,
				&::deamer::external::cpp::ast::Node::GetNodes,
				&EnterExitListener::DispatchEntry,
				&EnterExitListener::DispatchExit,
				this);
		}

		void DispatchEntry(const ::deamer::external::cpp::ast::Node* node) 
		{
			const auto enumeratedValue = static_cast<DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::ENDING_USELESS_SYMBOLS:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ENDING_USELESS_SYMBOLS*>(node));
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::VERTICAL_SLASH:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VERTICAL_SLASH*>(node));
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_PARANTHESIS:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_PARANTHESIS*>(node));
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_PARANTHESIS:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_PARANTHESIS*>(node));
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_BRACKET:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_BRACKET*>(node));
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_BRACKET:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_BRACKET*>(node));
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_SQUARE_BRACKET:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_SQUARE_BRACKET*>(node));
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_SQUARE_BRACKET:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_SQUARE_BRACKET*>(node));
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::QUESTION_MARK:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::QUESTION_MARK*>(node));
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::EXCLAMATION_MARK:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::EXCLAMATION_MARK*>(node));
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::TILDE:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::TILDE*>(node));
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::ARROW:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ARROW*>(node));
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::STAR:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::STAR*>(node));
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::PLUS:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::PLUS*>(node));
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::MINUS:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MINUS*>(node));
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::VALUE:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VALUE*>(node));
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::NUMBER:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::NUMBER*>(node));
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::SINGLE_LINE_COMMENT:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SINGLE_LINE_COMMENT*>(node));
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::MULTI_LINE_COMMENT:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MULTI_LINE_COMMENT*>(node));
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::SYMBOLS:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SYMBOLS*>(node));
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::ESCAPE_CHARS:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ESCAPE_CHARS*>(node));
				break;
			}


			// Nonterminal cases
			
			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::program:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::program*>(node));
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::stmts:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts*>(node));
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::stmt:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmt*>(node));
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::group:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group*>(node));
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::nested_group:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::nested_group*>(node));
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::optional_group:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group*>(node));
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::zero_or_more_group:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::zero_or_more_group*>(node));
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::not_group:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::not_group*>(node));
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::one_or_more_group:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::one_or_more_group*>(node));
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::or_group:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::or_group*>(node));
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::min_max_group:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group*>(node));
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::extension_group:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::extension_group*>(node));
				break;
			}

			}
		}

		void DispatchExit(const ::deamer::external::cpp::ast::Node* node) 
		{
			const auto enumeratedValue = static_cast<DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::ENDING_USELESS_SYMBOLS:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ENDING_USELESS_SYMBOLS*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::VERTICAL_SLASH:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VERTICAL_SLASH*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_PARANTHESIS:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_PARANTHESIS*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_PARANTHESIS:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_PARANTHESIS*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_BRACKET:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_BRACKET*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_BRACKET:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_BRACKET*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::LEFT_SQUARE_BRACKET:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_SQUARE_BRACKET*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::RIGHT_SQUARE_BRACKET:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_SQUARE_BRACKET*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::QUESTION_MARK:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::QUESTION_MARK*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::EXCLAMATION_MARK:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::EXCLAMATION_MARK*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::TILDE:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::TILDE*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::ARROW:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ARROW*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::STAR:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::STAR*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::PLUS:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::PLUS*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::MINUS:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MINUS*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::VALUE:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VALUE*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::NUMBER:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::NUMBER*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::SINGLE_LINE_COMMENT:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SINGLE_LINE_COMMENT*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::MULTI_LINE_COMMENT:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MULTI_LINE_COMMENT*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::SYMBOLS:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SYMBOLS*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::ESCAPE_CHARS:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ESCAPE_CHARS*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}


			// Nonterminal cases
			
			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::program:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::program*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::stmts:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::stmt:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmt*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::group:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::nested_group:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::nested_group*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::optional_group:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::zero_or_more_group:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::zero_or_more_group*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::not_group:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::not_group*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::one_or_more_group:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::one_or_more_group*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::or_group:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::or_group*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::min_max_group:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR_PRODUCTION_RULE::ast::Type::extension_group:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::extension_group*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			}
		}

		
		virtual void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ENDING_USELESS_SYMBOLS* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VERTICAL_SLASH* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_PARANTHESIS* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_PARANTHESIS* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_BRACKET* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_BRACKET* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_SQUARE_BRACKET* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_SQUARE_BRACKET* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::QUESTION_MARK* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::EXCLAMATION_MARK* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::TILDE* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ARROW* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::STAR* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::PLUS* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MINUS* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VALUE* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::NUMBER* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SINGLE_LINE_COMMENT* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MULTI_LINE_COMMENT* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SYMBOLS* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ESCAPE_CHARS* node) 
		{
		}

		
		virtual void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ENDING_USELESS_SYMBOLS* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VERTICAL_SLASH* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_PARANTHESIS* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_PARANTHESIS* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_BRACKET* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_BRACKET* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_SQUARE_BRACKET* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_SQUARE_BRACKET* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::QUESTION_MARK* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::EXCLAMATION_MARK* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::TILDE* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ARROW* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::STAR* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::PLUS* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MINUS* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VALUE* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::NUMBER* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SINGLE_LINE_COMMENT* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MULTI_LINE_COMMENT* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SYMBOLS* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ESCAPE_CHARS* node) 
		{
		}


		
		virtual void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::program* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmt* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::nested_group* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::zero_or_more_group* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::not_group* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::one_or_more_group* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::or_group* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::extension_group* node) 
		{
		}

		
		virtual void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::program* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmt* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::nested_group* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::zero_or_more_group* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::not_group* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::one_or_more_group* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::or_group* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::extension_group* node) 
		{
		}


		
		virtual void EnterTerminal(const ::deamer::external::cpp::ast::Node* node) 
		{
		}
		
		virtual void ExitTerminal(const ::deamer::external::cpp::ast::Node* node) 
		{
		}
		
		virtual void EnterNonTerminal(const ::deamer::external::cpp::ast::Node* node) 
		{
		}
		
		virtual void ExitNonTerminal(const ::deamer::external::cpp::ast::Node* node) 
		{
		}
		
		virtual void EnterAnything(const ::deamer::external::cpp::ast::Node* node) 
		{
		}

		virtual void ExitAnything(const ::deamer::external::cpp::ast::Node* node) 
		{
		}
	};

}}}

#endif // DLDL_GRAMMAR_PRODUCTION_RULE_AST_LISTENER_ENTEREXITLISTENER_H