#ifndef DLDL_GENERATE_LPDWRITER_H
#define DLDL_GENERATE_LPDWRITER_H

#include "DLDL/IR/Language.h"
#include "LPDSubWriterFactory.h"
#include <Deamer/File/Tool/File.h>

namespace DLDL::generate
{
	class LPDWriter
	{
	private:
	private:
		LPDWriter() = default;
		~LPDWriter() = default;

	public:
		static deamer::file::tool::File GetLanguage(ir::Language* language)
		{
			deamer::file::tool::File file("Language", "h", "");

			return file;
		}

		static deamer::file::tool::File GetCompilerGenerator(ir::Language* language)
		{
			deamer::file::tool::File file("CompilerGenerator", "h", "");

			return file;
		}

		static deamer::file::tool::File GetFileContentSourceFile(ir::Language* language,
																 const ir::LPD& lpd)
		{
			deamer::file::tool::File file = LPDSubWriterFactory::GetLPDSubWriter(lpd.GetType())
												->GetFileContentSourceFile(language, lpd);

			return file;
		}

		static deamer::file::tool::File GetFileContentHeaderFile(ir::Language* language,
																 const ir::LPD& lpd)
		{
			deamer::file::tool::File file = LPDSubWriterFactory::GetLPDSubWriter(lpd.GetType())
												->GetFileContentHeaderFile(language, lpd);

			return file;
		}
	};
}

#endif // DLDL_GENERATE_LPDWRITER_H