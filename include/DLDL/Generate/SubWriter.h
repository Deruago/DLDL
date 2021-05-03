#ifndef DLDL_GENERATE_SUBWRITER_H
#define DLDL_GENERATE_SUBWRITER_H

#include "DLDL/IR/Language.h"
#include <Deamer/File/Tool/File.h>

namespace DLDL::generate
{
	class SubWriter
	{
	public:
		SubWriter() = default;
		virtual ~SubWriter() = default;
	public:
		virtual deamer::file::tool::File GetFileContentSourceFile(ir::Language* language,
														  const ir::LPD& lpd) = 0;

		virtual deamer::file::tool::File GetFileContentHeaderFile(ir::Language* language,
																  const ir::LPD& lpd) = 0;
	};
}


#endif // DLDL_GENERATE_SUBWRITER_H