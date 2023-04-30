#ifndef DLDL_GENERATE_SUBWRITER_IMPORTLPDWRITER_H
#define DLDL_GENERATE_SUBWRITER_IMPORTLPDWRITER_H

#include "DLDL/Generate/SubWriter.h"
#include "DLDL/Template/Definition/Import/ImportHTemplate.h"
#include "DLDL_VALUE/IR/Value.h"
#include <Deamer/File/Tool/File.h>
#include <optional>

namespace DLDL::generate::sub
{
	class ImportLPDWriter : public SubWriter
	{
	public:
		ImportLPDWriter() = default;

	public:
		deamer::file::tool::File GetFileContentHeaderFile(ir::Language* language,
														  const ir::LPD& lpd) override;

		deamer::file::tool::File GetFileContentSourceFile(ir::Language* language,
														  const ir::LPD& lpd) override;
		std::optional<std::string> GetValueRule(const std::string& valueRule, ir::Value* valueLpd);
	};
}

#endif // DLDL_GENERATE_SUBWRITER_IMPORTLPDWRITER_H
