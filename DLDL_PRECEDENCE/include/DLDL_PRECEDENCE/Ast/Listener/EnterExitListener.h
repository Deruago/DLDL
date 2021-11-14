#ifndef DLDL_PRECEDENCE_AST_LISTENER_ENTEREXITLISTENER_H
#define DLDL_PRECEDENCE_AST_LISTENER_ENTEREXITLISTENER_H

#include "DLDL_PRECEDENCE/Ast/Node/DLDL_PRECEDENCE.h"
#include "DLDL_PRECEDENCE/Ast/Enum/Type.h"

#include "DLDL_PRECEDENCE/Ast/Node/PRECEDENCE.h"
#include "DLDL_PRECEDENCE/Ast/Node/NUMBER.h"
#include "DLDL_PRECEDENCE/Ast/Node/TERMINAL.h"
#include "DLDL_PRECEDENCE/Ast/Node/SYMBOLS.h"
#include "DLDL_PRECEDENCE/Ast/Node/ESCAPE_CHARS.h"


#include "DLDL_PRECEDENCE/Ast/Node/program.h"
#include "DLDL_PRECEDENCE/Ast/Node/stmts.h"
#include "DLDL_PRECEDENCE/Ast/Node/stmt.h"
#include "DLDL_PRECEDENCE/Ast/Node/localized_precedence.h"
#include "DLDL_PRECEDENCE/Ast/Node/specific_precedence.h"
#include "DLDL_PRECEDENCE/Ast/Node/terminal_one_or_more.h"

#include <Deamer/External/Cpp/Ast/Listener.h>
#include <Deamer/Algorithm/Tree/DFS.h>

namespace DLDL_PRECEDENCE { namespace ast { namespace listener { 

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
			const auto enumeratedValue = static_cast<DLDL_PRECEDENCE::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case DLDL_PRECEDENCE::ast::Type::PRECEDENCE:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_PRECEDENCE::ast::node::PRECEDENCE*>(node));
				break;
			}

			case DLDL_PRECEDENCE::ast::Type::NUMBER:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_PRECEDENCE::ast::node::NUMBER*>(node));
				break;
			}

			case DLDL_PRECEDENCE::ast::Type::TERMINAL:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_PRECEDENCE::ast::node::TERMINAL*>(node));
				break;
			}

			case DLDL_PRECEDENCE::ast::Type::SYMBOLS:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_PRECEDENCE::ast::node::SYMBOLS*>(node));
				break;
			}

			case DLDL_PRECEDENCE::ast::Type::ESCAPE_CHARS:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_PRECEDENCE::ast::node::ESCAPE_CHARS*>(node));
				break;
			}


			// Nonterminal cases
			
			case DLDL_PRECEDENCE::ast::Type::program:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_PRECEDENCE::ast::node::program*>(node));
				break;
			}

			case DLDL_PRECEDENCE::ast::Type::stmts:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_PRECEDENCE::ast::node::stmts*>(node));
				break;
			}

			case DLDL_PRECEDENCE::ast::Type::stmt:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_PRECEDENCE::ast::node::stmt*>(node));
				break;
			}

			case DLDL_PRECEDENCE::ast::Type::localized_precedence:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_PRECEDENCE::ast::node::localized_precedence*>(node));
				break;
			}

			case DLDL_PRECEDENCE::ast::Type::specific_precedence:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_PRECEDENCE::ast::node::specific_precedence*>(node));
				break;
			}

			case DLDL_PRECEDENCE::ast::Type::terminal_one_or_more:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_PRECEDENCE::ast::node::terminal_one_or_more*>(node));
				break;
			}

			}
		}

		void DispatchExit(const ::deamer::external::cpp::ast::Node* node) 
		{
			const auto enumeratedValue = static_cast<DLDL_PRECEDENCE::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case DLDL_PRECEDENCE::ast::Type::PRECEDENCE:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_PRECEDENCE::ast::node::PRECEDENCE*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_PRECEDENCE::ast::Type::NUMBER:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_PRECEDENCE::ast::node::NUMBER*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_PRECEDENCE::ast::Type::TERMINAL:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_PRECEDENCE::ast::node::TERMINAL*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_PRECEDENCE::ast::Type::SYMBOLS:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_PRECEDENCE::ast::node::SYMBOLS*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_PRECEDENCE::ast::Type::ESCAPE_CHARS:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_PRECEDENCE::ast::node::ESCAPE_CHARS*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}


			// Nonterminal cases
			
			case DLDL_PRECEDENCE::ast::Type::program:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_PRECEDENCE::ast::node::program*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_PRECEDENCE::ast::Type::stmts:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_PRECEDENCE::ast::node::stmts*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_PRECEDENCE::ast::Type::stmt:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_PRECEDENCE::ast::node::stmt*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_PRECEDENCE::ast::Type::localized_precedence:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_PRECEDENCE::ast::node::localized_precedence*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_PRECEDENCE::ast::Type::specific_precedence:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_PRECEDENCE::ast::node::specific_precedence*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_PRECEDENCE::ast::Type::terminal_one_or_more:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_PRECEDENCE::ast::node::terminal_one_or_more*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			}
		}

		
		virtual void ListenEntry(const DLDL_PRECEDENCE::ast::node::PRECEDENCE* node) 
		{
		}

		virtual void ListenEntry(const DLDL_PRECEDENCE::ast::node::NUMBER* node) 
		{
		}

		virtual void ListenEntry(const DLDL_PRECEDENCE::ast::node::TERMINAL* node) 
		{
		}

		virtual void ListenEntry(const DLDL_PRECEDENCE::ast::node::SYMBOLS* node) 
		{
		}

		virtual void ListenEntry(const DLDL_PRECEDENCE::ast::node::ESCAPE_CHARS* node) 
		{
		}

		
		virtual void ListenExit(const DLDL_PRECEDENCE::ast::node::PRECEDENCE* node) 
		{
		}

		virtual void ListenExit(const DLDL_PRECEDENCE::ast::node::NUMBER* node) 
		{
		}

		virtual void ListenExit(const DLDL_PRECEDENCE::ast::node::TERMINAL* node) 
		{
		}

		virtual void ListenExit(const DLDL_PRECEDENCE::ast::node::SYMBOLS* node) 
		{
		}

		virtual void ListenExit(const DLDL_PRECEDENCE::ast::node::ESCAPE_CHARS* node) 
		{
		}


		
		virtual void ListenEntry(const DLDL_PRECEDENCE::ast::node::program* node) 
		{
		}

		virtual void ListenEntry(const DLDL_PRECEDENCE::ast::node::stmts* node) 
		{
		}

		virtual void ListenEntry(const DLDL_PRECEDENCE::ast::node::stmt* node) 
		{
		}

		virtual void ListenEntry(const DLDL_PRECEDENCE::ast::node::localized_precedence* node) 
		{
		}

		virtual void ListenEntry(const DLDL_PRECEDENCE::ast::node::specific_precedence* node) 
		{
		}

		virtual void ListenEntry(const DLDL_PRECEDENCE::ast::node::terminal_one_or_more* node) 
		{
		}

		
		virtual void ListenExit(const DLDL_PRECEDENCE::ast::node::program* node) 
		{
		}

		virtual void ListenExit(const DLDL_PRECEDENCE::ast::node::stmts* node) 
		{
		}

		virtual void ListenExit(const DLDL_PRECEDENCE::ast::node::stmt* node) 
		{
		}

		virtual void ListenExit(const DLDL_PRECEDENCE::ast::node::localized_precedence* node) 
		{
		}

		virtual void ListenExit(const DLDL_PRECEDENCE::ast::node::specific_precedence* node) 
		{
		}

		virtual void ListenExit(const DLDL_PRECEDENCE::ast::node::terminal_one_or_more* node) 
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

#endif // DLDL_PRECEDENCE_AST_LISTENER_ENTEREXITLISTENER_H