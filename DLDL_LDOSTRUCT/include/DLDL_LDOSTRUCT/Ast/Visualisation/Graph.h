#ifndef DLDL_LDOSTRUCT_AST_VISUALISATION_GRAPH_H
#define DLDL_LDOSTRUCT_AST_VISUALISATION_GRAPH_H

#include "DLDL_LDOSTRUCT/Ast/Listener/EnterExitListener.h"

namespace DLDL_LDOSTRUCT { namespace ast { namespace listener { namespace deamer { namespace visualisation {

	class Graph : public EnterExitListener
	{
	private:
		std::string output;

		void Init()
		{
			output += "digraph DLDL_LDOSTRUCT_AST {\n";
		}

		void End()
		{
			output += "}\n";
		}

		void AddConnection(const  ::deamer::external::cpp::ast::Node* source, const  ::deamer::external::cpp::ast::Node* target)
		{
			output += "\t" + std::to_string(::std::size_t(source)) + " -> " + std::to_string(::std::size_t(target)) + ";\n";
		}

		
		void ListenEntry(const ::DLDL_LDOSTRUCT::ast::node::program* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"program\"];\n";
		}

		void ListenEntry(const ::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__stmt__* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_star__stmt__\"];\n";
		}

		void ListenEntry(const ::DLDL_LDOSTRUCT::ast::node::stmt* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"stmt\"];\n";
		}

		void ListenEntry(const ::DLDL_LDOSTRUCT::ast::node::argument* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"argument\"];\n";
		}

		void ListenEntry(const ::DLDL_LDOSTRUCT::ast::node::argument_name* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"argument_name\"];\n";
		}

		void ListenEntry(const ::DLDL_LDOSTRUCT::ast::node::argument_block* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"argument_block\"];\n";
		}

		void ListenEntry(const ::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__argument_stmt__* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_star__argument_stmt__\"];\n";
		}

		void ListenEntry(const ::DLDL_LDOSTRUCT::ast::node::argument_stmt* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"argument_stmt\"];\n";
		}

		void ListenEntry(const ::DLDL_LDOSTRUCT::ast::node::COLON* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"COLON\"];\n";
		}

		void ListenEntry(const ::DLDL_LDOSTRUCT::ast::node::LEFT_ANGLE_BRACKET* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"LEFT_ANGLE_BRACKET\"];\n";
		}

		void ListenEntry(const ::DLDL_LDOSTRUCT::ast::node::RIGHT_ANGLE_BRACKET* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"RIGHT_ANGLE_BRACKET\"];\n";
		}

		void ListenEntry(const ::DLDL_LDOSTRUCT::ast::node::VARNAME* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"VARNAME\"];\n";
		}

		void ListenEntry(const ::DLDL_LDOSTRUCT::ast::node::INDENTED_VALUE* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"INDENTED_VALUE\"];\n";
		}

		void ListenEntry(const ::DLDL_LDOSTRUCT::ast::node::ESCAPE_CHARS* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"ESCAPE_CHARS\"];\n";
		}

		
		void ListenExit(const ::DLDL_LDOSTRUCT::ast::node::program* node) override
		{
		}

		void ListenExit(const ::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__stmt__* node) override
		{
		}

		void ListenExit(const ::DLDL_LDOSTRUCT::ast::node::stmt* node) override
		{
		}

		void ListenExit(const ::DLDL_LDOSTRUCT::ast::node::argument* node) override
		{
		}

		void ListenExit(const ::DLDL_LDOSTRUCT::ast::node::argument_name* node) override
		{
		}

		void ListenExit(const ::DLDL_LDOSTRUCT::ast::node::argument_block* node) override
		{
		}

		void ListenExit(const ::DLDL_LDOSTRUCT::ast::node::deamerreserved_star__argument_stmt__* node) override
		{
		}

		void ListenExit(const ::DLDL_LDOSTRUCT::ast::node::argument_stmt* node) override
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

#endif // DLDL_LDOSTRUCT_AST_VISUALISATION_GRAPH_H