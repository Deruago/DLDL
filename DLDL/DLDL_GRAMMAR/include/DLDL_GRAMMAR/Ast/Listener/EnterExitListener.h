#ifndef DLDL_GRAMMAR_AST_LISTENER_ENTEREXITLISTENER_H
#define DLDL_GRAMMAR_AST_LISTENER_ENTEREXITLISTENER_H

#include "DLDL_GRAMMAR/Ast/Node/DLDL_GRAMMAR.h"
#include "DLDL_GRAMMAR/Ast/Enum/Type.h"

#include "DLDL_GRAMMAR/Ast/Node/COMMENT.h"
#include "DLDL_GRAMMAR/Ast/Node/START_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/GROUP_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/INLINE_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/INLINE_GROUP_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/UNKNOWN_ABSTRACTION.h"
#include "DLDL_GRAMMAR/Ast/Node/NONTERMINAL.h"
#include "DLDL_GRAMMAR/Ast/Node/PRODUCTION_RULE.h"
#include "DLDL_GRAMMAR/Ast/Node/ESCAPE_CHARS.h"


#include "DLDL_GRAMMAR/Ast/Node/program.h"
#include "DLDL_GRAMMAR/Ast/Node/stmts.h"
#include "DLDL_GRAMMAR/Ast/Node/stmt.h"
#include "DLDL_GRAMMAR/Ast/Node/abstraction_declaration.h"
#include "DLDL_GRAMMAR/Ast/Node/abstraction.h"
#include "DLDL_GRAMMAR/Ast/Node/definition.h"
#include "DLDL_GRAMMAR/Ast/Node/production_rules.h"

#include <Deamer/External/Cpp/Ast/Listener.h>
#include <Deamer/Algorithm/Tree/DFS.h>

namespace DLDL_GRAMMAR { namespace ast { namespace listener { 

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
			const auto enumeratedValue = static_cast<DLDL_GRAMMAR::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case DLDL_GRAMMAR::ast::Type::COMMENT:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR::ast::node::COMMENT*>(node));
				break;
			}

			case DLDL_GRAMMAR::ast::Type::START_ABSTRACTION:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR::ast::node::START_ABSTRACTION*>(node));
				break;
			}

			case DLDL_GRAMMAR::ast::Type::GROUP_ABSTRACTION:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR::ast::node::GROUP_ABSTRACTION*>(node));
				break;
			}

			case DLDL_GRAMMAR::ast::Type::INLINE_ABSTRACTION:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR::ast::node::INLINE_ABSTRACTION*>(node));
				break;
			}

			case DLDL_GRAMMAR::ast::Type::INLINE_GROUP_ABSTRACTION:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR::ast::node::INLINE_GROUP_ABSTRACTION*>(node));
				break;
			}

			case DLDL_GRAMMAR::ast::Type::UNKNOWN_ABSTRACTION:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR::ast::node::UNKNOWN_ABSTRACTION*>(node));
				break;
			}

			case DLDL_GRAMMAR::ast::Type::NONTERMINAL:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR::ast::node::NONTERMINAL*>(node));
				break;
			}

			case DLDL_GRAMMAR::ast::Type::PRODUCTION_RULE:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR::ast::node::PRODUCTION_RULE*>(node));
				break;
			}

			case DLDL_GRAMMAR::ast::Type::ESCAPE_CHARS:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR::ast::node::ESCAPE_CHARS*>(node));
				break;
			}


			// Nonterminal cases
			
			case DLDL_GRAMMAR::ast::Type::program:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR::ast::node::program*>(node));
				break;
			}

			case DLDL_GRAMMAR::ast::Type::stmts:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR::ast::node::stmts*>(node));
				break;
			}

			case DLDL_GRAMMAR::ast::Type::stmt:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR::ast::node::stmt*>(node));
				break;
			}

			case DLDL_GRAMMAR::ast::Type::abstraction_declaration:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR::ast::node::abstraction_declaration*>(node));
				break;
			}

			case DLDL_GRAMMAR::ast::Type::abstraction:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR::ast::node::abstraction*>(node));
				break;
			}

			case DLDL_GRAMMAR::ast::Type::definition:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR::ast::node::definition*>(node));
				break;
			}

			case DLDL_GRAMMAR::ast::Type::production_rules:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_GRAMMAR::ast::node::production_rules*>(node));
				break;
			}

			}
		}

		void DispatchExit(const ::deamer::external::cpp::ast::Node* node) 
		{
			const auto enumeratedValue = static_cast<DLDL_GRAMMAR::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case DLDL_GRAMMAR::ast::Type::COMMENT:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_GRAMMAR::ast::node::COMMENT*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR::ast::Type::START_ABSTRACTION:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_GRAMMAR::ast::node::START_ABSTRACTION*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR::ast::Type::GROUP_ABSTRACTION:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_GRAMMAR::ast::node::GROUP_ABSTRACTION*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR::ast::Type::INLINE_ABSTRACTION:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_GRAMMAR::ast::node::INLINE_ABSTRACTION*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR::ast::Type::INLINE_GROUP_ABSTRACTION:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_GRAMMAR::ast::node::INLINE_GROUP_ABSTRACTION*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR::ast::Type::UNKNOWN_ABSTRACTION:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_GRAMMAR::ast::node::UNKNOWN_ABSTRACTION*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR::ast::Type::NONTERMINAL:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_GRAMMAR::ast::node::NONTERMINAL*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR::ast::Type::PRODUCTION_RULE:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_GRAMMAR::ast::node::PRODUCTION_RULE*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR::ast::Type::ESCAPE_CHARS:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_GRAMMAR::ast::node::ESCAPE_CHARS*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}


			// Nonterminal cases
			
			case DLDL_GRAMMAR::ast::Type::program:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_GRAMMAR::ast::node::program*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR::ast::Type::stmts:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_GRAMMAR::ast::node::stmts*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR::ast::Type::stmt:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_GRAMMAR::ast::node::stmt*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR::ast::Type::abstraction_declaration:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_GRAMMAR::ast::node::abstraction_declaration*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR::ast::Type::abstraction:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_GRAMMAR::ast::node::abstraction*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR::ast::Type::definition:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_GRAMMAR::ast::node::definition*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_GRAMMAR::ast::Type::production_rules:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_GRAMMAR::ast::node::production_rules*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			}
		}

		
		virtual void ListenEntry(const DLDL_GRAMMAR::ast::node::COMMENT* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR::ast::node::START_ABSTRACTION* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR::ast::node::GROUP_ABSTRACTION* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR::ast::node::INLINE_ABSTRACTION* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR::ast::node::INLINE_GROUP_ABSTRACTION* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR::ast::node::UNKNOWN_ABSTRACTION* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR::ast::node::NONTERMINAL* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR::ast::node::PRODUCTION_RULE* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR::ast::node::ESCAPE_CHARS* node) 
		{
		}

		
		virtual void ListenExit(const DLDL_GRAMMAR::ast::node::COMMENT* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR::ast::node::START_ABSTRACTION* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR::ast::node::GROUP_ABSTRACTION* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR::ast::node::INLINE_ABSTRACTION* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR::ast::node::INLINE_GROUP_ABSTRACTION* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR::ast::node::UNKNOWN_ABSTRACTION* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR::ast::node::NONTERMINAL* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR::ast::node::PRODUCTION_RULE* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR::ast::node::ESCAPE_CHARS* node) 
		{
		}


		
		virtual void ListenEntry(const DLDL_GRAMMAR::ast::node::program* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR::ast::node::stmts* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR::ast::node::stmt* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR::ast::node::abstraction_declaration* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR::ast::node::abstraction* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR::ast::node::definition* node) 
		{
		}

		virtual void ListenEntry(const DLDL_GRAMMAR::ast::node::production_rules* node) 
		{
		}

		
		virtual void ListenExit(const DLDL_GRAMMAR::ast::node::program* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR::ast::node::stmts* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR::ast::node::stmt* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR::ast::node::abstraction_declaration* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR::ast::node::abstraction* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR::ast::node::definition* node) 
		{
		}

		virtual void ListenExit(const DLDL_GRAMMAR::ast::node::production_rules* node) 
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

#endif // DLDL_GRAMMAR_AST_LISTENER_ENTEREXITLISTENER_H