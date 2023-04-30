#include "DLDL_VALUE/IR/Parser.h"
#include "DLDL_VALUE/IR/Value.h"

DLDL::ir::value::Parser::Parser(::deamer::file::tool::OSType os_) : ::DLDL::ir::Parser(Type::Value)
{
}

DLDL::ir::IR* DLDL::ir::value::Parser::GetIR(std::string text)
{
	const auto parser = DLDL_VALUE::bison::parser::Parser();
	auto tree = std::unique_ptr<deamer::external::cpp::ast::Tree>(parser.Parse(text));
	if (tree == nullptr || tree->GetStartNode() == nullptr)
	{
		return new DLDL::ir::Value();
	}

	auto valueListener = DLDL_VALUE::ast::listener::user::Value();
	valueListener.Dispatch(tree->GetStartNode());

	auto* valueIr = valueListener.GetValue();

	return valueIr;
}
