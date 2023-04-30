#ifndef DLDL_VALUE_AST_LISTENER_ENTEREXITLISTENER_H
#define DLDL_VALUE_AST_LISTENER_ENTEREXITLISTENER_H

#include "DLDL_VALUE/Ast/Node/DLDL_VALUE.h"
#include "DLDL_VALUE/Ast/Enum/Type.h"

#include "DLDL_VALUE/Ast/Node/SINGLE_COMMENT.h"
#include "DLDL_VALUE/Ast/Node/MULTI_COMMENT.h"
#include "DLDL_VALUE/Ast/Node/LEFT_PARANTHESIS.h"
#include "DLDL_VALUE/Ast/Node/RIGHT_PARANTHESIS.h"
#include "DLDL_VALUE/Ast/Node/LEFT_BRACKET.h"
#include "DLDL_VALUE/Ast/Node/RIGHT_BRACKET.h"
#include "DLDL_VALUE/Ast/Node/LEFT_SQUARE_BRACKET.h"
#include "DLDL_VALUE/Ast/Node/RIGHT_SQUARE_BRACKET.h"
#include "DLDL_VALUE/Ast/Node/DOT.h"
#include "DLDL_VALUE/Ast/Node/VALUE_CHARACTERISTIC.h"
#include "DLDL_VALUE/Ast/Node/VALUE_RULE.h"
#include "DLDL_VALUE/Ast/Node/NUMBER.h"
#include "DLDL_VALUE/Ast/Node/TEXT.h"
#include "DLDL_VALUE/Ast/Node/VARNAME.h"
#include "DLDL_VALUE/Ast/Node/ESCAPE_CHARS.h"


#include "DLDL_VALUE/Ast/Node/program.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_VALUE/Ast/Node/stmt.h"
#include "DLDL_VALUE/Ast/Node/value_charactersitic_declaration.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_long_82.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_long_85.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_long_88.h"
#include "DLDL_VALUE/Ast/Node/value_declaration.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_long_91.h"
#include "DLDL_VALUE/Ast/Node/value_characteristic_abstraction.h"
#include "DLDL_VALUE/Ast/Node/value_declaration_abstraction.h"
#include "DLDL_VALUE/Ast/Node/value_abstraction.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_star__value_abstraction__.h"
#include "DLDL_VALUE/Ast/Node/deamerreserved_long_96.h"
#include "DLDL_VALUE/Ast/Node/value.h"
#include "DLDL_VALUE/Ast/Node/syntactic_context.h"
#include "DLDL_VALUE/Ast/Node/abstraction_name.h"
#include "DLDL_VALUE/Ast/Node/value_rule_name.h"

#include <Deamer/External/Cpp/Ast/Listener.h>
#include <Deamer/Algorithm/Tree/DFS.h>

namespace DLDL_VALUE { namespace ast { namespace listener { 

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
			const auto enumeratedValue = static_cast<DLDL_VALUE::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case DLDL_VALUE::ast::Type::SINGLE_COMMENT:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_VALUE::ast::node::SINGLE_COMMENT*>(node));
				break;
			}

			case DLDL_VALUE::ast::Type::MULTI_COMMENT:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_VALUE::ast::node::MULTI_COMMENT*>(node));
				break;
			}

			case DLDL_VALUE::ast::Type::LEFT_PARANTHESIS:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_VALUE::ast::node::LEFT_PARANTHESIS*>(node));
				break;
			}

			case DLDL_VALUE::ast::Type::RIGHT_PARANTHESIS:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_VALUE::ast::node::RIGHT_PARANTHESIS*>(node));
				break;
			}

			case DLDL_VALUE::ast::Type::LEFT_BRACKET:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_VALUE::ast::node::LEFT_BRACKET*>(node));
				break;
			}

			case DLDL_VALUE::ast::Type::RIGHT_BRACKET:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_VALUE::ast::node::RIGHT_BRACKET*>(node));
				break;
			}

			case DLDL_VALUE::ast::Type::LEFT_SQUARE_BRACKET:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET*>(node));
				break;
			}

			case DLDL_VALUE::ast::Type::RIGHT_SQUARE_BRACKET:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET*>(node));
				break;
			}

			case DLDL_VALUE::ast::Type::DOT:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_VALUE::ast::node::DOT*>(node));
				break;
			}

			case DLDL_VALUE::ast::Type::VALUE_CHARACTERISTIC:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_VALUE::ast::node::VALUE_CHARACTERISTIC*>(node));
				break;
			}

			case DLDL_VALUE::ast::Type::VALUE_RULE:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_VALUE::ast::node::VALUE_RULE*>(node));
				break;
			}

			case DLDL_VALUE::ast::Type::NUMBER:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_VALUE::ast::node::NUMBER*>(node));
				break;
			}

			case DLDL_VALUE::ast::Type::TEXT:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_VALUE::ast::node::TEXT*>(node));
				break;
			}

			case DLDL_VALUE::ast::Type::VARNAME:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_VALUE::ast::node::VARNAME*>(node));
				break;
			}

			case DLDL_VALUE::ast::Type::ESCAPE_CHARS:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_VALUE::ast::node::ESCAPE_CHARS*>(node));
				break;
			}


			// Nonterminal cases
			
			case DLDL_VALUE::ast::Type::program:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_VALUE::ast::node::program*>(node));
				break;
			}

			case DLDL_VALUE::ast::Type::deamerreserved_star__stmt__:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_VALUE::ast::node::deamerreserved_star__stmt__*>(node));
				break;
			}

			case DLDL_VALUE::ast::Type::stmt:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_VALUE::ast::node::stmt*>(node));
				break;
			}

			case DLDL_VALUE::ast::Type::value_charactersitic_declaration:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_VALUE::ast::node::value_charactersitic_declaration*>(node));
				break;
			}

			case DLDL_VALUE::ast::Type::deamerreserved_long_82:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_VALUE::ast::node::deamerreserved_long_82*>(node));
				break;
			}

			case DLDL_VALUE::ast::Type::deamerreserved_long_85:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_VALUE::ast::node::deamerreserved_long_85*>(node));
				break;
			}

			case DLDL_VALUE::ast::Type::deamerreserved_long_88:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_VALUE::ast::node::deamerreserved_long_88*>(node));
				break;
			}

			case DLDL_VALUE::ast::Type::value_declaration:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_VALUE::ast::node::value_declaration*>(node));
				break;
			}

			case DLDL_VALUE::ast::Type::deamerreserved_long_91:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_VALUE::ast::node::deamerreserved_long_91*>(node));
				break;
			}

			case DLDL_VALUE::ast::Type::value_characteristic_abstraction:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_VALUE::ast::node::value_characteristic_abstraction*>(node));
				break;
			}

			case DLDL_VALUE::ast::Type::value_declaration_abstraction:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_VALUE::ast::node::value_declaration_abstraction*>(node));
				break;
			}

			case DLDL_VALUE::ast::Type::value_abstraction:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_VALUE::ast::node::value_abstraction*>(node));
				break;
			}

			case DLDL_VALUE::ast::Type::deamerreserved_star__value_abstraction__:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__*>(node));
				break;
			}

			case DLDL_VALUE::ast::Type::deamerreserved_long_96:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_VALUE::ast::node::deamerreserved_long_96*>(node));
				break;
			}

			case DLDL_VALUE::ast::Type::value:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_VALUE::ast::node::value*>(node));
				break;
			}

			case DLDL_VALUE::ast::Type::syntactic_context:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_VALUE::ast::node::syntactic_context*>(node));
				break;
			}

			case DLDL_VALUE::ast::Type::abstraction_name:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_VALUE::ast::node::abstraction_name*>(node));
				break;
			}

			case DLDL_VALUE::ast::Type::value_rule_name:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_VALUE::ast::node::value_rule_name*>(node));
				break;
			}

			}
		}

		void DispatchExit(const ::deamer::external::cpp::ast::Node* node) 
		{
			const auto enumeratedValue = static_cast<DLDL_VALUE::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case DLDL_VALUE::ast::Type::SINGLE_COMMENT:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_VALUE::ast::node::SINGLE_COMMENT*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_VALUE::ast::Type::MULTI_COMMENT:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_VALUE::ast::node::MULTI_COMMENT*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_VALUE::ast::Type::LEFT_PARANTHESIS:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_VALUE::ast::node::LEFT_PARANTHESIS*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_VALUE::ast::Type::RIGHT_PARANTHESIS:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_VALUE::ast::node::RIGHT_PARANTHESIS*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_VALUE::ast::Type::LEFT_BRACKET:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_VALUE::ast::node::LEFT_BRACKET*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_VALUE::ast::Type::RIGHT_BRACKET:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_VALUE::ast::node::RIGHT_BRACKET*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_VALUE::ast::Type::LEFT_SQUARE_BRACKET:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_VALUE::ast::Type::RIGHT_SQUARE_BRACKET:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_VALUE::ast::Type::DOT:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_VALUE::ast::node::DOT*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_VALUE::ast::Type::VALUE_CHARACTERISTIC:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_VALUE::ast::node::VALUE_CHARACTERISTIC*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_VALUE::ast::Type::VALUE_RULE:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_VALUE::ast::node::VALUE_RULE*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_VALUE::ast::Type::NUMBER:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_VALUE::ast::node::NUMBER*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_VALUE::ast::Type::TEXT:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_VALUE::ast::node::TEXT*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_VALUE::ast::Type::VARNAME:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_VALUE::ast::node::VARNAME*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_VALUE::ast::Type::ESCAPE_CHARS:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_VALUE::ast::node::ESCAPE_CHARS*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}


			// Nonterminal cases
			
			case DLDL_VALUE::ast::Type::program:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_VALUE::ast::node::program*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_VALUE::ast::Type::deamerreserved_star__stmt__:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_VALUE::ast::node::deamerreserved_star__stmt__*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_VALUE::ast::Type::stmt:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_VALUE::ast::node::stmt*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_VALUE::ast::Type::value_charactersitic_declaration:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_VALUE::ast::node::value_charactersitic_declaration*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_VALUE::ast::Type::deamerreserved_long_82:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_VALUE::ast::node::deamerreserved_long_82*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_VALUE::ast::Type::deamerreserved_long_85:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_VALUE::ast::node::deamerreserved_long_85*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_VALUE::ast::Type::deamerreserved_long_88:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_VALUE::ast::node::deamerreserved_long_88*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_VALUE::ast::Type::value_declaration:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_VALUE::ast::node::value_declaration*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_VALUE::ast::Type::deamerreserved_long_91:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_VALUE::ast::node::deamerreserved_long_91*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_VALUE::ast::Type::value_characteristic_abstraction:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_VALUE::ast::node::value_characteristic_abstraction*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_VALUE::ast::Type::value_declaration_abstraction:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_VALUE::ast::node::value_declaration_abstraction*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_VALUE::ast::Type::value_abstraction:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_VALUE::ast::node::value_abstraction*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_VALUE::ast::Type::deamerreserved_star__value_abstraction__:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_VALUE::ast::Type::deamerreserved_long_96:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_VALUE::ast::node::deamerreserved_long_96*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_VALUE::ast::Type::value:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_VALUE::ast::node::value*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_VALUE::ast::Type::syntactic_context:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_VALUE::ast::node::syntactic_context*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_VALUE::ast::Type::abstraction_name:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_VALUE::ast::node::abstraction_name*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_VALUE::ast::Type::value_rule_name:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_VALUE::ast::node::value_rule_name*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			}
		}

		
		virtual void ListenEntry(const DLDL_VALUE::ast::node::SINGLE_COMMENT* node) 
		{
		}

		virtual void ListenEntry(const DLDL_VALUE::ast::node::MULTI_COMMENT* node) 
		{
		}

		virtual void ListenEntry(const DLDL_VALUE::ast::node::LEFT_PARANTHESIS* node) 
		{
		}

		virtual void ListenEntry(const DLDL_VALUE::ast::node::RIGHT_PARANTHESIS* node) 
		{
		}

		virtual void ListenEntry(const DLDL_VALUE::ast::node::LEFT_BRACKET* node) 
		{
		}

		virtual void ListenEntry(const DLDL_VALUE::ast::node::RIGHT_BRACKET* node) 
		{
		}

		virtual void ListenEntry(const DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET* node) 
		{
		}

		virtual void ListenEntry(const DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET* node) 
		{
		}

		virtual void ListenEntry(const DLDL_VALUE::ast::node::DOT* node) 
		{
		}

		virtual void ListenEntry(const DLDL_VALUE::ast::node::VALUE_CHARACTERISTIC* node) 
		{
		}

		virtual void ListenEntry(const DLDL_VALUE::ast::node::VALUE_RULE* node) 
		{
		}

		virtual void ListenEntry(const DLDL_VALUE::ast::node::NUMBER* node) 
		{
		}

		virtual void ListenEntry(const DLDL_VALUE::ast::node::TEXT* node) 
		{
		}

		virtual void ListenEntry(const DLDL_VALUE::ast::node::VARNAME* node) 
		{
		}

		virtual void ListenEntry(const DLDL_VALUE::ast::node::ESCAPE_CHARS* node) 
		{
		}

		
		virtual void ListenExit(const DLDL_VALUE::ast::node::SINGLE_COMMENT* node) 
		{
		}

		virtual void ListenExit(const DLDL_VALUE::ast::node::MULTI_COMMENT* node) 
		{
		}

		virtual void ListenExit(const DLDL_VALUE::ast::node::LEFT_PARANTHESIS* node) 
		{
		}

		virtual void ListenExit(const DLDL_VALUE::ast::node::RIGHT_PARANTHESIS* node) 
		{
		}

		virtual void ListenExit(const DLDL_VALUE::ast::node::LEFT_BRACKET* node) 
		{
		}

		virtual void ListenExit(const DLDL_VALUE::ast::node::RIGHT_BRACKET* node) 
		{
		}

		virtual void ListenExit(const DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET* node) 
		{
		}

		virtual void ListenExit(const DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET* node) 
		{
		}

		virtual void ListenExit(const DLDL_VALUE::ast::node::DOT* node) 
		{
		}

		virtual void ListenExit(const DLDL_VALUE::ast::node::VALUE_CHARACTERISTIC* node) 
		{
		}

		virtual void ListenExit(const DLDL_VALUE::ast::node::VALUE_RULE* node) 
		{
		}

		virtual void ListenExit(const DLDL_VALUE::ast::node::NUMBER* node) 
		{
		}

		virtual void ListenExit(const DLDL_VALUE::ast::node::TEXT* node) 
		{
		}

		virtual void ListenExit(const DLDL_VALUE::ast::node::VARNAME* node) 
		{
		}

		virtual void ListenExit(const DLDL_VALUE::ast::node::ESCAPE_CHARS* node) 
		{
		}


		
		virtual void ListenEntry(const DLDL_VALUE::ast::node::program* node) 
		{
		}

		virtual void ListenEntry(const DLDL_VALUE::ast::node::deamerreserved_star__stmt__* node) 
		{
		}

		virtual void ListenEntry(const DLDL_VALUE::ast::node::stmt* node) 
		{
		}

		virtual void ListenEntry(const DLDL_VALUE::ast::node::value_charactersitic_declaration* node) 
		{
		}

		virtual void ListenEntry(const DLDL_VALUE::ast::node::deamerreserved_long_82* node) 
		{
		}

		virtual void ListenEntry(const DLDL_VALUE::ast::node::deamerreserved_long_85* node) 
		{
		}

		virtual void ListenEntry(const DLDL_VALUE::ast::node::deamerreserved_long_88* node) 
		{
		}

		virtual void ListenEntry(const DLDL_VALUE::ast::node::value_declaration* node) 
		{
		}

		virtual void ListenEntry(const DLDL_VALUE::ast::node::deamerreserved_long_91* node) 
		{
		}

		virtual void ListenEntry(const DLDL_VALUE::ast::node::value_characteristic_abstraction* node) 
		{
		}

		virtual void ListenEntry(const DLDL_VALUE::ast::node::value_declaration_abstraction* node) 
		{
		}

		virtual void ListenEntry(const DLDL_VALUE::ast::node::value_abstraction* node) 
		{
		}

		virtual void ListenEntry(const DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__* node) 
		{
		}

		virtual void ListenEntry(const DLDL_VALUE::ast::node::deamerreserved_long_96* node) 
		{
		}

		virtual void ListenEntry(const DLDL_VALUE::ast::node::value* node) 
		{
		}

		virtual void ListenEntry(const DLDL_VALUE::ast::node::syntactic_context* node) 
		{
		}

		virtual void ListenEntry(const DLDL_VALUE::ast::node::abstraction_name* node) 
		{
		}

		virtual void ListenEntry(const DLDL_VALUE::ast::node::value_rule_name* node) 
		{
		}

		
		virtual void ListenExit(const DLDL_VALUE::ast::node::program* node) 
		{
		}

		virtual void ListenExit(const DLDL_VALUE::ast::node::deamerreserved_star__stmt__* node) 
		{
		}

		virtual void ListenExit(const DLDL_VALUE::ast::node::stmt* node) 
		{
		}

		virtual void ListenExit(const DLDL_VALUE::ast::node::value_charactersitic_declaration* node) 
		{
		}

		virtual void ListenExit(const DLDL_VALUE::ast::node::deamerreserved_long_82* node) 
		{
		}

		virtual void ListenExit(const DLDL_VALUE::ast::node::deamerreserved_long_85* node) 
		{
		}

		virtual void ListenExit(const DLDL_VALUE::ast::node::deamerreserved_long_88* node) 
		{
		}

		virtual void ListenExit(const DLDL_VALUE::ast::node::value_declaration* node) 
		{
		}

		virtual void ListenExit(const DLDL_VALUE::ast::node::deamerreserved_long_91* node) 
		{
		}

		virtual void ListenExit(const DLDL_VALUE::ast::node::value_characteristic_abstraction* node) 
		{
		}

		virtual void ListenExit(const DLDL_VALUE::ast::node::value_declaration_abstraction* node) 
		{
		}

		virtual void ListenExit(const DLDL_VALUE::ast::node::value_abstraction* node) 
		{
		}

		virtual void ListenExit(const DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__* node) 
		{
		}

		virtual void ListenExit(const DLDL_VALUE::ast::node::deamerreserved_long_96* node) 
		{
		}

		virtual void ListenExit(const DLDL_VALUE::ast::node::value* node) 
		{
		}

		virtual void ListenExit(const DLDL_VALUE::ast::node::syntactic_context* node) 
		{
		}

		virtual void ListenExit(const DLDL_VALUE::ast::node::abstraction_name* node) 
		{
		}

		virtual void ListenExit(const DLDL_VALUE::ast::node::value_rule_name* node) 
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

#endif // DLDL_VALUE_AST_LISTENER_ENTEREXITLISTENER_H