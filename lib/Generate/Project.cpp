#include "DLDL/Generate/Project.h"

DLDL::generate::Project::Project(std::vector<ir::Language*> languages_, bool multiProject_,
								 const std::string& compilerGeneratorDirName)
	: languages(languages_),
	  CompilerGenerator(compilerGeneratorDirName),
	  multiProject(multiProject_)
{
}

void DLDL::generate::Project::WriteToDisk(deamer::file::tool::Directory directoryToWrite,
										  std::string path)
{
	path += directoryToWrite.GetThisDirectory() + "/";

	std::filesystem::create_directories(path);

	for (const auto& file : directoryToWrite.GetFiles())
	{
		const auto filePath = path + file.GetCompleteFileName();

		if (file.GetGenerationLevel() ==
				::deamer::file::tool::GenerationLevel::Dont_generate_if_file_already_exists &&
			std::filesystem::exists(filePath) && !std::filesystem::is_empty(filePath))
		{
			return;
		}

		std::ofstream outputFile;
		outputFile.open(filePath);

		outputFile << file.FileContent();

		outputFile.close();
	}

	for (const auto& childDirectory : directoryToWrite.GetDirectories())
	{
		WriteToDisk(childDirectory, path);
	}
}

deamer::file::tool::Directory DLDL::generate::Project::Generate()
{
	deamer::file::tool::Directory includeDir("include");
	deamer::file::tool::Directory libDir("lib");

	CompilerGenerator.AddFile(LPDWriter::GetMain(languages, multiProject));
	CompilerGenerator.AddFile(LPDWriter::GetCMakeLists(languages));

	for (auto* language : languages)
	{
		deamer::file::tool::Directory languageHeaderDir(language->GetName());
		deamer::file::tool::Directory languageSourceDir(language->GetName());

		deamer::file::tool::File languageFile = LPDWriter::GetLanguage(language);
		deamer::file::tool::File compilerGenerator = LPDWriter::GetCompilerGenerator(language);

		languageHeaderDir.AddFile(languageFile);
		languageHeaderDir.AddFile(compilerGenerator);

		auto LPDs = language->GetCurrentLPDs();
		for (auto& LPD : LPDs)
		{
			deamer::file::tool::File source = LPDWriter().GetFileContentSourceFile(language, LPD);
			languageSourceDir.AddFile(source);

			deamer::file::tool::File header = LPDWriter().GetFileContentHeaderFile(language, LPD);
			languageHeaderDir.AddFile(header);
		}

		for (auto* child : language->GetChildren())
		{
			Generate(child, languageHeaderDir, languageSourceDir);
		}

		libDir += languageSourceDir;
		includeDir += languageHeaderDir;
	}

	CompilerGenerator += libDir;
	CompilerGenerator += includeDir;

	return CompilerGenerator;
}

std::string DLDL::generate::Project::GetLanguageTarget()
{
	std::string output;
	for (auto* language : languages)
	{
		output += language->GetName() + "_";
	}

	output += "CompilerGenerator_Main";

	return output;
}

void DLDL::generate::Project::Generate(ir::Language* language_,
									   deamer::file::tool::Directory& parentHeader,
									   deamer::file::tool::Directory& parentSource)
{
	auto LPDs = language_->GetCurrentLPDs();
	deamer::file::tool::Directory languageHeaderDir(language_->GetName());
	deamer::file::tool::Directory languageSourceDir(language_->GetName());

	deamer::file::tool::File languageFile = LPDWriter::GetLanguage(language_);
	deamer::file::tool::File compilerGenerator = LPDWriter::GetCompilerGenerator(language_);

	languageHeaderDir.AddFile(languageFile);
	languageHeaderDir.AddFile(compilerGenerator);

	for (auto& LPD : LPDs)
	{
		deamer::file::tool::File source = LPDWriter().GetFileContentSourceFile(language_, LPD);
		languageSourceDir.AddFile(source);

		deamer::file::tool::File header = LPDWriter().GetFileContentHeaderFile(language_, LPD);
		languageHeaderDir.AddFile(header);
	}

	for (auto* child : language_->GetChildren())
	{
		Generate(child, languageHeaderDir, languageSourceDir);
	}

	parentHeader += languageHeaderDir;
	parentSource += languageSourceDir;
}
