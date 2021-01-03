#ifndef DLDL_OUTPUTFORMATTER_H
#define DLDL_OUTPUTFORMATTER_H

#include <AstVisitor/DLDL_AstPrinter.h>
#include <AstVisitor/DLDL_AstVisitor.h>
#include <Deamer/FileProcessor/FileReadProcessor.h>
#include <OutputFormatter.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Console/Argument.h>
#include <Console/ArgumentType_t.h>

namespace DLDL
{
	class OutputFormatter
	{
	private:
		const std::vector<DLDL::Argument> Arguments;
		
		bool IsArgumentActivated(const DLDL::ArgumentType_t type) const;
	public:
		DLDL_AstVisitor ast_visitor_;
		std::string LanguageName;
		OutputFormatter(const DLDL_AstVisitor& ast_visitor, const std::string& language_name, const std::vector<DLDL::Argument>& arguments);
		std::string Format() const;
		std::string MakeMakeFile() const;
		std::string MakeMakeFileWithDebugMessages() const;
		std::string LanguageInit() const;
		std::string LanguageGrammer() const;
		std::string RetrieveLanguageDefinition() const;
		std::string LanguageThreatAnalysis() const;
		std::string LanguageCompilation() const;
		std::string PrintLanguageDefinition() const;
	private:
		
	};
}

#endif //DLDL_OUTPUTFORMATTER_H