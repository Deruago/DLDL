#include "DLDL/IR/IRParser.h"
#include "DLDL_GENERATION/IR/Parser.h"
#include "DLDL_GRAMMAR/IR/Parser.h"
#include "DLDL_LEXER/IR/Parser.h"
#include "DLDL_OOPSYNTAX/IR/Parser.h"

DLDL::ir::IR* DLDL::ir::IRParser::Parse(const Type type, const std::string& fileContent,
										::deamer::file::tool::OSType os)
{
	switch (type)
	{
	case Type::Unknown:
		break;
	case Type::Lexicon:
		return ::DLDL::ir::lexer::Parser().GetIR(fileContent);
		break;
	case Type::Grammar:
		return ::DLDL::ir::grammar::Parser().GetIR(fileContent);
		break;
	case Type::Precedence:
		break;
	case Type::Associativity:
		break;
	case Type::Generation:
		return ::DLDL::ir::generation::Parser(os).GetIR(fileContent);
		break;
	case Type::OopSyntax:
		return ::DLDL::ir::oopsyntax::Parser(os).GetIR(fileContent);
		break;
	case Type::Identity:
		break;
	case Type::AstOptimization:
		break;
	case Type::AstTranslation:
		break;
	case Type::Coloring:
		break;
	case Type::Formatting:
		break;
	case Type::Documentation:
		break;
	case Type::Threat:
		break;
	default:
		break;
	}
}
