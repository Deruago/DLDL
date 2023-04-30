#ifndef DLDL_LPDSTRUCT_AST_LISTENER_ENTEREXITLISTENER_H
#define DLDL_LPDSTRUCT_AST_LISTENER_ENTEREXITLISTENER_H

#include "DLDL_LPDSTRUCT/Ast/Node/DLDL_LPDSTRUCT.h"
#include "DLDL_LPDSTRUCT/Ast/Enum/Type.h"

#include "DLDL_LPDSTRUCT/Ast/Node/COLON.h"
#include "DLDL_LPDSTRUCT/Ast/Node/LEFT_ANGLE_BRACKET.h"
#include "DLDL_LPDSTRUCT/Ast/Node/RIGHT_ANGLE_BRACKET.h"
#include "DLDL_LPDSTRUCT/Ast/Node/VARNAME.h"
#include "DLDL_LPDSTRUCT/Ast/Node/VARNAME_EXT.h"
#include "DLDL_LPDSTRUCT/Ast/Node/INDENTED_VALUE.h"
#include "DLDL_LPDSTRUCT/Ast/Node/ESCAPE_CHARS.h"


#include "DLDL_LPDSTRUCT/Ast/Node/program.h"
#include "DLDL_LPDSTRUCT/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_LPDSTRUCT/Ast/Node/stmt.h"
#include "DLDL_LPDSTRUCT/Ast/Node/argument.h"
#include "DLDL_LPDSTRUCT/Ast/Node/argument_name.h"
#include "DLDL_LPDSTRUCT/Ast/Node/argument_block.h"
#include "DLDL_LPDSTRUCT/Ast/Node/deamerreserved_long_60.h"
#include "DLDL_LPDSTRUCT/Ast/Node/deamerreserved_long_63.h"
#include "DLDL_LPDSTRUCT/Ast/Node/deamerreserved_long_66.h"

#include <Deamer/External/Cpp/Ast/Listener.h>
#include <Deamer/Algorithm/Tree/DFS.h>

namespace DLDL_LPDSTRUCT { namespace ast { namespace listener { 

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
			const auto enumeratedValue = static_cast<DLDL_LPDSTRUCT::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case DLDL_LPDSTRUCT::ast::Type::COLON:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDSTRUCT::ast::node::COLON*>(node));
				break;
			}

			case DLDL_LPDSTRUCT::ast::Type::LEFT_ANGLE_BRACKET:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDSTRUCT::ast::node::LEFT_ANGLE_BRACKET*>(node));
				break;
			}

			case DLDL_LPDSTRUCT::ast::Type::RIGHT_ANGLE_BRACKET:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDSTRUCT::ast::node::RIGHT_ANGLE_BRACKET*>(node));
				break;
			}

			case DLDL_LPDSTRUCT::ast::Type::VARNAME:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDSTRUCT::ast::node::VARNAME*>(node));
				break;
			}

			case DLDL_LPDSTRUCT::ast::Type::VARNAME_EXT:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDSTRUCT::ast::node::VARNAME_EXT*>(node));
				break;
			}

			case DLDL_LPDSTRUCT::ast::Type::INDENTED_VALUE:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDSTRUCT::ast::node::INDENTED_VALUE*>(node));
				break;
			}

			case DLDL_LPDSTRUCT::ast::Type::ESCAPE_CHARS:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDSTRUCT::ast::node::ESCAPE_CHARS*>(node));
				break;
			}


			// Nonterminal cases
			
			case DLDL_LPDSTRUCT::ast::Type::program:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDSTRUCT::ast::node::program*>(node));
				break;
			}

			case DLDL_LPDSTRUCT::ast::Type::deamerreserved_star__stmt__:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDSTRUCT::ast::node::deamerreserved_star__stmt__*>(node));
				break;
			}

			case DLDL_LPDSTRUCT::ast::Type::stmt:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDSTRUCT::ast::node::stmt*>(node));
				break;
			}

			case DLDL_LPDSTRUCT::ast::Type::argument:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDSTRUCT::ast::node::argument*>(node));
				break;
			}

			case DLDL_LPDSTRUCT::ast::Type::argument_name:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDSTRUCT::ast::node::argument_name*>(node));
				break;
			}

			case DLDL_LPDSTRUCT::ast::Type::argument_block:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDSTRUCT::ast::node::argument_block*>(node));
				break;
			}

			case DLDL_LPDSTRUCT::ast::Type::deamerreserved_long_60:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDSTRUCT::ast::node::deamerreserved_long_60*>(node));
				break;
			}

			case DLDL_LPDSTRUCT::ast::Type::deamerreserved_long_63:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDSTRUCT::ast::node::deamerreserved_long_63*>(node));
				break;
			}

			case DLDL_LPDSTRUCT::ast::Type::deamerreserved_long_66:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDSTRUCT::ast::node::deamerreserved_long_66*>(node));
				break;
			}

			}
		}

		void DispatchExit(const ::deamer::external::cpp::ast::Node* node) 
		{
			const auto enumeratedValue = static_cast<DLDL_LPDSTRUCT::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case DLDL_LPDSTRUCT::ast::Type::COLON:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDSTRUCT::ast::node::COLON*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDSTRUCT::ast::Type::LEFT_ANGLE_BRACKET:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDSTRUCT::ast::node::LEFT_ANGLE_BRACKET*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDSTRUCT::ast::Type::RIGHT_ANGLE_BRACKET:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDSTRUCT::ast::node::RIGHT_ANGLE_BRACKET*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDSTRUCT::ast::Type::VARNAME:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDSTRUCT::ast::node::VARNAME*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDSTRUCT::ast::Type::VARNAME_EXT:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDSTRUCT::ast::node::VARNAME_EXT*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDSTRUCT::ast::Type::INDENTED_VALUE:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDSTRUCT::ast::node::INDENTED_VALUE*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDSTRUCT::ast::Type::ESCAPE_CHARS:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDSTRUCT::ast::node::ESCAPE_CHARS*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}


			// Nonterminal cases
			
			case DLDL_LPDSTRUCT::ast::Type::program:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDSTRUCT::ast::node::program*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDSTRUCT::ast::Type::deamerreserved_star__stmt__:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDSTRUCT::ast::node::deamerreserved_star__stmt__*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDSTRUCT::ast::Type::stmt:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDSTRUCT::ast::node::stmt*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDSTRUCT::ast::Type::argument:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDSTRUCT::ast::node::argument*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDSTRUCT::ast::Type::argument_name:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDSTRUCT::ast::node::argument_name*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDSTRUCT::ast::Type::argument_block:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDSTRUCT::ast::node::argument_block*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDSTRUCT::ast::Type::deamerreserved_long_60:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDSTRUCT::ast::node::deamerreserved_long_60*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDSTRUCT::ast::Type::deamerreserved_long_63:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDSTRUCT::ast::node::deamerreserved_long_63*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDSTRUCT::ast::Type::deamerreserved_long_66:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDSTRUCT::ast::node::deamerreserved_long_66*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			}
		}

		
		virtual void ListenEntry(const DLDL_LPDSTRUCT::ast::node::COLON* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDSTRUCT::ast::node::LEFT_ANGLE_BRACKET* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDSTRUCT::ast::node::RIGHT_ANGLE_BRACKET* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDSTRUCT::ast::node::VARNAME* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDSTRUCT::ast::node::VARNAME_EXT* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDSTRUCT::ast::node::INDENTED_VALUE* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDSTRUCT::ast::node::ESCAPE_CHARS* node) 
		{
		}

		
		virtual void ListenExit(const DLDL_LPDSTRUCT::ast::node::COLON* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDSTRUCT::ast::node::LEFT_ANGLE_BRACKET* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDSTRUCT::ast::node::RIGHT_ANGLE_BRACKET* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDSTRUCT::ast::node::VARNAME* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDSTRUCT::ast::node::VARNAME_EXT* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDSTRUCT::ast::node::INDENTED_VALUE* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDSTRUCT::ast::node::ESCAPE_CHARS* node) 
		{
		}


		
		virtual void ListenEntry(const DLDL_LPDSTRUCT::ast::node::program* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDSTRUCT::ast::node::deamerreserved_star__stmt__* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDSTRUCT::ast::node::stmt* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDSTRUCT::ast::node::argument* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDSTRUCT::ast::node::argument_name* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDSTRUCT::ast::node::argument_block* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDSTRUCT::ast::node::deamerreserved_long_60* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDSTRUCT::ast::node::deamerreserved_long_63* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDSTRUCT::ast::node::deamerreserved_long_66* node) 
		{
		}

		
		virtual void ListenExit(const DLDL_LPDSTRUCT::ast::node::program* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDSTRUCT::ast::node::deamerreserved_star__stmt__* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDSTRUCT::ast::node::stmt* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDSTRUCT::ast::node::argument* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDSTRUCT::ast::node::argument_name* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDSTRUCT::ast::node::argument_block* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDSTRUCT::ast::node::deamerreserved_long_60* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDSTRUCT::ast::node::deamerreserved_long_63* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDSTRUCT::ast::node::deamerreserved_long_66* node) 
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

#endif // DLDL_LPDSTRUCT_AST_LISTENER_ENTEREXITLISTENER_H