#ifndef DLDL_IMPORT_AST_LISTENER_ENTEREXITLISTENER_H
#define DLDL_IMPORT_AST_LISTENER_ENTEREXITLISTENER_H

#include "DLDL_IMPORT/Ast/Node/DLDL_IMPORT.h"
#include "DLDL_IMPORT/Ast/Enum/Type.h"

#include "DLDL_IMPORT/Ast/Node/SINGLE_COMMENT.h"
#include "DLDL_IMPORT/Ast/Node/MULTI_COMMENT.h"
#include "DLDL_IMPORT/Ast/Node/LEFT_PARANTHESIS.h"
#include "DLDL_IMPORT/Ast/Node/RIGHT_PARANTHESIS.h"
#include "DLDL_IMPORT/Ast/Node/LEFT_SQUARE_BRACKET.h"
#include "DLDL_IMPORT/Ast/Node/RIGHT_SQUARE_BRACKET.h"
#include "DLDL_IMPORT/Ast/Node/COLON.h"
#include "DLDL_IMPORT/Ast/Node/DOT.h"
#include "DLDL_IMPORT/Ast/Node/IMPORT_FILE.h"
#include "DLDL_IMPORT/Ast/Node/IMPORT_MODULE.h"
#include "DLDL_IMPORT/Ast/Node/IMPORT.h"
#include "DLDL_IMPORT/Ast/Node/TEXT.h"
#include "DLDL_IMPORT/Ast/Node/VARNAME.h"
#include "DLDL_IMPORT/Ast/Node/ESCAPE_CHARS.h"


#include "DLDL_IMPORT/Ast/Node/program.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_IMPORT/Ast/Node/stmt.h"
#include "DLDL_IMPORT/Ast/Node/import_declaration.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_arrow__import_context__.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_long_40.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_long_43.h"
#include "DLDL_IMPORT/Ast/Node/specialization.h"
#include "DLDL_IMPORT/Ast/Node/import_abstraction.h"
#include "DLDL_IMPORT/Ast/Node/value.h"
#include "DLDL_IMPORT/Ast/Node/deamerreserved_optional__VARNAME__.h"
#include "DLDL_IMPORT/Ast/Node/abstraction.h"
#include "DLDL_IMPORT/Ast/Node/import_context.h"
#include "DLDL_IMPORT/Ast/Node/import_rule_name.h"

#include <Deamer/External/Cpp/Ast/Listener.h>
#include <Deamer/Algorithm/Tree/DFS.h>

namespace DLDL_IMPORT { namespace ast { namespace listener { 

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
			const auto enumeratedValue = static_cast<DLDL_IMPORT::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case DLDL_IMPORT::ast::Type::SINGLE_COMMENT:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_IMPORT::ast::node::SINGLE_COMMENT*>(node));
				break;
			}

			case DLDL_IMPORT::ast::Type::MULTI_COMMENT:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_IMPORT::ast::node::MULTI_COMMENT*>(node));
				break;
			}

			case DLDL_IMPORT::ast::Type::LEFT_PARANTHESIS:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_IMPORT::ast::node::LEFT_PARANTHESIS*>(node));
				break;
			}

			case DLDL_IMPORT::ast::Type::RIGHT_PARANTHESIS:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_IMPORT::ast::node::RIGHT_PARANTHESIS*>(node));
				break;
			}

			case DLDL_IMPORT::ast::Type::LEFT_SQUARE_BRACKET:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_IMPORT::ast::node::LEFT_SQUARE_BRACKET*>(node));
				break;
			}

			case DLDL_IMPORT::ast::Type::RIGHT_SQUARE_BRACKET:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_IMPORT::ast::node::RIGHT_SQUARE_BRACKET*>(node));
				break;
			}

			case DLDL_IMPORT::ast::Type::COLON:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_IMPORT::ast::node::COLON*>(node));
				break;
			}

			case DLDL_IMPORT::ast::Type::DOT:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_IMPORT::ast::node::DOT*>(node));
				break;
			}

			case DLDL_IMPORT::ast::Type::IMPORT_FILE:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_IMPORT::ast::node::IMPORT_FILE*>(node));
				break;
			}

			case DLDL_IMPORT::ast::Type::IMPORT_MODULE:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_IMPORT::ast::node::IMPORT_MODULE*>(node));
				break;
			}

			case DLDL_IMPORT::ast::Type::IMPORT:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_IMPORT::ast::node::IMPORT*>(node));
				break;
			}

			case DLDL_IMPORT::ast::Type::TEXT:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_IMPORT::ast::node::TEXT*>(node));
				break;
			}

			case DLDL_IMPORT::ast::Type::VARNAME:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_IMPORT::ast::node::VARNAME*>(node));
				break;
			}

			case DLDL_IMPORT::ast::Type::ESCAPE_CHARS:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_IMPORT::ast::node::ESCAPE_CHARS*>(node));
				break;
			}


			// Nonterminal cases
			
			case DLDL_IMPORT::ast::Type::program:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_IMPORT::ast::node::program*>(node));
				break;
			}

			case DLDL_IMPORT::ast::Type::deamerreserved_star__stmt__:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_IMPORT::ast::node::deamerreserved_star__stmt__*>(node));
				break;
			}

			case DLDL_IMPORT::ast::Type::stmt:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_IMPORT::ast::node::stmt*>(node));
				break;
			}

			case DLDL_IMPORT::ast::Type::import_declaration:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_IMPORT::ast::node::import_declaration*>(node));
				break;
			}

			case DLDL_IMPORT::ast::Type::deamerreserved_arrow__import_context__:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_IMPORT::ast::node::deamerreserved_arrow__import_context__*>(node));
				break;
			}

			case DLDL_IMPORT::ast::Type::deamerreserved_long_40:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_IMPORT::ast::node::deamerreserved_long_40*>(node));
				break;
			}

			case DLDL_IMPORT::ast::Type::deamerreserved_long_43:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_IMPORT::ast::node::deamerreserved_long_43*>(node));
				break;
			}

			case DLDL_IMPORT::ast::Type::specialization:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_IMPORT::ast::node::specialization*>(node));
				break;
			}

			case DLDL_IMPORT::ast::Type::import_abstraction:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_IMPORT::ast::node::import_abstraction*>(node));
				break;
			}

			case DLDL_IMPORT::ast::Type::value:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_IMPORT::ast::node::value*>(node));
				break;
			}

			case DLDL_IMPORT::ast::Type::deamerreserved_optional__VARNAME__:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_IMPORT::ast::node::deamerreserved_optional__VARNAME__*>(node));
				break;
			}

			case DLDL_IMPORT::ast::Type::abstraction:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_IMPORT::ast::node::abstraction*>(node));
				break;
			}

			case DLDL_IMPORT::ast::Type::import_context:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_IMPORT::ast::node::import_context*>(node));
				break;
			}

			case DLDL_IMPORT::ast::Type::import_rule_name:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_IMPORT::ast::node::import_rule_name*>(node));
				break;
			}

			}
		}

		void DispatchExit(const ::deamer::external::cpp::ast::Node* node) 
		{
			const auto enumeratedValue = static_cast<DLDL_IMPORT::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case DLDL_IMPORT::ast::Type::SINGLE_COMMENT:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_IMPORT::ast::node::SINGLE_COMMENT*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_IMPORT::ast::Type::MULTI_COMMENT:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_IMPORT::ast::node::MULTI_COMMENT*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_IMPORT::ast::Type::LEFT_PARANTHESIS:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_IMPORT::ast::node::LEFT_PARANTHESIS*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_IMPORT::ast::Type::RIGHT_PARANTHESIS:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_IMPORT::ast::node::RIGHT_PARANTHESIS*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_IMPORT::ast::Type::LEFT_SQUARE_BRACKET:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_IMPORT::ast::node::LEFT_SQUARE_BRACKET*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_IMPORT::ast::Type::RIGHT_SQUARE_BRACKET:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_IMPORT::ast::node::RIGHT_SQUARE_BRACKET*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_IMPORT::ast::Type::COLON:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_IMPORT::ast::node::COLON*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_IMPORT::ast::Type::DOT:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_IMPORT::ast::node::DOT*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_IMPORT::ast::Type::IMPORT_FILE:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_IMPORT::ast::node::IMPORT_FILE*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_IMPORT::ast::Type::IMPORT_MODULE:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_IMPORT::ast::node::IMPORT_MODULE*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_IMPORT::ast::Type::IMPORT:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_IMPORT::ast::node::IMPORT*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_IMPORT::ast::Type::TEXT:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_IMPORT::ast::node::TEXT*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_IMPORT::ast::Type::VARNAME:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_IMPORT::ast::node::VARNAME*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_IMPORT::ast::Type::ESCAPE_CHARS:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_IMPORT::ast::node::ESCAPE_CHARS*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}


			// Nonterminal cases
			
			case DLDL_IMPORT::ast::Type::program:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_IMPORT::ast::node::program*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_IMPORT::ast::Type::deamerreserved_star__stmt__:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_IMPORT::ast::node::deamerreserved_star__stmt__*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_IMPORT::ast::Type::stmt:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_IMPORT::ast::node::stmt*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_IMPORT::ast::Type::import_declaration:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_IMPORT::ast::node::import_declaration*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_IMPORT::ast::Type::deamerreserved_arrow__import_context__:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_IMPORT::ast::node::deamerreserved_arrow__import_context__*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_IMPORT::ast::Type::deamerreserved_long_40:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_IMPORT::ast::node::deamerreserved_long_40*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_IMPORT::ast::Type::deamerreserved_long_43:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_IMPORT::ast::node::deamerreserved_long_43*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_IMPORT::ast::Type::specialization:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_IMPORT::ast::node::specialization*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_IMPORT::ast::Type::import_abstraction:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_IMPORT::ast::node::import_abstraction*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_IMPORT::ast::Type::value:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_IMPORT::ast::node::value*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_IMPORT::ast::Type::deamerreserved_optional__VARNAME__:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_IMPORT::ast::node::deamerreserved_optional__VARNAME__*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_IMPORT::ast::Type::abstraction:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_IMPORT::ast::node::abstraction*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_IMPORT::ast::Type::import_context:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_IMPORT::ast::node::import_context*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_IMPORT::ast::Type::import_rule_name:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_IMPORT::ast::node::import_rule_name*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			}
		}

		
		virtual void ListenEntry(const DLDL_IMPORT::ast::node::SINGLE_COMMENT* node) 
		{
		}

		virtual void ListenEntry(const DLDL_IMPORT::ast::node::MULTI_COMMENT* node) 
		{
		}

		virtual void ListenEntry(const DLDL_IMPORT::ast::node::LEFT_PARANTHESIS* node) 
		{
		}

		virtual void ListenEntry(const DLDL_IMPORT::ast::node::RIGHT_PARANTHESIS* node) 
		{
		}

		virtual void ListenEntry(const DLDL_IMPORT::ast::node::LEFT_SQUARE_BRACKET* node) 
		{
		}

		virtual void ListenEntry(const DLDL_IMPORT::ast::node::RIGHT_SQUARE_BRACKET* node) 
		{
		}

		virtual void ListenEntry(const DLDL_IMPORT::ast::node::COLON* node) 
		{
		}

		virtual void ListenEntry(const DLDL_IMPORT::ast::node::DOT* node) 
		{
		}

		virtual void ListenEntry(const DLDL_IMPORT::ast::node::IMPORT_FILE* node) 
		{
		}

		virtual void ListenEntry(const DLDL_IMPORT::ast::node::IMPORT_MODULE* node) 
		{
		}

		virtual void ListenEntry(const DLDL_IMPORT::ast::node::IMPORT* node) 
		{
		}

		virtual void ListenEntry(const DLDL_IMPORT::ast::node::TEXT* node) 
		{
		}

		virtual void ListenEntry(const DLDL_IMPORT::ast::node::VARNAME* node) 
		{
		}

		virtual void ListenEntry(const DLDL_IMPORT::ast::node::ESCAPE_CHARS* node) 
		{
		}

		
		virtual void ListenExit(const DLDL_IMPORT::ast::node::SINGLE_COMMENT* node) 
		{
		}

		virtual void ListenExit(const DLDL_IMPORT::ast::node::MULTI_COMMENT* node) 
		{
		}

		virtual void ListenExit(const DLDL_IMPORT::ast::node::LEFT_PARANTHESIS* node) 
		{
		}

		virtual void ListenExit(const DLDL_IMPORT::ast::node::RIGHT_PARANTHESIS* node) 
		{
		}

		virtual void ListenExit(const DLDL_IMPORT::ast::node::LEFT_SQUARE_BRACKET* node) 
		{
		}

		virtual void ListenExit(const DLDL_IMPORT::ast::node::RIGHT_SQUARE_BRACKET* node) 
		{
		}

		virtual void ListenExit(const DLDL_IMPORT::ast::node::COLON* node) 
		{
		}

		virtual void ListenExit(const DLDL_IMPORT::ast::node::DOT* node) 
		{
		}

		virtual void ListenExit(const DLDL_IMPORT::ast::node::IMPORT_FILE* node) 
		{
		}

		virtual void ListenExit(const DLDL_IMPORT::ast::node::IMPORT_MODULE* node) 
		{
		}

		virtual void ListenExit(const DLDL_IMPORT::ast::node::IMPORT* node) 
		{
		}

		virtual void ListenExit(const DLDL_IMPORT::ast::node::TEXT* node) 
		{
		}

		virtual void ListenExit(const DLDL_IMPORT::ast::node::VARNAME* node) 
		{
		}

		virtual void ListenExit(const DLDL_IMPORT::ast::node::ESCAPE_CHARS* node) 
		{
		}


		
		virtual void ListenEntry(const DLDL_IMPORT::ast::node::program* node) 
		{
		}

		virtual void ListenEntry(const DLDL_IMPORT::ast::node::deamerreserved_star__stmt__* node) 
		{
		}

		virtual void ListenEntry(const DLDL_IMPORT::ast::node::stmt* node) 
		{
		}

		virtual void ListenEntry(const DLDL_IMPORT::ast::node::import_declaration* node) 
		{
		}

		virtual void ListenEntry(const DLDL_IMPORT::ast::node::deamerreserved_arrow__import_context__* node) 
		{
		}

		virtual void ListenEntry(const DLDL_IMPORT::ast::node::deamerreserved_long_40* node) 
		{
		}

		virtual void ListenEntry(const DLDL_IMPORT::ast::node::deamerreserved_long_43* node) 
		{
		}

		virtual void ListenEntry(const DLDL_IMPORT::ast::node::specialization* node) 
		{
		}

		virtual void ListenEntry(const DLDL_IMPORT::ast::node::import_abstraction* node) 
		{
		}

		virtual void ListenEntry(const DLDL_IMPORT::ast::node::value* node) 
		{
		}

		virtual void ListenEntry(const DLDL_IMPORT::ast::node::deamerreserved_optional__VARNAME__* node) 
		{
		}

		virtual void ListenEntry(const DLDL_IMPORT::ast::node::abstraction* node) 
		{
		}

		virtual void ListenEntry(const DLDL_IMPORT::ast::node::import_context* node) 
		{
		}

		virtual void ListenEntry(const DLDL_IMPORT::ast::node::import_rule_name* node) 
		{
		}

		
		virtual void ListenExit(const DLDL_IMPORT::ast::node::program* node) 
		{
		}

		virtual void ListenExit(const DLDL_IMPORT::ast::node::deamerreserved_star__stmt__* node) 
		{
		}

		virtual void ListenExit(const DLDL_IMPORT::ast::node::stmt* node) 
		{
		}

		virtual void ListenExit(const DLDL_IMPORT::ast::node::import_declaration* node) 
		{
		}

		virtual void ListenExit(const DLDL_IMPORT::ast::node::deamerreserved_arrow__import_context__* node) 
		{
		}

		virtual void ListenExit(const DLDL_IMPORT::ast::node::deamerreserved_long_40* node) 
		{
		}

		virtual void ListenExit(const DLDL_IMPORT::ast::node::deamerreserved_long_43* node) 
		{
		}

		virtual void ListenExit(const DLDL_IMPORT::ast::node::specialization* node) 
		{
		}

		virtual void ListenExit(const DLDL_IMPORT::ast::node::import_abstraction* node) 
		{
		}

		virtual void ListenExit(const DLDL_IMPORT::ast::node::value* node) 
		{
		}

		virtual void ListenExit(const DLDL_IMPORT::ast::node::deamerreserved_optional__VARNAME__* node) 
		{
		}

		virtual void ListenExit(const DLDL_IMPORT::ast::node::abstraction* node) 
		{
		}

		virtual void ListenExit(const DLDL_IMPORT::ast::node::import_context* node) 
		{
		}

		virtual void ListenExit(const DLDL_IMPORT::ast::node::import_rule_name* node) 
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

#endif // DLDL_IMPORT_AST_LISTENER_ENTEREXITLISTENER_H