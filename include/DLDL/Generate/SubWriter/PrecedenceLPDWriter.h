#ifndef DLDL_GENERATE_SUBWRITER_PRECEDENCELPDWRITER_H
#define DLDL_GENERATE_SUBWRITER_PRECEDENCELPDWRITER_H

#include "DLDL/Generate/SubWriter.h"

namespace DLDL::generate::sub
{
	class PrecedenceLPDWriter : public SubWriter
	{
	public:
		PrecedenceLPDWriter() = default;

	public:
		deamer::file::tool::File GetFileContentHeaderFile(ir::Language* language,
														  const ir::LPD& lpd) override;

		deamer::file::tool::File GetFileContentSourceFile(ir::Language* language,
														  const ir::LPD& lpd) override;
	};
}

#endif // DLDL_GENERATE_SUBWRITER_PRECEDENCELPDWRITER_H
