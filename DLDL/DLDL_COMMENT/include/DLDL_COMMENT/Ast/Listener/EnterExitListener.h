#ifndef DLDL_COMMENT_AST_LISTENER_ENTEREXITLISTENER_H
#define DLDL_COMMENT_AST_LISTENER_ENTEREXITLISTENER_H

#include "DLDL_COMMENT/Ast/Node/DLDL_COMMENT.h"
#include "DLDL_COMMENT/Ast/Enum/Type.h"

#include "DLDL_COMMENT/Ast/Node/SINGLE_COMMENT.h"
#include "DLDL_COMMENT/Ast/Node/MULTI_COMMENT.h"
#include "DLDL_COMMENT/Ast/Node/COMMENT_VALUE.h"
#include "DLDL_COMMENT/Ast/Node/LEFT_SQUARE_BRACKET.h"
#include "DLDL_COMMENT/Ast/Node/RIGHT_SQUARE_BRACKET.h"
#include "DLDL_COMMENT/Ast/Node/START.h"
#include "DLDL_COMMENT/Ast/Node/END.h"
#include "DLDL_COMMENT/Ast/Node/TEXT.h"
#include "DLDL_COMMENT/Ast/Node/VARNAME.h"
#include "DLDL_COMMENT/Ast/Node/ESCAPE_CHARS.h"


#include "DLDL_COMMENT/Ast/Node/program.h"
#include "DLDL_COMMENT/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_COMMENT/Ast/Node/stmt.h"
#include "DLDL_COMMENT/Ast/Node/comment_value_declaration.h"
#include "DLDL_COMMENT/Ast/Node/deamerreserved_long_3.h"
#include "DLDL_COMMENT/Ast/Node/deamerreserved_long_6.h"
#include "DLDL_COMMENT/Ast/Node/comment_abstraction.h"
#include "DLDL_COMMENT/Ast/Node/start_abstraction.h"
#include "DLDL_COMMENT/Ast/Node/end_abstraction.h"
#include "DLDL_COMMENT/Ast/Node/start_sequence.h"
#include "DLDL_COMMENT/Ast/Node/end_sequence.h"
#include "DLDL_COMMENT/Ast/Node/sequence.h"
#include "DLDL_COMMENT/Ast/Node/syntactic_reference.h"

#include <Deamer/External/Cpp/Ast/Listener.h>
#include <Deamer/Algorithm/Tree/DFS.h>

namespace DLDL_COMMENT { namespace ast { namespace listener { 

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
			const auto enumeratedValue = static_cast<DLDL_COMMENT::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case DLDL_COMMENT::ast::Type::SINGLE_COMMENT:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_COMMENT::ast::node::SINGLE_COMMENT*>(node));
				break;
			}

			case DLDL_COMMENT::ast::Type::MULTI_COMMENT:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_COMMENT::ast::node::MULTI_COMMENT*>(node));
				break;
			}

			case DLDL_COMMENT::ast::Type::COMMENT_VALUE:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_COMMENT::ast::node::COMMENT_VALUE*>(node));
				break;
			}

			case DLDL_COMMENT::ast::Type::LEFT_SQUARE_BRACKET:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_COMMENT::ast::node::LEFT_SQUARE_BRACKET*>(node));
				break;
			}

			case DLDL_COMMENT::ast::Type::RIGHT_SQUARE_BRACKET:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_COMMENT::ast::node::RIGHT_SQUARE_BRACKET*>(node));
				break;
			}

			case DLDL_COMMENT::ast::Type::START:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_COMMENT::ast::node::START*>(node));
				break;
			}

			case DLDL_COMMENT::ast::Type::END:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_COMMENT::ast::node::END*>(node));
				break;
			}

			case DLDL_COMMENT::ast::Type::TEXT:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_COMMENT::ast::node::TEXT*>(node));
				break;
			}

			case DLDL_COMMENT::ast::Type::VARNAME:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_COMMENT::ast::node::VARNAME*>(node));
				break;
			}

			case DLDL_COMMENT::ast::Type::ESCAPE_CHARS:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_COMMENT::ast::node::ESCAPE_CHARS*>(node));
				break;
			}


			// Nonterminal cases
			
			case DLDL_COMMENT::ast::Type::program:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_COMMENT::ast::node::program*>(node));
				break;
			}

			case DLDL_COMMENT::ast::Type::deamerreserved_star__stmt__:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_COMMENT::ast::node::deamerreserved_star__stmt__*>(node));
				break;
			}

			case DLDL_COMMENT::ast::Type::stmt:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_COMMENT::ast::node::stmt*>(node));
				break;
			}

			case DLDL_COMMENT::ast::Type::comment_value_declaration:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_COMMENT::ast::node::comment_value_declaration*>(node));
				break;
			}

			case DLDL_COMMENT::ast::Type::deamerreserved_long_3:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_COMMENT::ast::node::deamerreserved_long_3*>(node));
				break;
			}

			case DLDL_COMMENT::ast::Type::deamerreserved_long_6:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_COMMENT::ast::node::deamerreserved_long_6*>(node));
				break;
			}

			case DLDL_COMMENT::ast::Type::comment_abstraction:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_COMMENT::ast::node::comment_abstraction*>(node));
				break;
			}

			case DLDL_COMMENT::ast::Type::start_abstraction:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_COMMENT::ast::node::start_abstraction*>(node));
				break;
			}

			case DLDL_COMMENT::ast::Type::end_abstraction:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_COMMENT::ast::node::end_abstraction*>(node));
				break;
			}

			case DLDL_COMMENT::ast::Type::start_sequence:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_COMMENT::ast::node::start_sequence*>(node));
				break;
			}

			case DLDL_COMMENT::ast::Type::end_sequence:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_COMMENT::ast::node::end_sequence*>(node));
				break;
			}

			case DLDL_COMMENT::ast::Type::sequence:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_COMMENT::ast::node::sequence*>(node));
				break;
			}

			case DLDL_COMMENT::ast::Type::syntactic_reference:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_COMMENT::ast::node::syntactic_reference*>(node));
				break;
			}

			}
		}

		void DispatchExit(const ::deamer::external::cpp::ast::Node* node) 
		{
			const auto enumeratedValue = static_cast<DLDL_COMMENT::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case DLDL_COMMENT::ast::Type::SINGLE_COMMENT:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_COMMENT::ast::node::SINGLE_COMMENT*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_COMMENT::ast::Type::MULTI_COMMENT:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_COMMENT::ast::node::MULTI_COMMENT*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_COMMENT::ast::Type::COMMENT_VALUE:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_COMMENT::ast::node::COMMENT_VALUE*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_COMMENT::ast::Type::LEFT_SQUARE_BRACKET:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_COMMENT::ast::node::LEFT_SQUARE_BRACKET*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_COMMENT::ast::Type::RIGHT_SQUARE_BRACKET:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_COMMENT::ast::node::RIGHT_SQUARE_BRACKET*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_COMMENT::ast::Type::START:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_COMMENT::ast::node::START*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_COMMENT::ast::Type::END:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_COMMENT::ast::node::END*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_COMMENT::ast::Type::TEXT:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_COMMENT::ast::node::TEXT*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_COMMENT::ast::Type::VARNAME:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_COMMENT::ast::node::VARNAME*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_COMMENT::ast::Type::ESCAPE_CHARS:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_COMMENT::ast::node::ESCAPE_CHARS*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}


			// Nonterminal cases
			
			case DLDL_COMMENT::ast::Type::program:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_COMMENT::ast::node::program*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_COMMENT::ast::Type::deamerreserved_star__stmt__:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_COMMENT::ast::node::deamerreserved_star__stmt__*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_COMMENT::ast::Type::stmt:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_COMMENT::ast::node::stmt*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_COMMENT::ast::Type::comment_value_declaration:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_COMMENT::ast::node::comment_value_declaration*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_COMMENT::ast::Type::deamerreserved_long_3:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_COMMENT::ast::node::deamerreserved_long_3*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_COMMENT::ast::Type::deamerreserved_long_6:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_COMMENT::ast::node::deamerreserved_long_6*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_COMMENT::ast::Type::comment_abstraction:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_COMMENT::ast::node::comment_abstraction*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_COMMENT::ast::Type::start_abstraction:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_COMMENT::ast::node::start_abstraction*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_COMMENT::ast::Type::end_abstraction:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_COMMENT::ast::node::end_abstraction*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_COMMENT::ast::Type::start_sequence:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_COMMENT::ast::node::start_sequence*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_COMMENT::ast::Type::end_sequence:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_COMMENT::ast::node::end_sequence*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_COMMENT::ast::Type::sequence:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_COMMENT::ast::node::sequence*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_COMMENT::ast::Type::syntactic_reference:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_COMMENT::ast::node::syntactic_reference*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			}
		}

		
		virtual void ListenEntry(const DLDL_COMMENT::ast::node::SINGLE_COMMENT* node) 
		{
		}

		virtual void ListenEntry(const DLDL_COMMENT::ast::node::MULTI_COMMENT* node) 
		{
		}

		virtual void ListenEntry(const DLDL_COMMENT::ast::node::COMMENT_VALUE* node) 
		{
		}

		virtual void ListenEntry(const DLDL_COMMENT::ast::node::LEFT_SQUARE_BRACKET* node) 
		{
		}

		virtual void ListenEntry(const DLDL_COMMENT::ast::node::RIGHT_SQUARE_BRACKET* node) 
		{
		}

		virtual void ListenEntry(const DLDL_COMMENT::ast::node::START* node) 
		{
		}

		virtual void ListenEntry(const DLDL_COMMENT::ast::node::END* node) 
		{
		}

		virtual void ListenEntry(const DLDL_COMMENT::ast::node::TEXT* node) 
		{
		}

		virtual void ListenEntry(const DLDL_COMMENT::ast::node::VARNAME* node) 
		{
		}

		virtual void ListenEntry(const DLDL_COMMENT::ast::node::ESCAPE_CHARS* node) 
		{
		}

		
		virtual void ListenExit(const DLDL_COMMENT::ast::node::SINGLE_COMMENT* node) 
		{
		}

		virtual void ListenExit(const DLDL_COMMENT::ast::node::MULTI_COMMENT* node) 
		{
		}

		virtual void ListenExit(const DLDL_COMMENT::ast::node::COMMENT_VALUE* node) 
		{
		}

		virtual void ListenExit(const DLDL_COMMENT::ast::node::LEFT_SQUARE_BRACKET* node) 
		{
		}

		virtual void ListenExit(const DLDL_COMMENT::ast::node::RIGHT_SQUARE_BRACKET* node) 
		{
		}

		virtual void ListenExit(const DLDL_COMMENT::ast::node::START* node) 
		{
		}

		virtual void ListenExit(const DLDL_COMMENT::ast::node::END* node) 
		{
		}

		virtual void ListenExit(const DLDL_COMMENT::ast::node::TEXT* node) 
		{
		}

		virtual void ListenExit(const DLDL_COMMENT::ast::node::VARNAME* node) 
		{
		}

		virtual void ListenExit(const DLDL_COMMENT::ast::node::ESCAPE_CHARS* node) 
		{
		}


		
		virtual void ListenEntry(const DLDL_COMMENT::ast::node::program* node) 
		{
		}

		virtual void ListenEntry(const DLDL_COMMENT::ast::node::deamerreserved_star__stmt__* node) 
		{
		}

		virtual void ListenEntry(const DLDL_COMMENT::ast::node::stmt* node) 
		{
		}

		virtual void ListenEntry(const DLDL_COMMENT::ast::node::comment_value_declaration* node) 
		{
		}

		virtual void ListenEntry(const DLDL_COMMENT::ast::node::deamerreserved_long_3* node) 
		{
		}

		virtual void ListenEntry(const DLDL_COMMENT::ast::node::deamerreserved_long_6* node) 
		{
		}

		virtual void ListenEntry(const DLDL_COMMENT::ast::node::comment_abstraction* node) 
		{
		}

		virtual void ListenEntry(const DLDL_COMMENT::ast::node::start_abstraction* node) 
		{
		}

		virtual void ListenEntry(const DLDL_COMMENT::ast::node::end_abstraction* node) 
		{
		}

		virtual void ListenEntry(const DLDL_COMMENT::ast::node::start_sequence* node) 
		{
		}

		virtual void ListenEntry(const DLDL_COMMENT::ast::node::end_sequence* node) 
		{
		}

		virtual void ListenEntry(const DLDL_COMMENT::ast::node::sequence* node) 
		{
		}

		virtual void ListenEntry(const DLDL_COMMENT::ast::node::syntactic_reference* node) 
		{
		}

		
		virtual void ListenExit(const DLDL_COMMENT::ast::node::program* node) 
		{
		}

		virtual void ListenExit(const DLDL_COMMENT::ast::node::deamerreserved_star__stmt__* node) 
		{
		}

		virtual void ListenExit(const DLDL_COMMENT::ast::node::stmt* node) 
		{
		}

		virtual void ListenExit(const DLDL_COMMENT::ast::node::comment_value_declaration* node) 
		{
		}

		virtual void ListenExit(const DLDL_COMMENT::ast::node::deamerreserved_long_3* node) 
		{
		}

		virtual void ListenExit(const DLDL_COMMENT::ast::node::deamerreserved_long_6* node) 
		{
		}

		virtual void ListenExit(const DLDL_COMMENT::ast::node::comment_abstraction* node) 
		{
		}

		virtual void ListenExit(const DLDL_COMMENT::ast::node::start_abstraction* node) 
		{
		}

		virtual void ListenExit(const DLDL_COMMENT::ast::node::end_abstraction* node) 
		{
		}

		virtual void ListenExit(const DLDL_COMMENT::ast::node::start_sequence* node) 
		{
		}

		virtual void ListenExit(const DLDL_COMMENT::ast::node::end_sequence* node) 
		{
		}

		virtual void ListenExit(const DLDL_COMMENT::ast::node::sequence* node) 
		{
		}

		virtual void ListenExit(const DLDL_COMMENT::ast::node::syntactic_reference* node) 
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

#endif // DLDL_COMMENT_AST_LISTENER_ENTEREXITLISTENER_H