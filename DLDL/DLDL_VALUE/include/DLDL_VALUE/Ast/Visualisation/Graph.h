#ifndef DLDL_VALUE_AST_VISUALISATION_GRAPH_H
#define DLDL_VALUE_AST_VISUALISATION_GRAPH_H

#include "DLDL_VALUE/Ast/Listener/EnterExitListener.h"

namespace DLDL_VALUE { namespace ast { namespace listener { namespace deamer { namespace visualisation {

	class Graph : public EnterExitListener
	{
	private:
		std::string output;

		void Init()
		{
			output += "digraph DLDL_VALUE_AST {\n";
		}

		void End()
		{
			output += "}\n";
		}

		void AddConnection(const  ::deamer::external::cpp::ast::Node* source, const  ::deamer::external::cpp::ast::Node* target)
		{
			output += "\t" + std::to_string(::std::size_t(source)) + " -> " + std::to_string(::std::size_t(target)) + ";\n";
		}

		
		void ListenEntry(const ::DLDL_VALUE::ast::node::program* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"program\"];\n";
		}

		void ListenEntry(const ::DLDL_VALUE::ast::node::deamerreserved_star__stmt__* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_star__stmt__\"];\n";
		}

		void ListenEntry(const ::DLDL_VALUE::ast::node::stmt* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"stmt\"];\n";
		}

		void ListenEntry(const ::DLDL_VALUE::ast::node::value_charactersitic_declaration* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"value_charactersitic_declaration\"];\n";
		}

		void ListenEntry(const ::DLDL_VALUE::ast::node::deamerreserved_long_82* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_long_82\"];\n";
		}

		void ListenEntry(const ::DLDL_VALUE::ast::node::deamerreserved_long_85* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_long_85\"];\n";
		}

		void ListenEntry(const ::DLDL_VALUE::ast::node::deamerreserved_long_88* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_long_88\"];\n";
		}

		void ListenEntry(const ::DLDL_VALUE::ast::node::value_declaration* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"value_declaration\"];\n";
		}

		void ListenEntry(const ::DLDL_VALUE::ast::node::deamerreserved_long_91* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_long_91\"];\n";
		}

		void ListenEntry(const ::DLDL_VALUE::ast::node::value_characteristic_abstraction* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"value_characteristic_abstraction\"];\n";
		}

		void ListenEntry(const ::DLDL_VALUE::ast::node::value_declaration_abstraction* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"value_declaration_abstraction\"];\n";
		}

		void ListenEntry(const ::DLDL_VALUE::ast::node::value_abstraction* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"value_abstraction\"];\n";
		}

		void ListenEntry(const ::DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_star__value_abstraction__\"];\n";
		}

		void ListenEntry(const ::DLDL_VALUE::ast::node::deamerreserved_long_96* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_long_96\"];\n";
		}

		void ListenEntry(const ::DLDL_VALUE::ast::node::value* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"value\"];\n";
		}

		void ListenEntry(const ::DLDL_VALUE::ast::node::syntactic_context* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"syntactic_context\"];\n";
		}

		void ListenEntry(const ::DLDL_VALUE::ast::node::abstraction_name* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"abstraction_name\"];\n";
		}

		void ListenEntry(const ::DLDL_VALUE::ast::node::value_rule_name* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"value_rule_name\"];\n";
		}

		void ListenEntry(const ::DLDL_VALUE::ast::node::SINGLE_COMMENT* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"SINGLE_COMMENT\"];\n";
		}

		void ListenEntry(const ::DLDL_VALUE::ast::node::MULTI_COMMENT* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"MULTI_COMMENT\"];\n";
		}

		void ListenEntry(const ::DLDL_VALUE::ast::node::LEFT_PARANTHESIS* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"LEFT_PARANTHESIS\"];\n";
		}

		void ListenEntry(const ::DLDL_VALUE::ast::node::RIGHT_PARANTHESIS* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"RIGHT_PARANTHESIS\"];\n";
		}

		void ListenEntry(const ::DLDL_VALUE::ast::node::LEFT_BRACKET* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"LEFT_BRACKET\"];\n";
		}

		void ListenEntry(const ::DLDL_VALUE::ast::node::RIGHT_BRACKET* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"RIGHT_BRACKET\"];\n";
		}

		void ListenEntry(const ::DLDL_VALUE::ast::node::LEFT_SQUARE_BRACKET* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"LEFT_SQUARE_BRACKET\"];\n";
		}

		void ListenEntry(const ::DLDL_VALUE::ast::node::RIGHT_SQUARE_BRACKET* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"RIGHT_SQUARE_BRACKET\"];\n";
		}

		void ListenEntry(const ::DLDL_VALUE::ast::node::DOT* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"DOT\"];\n";
		}

		void ListenEntry(const ::DLDL_VALUE::ast::node::VALUE_CHARACTERISTIC* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"VALUE_CHARACTERISTIC\"];\n";
		}

		void ListenEntry(const ::DLDL_VALUE::ast::node::VALUE_RULE* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"VALUE_RULE\"];\n";
		}

		void ListenEntry(const ::DLDL_VALUE::ast::node::NUMBER* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"NUMBER\"];\n";
		}

		void ListenEntry(const ::DLDL_VALUE::ast::node::TEXT* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"TEXT\"];\n";
		}

		void ListenEntry(const ::DLDL_VALUE::ast::node::VARNAME* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"VARNAME\"];\n";
		}

		void ListenEntry(const ::DLDL_VALUE::ast::node::ESCAPE_CHARS* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"ESCAPE_CHARS\"];\n";
		}

		
		void ListenExit(const ::DLDL_VALUE::ast::node::program* node) override
		{
		}

		void ListenExit(const ::DLDL_VALUE::ast::node::deamerreserved_star__stmt__* node) override
		{
		}

		void ListenExit(const ::DLDL_VALUE::ast::node::stmt* node) override
		{
		}

		void ListenExit(const ::DLDL_VALUE::ast::node::value_charactersitic_declaration* node) override
		{
		}

		void ListenExit(const ::DLDL_VALUE::ast::node::deamerreserved_long_82* node) override
		{
		}

		void ListenExit(const ::DLDL_VALUE::ast::node::deamerreserved_long_85* node) override
		{
		}

		void ListenExit(const ::DLDL_VALUE::ast::node::deamerreserved_long_88* node) override
		{
		}

		void ListenExit(const ::DLDL_VALUE::ast::node::value_declaration* node) override
		{
		}

		void ListenExit(const ::DLDL_VALUE::ast::node::deamerreserved_long_91* node) override
		{
		}

		void ListenExit(const ::DLDL_VALUE::ast::node::value_characteristic_abstraction* node) override
		{
		}

		void ListenExit(const ::DLDL_VALUE::ast::node::value_declaration_abstraction* node) override
		{
		}

		void ListenExit(const ::DLDL_VALUE::ast::node::value_abstraction* node) override
		{
		}

		void ListenExit(const ::DLDL_VALUE::ast::node::deamerreserved_star__value_abstraction__* node) override
		{
		}

		void ListenExit(const ::DLDL_VALUE::ast::node::deamerreserved_long_96* node) override
		{
		}

		void ListenExit(const ::DLDL_VALUE::ast::node::value* node) override
		{
		}

		void ListenExit(const ::DLDL_VALUE::ast::node::syntactic_context* node) override
		{
		}

		void ListenExit(const ::DLDL_VALUE::ast::node::abstraction_name* node) override
		{
		}

		void ListenExit(const ::DLDL_VALUE::ast::node::value_rule_name* node) override
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

#endif // DLDL_VALUE_AST_VISUALISATION_GRAPH_H