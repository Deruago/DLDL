#ifndef DLDL_LPDDEF_AST_LISTENER_ENTEREXITLISTENER_H
#define DLDL_LPDDEF_AST_LISTENER_ENTEREXITLISTENER_H

#include "DLDL_LPDDEF/Ast/Node/DLDL_LPDDEF.h"
#include "DLDL_LPDDEF/Ast/Enum/Type.h"

#include "DLDL_LPDDEF/Ast/Node/COLON.h"
#include "DLDL_LPDDEF/Ast/Node/LEFT_ANGLE_BRACKET.h"
#include "DLDL_LPDDEF/Ast/Node/RIGHT_ANGLE_BRACKET.h"
#include "DLDL_LPDDEF/Ast/Node/VARNAME.h"
#include "DLDL_LPDDEF/Ast/Node/INDENTED_VALUE.h"
#include "DLDL_LPDDEF/Ast/Node/ESCAPE_CHARS.h"


#include "DLDL_LPDDEF/Ast/Node/program.h"
#include "DLDL_LPDDEF/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_LPDDEF/Ast/Node/stmt.h"
#include "DLDL_LPDDEF/Ast/Node/argument.h"
#include "DLDL_LPDDEF/Ast/Node/argument_name.h"
#include "DLDL_LPDDEF/Ast/Node/argument_block.h"
#include "DLDL_LPDDEF/Ast/Node/deamerreserved_star__argument_stmt__.h"
#include "DLDL_LPDDEF/Ast/Node/argument_stmt.h"

#include <Deamer/External/Cpp/Ast/Listener.h>
#include <Deamer/Algorithm/Tree/DFS.h>

namespace DLDL_LPDDEF { namespace ast { namespace listener { 

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
			const auto enumeratedValue = static_cast<DLDL_LPDDEF::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case DLDL_LPDDEF::ast::Type::COLON:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF::ast::node::COLON*>(node));
				break;
			}

			case DLDL_LPDDEF::ast::Type::LEFT_ANGLE_BRACKET:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF::ast::node::LEFT_ANGLE_BRACKET*>(node));
				break;
			}

			case DLDL_LPDDEF::ast::Type::RIGHT_ANGLE_BRACKET:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF::ast::node::RIGHT_ANGLE_BRACKET*>(node));
				break;
			}

			case DLDL_LPDDEF::ast::Type::VARNAME:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF::ast::node::VARNAME*>(node));
				break;
			}

			case DLDL_LPDDEF::ast::Type::INDENTED_VALUE:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF::ast::node::INDENTED_VALUE*>(node));
				break;
			}

			case DLDL_LPDDEF::ast::Type::ESCAPE_CHARS:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF::ast::node::ESCAPE_CHARS*>(node));
				break;
			}


			// Nonterminal cases
			
			case DLDL_LPDDEF::ast::Type::program:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF::ast::node::program*>(node));
				break;
			}

			case DLDL_LPDDEF::ast::Type::deamerreserved_star__stmt__:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF::ast::node::deamerreserved_star__stmt__*>(node));
				break;
			}

			case DLDL_LPDDEF::ast::Type::stmt:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF::ast::node::stmt*>(node));
				break;
			}

			case DLDL_LPDDEF::ast::Type::argument:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF::ast::node::argument*>(node));
				break;
			}

			case DLDL_LPDDEF::ast::Type::argument_name:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF::ast::node::argument_name*>(node));
				break;
			}

			case DLDL_LPDDEF::ast::Type::argument_block:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF::ast::node::argument_block*>(node));
				break;
			}

			case DLDL_LPDDEF::ast::Type::deamerreserved_star__argument_stmt__:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF::ast::node::deamerreserved_star__argument_stmt__*>(node));
				break;
			}

			case DLDL_LPDDEF::ast::Type::argument_stmt:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF::ast::node::argument_stmt*>(node));
				break;
			}

			}
		}

		void DispatchExit(const ::deamer::external::cpp::ast::Node* node) 
		{
			const auto enumeratedValue = static_cast<DLDL_LPDDEF::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case DLDL_LPDDEF::ast::Type::COLON:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDDEF::ast::node::COLON*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF::ast::Type::LEFT_ANGLE_BRACKET:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDDEF::ast::node::LEFT_ANGLE_BRACKET*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF::ast::Type::RIGHT_ANGLE_BRACKET:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDDEF::ast::node::RIGHT_ANGLE_BRACKET*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF::ast::Type::VARNAME:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDDEF::ast::node::VARNAME*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF::ast::Type::INDENTED_VALUE:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDDEF::ast::node::INDENTED_VALUE*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF::ast::Type::ESCAPE_CHARS:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDDEF::ast::node::ESCAPE_CHARS*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}


			// Nonterminal cases
			
			case DLDL_LPDDEF::ast::Type::program:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDDEF::ast::node::program*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF::ast::Type::deamerreserved_star__stmt__:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDDEF::ast::node::deamerreserved_star__stmt__*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF::ast::Type::stmt:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDDEF::ast::node::stmt*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF::ast::Type::argument:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDDEF::ast::node::argument*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF::ast::Type::argument_name:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDDEF::ast::node::argument_name*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF::ast::Type::argument_block:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDDEF::ast::node::argument_block*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF::ast::Type::deamerreserved_star__argument_stmt__:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDDEF::ast::node::deamerreserved_star__argument_stmt__*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF::ast::Type::argument_stmt:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDDEF::ast::node::argument_stmt*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			}
		}

		
		virtual void ListenEntry(const DLDL_LPDDEF::ast::node::COLON* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF::ast::node::LEFT_ANGLE_BRACKET* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF::ast::node::RIGHT_ANGLE_BRACKET* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF::ast::node::VARNAME* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF::ast::node::INDENTED_VALUE* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF::ast::node::ESCAPE_CHARS* node) 
		{
		}

		
		virtual void ListenExit(const DLDL_LPDDEF::ast::node::COLON* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF::ast::node::LEFT_ANGLE_BRACKET* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF::ast::node::RIGHT_ANGLE_BRACKET* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF::ast::node::VARNAME* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF::ast::node::INDENTED_VALUE* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF::ast::node::ESCAPE_CHARS* node) 
		{
		}


		
		virtual void ListenEntry(const DLDL_LPDDEF::ast::node::program* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF::ast::node::deamerreserved_star__stmt__* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF::ast::node::stmt* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF::ast::node::argument* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF::ast::node::argument_name* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF::ast::node::argument_block* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF::ast::node::deamerreserved_star__argument_stmt__* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF::ast::node::argument_stmt* node) 
		{
		}

		
		virtual void ListenExit(const DLDL_LPDDEF::ast::node::program* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF::ast::node::deamerreserved_star__stmt__* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF::ast::node::stmt* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF::ast::node::argument* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF::ast::node::argument_name* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF::ast::node::argument_block* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF::ast::node::deamerreserved_star__argument_stmt__* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF::ast::node::argument_stmt* node) 
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

#endif // DLDL_LPDDEF_AST_LISTENER_ENTEREXITLISTENER_H