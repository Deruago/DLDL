#ifndef DLDL_GENERATE_SUBWRITER_GENERATIONLPDWRITER_H
#define DLDL_GENERATE_SUBWRITER_GENERATIONLPDWRITER_H

#include "DLDL/Generate/SubWriter.h"
#include "DLDL/Template/Definition/Generation/GenerationHTemplate.h"

namespace DLDL::generate::sub
{
	class GenerationLPDWriter : public SubWriter
	{
	public:
		GenerationLPDWriter() = default;
	public:
		deamer::file::tool::File GetFileContentHeaderFile(ir::Language* language, const ir::LPD& lpd) override
		{
			deamer::file::tool::File file("Generation", "h", "");

			auto* generation = static_cast<ir::special::Generation*>(lpd.GetIR());

			auto generator = DLDL::filetemplate::GenerationTemplate();

			FillInDefaultVariablesInConstruction(generator, language);

			for (auto tool : generation->GetTools())
			{
				std::string sourcetool;
				if (tool.type == ir::special::ToolType::Ast && tool.name == "CPP") {
					sourcetool = "DeamerAST";
				}
				else {
					sourcetool = tool.name;
				}

				generator.generate_tool_->Set(sourcetool);

				for (auto integration : tool.integrations)
				{
					generator.generate_tool_source_->Set(sourcetool);
					generator.generate_tool_target_->Set(integration.name);

					generator.integration_declaration_->ExpandVariableField();
					generator.integration_implementation_->ExpandVariableField();
					generator.integration_add_object_->ExpandVariableField();
				}

				for (auto argument : tool.arguments)
				{
					generator.argument_->Set(argument.GetArgumentNameUnderscored());
					generator.argument_string_->Set(argument.GetArgumentName());

					generator.argument_declaration_->ExpandVariableField();
					generator.argument_implementation_->ExpandVariableField();
					generator.argument_add_object_->ExpandVariableField();
				}

				generator.generate_tools_declaration_->ExpandVariableField();
				generator.generate_tools_implementation_->ExpandVariableField();
				generator.generate_tools_add_object_->ExpandVariableField();
			}

			file.SetFileContent(generator.GetOutput());

			return file;
		}

		deamer::file::tool::File GetFileContentSourceFile(ir::Language* language, const ir::LPD& lpd) override
		{
			deamer::file::tool::File file("Generation", "cpp", "");

			return file;
		}
	};
}

#endif // DLDL_GENERATE_SUBWRITER_GENERATIONLPDWRITER_H