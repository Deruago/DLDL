#ifndef DLDL_GENERATE_SUBWRITER_GRAMMARLPDWRITER_H
#define DLDL_GENERATE_SUBWRITER_GRAMMARLPDWRITER_H

#include "DLDL/Generate/SubWriter.h"
#include "DLDL_GRAMMAR/IR/Grammar.h"
#include "DLDL/Template/Definition/Grammar/GrammarHTemplate.h"
#include "DLDL/Template/Definition/Grammar/GrammarCPPTemplate.h"

namespace DLDL::generate::sub
{
	class GrammarLPDWriter : public SubWriter
	{
	public:
		GrammarLPDWriter() = default;

	public:
		deamer::file::tool::File GetFileContentHeaderFile(ir::Language* language,
		                                                  const ir::LPD& lpd) override;

		deamer::file::tool::File GetFileContentSourceFile(ir::Language* language,
		                                                  const ir::LPD& lpd) override;
	};
}

#endif // DLDL_GENERATE_SUBWRITER_GRAMMARLPDWRITER_H