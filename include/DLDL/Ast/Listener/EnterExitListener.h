#ifndef DLDL_AST_LISTENER_ENTEREXITLISTENER_H
#define DLDL_AST_LISTENER_ENTEREXITLISTENER_H

#include "DLDL/Ast/Node/DLDL.h"
#include "DLDL/Ast/Enum/Type.h"

#include "DLDL/Ast/Node/ANY.h"


#include "DLDL/Ast/Node/program.h"
#include "DLDL/Ast/Node/stmts.h"
#include "DLDL/Ast/Node/stmt.h"

#include <Deamer/External/Cpp/Ast/Listener.h>
#include <Deamer/Algorithm/Tree/DFS.h>

namespace DLDL { namespace ast { namespace listener { 

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
			const auto enumeratedValue = static_cast<DLDL::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case DLDL::ast::Type::ANY:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL::ast::node::ANY*>(node));
				break;
			}


			// Nonterminal cases
			
			case DLDL::ast::Type::program:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL::ast::node::program*>(node));
				break;
			}

			case DLDL::ast::Type::stmts:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL::ast::node::stmts*>(node));
				break;
			}

			case DLDL::ast::Type::stmt:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL::ast::node::stmt*>(node));
				break;
			}

			}
		}

		void DispatchExit(const ::deamer::external::cpp::ast::Node* node) 
		{
			const auto enumeratedValue = static_cast<DLDL::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case DLDL::ast::Type::ANY:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL::ast::node::ANY*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}


			// Nonterminal cases
			
			case DLDL::ast::Type::program:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL::ast::node::program*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL::ast::Type::stmts:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL::ast::node::stmts*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL::ast::Type::stmt:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL::ast::node::stmt*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			}
		}

		
		virtual void ListenEntry(const DLDL::ast::node::ANY* node) 
		{
		}

		
		virtual void ListenExit(const DLDL::ast::node::ANY* node) 
		{
		}


		
		virtual void ListenEntry(const DLDL::ast::node::program* node) 
		{
		}

		virtual void ListenEntry(const DLDL::ast::node::stmts* node) 
		{
		}

		virtual void ListenEntry(const DLDL::ast::node::stmt* node) 
		{
		}

		
		virtual void ListenExit(const DLDL::ast::node::program* node) 
		{
		}

		virtual void ListenExit(const DLDL::ast::node::stmts* node) 
		{
		}

		virtual void ListenExit(const DLDL::ast::node::stmt* node) 
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

#endif // DLDL_AST_LISTENER_ENTEREXITLISTENER_H