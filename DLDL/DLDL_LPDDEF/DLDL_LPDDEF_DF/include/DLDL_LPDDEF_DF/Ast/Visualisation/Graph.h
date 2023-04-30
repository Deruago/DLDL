#ifndef DLDL_LPDDEF_DF_AST_VISUALISATION_GRAPH_H
#define DLDL_LPDDEF_DF_AST_VISUALISATION_GRAPH_H

#include "DLDL_LPDDEF_DF/Ast/Listener/EnterExitListener.h"

namespace DLDL_LPDDEF_DF { namespace ast { namespace listener { namespace deamer { namespace visualisation {

	class Graph : public EnterExitListener
	{
	private:
		std::string output;

		void Init()
		{
			output += "digraph DLDL_LPDDEF_DF_AST {\n";
		}

		void End()
		{
			output += "}\n";
		}

		void AddConnection(const  ::deamer::external::cpp::ast::Node* source, const  ::deamer::external::cpp::ast::Node* target)
		{
			output += "\t" + std::to_string(::std::size_t(source)) + " -> " + std::to_string(::std::size_t(target)) + ";\n";
		}

		
		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::program* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"program\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_star__stmt__\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::stmt* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"stmt\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::comment_line* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"comment_line\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::vector_variant* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"vector_variant\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_optional__value_part__* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_optional__value_part__\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::optional_variant* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"optional_variant\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::value_part* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"value_part\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::standard_variant* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"standard_variant\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::value* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"value\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::value_type* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"value_type\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_arrow__value_type__\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_star__COMMA__value_type__\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_long_54* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_long_54\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::var_type* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"var_type\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_arrow__VARNAME__\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_star__COLON__VARNAME__\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::var_name* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"var_name\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::LAB* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"LAB\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::RAB* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"RAB\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::LSB* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"LSB\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::RSB* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"RSB\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::EQ* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"EQ\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::COLON* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"COLON\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::LB* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"LB\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::RB* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"RB\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::COMMA* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"COMMA\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::OPTIONAL* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"OPTIONAL\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::VECTOR* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"VECTOR\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::DEAMER_VARNAME* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"DEAMER_VARNAME\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::COMMENT* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"COMMENT\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::VARNAME* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"VARNAME\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::NUMBER* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"NUMBER\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::STRING* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"STRING\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::SEMICOLON* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"SEMICOLON\"];\n";
		}

		void ListenEntry(const ::DLDL_LPDDEF_DF::ast::node::ESCAPE_CHARS* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"ESCAPE_CHARS\"];\n";
		}

		
		void ListenExit(const ::DLDL_LPDDEF_DF::ast::node::program* node) override
		{
		}

		void ListenExit(const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__stmt__* node) override
		{
		}

		void ListenExit(const ::DLDL_LPDDEF_DF::ast::node::stmt* node) override
		{
		}

		void ListenExit(const ::DLDL_LPDDEF_DF::ast::node::comment_line* node) override
		{
		}

		void ListenExit(const ::DLDL_LPDDEF_DF::ast::node::vector_variant* node) override
		{
		}

		void ListenExit(const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_optional__value_part__* node) override
		{
		}

		void ListenExit(const ::DLDL_LPDDEF_DF::ast::node::optional_variant* node) override
		{
		}

		void ListenExit(const ::DLDL_LPDDEF_DF::ast::node::value_part* node) override
		{
		}

		void ListenExit(const ::DLDL_LPDDEF_DF::ast::node::standard_variant* node) override
		{
		}

		void ListenExit(const ::DLDL_LPDDEF_DF::ast::node::value* node) override
		{
		}

		void ListenExit(const ::DLDL_LPDDEF_DF::ast::node::value_type* node) override
		{
		}

		void ListenExit(const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__value_type__* node) override
		{
		}

		void ListenExit(const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COMMA__value_type__* node) override
		{
		}

		void ListenExit(const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_long_54* node) override
		{
		}

		void ListenExit(const ::DLDL_LPDDEF_DF::ast::node::var_type* node) override
		{
		}

		void ListenExit(const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_arrow__VARNAME__* node) override
		{
		}

		void ListenExit(const ::DLDL_LPDDEF_DF::ast::node::deamerreserved_star__COLON__VARNAME__* node) override
		{
		}

		void ListenExit(const ::DLDL_LPDDEF_DF::ast::node::var_name* node) override
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

#endif // DLDL_LPDDEF_DF_AST_VISUALISATION_GRAPH_H