#ifndef DLDL_ARGUMENT_AST_LISTENER_ENTEREXITLISTENER_H
#define DLDL_ARGUMENT_AST_LISTENER_ENTEREXITLISTENER_H

#include "DLDL_ARGUMENT/Ast/Node/DLDL_ARGUMENT.h"
#include "DLDL_ARGUMENT/Ast/Enum/Type.h"

#include "DLDL_ARGUMENT/Ast/Node/SINGLE_COMMENT.h"
#include "DLDL_ARGUMENT/Ast/Node/MULTI_COMMENT.h"
#include "DLDL_ARGUMENT/Ast/Node/TEXT.h"
#include "DLDL_ARGUMENT/Ast/Node/VARNAME.h"
#include "DLDL_ARGUMENT/Ast/Node/ESCAPE_CHARS.h"


#include "DLDL_ARGUMENT/Ast/Node/program.h"

#include <Deamer/External/Cpp/Ast/Listener.h>
#include <Deamer/Algorithm/Tree/DFS.h>

namespace DLDL_ARGUMENT { namespace ast { namespace listener { 

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
			const auto enumeratedValue = static_cast<DLDL_ARGUMENT::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case DLDL_ARGUMENT::ast::Type::SINGLE_COMMENT:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_ARGUMENT::ast::node::SINGLE_COMMENT*>(node));
				break;
			}

			case DLDL_ARGUMENT::ast::Type::MULTI_COMMENT:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_ARGUMENT::ast::node::MULTI_COMMENT*>(node));
				break;
			}

			case DLDL_ARGUMENT::ast::Type::TEXT:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_ARGUMENT::ast::node::TEXT*>(node));
				break;
			}

			case DLDL_ARGUMENT::ast::Type::VARNAME:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_ARGUMENT::ast::node::VARNAME*>(node));
				break;
			}

			case DLDL_ARGUMENT::ast::Type::ESCAPE_CHARS:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_ARGUMENT::ast::node::ESCAPE_CHARS*>(node));
				break;
			}


			// Nonterminal cases
			
			case DLDL_ARGUMENT::ast::Type::program:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_ARGUMENT::ast::node::program*>(node));
				break;
			}

			}
		}

		void DispatchExit(const ::deamer::external::cpp::ast::Node* node) 
		{
			const auto enumeratedValue = static_cast<DLDL_ARGUMENT::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case DLDL_ARGUMENT::ast::Type::SINGLE_COMMENT:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_ARGUMENT::ast::node::SINGLE_COMMENT*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_ARGUMENT::ast::Type::MULTI_COMMENT:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_ARGUMENT::ast::node::MULTI_COMMENT*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_ARGUMENT::ast::Type::TEXT:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_ARGUMENT::ast::node::TEXT*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_ARGUMENT::ast::Type::VARNAME:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_ARGUMENT::ast::node::VARNAME*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_ARGUMENT::ast::Type::ESCAPE_CHARS:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_ARGUMENT::ast::node::ESCAPE_CHARS*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}


			// Nonterminal cases
			
			case DLDL_ARGUMENT::ast::Type::program:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_ARGUMENT::ast::node::program*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			}
		}

		
		virtual void ListenEntry(const DLDL_ARGUMENT::ast::node::SINGLE_COMMENT* node) 
		{
		}

		virtual void ListenEntry(const DLDL_ARGUMENT::ast::node::MULTI_COMMENT* node) 
		{
		}

		virtual void ListenEntry(const DLDL_ARGUMENT::ast::node::TEXT* node) 
		{
		}

		virtual void ListenEntry(const DLDL_ARGUMENT::ast::node::VARNAME* node) 
		{
		}

		virtual void ListenEntry(const DLDL_ARGUMENT::ast::node::ESCAPE_CHARS* node) 
		{
		}

		
		virtual void ListenExit(const DLDL_ARGUMENT::ast::node::SINGLE_COMMENT* node) 
		{
		}

		virtual void ListenExit(const DLDL_ARGUMENT::ast::node::MULTI_COMMENT* node) 
		{
		}

		virtual void ListenExit(const DLDL_ARGUMENT::ast::node::TEXT* node) 
		{
		}

		virtual void ListenExit(const DLDL_ARGUMENT::ast::node::VARNAME* node) 
		{
		}

		virtual void ListenExit(const DLDL_ARGUMENT::ast::node::ESCAPE_CHARS* node) 
		{
		}


		
		virtual void ListenEntry(const DLDL_ARGUMENT::ast::node::program* node) 
		{
		}

		
		virtual void ListenExit(const DLDL_ARGUMENT::ast::node::program* node) 
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

#endif // DLDL_ARGUMENT_AST_LISTENER_ENTEREXITLISTENER_H