#ifndef DLDL_ARGUMENT_AST_VISUALISATION_GRAPH_H
#define DLDL_ARGUMENT_AST_VISUALISATION_GRAPH_H

#include "DLDL_ARGUMENT/Ast/Listener/EnterExitListener.h"

namespace DLDL_ARGUMENT { namespace ast { namespace listener { namespace deamer { namespace visualisation {

	class Graph : public EnterExitListener
	{
	private:
		std::string output;

		void Init()
		{
			output += "digraph DLDL_ARGUMENT_AST {\n";
		}

		void End()
		{
			output += "}\n";
		}

		void AddConnection(const  ::deamer::external::cpp::ast::Node* source, const  ::deamer::external::cpp::ast::Node* target)
		{
			output += "\t" + std::to_string(::std::size_t(source)) + " -> " + std::to_string(::std::size_t(target)) + ";\n";
		}

		
		void ListenEntry(const ::DLDL_ARGUMENT::ast::node::program* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"program\"];\n";
		}

		void ListenEntry(const ::DLDL_ARGUMENT::ast::node::SINGLE_COMMENT* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"SINGLE_COMMENT\"];\n";
		}

		void ListenEntry(const ::DLDL_ARGUMENT::ast::node::MULTI_COMMENT* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"MULTI_COMMENT\"];\n";
		}

		void ListenEntry(const ::DLDL_ARGUMENT::ast::node::TEXT* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"TEXT\"];\n";
		}

		void ListenEntry(const ::DLDL_ARGUMENT::ast::node::VARNAME* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"VARNAME\"];\n";
		}

		void ListenEntry(const ::DLDL_ARGUMENT::ast::node::ESCAPE_CHARS* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"ESCAPE_CHARS\"];\n";
		}

		
		void ListenExit(const ::DLDL_ARGUMENT::ast::node::program* node) override
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

#endif // DLDL_ARGUMENT_AST_VISUALISATION_GRAPH_H