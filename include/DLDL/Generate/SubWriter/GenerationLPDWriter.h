#ifndef DLDL_GENERATE_SUBWRITER_GENERATIONLPDWRITER_H
#define DLDL_GENERATE_SUBWRITER_GENERATIONLPDWRITER_H

#include "DLDL/Generate/SubWriter.h"

namespace DLDL::generate::sub
{
	class GenerationLPDWriter : public SubWriter
	{
	public:
		GenerationLPDWriter() = default;

	public:
		static constexpr const char* ConvertOSToString(deamer::file::tool::OSType os)
		{
			switch (os)
			{
			case deamer::file::tool::OSType::unknown:
				return ConvertOSToString(deamer::file::tool::os_used);
			case deamer::file::tool::OSType::all:
				return ConvertOSToString(deamer::file::tool::os_used);
			case deamer::file::tool::OSType::os_linux:
				return "linux";
			case deamer::file::tool::OSType::os_windows:
				return "windows";
			case deamer::file::tool::OSType::os_mac:
				return "mac";
			default:
				return ConvertOSToString(deamer::file::tool::os_used);
			}
		}

		deamer::file::tool::File GetFileContentHeaderFile(ir::Language* language,
														  const ir::LPD& lpd) override;

		deamer::file::tool::File GetFileContentSourceFile(ir::Language* language,
														  const ir::LPD& lpd) override;
	};
}

#endif // DLDL_GENERATE_SUBWRITER_GENERATIONLPDWRITER_H
