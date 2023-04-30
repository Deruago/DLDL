#ifndef DLDL_LEXER_AST_LISTENER_ENTEREXITLISTENER_H
#define DLDL_LEXER_AST_LISTENER_ENTEREXITLISTENER_H

#include "DLDL_LEXER/Ast/Node/DLDL_LEXER.h"
#include "DLDL_LEXER/Ast/Enum/Type.h"

#include "DLDL_LEXER/Ast/Node/DELETE_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/IGNORE_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/NOVALUE_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/CRASH_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/STANDARD_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/UNKNOWN_ABSTRACTION.h"
#include "DLDL_LEXER/Ast/Node/TERMINAL.h"
#include "DLDL_LEXER/Ast/Node/REGEX.h"
#include "DLDL_LEXER/Ast/Node/ESCAPE_CHARS.h"
#include "DLDL_LEXER/Ast/Node/COMMENT.h"


#include "DLDL_LEXER/Ast/Node/program.h"
#include "DLDL_LEXER/Ast/Node/stmts.h"
#include "DLDL_LEXER/Ast/Node/stmt.h"
#include "DLDL_LEXER/Ast/Node/tokendeclaration.h"
#include "DLDL_LEXER/Ast/Node/abstraction.h"

#include <Deamer/External/Cpp/Ast/Listener.h>
#include <Deamer/Algorithm/Tree/DFS.h>

namespace DLDL_LEXER { namespace ast { namespace listener { 

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
			const auto enumeratedValue = static_cast<DLDL_LEXER::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case DLDL_LEXER::ast::Type::DELETE_ABSTRACTION:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LEXER::ast::node::DELETE_ABSTRACTION*>(node));
				break;
			}

			case DLDL_LEXER::ast::Type::IGNORE_ABSTRACTION:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LEXER::ast::node::IGNORE_ABSTRACTION*>(node));
				break;
			}

			case DLDL_LEXER::ast::Type::NOVALUE_ABSTRACTION:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LEXER::ast::node::NOVALUE_ABSTRACTION*>(node));
				break;
			}

			case DLDL_LEXER::ast::Type::CRASH_ABSTRACTION:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LEXER::ast::node::CRASH_ABSTRACTION*>(node));
				break;
			}

			case DLDL_LEXER::ast::Type::STANDARD_ABSTRACTION:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LEXER::ast::node::STANDARD_ABSTRACTION*>(node));
				break;
			}

			case DLDL_LEXER::ast::Type::UNKNOWN_ABSTRACTION:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LEXER::ast::node::UNKNOWN_ABSTRACTION*>(node));
				break;
			}

			case DLDL_LEXER::ast::Type::TERMINAL:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LEXER::ast::node::TERMINAL*>(node));
				break;
			}

			case DLDL_LEXER::ast::Type::REGEX:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LEXER::ast::node::REGEX*>(node));
				break;
			}

			case DLDL_LEXER::ast::Type::ESCAPE_CHARS:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LEXER::ast::node::ESCAPE_CHARS*>(node));
				break;
			}

			case DLDL_LEXER::ast::Type::COMMENT:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LEXER::ast::node::COMMENT*>(node));
				break;
			}


			// Nonterminal cases
			
			case DLDL_LEXER::ast::Type::program:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LEXER::ast::node::program*>(node));
				break;
			}

			case DLDL_LEXER::ast::Type::stmts:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LEXER::ast::node::stmts*>(node));
				break;
			}

			case DLDL_LEXER::ast::Type::stmt:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LEXER::ast::node::stmt*>(node));
				break;
			}

			case DLDL_LEXER::ast::Type::tokendeclaration:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LEXER::ast::node::tokendeclaration*>(node));
				break;
			}

			case DLDL_LEXER::ast::Type::abstraction:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LEXER::ast::node::abstraction*>(node));
				break;
			}

			}
		}

		void DispatchExit(const ::deamer::external::cpp::ast::Node* node) 
		{
			const auto enumeratedValue = static_cast<DLDL_LEXER::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case DLDL_LEXER::ast::Type::DELETE_ABSTRACTION:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LEXER::ast::node::DELETE_ABSTRACTION*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LEXER::ast::Type::IGNORE_ABSTRACTION:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LEXER::ast::node::IGNORE_ABSTRACTION*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LEXER::ast::Type::NOVALUE_ABSTRACTION:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LEXER::ast::node::NOVALUE_ABSTRACTION*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LEXER::ast::Type::CRASH_ABSTRACTION:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LEXER::ast::node::CRASH_ABSTRACTION*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LEXER::ast::Type::STANDARD_ABSTRACTION:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LEXER::ast::node::STANDARD_ABSTRACTION*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LEXER::ast::Type::UNKNOWN_ABSTRACTION:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LEXER::ast::node::UNKNOWN_ABSTRACTION*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LEXER::ast::Type::TERMINAL:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LEXER::ast::node::TERMINAL*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LEXER::ast::Type::REGEX:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LEXER::ast::node::REGEX*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LEXER::ast::Type::ESCAPE_CHARS:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LEXER::ast::node::ESCAPE_CHARS*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LEXER::ast::Type::COMMENT:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LEXER::ast::node::COMMENT*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}


			// Nonterminal cases
			
			case DLDL_LEXER::ast::Type::program:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LEXER::ast::node::program*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LEXER::ast::Type::stmts:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LEXER::ast::node::stmts*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LEXER::ast::Type::stmt:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LEXER::ast::node::stmt*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LEXER::ast::Type::tokendeclaration:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LEXER::ast::node::tokendeclaration*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LEXER::ast::Type::abstraction:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LEXER::ast::node::abstraction*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			}
		}

		
		virtual void ListenEntry(const DLDL_LEXER::ast::node::DELETE_ABSTRACTION* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LEXER::ast::node::IGNORE_ABSTRACTION* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LEXER::ast::node::NOVALUE_ABSTRACTION* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LEXER::ast::node::CRASH_ABSTRACTION* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LEXER::ast::node::STANDARD_ABSTRACTION* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LEXER::ast::node::UNKNOWN_ABSTRACTION* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LEXER::ast::node::TERMINAL* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LEXER::ast::node::REGEX* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LEXER::ast::node::ESCAPE_CHARS* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LEXER::ast::node::COMMENT* node) 
		{
		}

		
		virtual void ListenExit(const DLDL_LEXER::ast::node::DELETE_ABSTRACTION* node) 
		{
		}

		virtual void ListenExit(const DLDL_LEXER::ast::node::IGNORE_ABSTRACTION* node) 
		{
		}

		virtual void ListenExit(const DLDL_LEXER::ast::node::NOVALUE_ABSTRACTION* node) 
		{
		}

		virtual void ListenExit(const DLDL_LEXER::ast::node::CRASH_ABSTRACTION* node) 
		{
		}

		virtual void ListenExit(const DLDL_LEXER::ast::node::STANDARD_ABSTRACTION* node) 
		{
		}

		virtual void ListenExit(const DLDL_LEXER::ast::node::UNKNOWN_ABSTRACTION* node) 
		{
		}

		virtual void ListenExit(const DLDL_LEXER::ast::node::TERMINAL* node) 
		{
		}

		virtual void ListenExit(const DLDL_LEXER::ast::node::REGEX* node) 
		{
		}

		virtual void ListenExit(const DLDL_LEXER::ast::node::ESCAPE_CHARS* node) 
		{
		}

		virtual void ListenExit(const DLDL_LEXER::ast::node::COMMENT* node) 
		{
		}


		
		virtual void ListenEntry(const DLDL_LEXER::ast::node::program* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LEXER::ast::node::stmts* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LEXER::ast::node::stmt* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LEXER::ast::node::tokendeclaration* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LEXER::ast::node::abstraction* node) 
		{
		}

		
		virtual void ListenExit(const DLDL_LEXER::ast::node::program* node) 
		{
		}

		virtual void ListenExit(const DLDL_LEXER::ast::node::stmts* node) 
		{
		}

		virtual void ListenExit(const DLDL_LEXER::ast::node::stmt* node) 
		{
		}

		virtual void ListenExit(const DLDL_LEXER::ast::node::tokendeclaration* node) 
		{
		}

		virtual void ListenExit(const DLDL_LEXER::ast::node::abstraction* node) 
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

#endif // DLDL_LEXER_AST_LISTENER_ENTEREXITLISTENER_H