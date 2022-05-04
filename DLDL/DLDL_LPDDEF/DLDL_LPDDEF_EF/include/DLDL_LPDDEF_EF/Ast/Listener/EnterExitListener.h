#ifndef DLDL_LPDDEF_EF_AST_LISTENER_ENTEREXITLISTENER_H
#define DLDL_LPDDEF_EF_AST_LISTENER_ENTEREXITLISTENER_H

#include "DLDL_LPDDEF_EF/Ast/Node/DLDL_LPDDEF_EF.h"
#include "DLDL_LPDDEF_EF/Ast/Enum/Type.h"

#include "DLDL_LPDDEF_EF/Ast/Node/COMMENT.h"
#include "DLDL_LPDDEF_EF/Ast/Node/VARNAME.h"
#include "DLDL_LPDDEF_EF/Ast/Node/NUMBER.h"
#include "DLDL_LPDDEF_EF/Ast/Node/COLON.h"
#include "DLDL_LPDDEF_EF/Ast/Node/SEMICOLON.h"
#include "DLDL_LPDDEF_EF/Ast/Node/ESCAPE_CHARS.h"


#include "DLDL_LPDDEF_EF/Ast/Node/program.h"
#include "DLDL_LPDDEF_EF/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_LPDDEF_EF/Ast/Node/stmt.h"
#include "DLDL_LPDDEF_EF/Ast/Node/comment_line.h"
#include "DLDL_LPDDEF_EF/Ast/Node/standard_variant.h"
#include "DLDL_LPDDEF_EF/Ast/Node/standard_variant_specific_number.h"
#include "DLDL_LPDDEF_EF/Ast/Node/value.h"
#include "DLDL_LPDDEF_EF/Ast/Node/enum_name.h"

#include <Deamer/External/Cpp/Ast/Listener.h>
#include <Deamer/Algorithm/Tree/DFS.h>

namespace DLDL_LPDDEF_EF { namespace ast { namespace listener { 

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
			const auto enumeratedValue = static_cast<DLDL_LPDDEF_EF::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case DLDL_LPDDEF_EF::ast::Type::COMMENT:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_EF::ast::node::COMMENT*>(node));
				break;
			}

			case DLDL_LPDDEF_EF::ast::Type::VARNAME:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_EF::ast::node::VARNAME*>(node));
				break;
			}

			case DLDL_LPDDEF_EF::ast::Type::NUMBER:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_EF::ast::node::NUMBER*>(node));
				break;
			}

			case DLDL_LPDDEF_EF::ast::Type::COLON:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_EF::ast::node::COLON*>(node));
				break;
			}

			case DLDL_LPDDEF_EF::ast::Type::SEMICOLON:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_EF::ast::node::SEMICOLON*>(node));
				break;
			}

			case DLDL_LPDDEF_EF::ast::Type::ESCAPE_CHARS:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_EF::ast::node::ESCAPE_CHARS*>(node));
				break;
			}


			// Nonterminal cases
			
			case DLDL_LPDDEF_EF::ast::Type::program:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_EF::ast::node::program*>(node));
				break;
			}

			case DLDL_LPDDEF_EF::ast::Type::deamerreserved_star__stmt__:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__*>(node));
				break;
			}

			case DLDL_LPDDEF_EF::ast::Type::stmt:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_EF::ast::node::stmt*>(node));
				break;
			}

			case DLDL_LPDDEF_EF::ast::Type::comment_line:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_EF::ast::node::comment_line*>(node));
				break;
			}

			case DLDL_LPDDEF_EF::ast::Type::standard_variant:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_EF::ast::node::standard_variant*>(node));
				break;
			}

			case DLDL_LPDDEF_EF::ast::Type::standard_variant_specific_number:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_EF::ast::node::standard_variant_specific_number*>(node));
				break;
			}

			case DLDL_LPDDEF_EF::ast::Type::value:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_EF::ast::node::value*>(node));
				break;
			}

			case DLDL_LPDDEF_EF::ast::Type::enum_name:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_EF::ast::node::enum_name*>(node));
				break;
			}

			}
		}

		void DispatchExit(const ::deamer::external::cpp::ast::Node* node) 
		{
			const auto enumeratedValue = static_cast<DLDL_LPDDEF_EF::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case DLDL_LPDDEF_EF::ast::Type::COMMENT:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDDEF_EF::ast::node::COMMENT*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_EF::ast::Type::VARNAME:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDDEF_EF::ast::node::VARNAME*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_EF::ast::Type::NUMBER:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDDEF_EF::ast::node::NUMBER*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_EF::ast::Type::COLON:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDDEF_EF::ast::node::COLON*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_EF::ast::Type::SEMICOLON:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDDEF_EF::ast::node::SEMICOLON*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_EF::ast::Type::ESCAPE_CHARS:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDDEF_EF::ast::node::ESCAPE_CHARS*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}


			// Nonterminal cases
			
			case DLDL_LPDDEF_EF::ast::Type::program:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDDEF_EF::ast::node::program*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_EF::ast::Type::deamerreserved_star__stmt__:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_EF::ast::Type::stmt:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDDEF_EF::ast::node::stmt*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_EF::ast::Type::comment_line:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDDEF_EF::ast::node::comment_line*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_EF::ast::Type::standard_variant:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDDEF_EF::ast::node::standard_variant*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_EF::ast::Type::standard_variant_specific_number:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDDEF_EF::ast::node::standard_variant_specific_number*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_EF::ast::Type::value:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDDEF_EF::ast::node::value*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_EF::ast::Type::enum_name:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDDEF_EF::ast::node::enum_name*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			}
		}

		
		virtual void ListenEntry(const DLDL_LPDDEF_EF::ast::node::COMMENT* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_EF::ast::node::VARNAME* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_EF::ast::node::NUMBER* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_EF::ast::node::COLON* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_EF::ast::node::SEMICOLON* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_EF::ast::node::ESCAPE_CHARS* node) 
		{
		}

		
		virtual void ListenExit(const DLDL_LPDDEF_EF::ast::node::COMMENT* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_EF::ast::node::VARNAME* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_EF::ast::node::NUMBER* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_EF::ast::node::COLON* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_EF::ast::node::SEMICOLON* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_EF::ast::node::ESCAPE_CHARS* node) 
		{
		}


		
		virtual void ListenEntry(const DLDL_LPDDEF_EF::ast::node::program* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_EF::ast::node::stmt* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_EF::ast::node::comment_line* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_EF::ast::node::standard_variant* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_EF::ast::node::standard_variant_specific_number* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_EF::ast::node::value* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_EF::ast::node::enum_name* node) 
		{
		}

		
		virtual void ListenExit(const DLDL_LPDDEF_EF::ast::node::program* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_EF::ast::node::stmt* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_EF::ast::node::comment_line* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_EF::ast::node::standard_variant* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_EF::ast::node::standard_variant_specific_number* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_EF::ast::node::value* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_EF::ast::node::enum_name* node) 
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

#endif // DLDL_LPDDEF_EF_AST_LISTENER_ENTEREXITLISTENER_H