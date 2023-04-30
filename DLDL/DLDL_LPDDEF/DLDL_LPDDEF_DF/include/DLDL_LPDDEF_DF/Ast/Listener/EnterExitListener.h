#ifndef DLDL_LPDDEF_DF_AST_LISTENER_ENTEREXITLISTENER_H
#define DLDL_LPDDEF_DF_AST_LISTENER_ENTEREXITLISTENER_H

#include "DLDL_LPDDEF_DF/Ast/Node/DLDL_LPDDEF_DF.h"
#include "DLDL_LPDDEF_DF/Ast/Enum/Type.h"

#include "DLDL_LPDDEF_DF/Ast/Node/LAB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/RAB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/LSB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/RSB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/EQ.h"
#include "DLDL_LPDDEF_DF/Ast/Node/COLON.h"
#include "DLDL_LPDDEF_DF/Ast/Node/LB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/RB.h"
#include "DLDL_LPDDEF_DF/Ast/Node/COMMA.h"
#include "DLDL_LPDDEF_DF/Ast/Node/OPTIONAL.h"
#include "DLDL_LPDDEF_DF/Ast/Node/VECTOR.h"
#include "DLDL_LPDDEF_DF/Ast/Node/DEAMER_VARNAME.h"
#include "DLDL_LPDDEF_DF/Ast/Node/COMMENT.h"
#include "DLDL_LPDDEF_DF/Ast/Node/VARNAME.h"
#include "DLDL_LPDDEF_DF/Ast/Node/NUMBER.h"
#include "DLDL_LPDDEF_DF/Ast/Node/STRING.h"
#include "DLDL_LPDDEF_DF/Ast/Node/SEMICOLON.h"
#include "DLDL_LPDDEF_DF/Ast/Node/ESCAPE_CHARS.h"


#include "DLDL_LPDDEF_DF/Ast/Node/program.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_star__stmt__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/stmt.h"
#include "DLDL_LPDDEF_DF/Ast/Node/comment_line.h"
#include "DLDL_LPDDEF_DF/Ast/Node/vector_variant.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_optional__value_part__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/optional_variant.h"
#include "DLDL_LPDDEF_DF/Ast/Node/value_part.h"
#include "DLDL_LPDDEF_DF/Ast/Node/standard_variant.h"
#include "DLDL_LPDDEF_DF/Ast/Node/value.h"
#include "DLDL_LPDDEF_DF/Ast/Node/value_type.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_arrow__value_type__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_star__COMMA__value_type__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_long_54.h"
#include "DLDL_LPDDEF_DF/Ast/Node/var_type.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_arrow__VARNAME__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/deamerreserved_star__COLON__VARNAME__.h"
#include "DLDL_LPDDEF_DF/Ast/Node/var_name.h"

#include <Deamer/External/Cpp/Ast/Listener.h>
#include <Deamer/Algorithm/Tree/DFS.h>

namespace DLDL_LPDDEF_DF { namespace ast { namespace listener { 

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
			const auto enumeratedValue = static_cast<DLDL_LPDDEF_DF::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case DLDL_LPDDEF_DF::ast::Type::LAB:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::LAB*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::RAB:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::RAB*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::LSB:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::LSB*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::RSB:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::RSB*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::EQ:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::EQ*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::COLON:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::COLON*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::LB:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::LB*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::RB:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::RB*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::COMMA:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::COMMA*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::OPTIONAL:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::OPTIONAL*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::VECTOR:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::VECTOR*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::DEAMER_VARNAME:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::COMMENT:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::COMMENT*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::VARNAME:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::VARNAME*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::NUMBER:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::NUMBER*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::STRING:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::STRING*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::SEMICOLON:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::SEMICOLON*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::ESCAPE_CHARS:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::ESCAPE_CHARS*>(node));
				break;
			}


			// Nonterminal cases
			
			case DLDL_LPDDEF_DF::ast::Type::program:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::program*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__stmt__:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::stmt:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::stmt*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::comment_line:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::comment_line*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::vector_variant:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::vector_variant*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::deamerreserved_optional__value_part__:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::deamerreserved_optional__value_part__*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::optional_variant:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::optional_variant*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::value_part:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::value_part*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::standard_variant:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::standard_variant*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::value:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::value*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::value_type:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::value_type*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::deamerreserved_arrow__value_type__:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COMMA__value_type__:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::deamerreserved_long_54:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::deamerreserved_long_54*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::var_type:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::var_type*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::deamerreserved_arrow__VARNAME__:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COLON__VARNAME__:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__*>(node));
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::var_name:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const DLDL_LPDDEF_DF::ast::node::var_name*>(node));
				break;
			}

			}
		}

		void DispatchExit(const ::deamer::external::cpp::ast::Node* node) 
		{
			const auto enumeratedValue = static_cast<DLDL_LPDDEF_DF::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case DLDL_LPDDEF_DF::ast::Type::LAB:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::LAB*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::RAB:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::RAB*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::LSB:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::LSB*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::RSB:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::RSB*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::EQ:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::EQ*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::COLON:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::COLON*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::LB:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::LB*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::RB:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::RB*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::COMMA:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::COMMA*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::OPTIONAL:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::OPTIONAL*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::VECTOR:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::VECTOR*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::DEAMER_VARNAME:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::COMMENT:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::COMMENT*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::VARNAME:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::VARNAME*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::NUMBER:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::NUMBER*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::STRING:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::STRING*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::SEMICOLON:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::SEMICOLON*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::ESCAPE_CHARS:
			{
				// Exit terminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::ESCAPE_CHARS*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}


			// Nonterminal cases
			
			case DLDL_LPDDEF_DF::ast::Type::program:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::program*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__stmt__:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::stmt:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::stmt*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::comment_line:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::comment_line*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::vector_variant:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::vector_variant*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::deamerreserved_optional__value_part__:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::deamerreserved_optional__value_part__*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::optional_variant:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::optional_variant*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::value_part:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::value_part*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::standard_variant:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::standard_variant*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::value:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::value*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::value_type:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::value_type*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::deamerreserved_arrow__value_type__:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COMMA__value_type__:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::deamerreserved_long_54:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::deamerreserved_long_54*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::var_type:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::var_type*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::deamerreserved_arrow__VARNAME__:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::deamerreserved_star__COLON__VARNAME__:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case DLDL_LPDDEF_DF::ast::Type::var_name:
			{
				// Exit nonterminal
				ListenExit(static_cast<const DLDL_LPDDEF_DF::ast::node::var_name*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			}
		}

		
		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::LAB* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::RAB* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::LSB* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::RSB* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::EQ* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::COLON* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::LB* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::RB* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::COMMA* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::OPTIONAL* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::VECTOR* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::COMMENT* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::VARNAME* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::NUMBER* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::STRING* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::SEMICOLON* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::ESCAPE_CHARS* node) 
		{
		}

		
		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::LAB* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::RAB* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::LSB* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::RSB* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::EQ* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::COLON* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::LB* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::RB* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::COMMA* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::OPTIONAL* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::VECTOR* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::COMMENT* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::VARNAME* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::NUMBER* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::STRING* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::SEMICOLON* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::ESCAPE_CHARS* node) 
		{
		}


		
		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::program* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::stmt* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::comment_line* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::vector_variant* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::deamerreserved_optional__value_part__* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::optional_variant* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::value_part* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::standard_variant* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::value* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::value_type* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::deamerreserved_long_54* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::var_type* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__* node) 
		{
		}

		virtual void ListenEntry(const DLDL_LPDDEF_DF::ast::node::var_name* node) 
		{
		}

		
		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::program* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::stmt* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::comment_line* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::vector_variant* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::deamerreserved_optional__value_part__* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::optional_variant* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::value_part* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::standard_variant* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::value* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::value_type* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::deamerreserved_long_54* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::var_type* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__* node) 
		{
		}

		virtual void ListenExit(const DLDL_LPDDEF_DF::ast::node::var_name* node) 
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

#endif // DLDL_LPDDEF_DF_AST_LISTENER_ENTEREXITLISTENER_H