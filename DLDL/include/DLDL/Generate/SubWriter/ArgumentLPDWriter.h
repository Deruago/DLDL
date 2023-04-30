#ifndef DLDL_GENERATE_SUBWRITER_ARGUMENTLPDWRITER_H
#define DLDL_GENERATE_SUBWRITER_ARGUMENTLPDWRITER_H

#include "DLDL/Generate/SubWriter.h"
#include "DLDL/Template/Definition/Argument/ArgumentHTemplate.h"
#include <Deamer/File/Tool/File.h>
#include <optional>

namespace DLDL::generate::sub
{
	class ArgumentLPDWriter : public SubWriter
	{
	public:
		ArgumentLPDWriter() = default;

	public:
		deamer::file::tool::File GetFileContentHeaderFile(ir::Language* language,
														  const ir::LPD& lpd) override;

		deamer::file::tool::File GetFileContentSourceFile(ir::Language* language,
														  const ir::LPD& lpd) override;
	};
}

#endif // DLDL_GENERATE_SUBWRITER_ARGUMENTLPDWRITER_H
