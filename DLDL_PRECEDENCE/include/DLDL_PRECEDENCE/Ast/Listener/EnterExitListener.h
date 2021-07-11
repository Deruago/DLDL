#ifndef DLDL_PRECEDENCE_AST_LISTENER_ENTEREXITLISTENER_H
#define DLDL_PRECEDENCE_AST_LISTENER_ENTEREXITLISTENER_H

#include <Deamer/External/Cpp/Ast/Listener.h>
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
			const auto enumeratedValue = static_cast<DLDL_PRECEDENCE::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case DLDL_PRECEDENCE::ast::Type::PRECEDENCE:
			{
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_PRECEDENCE::ast::node::PRECEDENCE*>(node));
				break;
			}

			case DLDL_PRECEDENCE::ast::Type::NUMBER:
			{
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_PRECEDENCE::ast::node::NUMBER*>(node));
				break;
			}

			case DLDL_PRECEDENCE::ast::Type::TERMINAL:
			{
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_PRECEDENCE::ast::node::TERMINAL*>(node));
				break;
			}

			case DLDL_PRECEDENCE::ast::Type::SYMBOLS:
			{
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_PRECEDENCE::ast::node::SYMBOLS*>(node));
				break;
			}

			case DLDL_PRECEDENCE::ast::Type::ESCAPE_CHARS:
			{
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
				
				// Go through its children
				DefaultAction(node);

				// Exit nonterminal
				ListenExit(static_cast<const DLDL_PRECEDENCE::ast::node::program*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_PRECEDENCE::ast::Type::stmts:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_PRECEDENCE::ast::node::stmts*>(node));
				
				// Go through its children
				DefaultAction(node);

				// Exit nonterminal
				ListenExit(static_cast<const DLDL_PRECEDENCE::ast::node::stmts*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_PRECEDENCE::ast::Type::stmt:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_PRECEDENCE::ast::node::stmt*>(node));
				
				// Go through its children
				DefaultAction(node);

				// Exit nonterminal
				ListenExit(static_cast<const DLDL_PRECEDENCE::ast::node::stmt*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_PRECEDENCE::ast::Type::localized_precedence:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_PRECEDENCE::ast::node::localized_precedence*>(node));
				
				// Go through its children
				DefaultAction(node);

				// Exit nonterminal
				ListenExit(static_cast<const DLDL_PRECEDENCE::ast::node::localized_precedence*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_PRECEDENCE::ast::Type::specific_precedence:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_PRECEDENCE::ast::node::specific_precedence*>(node));
				
				// Go through its children
				DefaultAction(node);

				// Exit nonterminal
				ListenExit(static_cast<const DLDL_PRECEDENCE::ast::node::specific_precedence*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_PRECEDENCE::ast::Type::terminal_one_or_more:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_PRECEDENCE::ast::node::terminal_one_or_more*>(node));
				
				// Go through its children
				DefaultAction(node);

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
	
	private:
		void DefaultAction(const ::deamer::external::cpp::ast::Node* node) 
		{
			for(const auto* child : node->GetNodes())
			{
				Dispatch(child);
			}
		}
	};

}}}

#endif // DLDL_PRECEDENCE_AST_LISTENER_ENTEREXITLISTENER_H