#include "DLDL/IR/IRParser.h"
#include "DLDL_COMMENT/IR/Parser.h"
#include "DLDL_GENERATION/IR/Parser.h"
#include "DLDL_GRAMMAR/IR/Parser.h"
#include "DLDL_IMPORT/IR/Parser.h"
#include "DLDL_LEXER/IR/Parser.h"
#include "DLDL_OOPSYNTAX/IR/Parser.h"
#include "DLDL_VALUE/IR/Parser.h"

std::vector<DLDL::ir::IR*> DLDL::ir::IRParser::Parse(const Type type,
													 const std::string& fileContent,
													 ::deamer::file::tool::OSType os)
{
	switch (type)
	{
	case Type::Unknown:
		break;
	case Type::Lexicon:
		return ::DLDL::ir::lexer::Parser().GetIRs(fileContent);
		break;
	case Type::Grammar:
		return ::DLDL::ir::grammar::Parser().GetIRs(fileContent);
		break;
	case Type::Precedence:
		break;
	case Type::Associativity:
		break;
	case Type::Generation:
		return ::DLDL::ir::generation::Parser(os).GetIRs(fileContent);
		break;
	case Type::OopSyntax:
		return ::DLDL::ir::oopsyntax::Parser(os).GetIRs(fileContent);
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
	case Type::Argument:
		// return ::DLDL::ir::argument::Parser(os).GetIRs(fileContent);
		break;
	case Type::Comment:
		return ::DLDL::ir::comment::Parser(os).GetIRs(fileContent);
	case Type::Import:
		return ::DLDL::ir::import::Parser(os).GetIRs(fileContent);
	case Type::Value:
		return ::DLDL::ir::value::Parser(os).GetIRs(fileContent);
	default:
		break;
	}

	return {};
}
