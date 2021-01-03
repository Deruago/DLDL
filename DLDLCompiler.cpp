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

std::string RetrieveFilenameFromFileLocation(std::string fileLocation)
{
	// remove till file name
	const size_t last_slash_idx = fileLocation.find_last_of("\\/");
	if (std::string::npos != last_slash_idx)
	{
		fileLocation.erase(0, last_slash_idx + 1);
	}

	// Remove extension if present.
	const size_t period_idx = fileLocation.rfind('.');
	if (std::string::npos != period_idx)
	{
		fileLocation.erase(period_idx);
	}
	
	return fileLocation;
}

bool DLDL::DLDLCompiler::IsArgumentActive(const DLDL::ArgumentType_t type) const
{
	for(const auto argument : Arguments)
	{
		if (argument.type == type)
		{
			return argument.activated;
		}
		
		// All arguments, activates every argument, thus encountering returns true
		if (argument.type == DLDL::ArgumentType_t::allArguments)
		{
			return true;
		}
	}
	
	return false;
}

DLDL::DLDLCompiler::DLDLCompiler(const std::vector<DLDL::Argument>& arguments)
: Arguments(arguments)
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
	const std::string languageName = RetrieveFilenameFromFileLocation(fileLocation);
	
	deamer::FileReadProcessor file_read = deamer::FileReadProcessor();
	std::string reformatted_code = file_read.ReadFile("./" + fileLocation);
	PrintReformattedCode(reformatted_code);

	DLDLParser parser = DLDLParser();
	deamer::AstNode* ast_node = parser.ParseText(reformatted_code);

	DLDL::DLDL_AstVisitor ast_visitor = DLDL::DLDL_AstVisitor();
	PrintToConsole("\nCreated Syntax Tree\n");
	
	if (ast_node != nullptr)
	{
		PrintAST(ast_node);
		
		PrintToConsole("Now Compiling to c++ DeamerProject implementation");
		
		ast_visitor.Dispatch(*ast_node);
		
		OutputFormatter output_formatter = OutputFormatter(ast_visitor, languageName, Arguments);
		WriteToFile("./" + languageName + "Generator.cpp", output_formatter.Format());
		WriteToFile("./Makefile", output_formatter.MakeMakeFile());
		
		TryCompilingNewCompiler();
	}
	
    return nullptr;
}

void DLDL::DLDLCompiler::TryCompilingNewCompiler()
{
	if (IsArgumentActive(DLDL::ArgumentType_t::autoCompile))
	{
		std::system("make CompilerGenerator && make Executable");
	}
}

void DLDL::DLDLCompiler::PrintReformattedCode(const std::string reformatted_code)
{
	if (IsArgumentActive(DLDL::ArgumentType_t::showTextAfterFilePreProcessor))
	{
		PrintToConsole(reformatted_code);
	}
}

void DLDL::DLDLCompiler::PrintAST(deamer::AstNode* astnode)
{
	if (IsArgumentActive(DLDL::ArgumentType_t::showAST))
	{
		DLDL_AstPrinter ast_printer = DLDL_AstPrinter();
		ast_printer.Dispatch(*astnode);
	}
}

void DLDL::DLDLCompiler::WriteToFile(const std::string& file_location, const std::string& file_content)
{
	const std::string file_path = file_location;
	std::ofstream new_file;

	new_file.open(file_path, std::ios_base::trunc);

	new_file << file_content << '\n';

	new_file.close();
}


void DLDL::DLDLCompiler::PrintToConsole(const std::string& text)
{
	if (IsArgumentActive(DLDL::ArgumentType_t::showtext))
	{
		std::cout << text << std::endl;
	}
}

