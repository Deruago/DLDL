#ifndef DLDL_GENERATION_AST_VISUALISATION_GRAPH_H
#define DLDL_GENERATION_AST_VISUALISATION_GRAPH_H

#include "DLDL_GENERATION/Ast/Listener/EnterExitListener.h"

namespace DLDL_GENERATION { namespace ast { namespace listener { namespace deamer { namespace visualisation {

	class Graph : public EnterExitListener
	{
	private:
		std::string output;

		void Init()
		{
			output += "digraph DLDL_GENERATION_AST {\n";
		}

		void End()
		{
			output += "}\n";
		}

		void AddConnection(const  ::deamer::external::cpp::ast::Node* source, const  ::deamer::external::cpp::ast::Node* target)
		{
			output += "\t" + std::to_string(::std::size_t(source)) + " -> " + std::to_string(::std::size_t(target)) + ";\n";
		}

		
		void ListenEntry(const ::DLDL_GENERATION::ast::node::program* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"program\"];\n";
		}

		void ListenEntry(const ::DLDL_GENERATION::ast::node::stmts* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"stmts\"];\n";
		}

		void ListenEntry(const ::DLDL_GENERATION::ast::node::stmt* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"stmt\"];\n";
		}

		void ListenEntry(const ::DLDL_GENERATION::ast::node::generate_declaration* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"generate_declaration\"];\n";
		}

		void ListenEntry(const ::DLDL_GENERATION::ast::node::integrate_declaration* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"integrate_declaration\"];\n";
		}

		void ListenEntry(const ::DLDL_GENERATION::ast::node::argument_declaration* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"argument_declaration\"];\n";
		}

		void ListenEntry(const ::DLDL_GENERATION::ast::node::type* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"type\"];\n";
		}

		void ListenEntry(const ::DLDL_GENERATION::ast::node::tool* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"tool\"];\n";
		}

		void ListenEntry(const ::DLDL_GENERATION::ast::node::argument_data* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"argument_data\"];\n";
		}

		void ListenEntry(const ::DLDL_GENERATION::ast::node::GENERATE* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"GENERATE\"];\n";
		}

		void ListenEntry(const ::DLDL_GENERATION::ast::node::INTEGRATE* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"INTEGRATE\"];\n";
		}

		void ListenEntry(const ::DLDL_GENERATION::ast::node::ARGUMENT* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"ARGUMENT\"];\n";
		}

		void ListenEntry(const ::DLDL_GENERATION::ast::node::VALUE* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"VALUE\"];\n";
		}

		void ListenEntry(const ::DLDL_GENERATION::ast::node::SYMBOLS* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"SYMBOLS\"];\n";
		}

		void ListenEntry(const ::DLDL_GENERATION::ast::node::ESCAPE_CHARS* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"ESCAPE_CHARS\"];\n";
		}

		
		void ListenExit(const ::DLDL_GENERATION::ast::node::program* node) override
		{
		}

		void ListenExit(const ::DLDL_GENERATION::ast::node::stmts* node) override
		{
		}

		void ListenExit(const ::DLDL_GENERATION::ast::node::stmt* node) override
		{
		}

		void ListenExit(const ::DLDL_GENERATION::ast::node::generate_declaration* node) override
		{
		}

		void ListenExit(const ::DLDL_GENERATION::ast::node::integrate_declaration* node) override
		{
		}

		void ListenExit(const ::DLDL_GENERATION::ast::node::argument_declaration* node) override
		{
		}

		void ListenExit(const ::DLDL_GENERATION::ast::node::type* node) override
		{
		}

		void ListenExit(const ::DLDL_GENERATION::ast::node::tool* node) override
		{
		}

		void ListenExit(const ::DLDL_GENERATION::ast::node::argument_data* node) override
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

#endif // DLDL_GENERATION_AST_VISUALISATION_GRAPH_H