#ifndef DLDL_LPDDEF_EF_AST_VISUALISATION_GRAPH_H
#define DLDL_LPDDEF_EF_AST_VISUALISATION_GRAPH_H

#include "DLDL_LPDDEF_EF/Ast/Listener/EnterExitListener.h"

namespace DLDL_LPDDEF_EF { namespace ast { namespace listener { namespace deamer { namespace visualisation {

	class Graph : public EnterExitListener
	{
	private:
		std::string output;

		void Init()
		{
			output += "digraph DLDL_LPDDEF_EF_AST {\n";
		}

		void End()
		{
			output += "}\n";
		}

		void AddConnection(const  ::deamer::external::cpp::ast::Node* source, const  ::deamer::external::cpp::ast::Node* target)
		{
			output += "\t" + std::to_string(::std::size_t(source)) + " -> " + std::to_string(::std::size_t(target)) + ";\n";
		}

		
		void ListenEntry(const ::DLDL_LPDDEF_EF::ast::node::program* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"program\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_star__stmt__\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_EF::ast::node::stmt* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"stmt\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_EF::ast::node::comment_line* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"comment_line\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_EF::ast::node::standard_variant* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"standard_variant\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_EF::ast::node::standard_variant_specific_number* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"standard_variant_specific_number\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_EF::ast::node::value* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"value\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_EF::ast::node::enum_name* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"enum_name\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_EF::ast::node::COMMENT* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"COMMENT\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_EF::ast::node::VARNAME* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"VARNAME\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_EF::ast::node::NUMBER* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"NUMBER\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_EF::ast::node::COLON* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"COLON\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_EF::ast::node::SEMICOLON* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"SEMICOLON\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_EF::ast::node::ESCAPE_CHARS* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"ESCAPE_CHARS\"];\n";
		}

		
		void ListenExit(const ::DLDL_LPDDEF_EF::ast::node::program* node) override
		{
		}

		void ListenExit(const ::DLDL_LPDDEF_EF::ast::node::deamerreserved_star__stmt__* node) override
		{
		}

		void ListenExit(const ::DLDL_LPDDEF_EF::ast::node::stmt* node) override
		{
		}

		void ListenExit(const ::DLDL_LPDDEF_EF::ast::node::comment_line* node) override
		{
		}

		void ListenExit(const ::DLDL_LPDDEF_EF::ast::node::standard_variant* node) override
		{
		}

		void ListenExit(const ::DLDL_LPDDEF_EF::ast::node::standard_variant_specific_number* node) override
		{
		}

		void ListenExit(const ::DLDL_LPDDEF_EF::ast::node::value* node) override
		{
		}

		void ListenExit(const ::DLDL_LPDDEF_EF::ast::node::enum_name* node) override
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

#endif // DLDL_LPDDEF_EF_AST_VISUALISATION_GRAPH_H