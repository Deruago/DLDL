#ifndef DLDL_GENERATE_SUBWRITER_LEXICONLPDWRITER_H
#define DLDL_GENERATE_SUBWRITER_LEXICONLPDWRITER_H

namespace DLDL::generate::sub
{
	class LexiconLPDWriter : public SubWriter
	{
	public:
		LexiconLPDWriter() = default;
	public:
		deamer::file::tool::File GetFileContentHeaderFile(ir::Language* language, const ir::LPD& lpd) override
		{
			deamer::file::tool::File file("Lexicon", "h", "");
			
			return file;
		}

		deamer::file::tool::File GetFileContentSourceFile(ir::Language* language, const ir::LPD& lpd) override
		{
			deamer::file::tool::File file("Lexicon", "cpp", "");
			
			return file;
		}
	};
}

#endif // DLDL_GENERATE_SUBWRITER_LEXICONLPDWRITER_H