#ifndef DLDL_GENERATE_SUBWRITER_GRAMMARLPDWRITER_H
#define DLDL_GENERATE_SUBWRITER_GRAMMARLPDWRITER_H

namespace DLDL::generate::sub
{
	class GrammarLPDWriter : public SubWriter
	{
	public:
		GrammarLPDWriter() = default;

	public:
		deamer::file::tool::File GetFileContentHeaderFile(ir::Language* language,
														  const ir::LPD& lpd) override
		{
			deamer::file::tool::File file("Grammar", "h", "");

			return file;
		}

		deamer::file::tool::File GetFileContentSourceFile(ir::Language* language,
														  const ir::LPD& lpd) override
		{
			deamer::file::tool::File file("Grammar", "cpp", "");

			return file;
		}
	};
}

#endif // DLDL_GENERATE_SUBWRITER_GRAMMARLPDWRITER_H