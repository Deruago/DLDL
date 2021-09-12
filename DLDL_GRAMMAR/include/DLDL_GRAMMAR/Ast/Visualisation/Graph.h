#ifndef DLDL_GRAMMAR_AST_VISUALISATION_GRAPH_H
#define DLDL_GRAMMAR_AST_VISUALISATION_GRAPH_H

#include "DLDL_GRAMMAR/Ast/Listener/EnterExitListener.h"

namespace DLDL_GRAMMAR { namespace ast { namespace listener { namespace deamer { namespace visualisation {

	class Graph : public EnterExitListener
	{
	private:
		std::string output;

		void Init()
		{
			output += "digraph DLDL_GRAMMAR_AST {\n";
		}

		void End()
		{
			output += "}\n";
		}

		void AddConnection(const  ::deamer::external::cpp::ast::Node* source, const  ::deamer::external::cpp::ast::Node* target)
		{
			output += "\t" + std::to_string(::std::size_t(source)) + " -> " + std::to_string(::std::size_t(target)) + ";\n";
		}

		
		void ListenEntry(const ::DLDL_GRAMMAR::ast::node::program* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"program\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR::ast::node::stmts* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"stmts\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR::ast::node::stmt* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"stmt\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR::ast::node::abstraction_declaration* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"abstraction_declaration\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR::ast::node::abstraction* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"abstraction\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR::ast::node::definition* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"definition\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR::ast::node::production_rules* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"production_rules\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR::ast::node::COMMENT* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"COMMENT\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR::ast::node::START_ABSTRACTION* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"START_ABSTRACTION\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR::ast::node::GROUP_ABSTRACTION* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"GROUP_ABSTRACTION\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR::ast::node::INLINE_ABSTRACTION* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"INLINE_ABSTRACTION\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR::ast::node::INLINE_GROUP_ABSTRACTION* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"INLINE_GROUP_ABSTRACTION\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR::ast::node::UNKNOWN_ABSTRACTION* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"UNKNOWN_ABSTRACTION\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR::ast::node::NONTERMINAL* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"NONTERMINAL\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR::ast::node::PRODUCTION_RULE* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"PRODUCTION_RULE\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR::ast::node::ESCAPE_CHARS* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"ESCAPE_CHARS\"];\n";
		}

		
		void ListenExit(const ::DLDL_GRAMMAR::ast::node::program* node) override
		{
		}

		void ListenExit(const ::DLDL_GRAMMAR::ast::node::stmts* node) override
		{
		}

		void ListenExit(const ::DLDL_GRAMMAR::ast::node::stmt* node) override
		{
		}

		void ListenExit(const ::DLDL_GRAMMAR::ast::node::abstraction_declaration* node) override
		{
		}

		void ListenExit(const ::DLDL_GRAMMAR::ast::node::abstraction* node) override
		{
		}

		void ListenExit(const ::DLDL_GRAMMAR::ast::node::definition* node) override
		{
		}

		void ListenExit(const ::DLDL_GRAMMAR::ast::node::production_rules* node) override
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

#endif // DLDL_GRAMMAR_AST_VISUALISATION_GRAPH_H