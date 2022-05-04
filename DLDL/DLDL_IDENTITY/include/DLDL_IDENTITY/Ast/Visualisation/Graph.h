#ifndef DLDL_IDENTITY_AST_VISUALISATION_GRAPH_H
#define DLDL_IDENTITY_AST_VISUALISATION_GRAPH_H

#include "DLDL_IDENTITY/Ast/Listener/EnterExitListener.h"

namespace DLDL_IDENTITY { namespace ast { namespace listener { namespace deamer { namespace visualisation {

	class Graph : public EnterExitListener
	{
	private:
		std::string output;

		void Init()
		{
			output += "digraph DLDL_IDENTITY_AST {\n";
		}

		void End()
		{
			output += "}\n";
		}

		void AddConnection(const  ::deamer::external::cpp::ast::Node* source, const  ::deamer::external::cpp::ast::Node* target)
		{
			output += "\t" + std::to_string(::std::size_t(source)) + " -> " + std::to_string(::std::size_t(target)) + ";\n";
		}

		
		void ListenEntry(const ::DLDL_IDENTITY::ast::node::program* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"program\"];\n";
		}

		void ListenEntry(const ::DLDL_IDENTITY::ast::node::stmts* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"stmts\"];\n";
		}

		void ListenEntry(const ::DLDL_IDENTITY::ast::node::stmt* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"stmt\"];\n";
		}

		void ListenEntry(const ::DLDL_IDENTITY::ast::node::name_declaration* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"name_declaration\"];\n";
		}

		void ListenEntry(const ::DLDL_IDENTITY::ast::node::NAME* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"NAME\"];\n";
		}

		void ListenEntry(const ::DLDL_IDENTITY::ast::node::VALUE* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"VALUE\"];\n";
		}

		void ListenEntry(const ::DLDL_IDENTITY::ast::node::SYMBOLS* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"SYMBOLS\"];\n";
		}

		void ListenEntry(const ::DLDL_IDENTITY::ast::node::ESCAPE_CHARS* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"ESCAPE_CHARS\"];\n";
		}

		
		void ListenExit(const ::DLDL_IDENTITY::ast::node::program* node) override
		{
		}

		void ListenExit(const ::DLDL_IDENTITY::ast::node::stmts* node) override
		{
		}

		void ListenExit(const ::DLDL_IDENTITY::ast::node::stmt* node) override
		{
		}

		void ListenExit(const ::DLDL_IDENTITY::ast::node::name_declaration* node) override
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

#endif // DLDL_IDENTITY_AST_VISUALISATION_GRAPH_H