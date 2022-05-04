#ifndef DLDL_GRAMMAR_PRODUCTION_RULE_AST_VISUALISATION_GRAPH_H
#define DLDL_GRAMMAR_PRODUCTION_RULE_AST_VISUALISATION_GRAPH_H

#include "DLDL_GRAMMAR_PRODUCTION_RULE/Ast/Listener/EnterExitListener.h"

namespace DLDL_GRAMMAR_PRODUCTION_RULE { namespace ast { namespace listener { namespace deamer { namespace visualisation {

	class Graph : public EnterExitListener
	{
	private:
		std::string output;

		void Init()
		{
			output += "digraph DLDL_GRAMMAR_PRODUCTION_RULE_AST {\n";
		}

		void End()
		{
			output += "}\n";
		}

		void AddConnection(const  ::deamer::external::cpp::ast::Node* source, const  ::deamer::external::cpp::ast::Node* target)
		{
			output += "\t" + std::to_string(::std::size_t(source)) + " -> " + std::to_string(::std::size_t(target)) + ";\n";
		}

		
		void ListenEntry(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::program* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"program\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"stmts\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmt* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"stmt\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"group\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::nested_group* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"nested_group\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"optional_group\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::zero_or_more_group* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"zero_or_more_group\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::one_or_more_group* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"one_or_more_group\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::or_group* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"or_group\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"min_max_group\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::extension_group* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"extension_group\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ENDING_USELESS_SYMBOLS* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"ENDING_USELESS_SYMBOLS\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VERTICAL_SLASH* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"VERTICAL_SLASH\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_PARANTHESIS* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"LEFT_PARANTHESIS\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_PARANTHESIS* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"RIGHT_PARANTHESIS\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_BRACKET* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"LEFT_BRACKET\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_BRACKET* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"RIGHT_BRACKET\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::LEFT_SQUARE_BRACKET* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"LEFT_SQUARE_BRACKET\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::RIGHT_SQUARE_BRACKET* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"RIGHT_SQUARE_BRACKET\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::QUESTION_MARK* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"QUESTION_MARK\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::EXCLAMATION_MARK* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"EXCLAMATION_MARK\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ARROW* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"ARROW\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::STAR* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"STAR\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::PLUS* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"PLUS\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MINUS* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"MINUS\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::VALUE* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"VALUE\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::NUMBER* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"NUMBER\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SINGLE_LINE_COMMENT* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"SINGLE_LINE_COMMENT\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::MULTI_LINE_COMMENT* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"MULTI_LINE_COMMENT\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::SYMBOLS* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"SYMBOLS\"];\n";
		}

		void ListenEntry(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::ESCAPE_CHARS* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"ESCAPE_CHARS\"];\n";
		}

		
		void ListenExit(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::program* node) override
		{
		}

		void ListenExit(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmts* node) override
		{
		}

		void ListenExit(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::stmt* node) override
		{
		}

		void ListenExit(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::group* node) override
		{
		}

		void ListenExit(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::nested_group* node) override
		{
		}

		void ListenExit(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::optional_group* node) override
		{
		}

		void ListenExit(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::zero_or_more_group* node) override
		{
		}

		void ListenExit(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::one_or_more_group* node) override
		{
		}

		void ListenExit(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::or_group* node) override
		{
		}

		void ListenExit(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::min_max_group* node) override
		{
		}

		void ListenExit(const ::DLDL_GRAMMAR_PRODUCTION_RULE::ast::node::extension_group* node) override
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

#endif // DLDL_GRAMMAR_PRODUCTION_RULE_AST_VISUALISATION_GRAPH_H