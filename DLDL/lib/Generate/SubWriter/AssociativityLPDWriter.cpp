#include "DLDL/Generate/SubWriter/AssociativityLPDWriter.h"

deamer::file::tool::File
DLDL::generate::sub::AssociativityLPDWriter::GetFileContentHeaderFile(ir::Language* language,
																	  const ir::LPD& lpd)
{
	deamer::file::tool::File file("Associativity", "h", "");

	// auto* associativity = static_cast<ir::Associativity*>(lpd.GetIR());

	return file;
}

deamer::file::tool::File
DLDL::generate::sub::AssociativityLPDWriter::GetFileContentSourceFile(ir::Language* language,
																	  const ir::LPD& lpd)
{
	deamer::file::tool::File file("Associativity", "cpp", "");

	return file;
}
