#ifndef DLDL_GENERATE_SUBWRITER_THREATLPDWRITER_H
#define DLDL_GENERATE_SUBWRITER_THREATLPDWRITER_H

#include "DLDL/Generate/SubWriter.h"
#include "DLDL/IR/SpecialDefinition/Threat.h"

namespace DLDL::generate::sub
{
	class ThreatLPDWriter : public SubWriter
	{
	public:
		ThreatLPDWriter() = default;

	public:
		deamer::file::tool::File GetFileContentHeaderFile(ir::Language* language,
														  const ir::LPD& lpd) override;

		deamer::file::tool::File GetFileContentSourceFile(ir::Language* language,
														  const ir::LPD& lpd) override;
	};
}

#endif // DLDL_GENERATE_SUBWRITER_THREATLPDWRITER_H
