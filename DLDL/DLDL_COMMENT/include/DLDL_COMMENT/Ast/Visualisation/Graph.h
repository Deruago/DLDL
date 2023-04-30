#ifndef DLDL_COMMENT_AST_VISUALISATION_GRAPH_H
#define DLDL_COMMENT_AST_VISUALISATION_GRAPH_H

#include "DLDL_COMMENT/Ast/Listener/EnterExitListener.h"

namespace DLDL_COMMENT { namespace ast { namespace listener { namespace deamer { namespace visualisation {

	class Graph : public EnterExitListener
	{
	private:
		std::string output;

		void Init()
		{
			output += "digraph DLDL_COMMENT_AST {\n";
		}

		void End()
		{
			output += "}\n";
		}

		void AddConnection(const  ::deamer::external::cpp::ast::Node* source, const  ::deamer::external::cpp::ast::Node* target)
		{
			output += "\t" + std::to_string(::std::size_t(source)) + " -> " + std::to_string(::std::size_t(target)) + ";\n";
		}

		
		void ListenEntry(const ::DLDL_COMMENT::ast::node::program* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"program\"];\n";
		}

		void ListenEntry(const ::DLDL_COMMENT::ast::node::deamerreserved_star__stmt__* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_star__stmt__\"];\n";
		}

		void ListenEntry(const ::DLDL_COMMENT::ast::node::stmt* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"stmt\"];\n";
		}

		void ListenEntry(const ::DLDL_COMMENT::ast::node::comment_value_declaration* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"comment_value_declaration\"];\n";
		}

		void ListenEntry(const ::DLDL_COMMENT::ast::node::deamerreserved_long_3* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_long_3\"];\n";
		}

		void ListenEntry(const ::DLDL_COMMENT::ast::node::deamerreserved_long_6* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_long_6\"];\n";
		}

		void ListenEntry(const ::DLDL_COMMENT::ast::node::comment_abstraction* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"comment_abstraction\"];\n";
		}

		void ListenEntry(const ::DLDL_COMMENT::ast::node::start_abstraction* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"start_abstraction\"];\n";
		}

		void ListenEntry(const ::DLDL_COMMENT::ast::node::end_abstraction* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"end_abstraction\"];\n";
		}

		void ListenEntry(const ::DLDL_COMMENT::ast::node::start_sequence* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"start_sequence\"];\n";
		}

		void ListenEntry(const ::DLDL_COMMENT::ast::node::end_sequence* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"end_sequence\"];\n";
		}

		void ListenEntry(const ::DLDL_COMMENT::ast::node::sequence* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"sequence\"];\n";
		}

		void ListenEntry(const ::DLDL_COMMENT::ast::node::syntactic_reference* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"syntactic_reference\"];\n";
		}

		void ListenEntry(const ::DLDL_COMMENT::ast::node::SINGLE_COMMENT* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"SINGLE_COMMENT\"];\n";
		}

		void ListenEntry(const ::DLDL_COMMENT::ast::node::MULTI_COMMENT* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"MULTI_COMMENT\"];\n";
		}

		void ListenEntry(const ::DLDL_COMMENT::ast::node::COMMENT_VALUE* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"COMMENT_VALUE\"];\n";
		}

		void ListenEntry(const ::DLDL_COMMENT::ast::node::LEFT_SQUARE_BRACKET* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"LEFT_SQUARE_BRACKET\"];\n";
		}

		void ListenEntry(const ::DLDL_COMMENT::ast::node::RIGHT_SQUARE_BRACKET* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"RIGHT_SQUARE_BRACKET\"];\n";
		}

		void ListenEntry(const ::DLDL_COMMENT::ast::node::START* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"START\"];\n";
		}

		void ListenEntry(const ::DLDL_COMMENT::ast::node::END* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"END\"];\n";
		}

		void ListenEntry(const ::DLDL_COMMENT::ast::node::TEXT* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"TEXT\"];\n";
		}

		void ListenEntry(const ::DLDL_COMMENT::ast::node::VARNAME* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"VARNAME\"];\n";
		}

		void ListenEntry(const ::DLDL_COMMENT::ast::node::ESCAPE_CHARS* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"ESCAPE_CHARS\"];\n";
		}

		
		void ListenExit(const ::DLDL_COMMENT::ast::node::program* node) override
		{
		}

		void ListenExit(const ::DLDL_COMMENT::ast::node::deamerreserved_star__stmt__* node) override
		{
		}

		void ListenExit(const ::DLDL_COMMENT::ast::node::stmt* node) override
		{
		}

		void ListenExit(const ::DLDL_COMMENT::ast::node::comment_value_declaration* node) override
		{
		}

		void ListenExit(const ::DLDL_COMMENT::ast::node::deamerreserved_long_3* node) override
		{
		}

		void ListenExit(const ::DLDL_COMMENT::ast::node::deamerreserved_long_6* node) override
		{
		}

		void ListenExit(const ::DLDL_COMMENT::ast::node::comment_abstraction* node) override
		{
		}

		void ListenExit(const ::DLDL_COMMENT::ast::node::start_abstraction* node) override
		{
		}

		void ListenExit(const ::DLDL_COMMENT::ast::node::end_abstraction* node) override
		{
		}

		void ListenExit(const ::DLDL_COMMENT::ast::node::start_sequence* node) override
		{
		}

		void ListenExit(const ::DLDL_COMMENT::ast::node::end_sequence* node) override
		{
		}

		void ListenExit(const ::DLDL_COMMENT::ast::node::sequence* node) override
		{
		}

		void ListenExit(const ::DLDL_COMMENT::ast::node::syntactic_reference* node) override
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

#endif // DLDL_COMMENT_AST_VISUALISATION_GRAPH_H