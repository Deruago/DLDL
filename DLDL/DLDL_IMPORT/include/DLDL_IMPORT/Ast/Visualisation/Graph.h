#ifndef DLDL_IMPORT_AST_VISUALISATION_GRAPH_H
#define DLDL_IMPORT_AST_VISUALISATION_GRAPH_H

#include "DLDL_IMPORT/Ast/Listener/EnterExitListener.h"

namespace DLDL_IMPORT { namespace ast { namespace listener { namespace deamer { namespace visualisation {

	class Graph : public EnterExitListener
	{
	private:
		std::string output;

		void Init()
		{
			output += "digraph DLDL_IMPORT_AST {\n";
		}

		void End()
		{
			output += "}\n";
		}

		void AddConnection(const  ::deamer::external::cpp::ast::Node* source, const  ::deamer::external::cpp::ast::Node* target)
		{
			output += "\t" + std::to_string(::std::size_t(source)) + " -> " + std::to_string(::std::size_t(target)) + ";\n";
		}

		
		void ListenEntry(const ::DLDL_IMPORT::ast::node::program* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"program\"];\n";
		}

		void ListenEntry(const ::DLDL_IMPORT::ast::node::deamerreserved_star__stmt__* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_star__stmt__\"];\n";
		}

		void ListenEntry(const ::DLDL_IMPORT::ast::node::stmt* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"stmt\"];\n";
		}

		void ListenEntry(const ::DLDL_IMPORT::ast::node::import_declaration* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"import_declaration\"];\n";
		}

		void ListenEntry(const ::DLDL_IMPORT::ast::node::deamerreserved_arrow__import_context__* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_arrow__import_context__\"];\n";
		}

		void ListenEntry(const ::DLDL_IMPORT::ast::node::deamerreserved_long_40* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_long_40\"];\n";
		}

		void ListenEntry(const ::DLDL_IMPORT::ast::node::deamerreserved_long_43* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_long_43\"];\n";
		}

		void ListenEntry(const ::DLDL_IMPORT::ast::node::specialization* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"specialization\"];\n";
		}

		void ListenEntry(const ::DLDL_IMPORT::ast::node::import_abstraction* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"import_abstraction\"];\n";
		}

		void ListenEntry(const ::DLDL_IMPORT::ast::node::value* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"value\"];\n";
		}

		void ListenEntry(const ::DLDL_IMPORT::ast::node::deamerreserved_optional__VARNAME__* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_optional__VARNAME__\"];\n";
		}

		void ListenEntry(const ::DLDL_IMPORT::ast::node::abstraction* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"abstraction\"];\n";
		}

		void ListenEntry(const ::DLDL_IMPORT::ast::node::import_context* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"import_context\"];\n";
		}

		void ListenEntry(const ::DLDL_IMPORT::ast::node::import_rule_name* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"import_rule_name\"];\n";
		}

		void ListenEntry(const ::DLDL_IMPORT::ast::node::SINGLE_COMMENT* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"SINGLE_COMMENT\"];\n";
		}

		void ListenEntry(const ::DLDL_IMPORT::ast::node::MULTI_COMMENT* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"MULTI_COMMENT\"];\n";
		}

		void ListenEntry(const ::DLDL_IMPORT::ast::node::LEFT_PARANTHESIS* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"LEFT_PARANTHESIS\"];\n";
		}

		void ListenEntry(const ::DLDL_IMPORT::ast::node::RIGHT_PARANTHESIS* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"RIGHT_PARANTHESIS\"];\n";
		}

		void ListenEntry(const ::DLDL_IMPORT::ast::node::LEFT_SQUARE_BRACKET* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"LEFT_SQUARE_BRACKET\"];\n";
		}

		void ListenEntry(const ::DLDL_IMPORT::ast::node::RIGHT_SQUARE_BRACKET* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"RIGHT_SQUARE_BRACKET\"];\n";
		}

		void ListenEntry(const ::DLDL_IMPORT::ast::node::COLON* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"COLON\"];\n";
		}

		void ListenEntry(const ::DLDL_IMPORT::ast::node::DOT* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"DOT\"];\n";
		}

		void ListenEntry(const ::DLDL_IMPORT::ast::node::IMPORT_FILE* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"IMPORT_FILE\"];\n";
		}

		void ListenEntry(const ::DLDL_IMPORT::ast::node::IMPORT_MODULE* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"IMPORT_MODULE\"];\n";
		}

		void ListenEntry(const ::DLDL_IMPORT::ast::node::IMPORT* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"IMPORT\"];\n";
		}

		void ListenEntry(const ::DLDL_IMPORT::ast::node::TEXT* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"TEXT\"];\n";
		}

		void ListenEntry(const ::DLDL_IMPORT::ast::node::VARNAME* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"VARNAME\"];\n";
		}

		void ListenEntry(const ::DLDL_IMPORT::ast::node::ESCAPE_CHARS* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"ESCAPE_CHARS\"];\n";
		}

		
		void ListenExit(const ::DLDL_IMPORT::ast::node::program* node) override
		{
		}

		void ListenExit(const ::DLDL_IMPORT::ast::node::deamerreserved_star__stmt__* node) override
		{
		}

		void ListenExit(const ::DLDL_IMPORT::ast::node::stmt* node) override
		{
		}

		void ListenExit(const ::DLDL_IMPORT::ast::node::import_declaration* node) override
		{
		}

		void ListenExit(const ::DLDL_IMPORT::ast::node::deamerreserved_arrow__import_context__* node) override
		{
		}

		void ListenExit(const ::DLDL_IMPORT::ast::node::deamerreserved_long_40* node) override
		{
		}

		void ListenExit(const ::DLDL_IMPORT::ast::node::deamerreserved_long_43* node) override
		{
		}

		void ListenExit(const ::DLDL_IMPORT::ast::node::specialization* node) override
		{
		}

		void ListenExit(const ::DLDL_IMPORT::ast::node::import_abstraction* node) override
		{
		}

		void ListenExit(const ::DLDL_IMPORT::ast::node::value* node) override
		{
		}

		void ListenExit(const ::DLDL_IMPORT::ast::node::deamerreserved_optional__VARNAME__* node) override
		{
		}

		void ListenExit(const ::DLDL_IMPORT::ast::node::abstraction* node) override
		{
		}

		void ListenExit(const ::DLDL_IMPORT::ast::node::import_context* node) override
		{
		}

		void ListenExit(const ::DLDL_IMPORT::ast::node::import_rule_name* node) override
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

#endif // DLDL_IMPORT_AST_VISUALISATION_GRAPH_H