#ifndef DLDL_GENERATE_SUBWRITER_IDENTITYLPDWRITER_H
#define DLDL_GENERATE_SUBWRITER_IDENTITYLPDWRITER_H

#include "DLDL/Generate/SubWriter.h"

namespace DLDL::generate::sub
{
	class IdentityLPDWriter : public SubWriter
	{
	public:
		IdentityLPDWriter() = default;

	public:
		deamer::file::tool::File GetFileContentHeaderFile(ir::Language* language,
														  const ir::LPD& lpd) override;

		deamer::file::tool::File GetFileContentSourceFile(ir::Language* language,
														  const ir::LPD& lpd) override;
	};
}

#endif // DLDL_GENERATE_SUBWRITER_IDENTITYLPDWRITER_H
