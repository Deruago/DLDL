#include "DLDL/IR/Lpd/ConstructLPD.h"
#include "DLDL/Filesystem/LoadFilesystem.h"
#include "DLDL_LDOSTRUCT/Ast/Listener/User/LdoStruct.h"
#include "DLDL_LDOSTRUCT/Bison/Parser.h"
#include "DLDL_LPDDEF/Ast/Listener/User/LpdDef.h"
#include "DLDL_LPDDEF/Bison/Parser.h"

static std::string Lower(std::string str)
{
	for (auto i = 0; i < str.size(); i++)
	{
		if (::isalpha(str[i]))
			str[i] = ::tolower(str[i]);
	}

	return str;
}

DLDL::ir::ConstructLPD::ConstructLPD(const std::string& relativeDirectoryToLpdDefinitions_)
	: relativeDirectoryToLpdDefinitions(relativeDirectoryToLpdDefinitions_)
{
	lpdProject = std::make_unique<LPDProject>();
}

void DLDL::ir::ConstructLPD::Construct(::deamer::file::tool::OSType os)
{
	::deamer::file::tool::Directory dir;
	auto loader = filesystem::LoadFilesystem(dir, relativeDirectoryToLpdDefinitions);
	if (loader.Error())
	{
		return;
	}

	for (auto lpd : loader.GetDirectDirectories())
	{
		std::cout << "Lpd map: " << lpd << "\n";
		auto lpdDef = ParseLpdDirectory(relativeDirectoryToLpdDefinitions + lpd + "/");
		if (lpdDef == nullptr)
		{
			std::cout << "Error\n";
			continue;
		}

		::deamer::file::tool::Directory lpdDir;
		auto lpdLoader =
			filesystem::LoadFilesystem(lpdDir, relativeDirectoryToLpdDefinitions + lpd + "/");
		lpdLoader.DirectLoad();
		for (auto lpdSubDir : lpdLoader.GetDirectDirectories())
		{
			if (lpdSubDir == "LDO")
			{
				lpdDef->SetLDOs(ParseLdoDirectory(relativeDirectoryToLpdDefinitions + lpd + "/" +
												  lpdSubDir + "/"));
			}
		}

		lpdProject->AddLPD(std::move(lpdDef));
	}
}

std::unique_ptr<DLDL::ir::LPDProject> DLDL::ir::ConstructLPD::GetLPDProject()
{
	return std::move(lpdProject);
}

std::unique_ptr<DLDL::ir::LpdDef> DLDL::ir::ConstructLPD::ParseLpdDirectory(const std::string& lpd)
{
	::deamer::file::tool::Directory lpdDir;
	auto lpdLoader = filesystem::LoadFilesystem(lpdDir, lpd);
	lpdLoader.DirectLoad();
	auto files = lpdDir.GetFiles();
	const auto file = std::find_if(
		std::cbegin(files), std::cend(files), [](const ::deamer::file::tool::File& file) {
			return Lower(file.GetFilename()) == "lpddef" && Lower(file.GetExtension()) == "dldl";
		});

	if (file == files.end())
	{
		std::cout << "No such file\n";
		return nullptr; // error no such file
	}

	std::string lpdDefinition = file->FileContent();

	auto parser = DLDL_LPDDEF::parser::Parser();
	std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(lpdDefinition));
	if (ast == nullptr)
	{
		std::cout << "Syntax error\n";
		return nullptr; // error the content was not following the grammar
	}
	auto startNode = ast->GetStartNode();

	auto listener = DLDL_LPDDEF::ast::listener::user::LpdDef();
	listener.Dispatch(startNode);
	std::unique_ptr<DLDL::ir::LpdDef> lpdDef(listener.GetLpdDef());

	return lpdDef;
}

std::vector<std::unique_ptr<DLDL::ir::LDO>>
DLDL::ir::ConstructLPD::ParseLdoDirectory(const std::string& ldoDirectory)
{
	std::vector<std::unique_ptr<DLDL::ir::LDO>> Ldos;
	::deamer::file::tool::Directory ldoDir;
	auto lpdLoader = filesystem::LoadFilesystem(ldoDir, ldoDirectory);
	lpdLoader.DirectLoad();
	auto files = ldoDir.GetFiles();

	for (auto file : files)
	{
		std::cout << "File: " << file.GetFilename() << "\n";
		if (file.GetExtension() != "dldl")
		{
			continue;
		}

		Ldos.push_back(ParseLdo(file));
	}

	return Ldos;
}

std::unique_ptr<DLDL::ir::LDO>
DLDL::ir::ConstructLPD::ParseLdo(const deamer::file::tool::File& file)
{
	const auto content = file.FileContent();
	const auto parser = DLDL_LDOSTRUCT::parser::Parser();
	const std::unique_ptr<::deamer::external::cpp::ast::Tree> ast(parser.Parse(content));
	if (ast == nullptr)
	{
		return nullptr; // some syntax error.
	}

	auto listener = DLDL_LDOSTRUCT::ast::listener::user::LdoStruct();
	listener.Dispatch(ast->GetStartNode());
	std::unique_ptr<DLDL::ir::LDO> Ldo(listener.GetLdoStruct());
	std::cout << "Ldo: " << Ldo->GetName() << "\n";
	return Ldo;
}
