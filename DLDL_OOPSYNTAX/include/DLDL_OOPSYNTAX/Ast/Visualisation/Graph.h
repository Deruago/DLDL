#ifndef DLDL_OOPSYNTAX_AST_VISUALISATION_GRAPH_H
#define DLDL_OOPSYNTAX_AST_VISUALISATION_GRAPH_H

#include "DLDL_OOPSYNTAX/Ast/Listener/EnterExitListener.h"

namespace DLDL_OOPSYNTAX { namespace ast { namespace listener { namespace deamer { namespace visualisation {

	class Graph : public EnterExitListener
	{
	private:
		std::string output;

		void Init()
		{
			output += "digraph DLDL_OOPSYNTAX_AST {\n";
		}

		void End()
		{
			output += "}\n";
		}

		void AddConnection(const  ::deamer::external::cpp::ast::Node* source, const  ::deamer::external::cpp::ast::Node* target)
		{
			output += "\t" + std::to_string(::std::size_t(source)) + " -> " + std::to_string(::std::size_t(target)) + ";\n";
		}

		
		void ListenEntry(const ::DLDL_OOPSYNTAX::ast::node::program* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"program\"];\n";
		}

		void ListenEntry(const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_star__stmt__\"];\n";
		}

		void ListenEntry(const ::DLDL_OOPSYNTAX::ast::node::stmt* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"stmt\"];\n";
		}

		void ListenEntry(const ::DLDL_OOPSYNTAX::ast::node::nonterminal_conversion* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"nonterminal_conversion\"];\n";
		}

		void ListenEntry(const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__production_rule_conversion__* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_star__production_rule_conversion__\"];\n";
		}

		void ListenEntry(const ::DLDL_OOPSYNTAX::ast::node::production_rule_conversion* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"production_rule_conversion\"];\n";
		}

		void ListenEntry(const ::DLDL_OOPSYNTAX::ast::node::numbered_pr_convert* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"numbered_pr_convert\"];\n";
		}

		void ListenEntry(const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__property_assignment__* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_star__property_assignment__\"];\n";
		}

		void ListenEntry(const ::DLDL_OOPSYNTAX::ast::node::property_assignment* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"property_assignment\"];\n";
		}

		void ListenEntry(const ::DLDL_OOPSYNTAX::ast::node::direct_property_assignment* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"direct_property_assignment\"];\n";
		}

		void ListenEntry(const ::DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"direct_any_property_assignment\"];\n";
		}

		void ListenEntry(const ::DLDL_OOPSYNTAX::ast::node::embedded_assignment* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"embedded_assignment\"];\n";
		}

		void ListenEntry(const ::DLDL_OOPSYNTAX::ast::node::nonterminal_name* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"nonterminal_name\"];\n";
		}

		void ListenEntry(const ::DLDL_OOPSYNTAX::ast::node::oop_type* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"oop_type\"];\n";
		}

		void ListenEntry(const ::DLDL_OOPSYNTAX::ast::node::property* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"property\"];\n";
		}

		void ListenEntry(const ::DLDL_OOPSYNTAX::ast::node::terminal_name* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"terminal_name\"];\n";
		}

		void ListenEntry(const ::DLDL_OOPSYNTAX::ast::node::ARROW* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"ARROW\"];\n";
		}

		void ListenEntry(const ::DLDL_OOPSYNTAX::ast::node::LEFT_BRACKET* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"LEFT_BRACKET\"];\n";
		}

		void ListenEntry(const ::DLDL_OOPSYNTAX::ast::node::RIGHT_BRACKET* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"RIGHT_BRACKET\"];\n";
		}

		void ListenEntry(const ::DLDL_OOPSYNTAX::ast::node::DOT* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"DOT\"];\n";
		}

		void ListenEntry(const ::DLDL_OOPSYNTAX::ast::node::EQ* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"EQ\"];\n";
		}

		void ListenEntry(const ::DLDL_OOPSYNTAX::ast::node::STAR* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"STAR\"];\n";
		}

		void ListenEntry(const ::DLDL_OOPSYNTAX::ast::node::VARNAME* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"VARNAME\"];\n";
		}

		void ListenEntry(const ::DLDL_OOPSYNTAX::ast::node::NUMBER* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"NUMBER\"];\n";
		}

		void ListenEntry(const ::DLDL_OOPSYNTAX::ast::node::COMMENT* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"COMMENT\"];\n";
		}

		void ListenEntry(const ::DLDL_OOPSYNTAX::ast::node::ESCAPE_CHAR* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"ESCAPE_CHAR\"];\n";
		}

		
		void ListenExit(const ::DLDL_OOPSYNTAX::ast::node::program* node) override
		{
		}

		void ListenExit(const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__stmt__* node) override
		{
		}

		void ListenExit(const ::DLDL_OOPSYNTAX::ast::node::stmt* node) override
		{
		}

		void ListenExit(const ::DLDL_OOPSYNTAX::ast::node::nonterminal_conversion* node) override
		{
		}

		void ListenExit(const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__production_rule_conversion__* node) override
		{
		}

		void ListenExit(const ::DLDL_OOPSYNTAX::ast::node::production_rule_conversion* node) override
		{
		}

		void ListenExit(const ::DLDL_OOPSYNTAX::ast::node::numbered_pr_convert* node) override
		{
		}

		void ListenExit(const ::DLDL_OOPSYNTAX::ast::node::deamerreserved_star__property_assignment__* node) override
		{
		}

		void ListenExit(const ::DLDL_OOPSYNTAX::ast::node::property_assignment* node) override
		{
		}

		void ListenExit(const ::DLDL_OOPSYNTAX::ast::node::direct_property_assignment* node) override
		{
		}

		void ListenExit(const ::DLDL_OOPSYNTAX::ast::node::direct_any_property_assignment* node) override
		{
		}

		void ListenExit(const ::DLDL_OOPSYNTAX::ast::node::embedded_assignment* node) override
		{
		}

		void ListenExit(const ::DLDL_OOPSYNTAX::ast::node::nonterminal_name* node) override
		{
		}

		void ListenExit(const ::DLDL_OOPSYNTAX::ast::node::oop_type* node) override
		{
		}

		void ListenExit(const ::DLDL_OOPSYNTAX::ast::node::property* node) override
		{
		}

		void ListenExit(const ::DLDL_OOPSYNTAX::ast::node::terminal_name* node) override
		{
		}


	public:
		Graph()
		{
			Init();
		}


		std::string GetGraph()
		{
			End();
			return output;
		}
	};

}}}}}

#endif // DLDL_OOPSYNTAX_AST_VISUALISATION_GRAPH_H