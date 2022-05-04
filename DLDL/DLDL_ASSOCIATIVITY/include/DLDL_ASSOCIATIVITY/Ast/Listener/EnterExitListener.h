#ifndef DLDL_ASSOCIATIVITY_AST_LISTENER_ENTEREXITLISTENER_H
#define DLDL_ASSOCIATIVITY_AST_LISTENER_ENTEREXITLISTENER_H

#include "DLDL_ASSOCIATIVITY/Ast/Node/DLDL_ASSOCIATIVITY.h"
#include "DLDL_ASSOCIATIVITY/Ast/Enum/Type.h"

#include "DLDL_ASSOCIATIVITY/Ast/Node/ASSOCIATIVITY.h"


#include "DLDL_ASSOCIATIVITY/Ast/Node/program.h"
#include "DLDL_ASSOCIATIVITY/Ast/Node/stmts.h"
#include "DLDL_ASSOCIATIVITY/Ast/Node/stmt.h"

#include <Deamer/External/Cpp/Ast/Listener.h>
#include <Deamer/Algorithm/Tree/DFS.h>

namespace DLDL_ASSOCIATIVITY { namespace ast { namespace listener { 

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
			const auto enumeratedValue = static_cast<DLDL_ASSOCIATIVITY::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case DLDL_ASSOCIATIVITY::ast::Type::ASSOCIATIVITY:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_ASSOCIATIVITY::ast::node::ASSOCIATIVITY*>(node));
				break;
			}


			// Nonterminal cases
			
			case DLDL_ASSOCIATIVITY::ast::Type::program:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_ASSOCIATIVITY::ast::node::program*>(node));
				break;
			}

			case DLDL_ASSOCIATIVITY::ast::Type::stmts:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_ASSOCIATIVITY::ast::node::stmts*>(node));
				break;
			}

			case DLDL_ASSOCIATIVITY::ast::Type::stmt:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_ASSOCIATIVITY::ast::node::stmt*>(node));
				break;
			}

			}
		}

		void DispatchExit(const ::deamer::external::cpp::ast::Node* node) 
		{
			const auto enumeratedValue = static_cast<DLDL_ASSOCIATIVITY::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case DLDL_ASSOCIATIVITY::ast::Type::ASSOCIATIVITY:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_ASSOCIATIVITY::ast::node::ASSOCIATIVITY*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}


			// Nonterminal cases
			
			case DLDL_ASSOCIATIVITY::ast::Type::program:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_ASSOCIATIVITY::ast::node::program*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_ASSOCIATIVITY::ast::Type::stmts:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_ASSOCIATIVITY::ast::node::stmts*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_ASSOCIATIVITY::ast::Type::stmt:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_ASSOCIATIVITY::ast::node::stmt*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			}
		}

		
		virtual void ListenEntry(const DLDL_ASSOCIATIVITY::ast::node::ASSOCIATIVITY* node) 
		{
		}

		
		virtual void ListenExit(const DLDL_ASSOCIATIVITY::ast::node::ASSOCIATIVITY* node) 
		{
		}


		
		virtual void ListenEntry(const DLDL_ASSOCIATIVITY::ast::node::program* node) 
		{
		}

		virtual void ListenEntry(const DLDL_ASSOCIATIVITY::ast::node::stmts* node) 
		{
		}

		virtual void ListenEntry(const DLDL_ASSOCIATIVITY::ast::node::stmt* node) 
		{
		}

		
		virtual void ListenExit(const DLDL_ASSOCIATIVITY::ast::node::program* node) 
		{
		}

		virtual void ListenExit(const DLDL_ASSOCIATIVITY::ast::node::stmts* node) 
		{
		}

		virtual void ListenExit(const DLDL_ASSOCIATIVITY::ast::node::stmt* node) 
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

#endif // DLDL_ASSOCIATIVITY_AST_LISTENER_ENTEREXITLISTENER_H