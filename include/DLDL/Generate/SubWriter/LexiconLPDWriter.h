#ifndef DLDL_GENERATE_SUBWRITER_LEXICONLPDWRITER_H
#define DLDL_GENERATE_SUBWRITER_LEXICONLPDWRITER_H

#include "DLDL/Generate/SubWriter.h"
#include "DLDL/IR/LPD.h"
#include "DLDL_LEXER/IR/Lexicon.h"
#include <Deamer/File/Tool/File.h>

namespace DLDL::generate::sub
{
	class LexiconLPDWriter : public SubWriter
	{
	public:
		LexiconLPDWriter() = default;

	public:
		deamer::file::tool::File GetFileContentHeaderFile(ir::Language* language,
														  const ir::LPD& lpd) override;

		deamer::file::tool::File GetFileContentSourceFile(ir::Language* language,
														  const ir::LPD& lpd) override;
	};
}

#endif // DLDL_GENERATE_SUBWRITER_LEXICONLPDWRITER_H
