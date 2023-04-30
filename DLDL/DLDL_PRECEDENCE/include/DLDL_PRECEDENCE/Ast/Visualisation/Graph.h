#ifndef DLDL_PRECEDENCE_AST_VISUALISATION_GRAPH_H
#define DLDL_PRECEDENCE_AST_VISUALISATION_GRAPH_H

#include "DLDL_PRECEDENCE/Ast/Listener/EnterExitListener.h"

namespace DLDL_PRECEDENCE { namespace ast { namespace listener { namespace deamer { namespace visualisation {

	class Graph : public EnterExitListener
	{
	private:
		std::string output;

		void Init()
		{
			output += "digraph DLDL_PRECEDENCE_AST {\n";
		}

		void End()
		{
			output += "}\n";
		}

		void AddConnection(const  ::deamer::external::cpp::ast::Node* source, const  ::deamer::external::cpp::ast::Node* target)
		{
			output += "\t" + std::to_string(::std::size_t(source)) + " -> " + std::to_string(::std::size_t(target)) + ";\n";
		}

		
		void ListenEntry(const ::DLDL_PRECEDENCE::ast::node::program* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"program\"];\n";
		}

		void ListenEntry(const ::DLDL_PRECEDENCE::ast::node::stmts* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"stmts\"];\n";
		}

		void ListenEntry(const ::DLDL_PRECEDENCE::ast::node::stmt* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"stmt\"];\n";
		}

		void ListenEntry(const ::DLDL_PRECEDENCE::ast::node::localized_precedence* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"localized_precedence\"];\n";
		}

		void ListenEntry(const ::DLDL_PRECEDENCE::ast::node::specific_precedence* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"specific_precedence\"];\n";
		}

		void ListenEntry(const ::DLDL_PRECEDENCE::ast::node::terminal_one_or_more* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"terminal_one_or_more\"];\n";
		}

		void ListenEntry(const ::DLDL_PRECEDENCE::ast::node::PRECEDENCE* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"PRECEDENCE\"];\n";
		}

		void ListenEntry(const ::DLDL_PRECEDENCE::ast::node::NUMBER* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"NUMBER\"];\n";
		}

		void ListenEntry(const ::DLDL_PRECEDENCE::ast::node::TERMINAL* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"TERMINAL\"];\n";
		}

		void ListenEntry(const ::DLDL_PRECEDENCE::ast::node::SYMBOLS* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"SYMBOLS\"];\n";
		}

		void ListenEntry(const ::DLDL_PRECEDENCE::ast::node::ESCAPE_CHARS* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"ESCAPE_CHARS\"];\n";
		}

		
		void ListenExit(const ::DLDL_PRECEDENCE::ast::node::program* node) override
		{
		}

		void ListenExit(const ::DLDL_PRECEDENCE::ast::node::stmts* node) override
		{
		}

		void ListenExit(const ::DLDL_PRECEDENCE::ast::node::stmt* node) override
		{
		}

		void ListenExit(const ::DLDL_PRECEDENCE::ast::node::localized_precedence* node) override
		{
		}

		void ListenExit(const ::DLDL_PRECEDENCE::ast::node::specific_precedence* node) override
		{
		}

		void ListenExit(const ::DLDL_PRECEDENCE::ast::node::terminal_one_or_more* node) override
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

#endif // DLDL_PRECEDENCE_AST_VISUALISATION_GRAPH_H