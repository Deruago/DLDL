#ifndef DLDL_GENERATION_AST_LISTENER_ENTEREXITLISTENER_H
#define DLDL_GENERATION_AST_LISTENER_ENTEREXITLISTENER_H

#include <Deamer/External/Cpp/Ast/Listener.h>
#include "DLDL_GENERATION/Ast/Node/DLDL_GENERATION.h"
#include "DLDL_GENERATION/Ast/Enum/Type.h"

#include "DLDL_GENERATION/Ast/Node/GENERATE.h"
#include "DLDL_GENERATION/Ast/Node/INTEGRATE.h"
#include "DLDL_GENERATION/Ast/Node/ARGUMENT.h"
#include "DLDL_GENERATION/Ast/Node/VALUE.h"
#include "DLDL_GENERATION/Ast/Node/SYMBOLS.h"
#include "DLDL_GENERATION/Ast/Node/ESCAPE_CHARS.h"


#include "DLDL_GENERATION/Ast/Node/program.h"
#include "DLDL_GENERATION/Ast/Node/stmts.h"
#include "DLDL_GENERATION/Ast/Node/stmt.h"
#include "DLDL_GENERATION/Ast/Node/generate_declaration.h"
#include "DLDL_GENERATION/Ast/Node/integrate_declaration.h"
#include "DLDL_GENERATION/Ast/Node/argument_declaration.h"
#include "DLDL_GENERATION/Ast/Node/type.h"
#include "DLDL_GENERATION/Ast/Node/tool.h"
#include "DLDL_GENERATION/Ast/Node/argument_data.h"


namespace DLDL_GENERATION { namespace ast { namespace listener { 

	class EnterExitListener : public ::deamer::external::cpp::ast::Listener
	{
	private:
	public:
		EnterExitListener() = default;
		~EnterExitListener() override = default;

	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node)  override
		{
			const auto enumeratedValue = static_cast<DLDL_GENERATION::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case DLDL_GENERATION::ast::Type::GENERATE:
			{
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GENERATION::ast::node::GENERATE*>(node));
				break;
			}

			case DLDL_GENERATION::ast::Type::INTEGRATE:
			{
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GENERATION::ast::node::INTEGRATE*>(node));
				break;
			}

			case DLDL_GENERATION::ast::Type::ARGUMENT:
			{
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GENERATION::ast::node::ARGUMENT*>(node));
				break;
			}

			case DLDL_GENERATION::ast::Type::VALUE:
			{
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GENERATION::ast::node::VALUE*>(node));
				break;
			}

			case DLDL_GENERATION::ast::Type::SYMBOLS:
			{
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GENERATION::ast::node::SYMBOLS*>(node));
				break;
			}

			case DLDL_GENERATION::ast::Type::ESCAPE_CHARS:
			{
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GENERATION::ast::node::ESCAPE_CHARS*>(node));
				break;
			}


			// Nonterminal cases
			
			case DLDL_GENERATION::ast::Type::program:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_GENERATION::ast::node::program*>(node));
				
				// Go through its children
				DefaultAction(node);

				// Exit nonterminal
				ListenExit(static_cast<const DLDL_GENERATION::ast::node::program*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GENERATION::ast::Type::stmts:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_GENERATION::ast::node::stmts*>(node));
				
				// Go through its children
				DefaultAction(node);

				// Exit nonterminal
				ListenExit(static_cast<const DLDL_GENERATION::ast::node::stmts*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GENERATION::ast::Type::stmt:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_GENERATION::ast::node::stmt*>(node));
				
				// Go through its children
				DefaultAction(node);

				// Exit nonterminal
				ListenExit(static_cast<const DLDL_GENERATION::ast::node::stmt*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GENERATION::ast::Type::generate_declaration:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_GENERATION::ast::node::generate_declaration*>(node));
				
				// Go through its children
				DefaultAction(node);

				// Exit nonterminal
				ListenExit(static_cast<const DLDL_GENERATION::ast::node::generate_declaration*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GENERATION::ast::Type::integrate_declaration:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_GENERATION::ast::node::integrate_declaration*>(node));
				
				// Go through its children
				DefaultAction(node);

				// Exit nonterminal
				ListenExit(static_cast<const DLDL_GENERATION::ast::node::integrate_declaration*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GENERATION::ast::Type::argument_declaration:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_GENERATION::ast::node::argument_declaration*>(node));
				
				// Go through its children
				DefaultAction(node);

				// Exit nonterminal
				ListenExit(static_cast<const DLDL_GENERATION::ast::node::argument_declaration*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GENERATION::ast::Type::type:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_GENERATION::ast::node::type*>(node));
				
				// Go through its children
				DefaultAction(node);

				// Exit nonterminal
				ListenExit(static_cast<const DLDL_GENERATION::ast::node::type*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GENERATION::ast::Type::tool:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_GENERATION::ast::node::tool*>(node));
				
				// Go through its children
				DefaultAction(node);

				// Exit nonterminal
				ListenExit(static_cast<const DLDL_GENERATION::ast::node::tool*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GENERATION::ast::Type::argument_data:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_GENERATION::ast::node::argument_data*>(node));
				
				// Go through its children
				DefaultAction(node);

				// Exit nonterminal
				ListenExit(static_cast<const DLDL_GENERATION::ast::node::argument_data*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			}
		}

		
		virtual void ListenEntry(const DLDL_GENERATION::ast::node::GENERATE* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GENERATION::ast::node::INTEGRATE* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GENERATION::ast::node::ARGUMENT* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GENERATION::ast::node::VALUE* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GENERATION::ast::node::SYMBOLS* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GENERATION::ast::node::ESCAPE_CHARS* node) 
		{
		}

		

		
		virtual void ListenEntry(const DLDL_GENERATION::ast::node::program* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GENERATION::ast::node::stmts* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GENERATION::ast::node::stmt* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GENERATION::ast::node::generate_declaration* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GENERATION::ast::node::integrate_declaration* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GENERATION::ast::node::argument_declaration* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GENERATION::ast::node::type* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GENERATION::ast::node::tool* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GENERATION::ast::node::argument_data* node) 
		{
		}

		
		virtual void ListenExit(const DLDL_GENERATION::ast::node::program* node) 
		{
		}

		virtual void ListenExit(const DLDL_GENERATION::ast::node::stmts* node) 
		{
		}

		virtual void ListenExit(const DLDL_GENERATION::ast::node::stmt* node) 
		{
		}

		virtual void ListenExit(const DLDL_GENERATION::ast::node::generate_declaration* node) 
		{
		}

		virtual void ListenExit(const DLDL_GENERATION::ast::node::integrate_declaration* node) 
		{
		}

		virtual void ListenExit(const DLDL_GENERATION::ast::node::argument_declaration* node) 
		{
		}

		virtual void ListenExit(const DLDL_GENERATION::ast::node::type* node) 
		{
		}

		virtual void ListenExit(const DLDL_GENERATION::ast::node::tool* node) 
		{
		}

		virtual void ListenExit(const DLDL_GENERATION::ast::node::argument_data* node) 
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

#endif // DLDL_GENERATION_AST_LISTENER_ENTEREXITLISTENER_H