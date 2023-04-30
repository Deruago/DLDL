#include "DLDL/Generate/SubWriter/FormattingLPDWriter.h"
#include "DLDL/IR/Language.h"
#include "DLDL/Template/Definition/Formatting/FormattingCPPTemplate.h"
#include "DLDL/Template/Definition/Formatting/FormattingHTemplate.h"
// #include "DLDL_FORMATTING/IR/Formatting.h"
#include "DLDL_GRAMMAR/IR/Grammar.h"
#include "DLDL_LEXER/IR/Lexicon.h"

deamer::file::tool::File
DLDL::generate::sub::FormattingLPDWriter::GetFileContentHeaderFile(ir::Language* language,
																   const ir::LPD& lpd)
{
	deamer::file::tool::File file("Formatting", "h", "");

	// auto* Formatting = static_cast<ir::Formatting*>(lpd.GetIR());
	auto* lexicon = static_cast<ir::Lexicon*>(language->GetIRIfExists(ir::Type::Lexicon));
	auto* grammar = static_cast<ir::Grammar*>(language->GetIRIfExists(ir::Type::Grammar));
	if (grammar == nullptr)
	{
		throw std::logic_error(
			"Formatting LPD requires a Grammar LPD. No Grammar LPD found in Definition directory.");
	}
	if (lexicon == nullptr)
	{
		throw std::logic_error(
			"Formatting LPD requires a Lexicon LPD. No Lexicon LPD found in Definition directory.");
	}

	auto generator = std::make_unique<DLDL::filetemplate::FormattingHTemplate>();
	FillInDefaultVariablesInConstruction(*generator, language);

	file.SetFileContent(generator->GetOutput());

	return file;
}

deamer::file::tool::File
DLDL::generate::sub::FormattingLPDWriter::GetFileContentSourceFile(ir::Language* language,
																   const ir::LPD& lpd)
{
	deamer::file::tool::File file("Formatting", "cpp", "");

	// auto* Formatting = static_cast<ir::Formatting*>(lpd.GetIR());
	auto* lexicon = static_cast<ir::Lexicon*>(language->GetIRIfExists(ir::Type::Lexicon));
	auto* grammar = static_cast<ir::Grammar*>(language->GetIRIfExists(ir::Type::Grammar));
	if (grammar == nullptr)
	{
		throw std::logic_error(
			"Formatting LPD requires a Grammar LPD. No Grammar LPD found in Definition directory.");
	}
	if (lexicon == nullptr)
	{
		throw std::logic_error(
			"Formatting LPD requires a Lexicon LPD. No Lexicon LPD found in Definition directory.");
	}

	auto generator = std::make_unique<DLDL::filetemplate::FormattingCPPTemplate>();
	FillInDefaultVariablesInConstruction(*generator, language);

	file.SetFileContent(generator->GetOutput());

	return file;
}
