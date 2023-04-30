#include "DLDL/Generate/SubWriter/PrecedenceLPDWriter.h"

deamer::file::tool::File
DLDL::generate::sub::PrecedenceLPDWriter::GetFileContentHeaderFile(ir::Language* language,
																   const ir::LPD& lpd)
{
	deamer::file::tool::File file("Precedence", "h", "");

	// auto* precedence = static_cast<ir::Precedence*>(lpd.GetIR());

	return file;
}

deamer::file::tool::File
DLDL::generate::sub::PrecedenceLPDWriter::GetFileContentSourceFile(ir::Language* language,
																   const ir::LPD& lpd)
{
	deamer::file::tool::File file("Precedence", "cpp", "");

	return file;
}
