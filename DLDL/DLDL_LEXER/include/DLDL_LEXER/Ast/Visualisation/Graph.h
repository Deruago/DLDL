#ifndef DLDL_LEXER_AST_VISUALISATION_GRAPH_H
#define DLDL_LEXER_AST_VISUALISATION_GRAPH_H

#include "DLDL_LEXER/Ast/Listener/EnterExitListener.h"

namespace DLDL_LEXER { namespace ast { namespace listener { namespace deamer { namespace visualisation {

	class Graph : public EnterExitListener
	{
	private:
		std::string output;

		void Init()
		{
			output += "digraph DLDL_LEXER_AST {\n";
		}

		void End()
		{
			output += "}\n";
		}

		void AddConnection(const  ::deamer::external::cpp::ast::Node* source, const  ::deamer::external::cpp::ast::Node* target)
		{
			output += "\t" + std::to_string(::std::size_t(source)) + " -> " + std::to_string(::std::size_t(target)) + ";\n";
		}

		
		void ListenEntry(const ::DLDL_LEXER::ast::node::program* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"program\"];\n";
		}

		void ListenEntry(const ::DLDL_LEXER::ast::node::stmts* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"stmts\"];\n";
		}

		void ListenEntry(const ::DLDL_LEXER::ast::node::stmt* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"stmt\"];\n";
		}

		void ListenEntry(const ::DLDL_LEXER::ast::node::tokendeclaration* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"tokendeclaration\"];\n";
		}

		void ListenEntry(const ::DLDL_LEXER::ast::node::abstraction* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"abstraction\"];\n";
		}

		void ListenEntry(const ::DLDL_LEXER::ast::node::DELETE_ABSTRACTION* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"DELETE_ABSTRACTION\"];\n";
		}

		void ListenEntry(const ::DLDL_LEXER::ast::node::IGNORE_ABSTRACTION* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"IGNORE_ABSTRACTION\"];\n";
		}

		void ListenEntry(const ::DLDL_LEXER::ast::node::NOVALUE_ABSTRACTION* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"NOVALUE_ABSTRACTION\"];\n";
		}

		void ListenEntry(const ::DLDL_LEXER::ast::node::CRASH_ABSTRACTION* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"CRASH_ABSTRACTION\"];\n";
		}

		void ListenEntry(const ::DLDL_LEXER::ast::node::STANDARD_ABSTRACTION* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"STANDARD_ABSTRACTION\"];\n";
		}

		void ListenEntry(const ::DLDL_LEXER::ast::node::UNKNOWN_ABSTRACTION* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"UNKNOWN_ABSTRACTION\"];\n";
		}

		void ListenEntry(const ::DLDL_LEXER::ast::node::TERMINAL* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"TERMINAL\"];\n";
		}

		void ListenEntry(const ::DLDL_LEXER::ast::node::REGEX* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"REGEX\"];\n";
		}

		void ListenEntry(const ::DLDL_LEXER::ast::node::ESCAPE_CHARS* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"ESCAPE_CHARS\"];\n";
		}

		void ListenEntry(const ::DLDL_LEXER::ast::node::COMMENT* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"COMMENT\"];\n";
		}

		
		void ListenExit(const ::DLDL_LEXER::ast::node::program* node) override
		{
		}

		void ListenExit(const ::DLDL_LEXER::ast::node::stmts* node) override
		{
		}

		void ListenExit(const ::DLDL_LEXER::ast::node::stmt* node) override
		{
		}

		void ListenExit(const ::DLDL_LEXER::ast::node::tokendeclaration* node) override
		{
		}

		void ListenExit(const ::DLDL_LEXER::ast::node::abstraction* node) override
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

#endif // DLDL_LEXER_AST_VISUALISATION_GRAPH_H