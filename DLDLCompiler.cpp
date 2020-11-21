#include <DLDLCompiler.h>
#include <DLDLParser.h>
#include <AstVisitor/DLDL_AstPrinter.h>
#include <AstVisitor/DLDL_AstVisitor.h>
#include <Deamer/FileProcessor/FileReadProcessor.h>
#include <OutputFormatter.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <fstream>

DLDL::DLDLCompiler::DLDLCompiler()
{

}

DLDL::DLDLCompiler::~DLDLCompiler()
{

}

deamer::CompiledObject* DLDL::DLDLCompiler::CompileText(std::string inputText)
{
    return nullptr;
}

deamer::CompiledObject* DLDL::DLDLCompiler::CompileFile(FILE* inputFile)
{
    return nullptr;
}

deamer::CompiledObject* DLDL::DLDLCompiler::CompileFile(std::string fileLocation)
{
	deamer::FileReadProcessor file_read = deamer::FileReadProcessor();
	std::string reformatted_code = file_read.ReadFile("./" + fileLocation);
	std::cout << reformatted_code << std::endl;
	//*
	DLDLParser parser = DLDLParser();
	deamer::AstNode* ast_node = parser.ParseText(reformatted_code);

	DLDL_AstPrinter ast_printer = DLDL_AstPrinter();
	DLDL::DLDL_AstVisitor ast_visitor = DLDL::DLDL_AstVisitor();
	std::cout << "\nCreated Syntax Tree\n" << std::endl;
	
	if (ast_node != nullptr)
	{
		ast_printer.Dispatch(*ast_node);
		std::cout << "Now Compiling to c++ DeamerProject implementation" << std::endl;
		ast_visitor.Dispatch(*ast_node);
		OutputFormatter output_formatter = OutputFormatter(ast_visitor, fileLocation);
		WriteToFile("./" + fileLocation + "Generator.cpp", output_formatter.Format());
		WriteToFile("./Makefile", output_formatter.MakeMakeFile());
		std::system("make CompilerGenerator");
		std::system("make Executable");
	}
	
    return nullptr;
}

void DLDL::DLDLCompiler::WriteToFile(const std::string& file_location, const std::string& file_content)
{
	const std::string file_path = file_location;
	std::ofstream new_file;

	new_file.open(file_path, std::ios_base::trunc);

	new_file << file_content << '\n';

	new_file.close();
}



