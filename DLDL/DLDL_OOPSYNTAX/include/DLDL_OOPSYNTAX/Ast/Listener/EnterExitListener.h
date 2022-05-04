#ifndef DLDL_OOPSYNTAX_AST_LISTENER_ENTEREXITLISTENER_H
#define DLDL_OOPSYNTAX_AST_LISTENER_ENTEREXITLISTENER_H

#include "DLDL_OOPSYNTAX/Ast/Node/DLDL_OOPSYNTAX.h"
#include "DLDL_OOPSYNTAX/Ast/Enum/Type.h"

#include "DLDL_OOPSYNTAX/Ast/Node/ARROW.h"
#include "DLDL_OOPSYNTAX/Ast/Node/LEFT_BRACKET.h"
#include "DLDL_OOPSYNTAX/Ast/Node/RIGHT_BRACKET.h"
#include "DLDL_OOPSYNTAX/Ast/Node/DOT.h"
#include "DLDL_OOPSYNTAX/Ast/Node/EQ.h"
#include "DLDL_OOPSYNTAX/Ast/Node/STAR.h"
#include "DLDL_OOPSYNTAX/Ast/Node/VARNAME.h"
#include "DLDL_OOPSYNTAX/Ast/Node/NUMBER.h"
#include "DLDL_OOPSYNTAX/Ast/Node/COMMENT.h"
#include "DLDL_OOPSYNTAX/Ast/Node/ESCAPE_CHAR.h"


#include "DLDL_OOPSYNTAX/Ast/Node/program.h"
#include "DLDL_OOPSYNTAX/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_OOPSYNTAX/Ast/Node/stmt.h"
#include "DLDL_OOPSYNTAX/Ast/Node/nonterminal_conversion.h"
#include "DLDL_OOPSYNTAX/Ast/Node/deamerreserved_star__production_rule_conversion__.h"
#include "DLDL_OOPSYNTAX/Ast/Node/production_rule_conversion.h"
#include "DLDL_OOPSYNTAX/Ast/Node/numbered_pr_convert.h"
#include "DLDL_OOPSYNTAX/Ast/Node/deamerreserved_star__property_assignment__.h"
#include "DLDL_OOPSYNTAX/Ast/Node/property_assignment.h"
#include "DLDL_OOPSYNTAX/Ast/Node/direct_property_assignment.h"
#include "DLDL_OOPSYNTAX/Ast/Node/direct_any_property_assignment.h"
#include "DLDL_OOPSYNTAX/Ast/Node/embedded_assignment.h"
#include "DLDL_OOPSYNTAX/Ast/Node/nonterminal_name.h"
#include "DLDL_OOPSYNTAX/Ast/Node/oop_type.h"
#include "DLDL_OOPSYNTAX/Ast/Node/property.h"
#include "DLDL_OOPSYNTAX/Ast/Node/terminal_name.h"

#include <Deamer/External/Cpp/Ast/Listener.h>
#include <Deamer/Algorithm/Tree/DFS.h>

namespace DLDL_OOPSYNTAX { namespace ast { namespace listener { 

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
			const auto enumeratedValue = static_cast<DLDL_OOPSYNTAX::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case DLDL_OOPSYNTAX::ast::Type::ARROW:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_OOPSYNTAX::ast::node::ARROW*>(node));
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::LEFT_BRACKET:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET*>(node));
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::RIGHT_BRACKET:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET*>(node));
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::DOT:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_OOPSYNTAX::ast::node::DOT*>(node));
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::EQ:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_OOPSYNTAX::ast::node::EQ*>(node));
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::STAR:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_OOPSYNTAX::ast::node::STAR*>(node));
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::VARNAME:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_OOPSYNTAX::ast::node::VARNAME*>(node));
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::NUMBER:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_OOPSYNTAX::ast::node::NUMBER*>(node));
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::COMMENT:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_OOPSYNTAX::ast::node::COMMENT*>(node));
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::ESCAPE_CHAR:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_OOPSYNTAX::ast::node::ESCAPE_CHAR*>(node));
				break;
			}


			// Nonterminal cases
			
			case DLDL_OOPSYNTAX::ast::Type::program:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_OOPSYNTAX::ast::node::program*>(node));
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::deamerreserved_star__stmt__:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__*>(node));
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::stmt:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_OOPSYNTAX::ast::node::stmt*>(node));
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::nonterminal_conversion:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_OOPSYNTAX::ast::node::nonterminal_conversion*>(node));
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::deamerreserved_star__production_rule_conversion__:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_OOPSYNTAX::ast::node::deamerreserved_star__production_rule_conversion__*>(node));
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::production_rule_conversion:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_OOPSYNTAX::ast::node::production_rule_conversion*>(node));
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::numbered_pr_convert:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_OOPSYNTAX::ast::node::numbered_pr_convert*>(node));
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::deamerreserved_star__property_assignment__:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_OOPSYNTAX::ast::node::deamerreserved_star__property_assignment__*>(node));
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::property_assignment:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_OOPSYNTAX::ast::node::property_assignment*>(node));
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::direct_property_assignment:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_OOPSYNTAX::ast::node::direct_property_assignment*>(node));
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::direct_any_property_assignment:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment*>(node));
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::embedded_assignment:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_OOPSYNTAX::ast::node::embedded_assignment*>(node));
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::nonterminal_name:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_OOPSYNTAX::ast::node::nonterminal_name*>(node));
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::oop_type:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_OOPSYNTAX::ast::node::oop_type*>(node));
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::property:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_OOPSYNTAX::ast::node::property*>(node));
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::terminal_name:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_OOPSYNTAX::ast::node::terminal_name*>(node));
				break;
			}

			}
		}

		void DispatchExit(const ::deamer::external::cpp::ast::Node* node) 
		{
			const auto enumeratedValue = static_cast<DLDL_OOPSYNTAX::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case DLDL_OOPSYNTAX::ast::Type::ARROW:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_OOPSYNTAX::ast::node::ARROW*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::LEFT_BRACKET:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::RIGHT_BRACKET:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::DOT:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_OOPSYNTAX::ast::node::DOT*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::EQ:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_OOPSYNTAX::ast::node::EQ*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::STAR:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_OOPSYNTAX::ast::node::STAR*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::VARNAME:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_OOPSYNTAX::ast::node::VARNAME*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::NUMBER:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_OOPSYNTAX::ast::node::NUMBER*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::COMMENT:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_OOPSYNTAX::ast::node::COMMENT*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::ESCAPE_CHAR:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_OOPSYNTAX::ast::node::ESCAPE_CHAR*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}


			// Nonterminal cases
			
			case DLDL_OOPSYNTAX::ast::Type::program:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_OOPSYNTAX::ast::node::program*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::deamerreserved_star__stmt__:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::stmt:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_OOPSYNTAX::ast::node::stmt*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::nonterminal_conversion:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_OOPSYNTAX::ast::node::nonterminal_conversion*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::deamerreserved_star__production_rule_conversion__:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_OOPSYNTAX::ast::node::deamerreserved_star__production_rule_conversion__*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::production_rule_conversion:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_OOPSYNTAX::ast::node::production_rule_conversion*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::numbered_pr_convert:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_OOPSYNTAX::ast::node::numbered_pr_convert*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::deamerreserved_star__property_assignment__:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_OOPSYNTAX::ast::node::deamerreserved_star__property_assignment__*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::property_assignment:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_OOPSYNTAX::ast::node::property_assignment*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::direct_property_assignment:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_OOPSYNTAX::ast::node::direct_property_assignment*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::direct_any_property_assignment:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::embedded_assignment:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_OOPSYNTAX::ast::node::embedded_assignment*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::nonterminal_name:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_OOPSYNTAX::ast::node::nonterminal_name*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::oop_type:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_OOPSYNTAX::ast::node::oop_type*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::property:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_OOPSYNTAX::ast::node::property*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_OOPSYNTAX::ast::Type::terminal_name:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_OOPSYNTAX::ast::node::terminal_name*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			}
		}

		
		virtual void ListenEntry(const DLDL_OOPSYNTAX::ast::node::ARROW* node) 
		{
		}

		virtual void ListenEntry(const DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET* node) 
		{
		}

		virtual void ListenEntry(const DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET* node) 
		{
		}

		virtual void ListenEntry(const DLDL_OOPSYNTAX::ast::node::DOT* node) 
		{
		}

		virtual void ListenEntry(const DLDL_OOPSYNTAX::ast::node::EQ* node) 
		{
		}

		virtual void ListenEntry(const DLDL_OOPSYNTAX::ast::node::STAR* node) 
		{
		}

		virtual void ListenEntry(const DLDL_OOPSYNTAX::ast::node::VARNAME* node) 
		{
		}

		virtual void ListenEntry(const DLDL_OOPSYNTAX::ast::node::NUMBER* node) 
		{
		}

		virtual void ListenEntry(const DLDL_OOPSYNTAX::ast::node::COMMENT* node) 
		{
		}

		virtual void ListenEntry(const DLDL_OOPSYNTAX::ast::node::ESCAPE_CHAR* node) 
		{
		}

		
		virtual void ListenExit(const DLDL_OOPSYNTAX::ast::node::ARROW* node) 
		{
		}

		virtual void ListenExit(const DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET* node) 
		{
		}

		virtual void ListenExit(const DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET* node) 
		{
		}

		virtual void ListenExit(const DLDL_OOPSYNTAX::ast::node::DOT* node) 
		{
		}

		virtual void ListenExit(const DLDL_OOPSYNTAX::ast::node::EQ* node) 
		{
		}

		virtual void ListenExit(const DLDL_OOPSYNTAX::ast::node::STAR* node) 
		{
		}

		virtual void ListenExit(const DLDL_OOPSYNTAX::ast::node::VARNAME* node) 
		{
		}

		virtual void ListenExit(const DLDL_OOPSYNTAX::ast::node::NUMBER* node) 
		{
		}

		virtual void ListenExit(const DLDL_OOPSYNTAX::ast::node::COMMENT* node) 
		{
		}

		virtual void ListenExit(const DLDL_OOPSYNTAX::ast::node::ESCAPE_CHAR* node) 
		{
		}


		
		virtual void ListenEntry(const DLDL_OOPSYNTAX::ast::node::program* node) 
		{
		}

		virtual void ListenEntry(const DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__* node) 
		{
		}

		virtual void ListenEntry(const DLDL_OOPSYNTAX::ast::node::stmt* node) 
		{
		}

		virtual void ListenEntry(const DLDL_OOPSYNTAX::ast::node::nonterminal_conversion* node) 
		{
		}

		virtual void ListenEntry(const DLDL_OOPSYNTAX::ast::node::deamerreserved_star__production_rule_conversion__* node) 
		{
		}

		virtual void ListenEntry(const DLDL_OOPSYNTAX::ast::node::production_rule_conversion* node) 
		{
		}

		virtual void ListenEntry(const DLDL_OOPSYNTAX::ast::node::numbered_pr_convert* node) 
		{
		}

		virtual void ListenEntry(const DLDL_OOPSYNTAX::ast::node::deamerreserved_star__property_assignment__* node) 
		{
		}

		virtual void ListenEntry(const DLDL_OOPSYNTAX::ast::node::property_assignment* node) 
		{
		}

		virtual void ListenEntry(const DLDL_OOPSYNTAX::ast::node::direct_property_assignment* node) 
		{
		}

		virtual void ListenEntry(const DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment* node) 
		{
		}

		virtual void ListenEntry(const DLDL_OOPSYNTAX::ast::node::embedded_assignment* node) 
		{
		}

		virtual void ListenEntry(const DLDL_OOPSYNTAX::ast::node::nonterminal_name* node) 
		{
		}

		virtual void ListenEntry(const DLDL_OOPSYNTAX::ast::node::oop_type* node) 
		{
		}

		virtual void ListenEntry(const DLDL_OOPSYNTAX::ast::node::property* node) 
		{
		}

		virtual void ListenEntry(const DLDL_OOPSYNTAX::ast::node::terminal_name* node) 
		{
		}

		
		virtual void ListenExit(const DLDL_OOPSYNTAX::ast::node::program* node) 
		{
		}

		virtual void ListenExit(const DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__* node) 
		{
		}

		virtual void ListenExit(const DLDL_OOPSYNTAX::ast::node::stmt* node) 
		{
		}

		virtual void ListenExit(const DLDL_OOPSYNTAX::ast::node::nonterminal_conversion* node) 
		{
		}

		virtual void ListenExit(const DLDL_OOPSYNTAX::ast::node::deamerreserved_star__production_rule_conversion__* node) 
		{
		}

		virtual void ListenExit(const DLDL_OOPSYNTAX::ast::node::production_rule_conversion* node) 
		{
		}

		virtual void ListenExit(const DLDL_OOPSYNTAX::ast::node::numbered_pr_convert* node) 
		{
		}

		virtual void ListenExit(const DLDL_OOPSYNTAX::ast::node::deamerreserved_star__property_assignment__* node) 
		{
		}

		virtual void ListenExit(const DLDL_OOPSYNTAX::ast::node::property_assignment* node) 
		{
		}

		virtual void ListenExit(const DLDL_OOPSYNTAX::ast::node::direct_property_assignment* node) 
		{
		}

		virtual void ListenExit(const DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment* node) 
		{
		}

		virtual void ListenExit(const DLDL_OOPSYNTAX::ast::node::embedded_assignment* node) 
		{
		}

		virtual void ListenExit(const DLDL_OOPSYNTAX::ast::node::nonterminal_name* node) 
		{
		}

		virtual void ListenExit(const DLDL_OOPSYNTAX::ast::node::oop_type* node) 
		{
		}

		virtual void ListenExit(const DLDL_OOPSYNTAX::ast::node::property* node) 
		{
		}

		virtual void ListenExit(const DLDL_OOPSYNTAX::ast::node::terminal_name* node) 
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

#endif // DLDL_OOPSYNTAX_AST_LISTENER_ENTEREXITLISTENER_H