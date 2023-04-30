#include "DLDL/Generate/SubWriter/CommentLPDWriter.h"
#include "DLDL/IR/Language.h"
#include "DLDL/Template/Definition/Comment/CommentCPPTemplate.h"
#include "DLDL/Template/Definition/Comment/CommentHTemplate.h"
#include "DLDL_COMMENT/IR/Comment.h"
#include "DLDL_GRAMMAR/IR/Grammar.h"
#include "DLDL_LEXER/IR/Lexicon.h"

deamer::file::tool::File
DLDL::generate::sub::CommentLPDWriter::GetFileContentHeaderFile(ir::Language* language,
																const ir::LPD& lpd)
{
	deamer::file::tool::File file("Comment", "h", "");

	auto* comment = static_cast<ir::Comment*>(lpd.GetIR());
	auto* lexicon = static_cast<ir::Lexicon*>(language->GetIRIfExists(ir::Type::Lexicon));
	auto* grammar = static_cast<ir::Grammar*>(language->GetIRIfExists(ir::Type::Grammar));
	if (grammar == nullptr)
	{
		throw std::logic_error(
			"Comment LPD requires a Grammar LPD. No Grammar LPD found in Definition directory.");
	}
	if (lexicon == nullptr)
	{
		throw std::logic_error(
			"Comment LPD requires a Lexicon LPD. No Lexicon LPD found in Definition directory.");
	}

	auto generator = std::make_unique<DLDL::filetemplate::CommentHTemplate>();
	FillInDefaultVariablesInConstruction(*generator, language);

	for (auto& commentValue : comment->GetCommentValues())
	{
		generator->terminal_name_->Set(commentValue.syntacticReference);
		generator->comment_declaration_->ExpandVariableField();
	}

	file.SetFileContent(generator->GetOutput());

	return file;
}

deamer::file::tool::File
DLDL::generate::sub::CommentLPDWriter::GetFileContentSourceFile(ir::Language* language,
																const ir::LPD& lpd)
{
	deamer::file::tool::File file("Comment", "cpp", "");

	auto* comment = static_cast<ir::Comment*>(lpd.GetIR());
	auto* lexicon = static_cast<ir::Lexicon*>(language->GetIRIfExists(ir::Type::Lexicon));
	auto* grammar = static_cast<ir::Grammar*>(language->GetIRIfExists(ir::Type::Grammar));
	if (grammar == nullptr)
	{
		throw std::logic_error(
			"Comment LPD requires a Grammar LPD. No Grammar LPD found in Definition directory.");
	}
	if (lexicon == nullptr)
	{
		throw std::logic_error(
			"Comment LPD requires a Lexicon LPD. No Lexicon LPD found in Definition directory.");
	}

	auto generator = std::make_unique<DLDL::filetemplate::CommentCPPTemplate>();
	FillInDefaultVariablesInConstruction(*generator, language);

	for (auto& commentValue : comment->GetCommentValues())
	{
		generator->terminal_name_->Set(commentValue.syntacticReference);
		generator->start_sequence_->Set(commentValue.startPattern.value_or(""));
		generator->escape_sequence_->Set("");
		generator->end_sequence_->Set(commentValue.endPattern.value_or(""));

		generator->comment_implementation_->ExpandVariableField();
		generator->add_comment_->ExpandVariableField();
	}

	file.SetFileContent(generator->GetOutput());

	return file;
}
