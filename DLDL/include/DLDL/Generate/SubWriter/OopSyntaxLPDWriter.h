#ifndef DLDL_GENERATE_SUBWRITER_OOPSYNTAXLPDWRITER_H
#define DLDL_GENERATE_SUBWRITER_OOPSYNTAXLPDWRITER_H

#include "DLDL/Generate/SubWriter.h"
#include "DLDL/Template/Definition/OopSyntax/OopSyntaxHTemplate.h"
#include <Deamer/File/Tool/File.h>
#include <Deamer/Language/Type/Definition/Object/Main/OOPSyntax/OopSyntaxScope.h>
#include <optional>

namespace DLDL::generate::sub
{
	class OopSyntaxLPDWriter : public SubWriter
	{
	public:
		OopSyntaxLPDWriter() = default;

	public:
		deamer::file::tool::File GetFileContentHeaderFile(ir::Language* language,
														  const ir::LPD& lpd) override;

		deamer::file::tool::File GetFileContentSourceFile(ir::Language* language,
														  const ir::LPD& lpd) override;

	private:
		std::string GetOopPropertyName(
			deamer::language::type::definition::object::main::OopConceptMemberType oopProperty);
		std::string GetOopTypeName(
			const std::optional<deamer::language::type::definition::object::main::OopSyntaxScope>&
				oopSyntaxScope_);
	};
}

#endif // DLDL_GENERATE_SUBWRITER_OOPSYNTAXLPDWRITER_H
