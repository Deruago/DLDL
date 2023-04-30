#ifndef DLDL_IDENTITY_AST_LISTENER_ENTEREXITLISTENER_H
#define DLDL_IDENTITY_AST_LISTENER_ENTEREXITLISTENER_H

#include "DLDL_IDENTITY/Ast/Node/DLDL_IDENTITY.h"
#include "DLDL_IDENTITY/Ast/Enum/Type.h"

#include "DLDL_IDENTITY/Ast/Node/NAME.h"
#include "DLDL_IDENTITY/Ast/Node/VALUE.h"
#include "DLDL_IDENTITY/Ast/Node/SYMBOLS.h"
#include "DLDL_IDENTITY/Ast/Node/ESCAPE_CHARS.h"


#include "DLDL_IDENTITY/Ast/Node/program.h"
#include "DLDL_IDENTITY/Ast/Node/stmts.h"
#include "DLDL_IDENTITY/Ast/Node/stmt.h"
#include "DLDL_IDENTITY/Ast/Node/name_declaration.h"

#include <Deamer/External/Cpp/Ast/Listener.h>
#include <Deamer/Algorithm/Tree/DFS.h>

namespace DLDL_IDENTITY { namespace ast { namespace listener { 

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
			const auto enumeratedValue = static_cast<DLDL_IDENTITY::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case DLDL_IDENTITY::ast::Type::NAME:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_IDENTITY::ast::node::NAME*>(node));
				break;
			}

			case DLDL_IDENTITY::ast::Type::VALUE:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_IDENTITY::ast::node::VALUE*>(node));
				break;
			}

			case DLDL_IDENTITY::ast::Type::SYMBOLS:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_IDENTITY::ast::node::SYMBOLS*>(node));
				break;
			}

			case DLDL_IDENTITY::ast::Type::ESCAPE_CHARS:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_IDENTITY::ast::node::ESCAPE_CHARS*>(node));
				break;
			}


			// Nonterminal cases
			
			case DLDL_IDENTITY::ast::Type::program:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_IDENTITY::ast::node::program*>(node));
				break;
			}

			case DLDL_IDENTITY::ast::Type::stmts:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_IDENTITY::ast::node::stmts*>(node));
				break;
			}

			case DLDL_IDENTITY::ast::Type::stmt:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_IDENTITY::ast::node::stmt*>(node));
				break;
			}

			case DLDL_IDENTITY::ast::Type::name_declaration:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_IDENTITY::ast::node::name_declaration*>(node));
				break;
			}

			}
		}

		void DispatchExit(const ::deamer::external::cpp::ast::Node* node) 
		{
			const auto enumeratedValue = static_cast<DLDL_IDENTITY::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case DLDL_IDENTITY::ast::Type::NAME:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_IDENTITY::ast::node::NAME*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_IDENTITY::ast::Type::VALUE:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_IDENTITY::ast::node::VALUE*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_IDENTITY::ast::Type::SYMBOLS:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_IDENTITY::ast::node::SYMBOLS*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_IDENTITY::ast::Type::ESCAPE_CHARS:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_IDENTITY::ast::node::ESCAPE_CHARS*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}


			// Nonterminal cases
			
			case DLDL_IDENTITY::ast::Type::program:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_IDENTITY::ast::node::program*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_IDENTITY::ast::Type::stmts:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_IDENTITY::ast::node::stmts*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_IDENTITY::ast::Type::stmt:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_IDENTITY::ast::node::stmt*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_IDENTITY::ast::Type::name_declaration:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_IDENTITY::ast::node::name_declaration*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			}
		}

		
		virtual void ListenEntry(const DLDL_IDENTITY::ast::node::NAME* node) 
		{
		}

		virtual void ListenEntry(const DLDL_IDENTITY::ast::node::VALUE* node) 
		{
		}

		virtual void ListenEntry(const DLDL_IDENTITY::ast::node::SYMBOLS* node) 
		{
		}

		virtual void ListenEntry(const DLDL_IDENTITY::ast::node::ESCAPE_CHARS* node) 
		{
		}

		
		virtual void ListenExit(const DLDL_IDENTITY::ast::node::NAME* node) 
		{
		}

		virtual void ListenExit(const DLDL_IDENTITY::ast::node::VALUE* node) 
		{
		}

		virtual void ListenExit(const DLDL_IDENTITY::ast::node::SYMBOLS* node) 
		{
		}

		virtual void ListenExit(const DLDL_IDENTITY::ast::node::ESCAPE_CHARS* node) 
		{
		}


		
		virtual void ListenEntry(const DLDL_IDENTITY::ast::node::program* node) 
		{
		}

		virtual void ListenEntry(const DLDL_IDENTITY::ast::node::stmts* node) 
		{
		}

		virtual void ListenEntry(const DLDL_IDENTITY::ast::node::stmt* node) 
		{
		}

		virtual void ListenEntry(const DLDL_IDENTITY::ast::node::name_declaration* node) 
		{
		}

		
		virtual void ListenExit(const DLDL_IDENTITY::ast::node::program* node) 
		{
		}

		virtual void ListenExit(const DLDL_IDENTITY::ast::node::stmts* node) 
		{
		}

		virtual void ListenExit(const DLDL_IDENTITY::ast::node::stmt* node) 
		{
		}

		virtual void ListenExit(const DLDL_IDENTITY::ast::node::name_declaration* node) 
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

#endif // DLDL_IDENTITY_AST_LISTENER_ENTEREXITLISTENER_H