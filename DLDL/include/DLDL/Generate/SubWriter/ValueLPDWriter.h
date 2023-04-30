#ifndef DLDL_GENERATE_SUBWRITER_VALUELPDWRITER_H
#define DLDL_GENERATE_SUBWRITER_VALUELPDWRITER_H

#include "DLDL/Generate/SubWriter.h"
#include "DLDL/Template/Definition/Value/ValueHTemplate.h"
#include <Deamer/File/Tool/File.h>
#include <optional>

namespace DLDL::generate::sub
{
	class ValueLPDWriter : public SubWriter
	{
	public:
		ValueLPDWriter() = default;

	public:
		deamer::file::tool::File GetFileContentHeaderFile(ir::Language* language,
														  const ir::LPD& lpd) override;

		deamer::file::tool::File GetFileContentSourceFile(ir::Language* language,
														  const ir::LPD& lpd) override;
	};
}

#endif // DLDL_GENERATE_SUBWRITER_VALUELPDWRITER_H
