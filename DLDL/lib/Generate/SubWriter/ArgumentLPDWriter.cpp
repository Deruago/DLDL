#include "DLDL/Generate/SubWriter/ArgumentLPDWriter.h"
#include "DLDL/IR/Language.h"
#include "DLDL/Template/Definition/Argument/ArgumentCPPTemplate.h"
#include "DLDL/Template/Definition/Argument/ArgumentHTemplate.h"
#include "DLDL_ARGUMENT/IR/Argument.h"
#include "DLDL_GRAMMAR/IR/Grammar.h"
#include "DLDL_LEXER/IR/Lexicon.h"

deamer::file::tool::File
DLDL::generate::sub::ArgumentLPDWriter::GetFileContentHeaderFile(ir::Language* language,
																 const ir::LPD& lpd)
{
	deamer::file::tool::File file("Argument", "h", "");

	auto* argument = static_cast<ir::Argument*>(lpd.GetIR());
	auto* lexicon = static_cast<ir::Lexicon*>(language->GetIRIfExists(ir::Type::Lexicon));
	auto* grammar = static_cast<ir::Grammar*>(language->GetIRIfExists(ir::Type::Grammar));
	if (grammar == nullptr)
	{
		throw std::logic_error(
			"Argument LPD requires a Grammar LPD. No Grammar LPD found in Definition directory.");
	}
	if (lexicon == nullptr)
	{
		throw std::logic_error(
			"Argument LPD requires a Lexicon LPD. No Lexicon LPD found in Definition directory.");
	}

	auto generator = std::make_unique<DLDL::filetemplate::ArgumentHTemplate>();
	FillInDefaultVariablesInConstruction(*generator, language);

	file.SetFileContent(generator->GetOutput());

	return file;
}

deamer::file::tool::File
DLDL::generate::sub::ArgumentLPDWriter::GetFileContentSourceFile(ir::Language* language,
																 const ir::LPD& lpd)
{
	deamer::file::tool::File file("Argument", "cpp", "");

	auto* argument = static_cast<ir::Argument*>(lpd.GetIR());
	auto* lexicon = static_cast<ir::Lexicon*>(language->GetIRIfExists(ir::Type::Lexicon));
	auto* grammar = static_cast<ir::Grammar*>(language->GetIRIfExists(ir::Type::Grammar));
	if (grammar == nullptr)
	{
		throw std::logic_error(
			"Argument LPD requires a Grammar LPD. No Grammar LPD found in Definition directory.");
	}
	if (lexicon == nullptr)
	{
		throw std::logic_error(
			"Argument LPD requires a Lexicon LPD. No Lexicon LPD found in Definition directory.");
	}

	auto generator = std::make_unique<DLDL::filetemplate::ArgumentCPPTemplate>();
	FillInDefaultVariablesInConstruction(*generator, language);

	file.SetFileContent(generator->GetOutput());

	return file;
}
