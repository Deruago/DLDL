#include "DLDL/Generate/Lpd/Project.h"
#include "DLDL/Template/Deamer/LPD/Converter/E_PT/E_PTTemplate.h"
#include "DLDL/Template/Deamer/LPD/Converter/OT_T/OT_TTemplate.h"
#include "DLDL/Template/Deamer/LPD/Converter/PT_E/PT_ETemplate.h"
#include "DLDL/Template/Deamer/LPD/Converter/T_OT/T_OTTemplate.h"
#include "DLDL/Template/Deamer/LPD/Enum/LDO/LDOTemplate.h"
#include "DLDL/Template/Deamer/LPD/Enum/LPD/LPDTemplate.h"
#include "DLDL/Template/Deamer/LPD/Generater/Default/DefaultTemplate.h"
#include "DLDL/Template/Deamer/LPD/LDO/Enum/EnumTemplate.h"
#include "DLDL/Template/Deamer/LPD/LDO/Main/MainTemplate.h"
#include "DLDL/Template/Deamer/LPD/LDO/MainSource/MainSourceTemplate.h"
#include "DLDL/Template/Deamer/LPD/LPD/Main/MainTemplate.h"
#include "DLDL/Template/Deamer/LPD/LPD/MainSource/MainSourceTemplate.h"
#include "DLDL/Template/Deamer/LPD/Validater/OEs_PT/OEs_PTTemplate.h"
#include "DLDL/Template/Deamer/LPD/Validater/PT_OE/PT_OETemplate.h"
#include <set>

static std::vector<std::string> Split(const std::string& str, char split)
{
	std::vector<std::string> out;

	std::string tmp;
	for (auto character : str)
	{
		if (character == split)
		{
			out.push_back(tmp);
			tmp.clear();
		}
		else
		{
			tmp += character;
		}
	}

	return out;
}

static std::string Lower(std::string str)
{
	for (auto i = 0; i < str.size(); i++)
	{
		if (::isalpha(str[i]))
		{
			str[i] = ::tolower(str[i]);
		}
	}

	return str;
}

DLDL::generate::lpd::Project::Project(std::unique_ptr<ir::LPDProject>& lpdProject_)
	: lpdProject(lpdProject_)
{
}

DLDL::generate::lpd::Project::LPDDirectory DLDL::generate::lpd::Project::Generate()
{
	LPDDirectory directory;

	GenerateMainLpd(directory);
	GenerateMainLdo(directory);
	GenerateEnumerations(directory);
	GenerateConverter(directory);
	GenerateValidater(directory);
	GenerateGenerater(directory);

	return directory;
}
#include <iostream>
void DLDL::generate::lpd::Project::GenerateMainLpd(LPDDirectory& directory) const
{
	::deamer::file::tool::Directory mainIncludeLpd;
	::deamer::file::tool::Directory mainSourceLpd;
	::deamer::file::tool::Directory toolIncludeLpd;
	::deamer::file::tool::Directory toolSourceLpd;

	auto mainTemplate = std::make_unique<filetemplate::lpd::lpd::MainTemplate>();
	auto mainSourceTemplate = std::make_unique<filetemplate::lpd::lpd::MainSourceTemplate>();
	mainTemplate->lpd_ctor_member_->variable_field_separator_->Set("");
	mainSourceTemplate->lpd_ctor_member_->variable_field_separator_->Set("");
	mainSourceTemplate->lpd_ctor_member_assignment_->variable_field_separator_->Set("");
	for (auto& lpd : lpdProject->GetLPDs())
	{
		if (!lpd->Generate)
		{
			continue;
		}

		std::cout << "lpd: " << lpd->GetName() << "\n";
		// Reset mainTemplate
		mainTemplate->brief_description_line_->variable_field_->Clear();
		mainTemplate->detailed_description_line_->variable_field_->Clear();
		mainTemplate->lpd_member_->variable_field_->Clear();
		mainTemplate->ldo_include_->variable_field_->Clear();
		mainTemplate->lpd_ctor_member_->variable_field_->Clear();
		mainTemplate->lpd_specific_function_->variable_field_->Clear();

		// Reset mainSourceTemplate
		mainSourceTemplate->lpd_ctor_member_->variable_field_->Clear();
		mainSourceTemplate->lpd_member_reference_->variable_field_->Clear();
		mainSourceTemplate->lpd_ctor_member_assignment_->variable_field_->Clear();
		mainSourceTemplate->lpd_specific_function_->variable_field_->Clear();

		mainTemplate->lpd_name_->Set(lpd->GetName());
		mainSourceTemplate->lpd_name_->Set(lpd->GetName());

		for (auto line : Split(lpd->GetDescription(), '\n'))
		{
			mainTemplate->brief_description_line_content_->Set(line);
			mainTemplate->brief_description_line_->ExpandVariableField();
		}

		std::string ctor_member;
		bool first = true;
		// LpdMember construction
		for (auto& lpdMember : lpd->GetLpdMembers())
		{
			if (!first)
			{
				mainTemplate->comma_extension_->Set(", \n\t\t\t");
				mainSourceTemplate->comma_extension_->Set(", \n\t\t\t");
			}
			else
			{
				mainTemplate->comma_extension_->Set("");
				mainSourceTemplate->comma_extension_->Set("");
				first = false;
			}
			mainTemplate->comment_->variable_field_->Clear();

			ir::LDO* ldo = nullptr;
			std::string target_lpd = GetLPDFromLDO(lpd, lpdMember, ldo);

			mainTemplate->target_lpd_name_->Set(target_lpd);
			mainTemplate->ldo_type_->Set(lpdMember.type);
			mainTemplate->ldo_name_->Set(lpdMember.name);

			mainSourceTemplate->target_lpd_name_->Set(target_lpd);
			mainSourceTemplate->ldo_type_->Set(lpdMember.type);
			mainSourceTemplate->ldo_name_->Set(lpdMember.name);
			if (lpdMember.optional)
			{
				mainTemplate->lpd_member_->Set(mainTemplate->lpd_member_optional_);
				mainTemplate->lpd_ctor_member_type_->Set(mainTemplate->lpd_ctor_member_optional_);
				mainSourceTemplate->lpd_ctor_member_type_->Set(
					mainSourceTemplate->lpd_ctor_member_optional_);
			}
			else if (lpdMember.variadic)
			{
				mainTemplate->lpd_member_->Set(mainTemplate->lpd_member_vector_);
				mainTemplate->lpd_ctor_member_type_->Set(mainTemplate->lpd_ctor_member_vector_);
				mainSourceTemplate->lpd_ctor_member_type_->Set(
					mainSourceTemplate->lpd_ctor_member_vector_);
			}
			else
			{
				mainTemplate->lpd_member_->Set(mainTemplate->lpd_member_standard_);
				mainTemplate->lpd_ctor_member_type_->Set(mainTemplate->lpd_ctor_member_standard_);
				mainSourceTemplate->lpd_ctor_member_type_->Set(
					mainSourceTemplate->lpd_ctor_member_standard_);
			}

			if (ldo->GetLDOType() == ir::LDOType::Ldo)
			{
				mainTemplate->optional_pointer_->Set("*");
				mainSourceTemplate->optional_pointer_->Set("*");
			}
			else
			{
				mainTemplate->optional_pointer_->Set("");
				mainSourceTemplate->optional_pointer_->Set("");
			}

			for (auto line : Split(lpdMember.comments, '\n'))
			{
				mainTemplate->comment_content_->Set(line);
				mainTemplate->comment_->ExpandVariableField();
			}

			// This generates the LDO type location
			if (GetLPDfromString(target_lpd) != nullptr && GetLPDfromString(target_lpd)->IsTool())
			{
				mainTemplate->loc_impl_->Set(mainTemplate->loc_tool_);
				mainSourceTemplate->loc_impl_->Set(mainSourceTemplate->loc_tool_);
			}
			else // It is main lpd or assume it is
			{
				mainTemplate->loc_impl_->Set(mainTemplate->loc_main_);
				mainSourceTemplate->loc_impl_->Set(mainSourceTemplate->loc_main_);
			}
			if (GetLPDfromString(target_lpd) != nullptr && GetLPDfromString(target_lpd)->Explicit)
			{
				mainTemplate->explicit_lpd_namespace_->Set(
					mainTemplate->explicit_lpd_namespace_dispatch_);
				mainSourceTemplate->explicit_lpd_namespace_->Set(
					mainSourceTemplate->explicit_lpd_namespace_dispatch_);
			}
			else
			{
				mainTemplate->explicit_lpd_namespace_->Set("");
				mainSourceTemplate->explicit_lpd_namespace_->Set("");
			}

			mainTemplate->ldo_include_->ExpandVariableField();
			mainTemplate->lpd_member_->ExpandVariableField();
			mainTemplate->lpd_ctor_member_->ExpandVariableField();
			mainSourceTemplate->lpd_ctor_member_->ExpandVariableField();
			mainSourceTemplate->lpd_member_reference_->ExpandVariableField();
			mainSourceTemplate->lpd_ctor_member_assignment_->ExpandVariableField();
		}

		// From now on used for LPD type location
		if (lpd->IsTool())
		{
			mainTemplate->loc_impl_->Set(mainTemplate->loc_tool_);
			mainSourceTemplate->loc_impl_->Set(mainSourceTemplate->loc_tool_);
		}
		else
		{
			mainTemplate->loc_impl_->Set(mainTemplate->loc_main_);
			mainSourceTemplate->loc_impl_->Set(mainSourceTemplate->loc_main_);
		}
		if (lpd != nullptr && lpd->Explicit)
		{
			mainTemplate->explicit_lpd_namespace_->Set(
				mainTemplate->explicit_lpd_namespace_dispatch_);
			mainSourceTemplate->explicit_lpd_namespace_->Set(
				mainSourceTemplate->explicit_lpd_namespace_dispatch_);
		}
		else
		{
			mainTemplate->explicit_lpd_namespace_->Set("");
			mainSourceTemplate->explicit_lpd_namespace_->Set("");
		}

		for (auto& function : lpd->GetFunctions())
		{
			if (Split(function.function, '\n').size() < 3)
			{
				// Not valid
				continue;
			}

			// Temporary fix, function prototype needs to be further analyzed
			mainTemplate->lpd_specific_function_prototype_->Set(function.function);
			mainTemplate->lpd_specific_function_->ExpandVariableField();

			// mainTemplate->lpd_specific_function_prototype_->Set(function.GetFunctionPrototype());
			// mainTemplate->lpd_specific_function_->ExpandVariableField();

			// mainSourceTemplate->lpd_specific_function_->Set(function.function);
			// mainSourceTemplate->lpd_specific_function_->ExpandVariableField();
		}

		if (lpd->IsTool())
		{
			toolIncludeLpd.AddFile(
				::deamer::file::tool::File(lpd->GetName(), "h", mainTemplate->GetOutput()));

			toolSourceLpd.AddFile(
				::deamer::file::tool::File(lpd->GetName(), "cpp", mainSourceTemplate->GetOutput()));
		}
		else
		{
			mainIncludeLpd.AddFile(
				::deamer::file::tool::File(lpd->GetName(), "h", mainTemplate->GetOutput()));

			mainSourceLpd.AddFile(
				::deamer::file::tool::File(lpd->GetName(), "cpp", mainSourceTemplate->GetOutput()));
		}
	}

	directory.mainLPD = mainIncludeLpd;
	directory.mainSourceLPD = mainSourceLpd;
	directory.toolLPD = toolIncludeLpd;
	directory.toolSourceLPD = toolSourceLpd;
}

void DLDL::generate::lpd::Project::GenerateMainLdo(LPDDirectory& directory) const
{
	::deamer::file::tool::Directory mainIncludeLdo;
	::deamer::file::tool::Directory mainSourceLdo;
	::deamer::file::tool::Directory toolIncludeLdo;
	::deamer::file::tool::Directory toolSourceLdo;

	auto ldoTemplate = filetemplate::ldo::ldo::MainTemplate();
	auto ldoSourceTemplate = filetemplate::ldo::ldo::MainSourceTemplate();
	auto enumTemplate = filetemplate::ldo::ldo::EnumTemplate();
	ldoTemplate.ldo_ctor_member_->variable_field_separator_->Set("");
	ldoSourceTemplate.ldo_ctor_member_->variable_field_separator_->Set("");
	ldoSourceTemplate.ldo_ctor_member_assignment_->variable_field_separator_->Set("");
	ldoSourceTemplate.ldo_compare_->variable_field_separator_->Set(" && ");

	for (const auto& lpd : lpdProject->GetLPDs())
	{
		if (!lpd->Generate)
		{
			continue;
		}

		::deamer::file::tool::Directory lpdIncludeDir(lpd->GetName());
		::deamer::file::tool::Directory lpdSourceDir(lpd->GetName());

		ldoTemplate.lpd_name_->Set(lpd->GetName());
		ldoSourceTemplate.lpd_name_->Set(lpd->GetName());

		for (const auto& ldo : lpd->GetLDOs())
		{
			if (!ldo->Generate)
			{
				continue;
			}

			std::set<std::string> LdoMemberHistory;
			ldoTemplate.ldo_member_->variable_field_->Clear();
			ldoTemplate.brief_description_line_->variable_field_->Clear();
			ldoTemplate.detailed_description_line_->variable_field_->Clear();
			ldoTemplate.ldo_include_->variable_field_->Clear();
			ldoTemplate.ldo_ctor_member_->variable_field_->Clear();
			ldoTemplate.ldo_specific_function_->variable_field_->Clear();

			ldoSourceTemplate.ldo_ctor_member_assignment_->variable_field_->Clear();
			ldoSourceTemplate.ldo_member_reference_->variable_field_->Clear();
			ldoSourceTemplate.ldo_ctor_member_->variable_field_->Clear();
			ldoSourceTemplate.ldo_compare_->variable_field_->Clear();
			ldoSourceTemplate.ldo_specific_function_->variable_field_->Clear();

			if (ldo->GetLDOType() != ir::LDOType::Ldo && ldo->GetLDOType() != ir::LDOType::Struct)
			{
				continue;
			}

			ldoTemplate.ldo_name_->Set(ldo->GetName());
			ldoSourceTemplate.ldo_name_->Set(ldo->GetName());
			bool first = true;
			for (auto& ldoMember : ldo->GetDataMembers())
			{
				if (first)
				{
					first = false;
					ldoTemplate.comma_extension_->Set("");
					ldoSourceTemplate.comma_extension_->Set("");
				}
				else
				{
					ldoTemplate.comma_extension_->Set(", \n\t\t\t");
					ldoSourceTemplate.comma_extension_->Set(", \n\t\t\t");
				}

				ldoTemplate.member_type_->Set(ldoMember.type);
				ldoTemplate.member_name_->Set(ldoMember.name);
				ldoSourceTemplate.member_type_->Set(ldoMember.type);
				ldoSourceTemplate.member_name_->Set(ldoMember.name);
				auto* ldoMemberPtr = GetLDOfromString(ldoMember, lpd);

				// This generates the LDO type location
				if (ldoMemberPtr != nullptr && ldoMemberPtr->GetLPD() != nullptr &&
					ldoMemberPtr->GetLPD()->IsTool())
				{
					ldoTemplate.loc_impl_->Set(ldoTemplate.loc_tool_);
					ldoSourceTemplate.loc_impl_->Set(ldoSourceTemplate.loc_tool_);
				}
				else // It is main lpd or assume it is
				{
					ldoTemplate.loc_impl_->Set(ldoTemplate.loc_main_);
					ldoSourceTemplate.loc_impl_->Set(ldoSourceTemplate.loc_main_);
				}
				if (ldoMemberPtr != nullptr && ldoMemberPtr->GetLPD() != nullptr &&
					ldoMemberPtr->GetLPD()->Explicit)
				{
					ldoTemplate.explicit_lpd_namespace_->Set(
						ldoTemplate.explicit_lpd_namespace_dispatch_);
					ldoSourceTemplate.explicit_lpd_namespace_->Set(
						ldoSourceTemplate.explicit_lpd_namespace_dispatch_);
				}
				else
				{
					ldoTemplate.explicit_lpd_namespace_->Set("");
					ldoSourceTemplate.explicit_lpd_namespace_->Set("");
				}

				if (ldoMember.variadic)
				{
					ldoTemplate.ldo_member_->Set(ldoTemplate.ldo_member_vector_);
					ldoTemplate.lpd_ctor_member_impl_->Set(ldoTemplate.ldo_ctor_vector_);
					ldoSourceTemplate.ldo_member_->Set(ldoSourceTemplate.ldo_member_vector_);
					ldoSourceTemplate.lpd_ctor_member_impl_->Set(
						ldoSourceTemplate.ldo_ctor_vector_);
				}
				else if (ldoMember.optional)
				{
					ldoTemplate.ldo_member_->Set(ldoTemplate.ldo_member_optional_);
					ldoTemplate.lpd_ctor_member_impl_->Set(ldoTemplate.ldo_ctor_optional_);
					ldoSourceTemplate.ldo_member_->Set(ldoSourceTemplate.ldo_member_optional_);
					ldoSourceTemplate.lpd_ctor_member_impl_->Set(
						ldoSourceTemplate.ldo_ctor_optional_);
				}
				else
				{
					ldoTemplate.ldo_member_->Set(ldoTemplate.ldo_member_standard_);
					ldoTemplate.lpd_ctor_member_impl_->Set(ldoTemplate.ldo_ctor_standard_);
					ldoSourceTemplate.ldo_member_->Set(ldoSourceTemplate.ldo_member_standard_);
					ldoSourceTemplate.lpd_ctor_member_impl_->Set(
						ldoSourceTemplate.ldo_ctor_standard_);
				}

				if ((ldoMemberPtr != nullptr && ldoMemberPtr->GetLDOType() == ir::LDOType::Ldo) ||
					(Lower(ldoMember.type) == "base"))
				{
					ldoTemplate.optional_pointer_->Set("*");
					ldoSourceTemplate.optional_pointer_->Set("*");
				}
				else
				{
					ldoTemplate.optional_pointer_->Set("");
					ldoSourceTemplate.optional_pointer_->Set("");
				}

				if (Lower(ldoMember.type) == "string")
				{
					ldoTemplate.member_type_->Set("string");
					ldoTemplate.ldo_namespace_->Set(ldoTemplate.default_std_namespace_);
					ldoSourceTemplate.member_type_->Set("string");
					ldoSourceTemplate.ldo_namespace_->Set(ldoSourceTemplate.default_std_namespace_);
				}
				else if (Lower(ldoMember.type) == "size_t")
				{
					ldoTemplate.member_type_->Set("size_t");
					ldoTemplate.ldo_namespace_->Set(ldoTemplate.default_std_namespace_);
					ldoSourceTemplate.member_type_->Set("size_t");
					ldoSourceTemplate.ldo_namespace_->Set(ldoSourceTemplate.default_std_namespace_);
				}
				else if (Lower(ldoMember.type) == "unsigned")
				{
					ldoTemplate.member_type_->Set("size_t");
					ldoTemplate.ldo_namespace_->Set(ldoTemplate.default_none_namespace_);
					ldoSourceTemplate.member_type_->Set("size_t");
					ldoSourceTemplate.ldo_namespace_->Set(
						ldoSourceTemplate.default_none_namespace_);
				}
				else if (Lower(ldoMember.type) == "int")
				{
					ldoTemplate.member_type_->Set("int");
					ldoTemplate.ldo_namespace_->Set(ldoTemplate.default_none_namespace_);
					ldoSourceTemplate.member_type_->Set("int");
					ldoSourceTemplate.ldo_namespace_->Set(
						ldoSourceTemplate.default_none_namespace_);
				}
				else if (Lower(ldoMember.type) == "bool")
				{
					ldoTemplate.member_type_->Set("bool");
					ldoTemplate.ldo_namespace_->Set(ldoTemplate.default_none_namespace_);
					ldoSourceTemplate.member_type_->Set("bool");
					ldoSourceTemplate.ldo_namespace_->Set(
						ldoSourceTemplate.default_none_namespace_);
				}
				else if (Lower(ldoMember.type) == "base")
				{
					ldoTemplate.member_type_->Set("Base");
					ldoTemplate.ldo_namespace_->Set(ldoTemplate.default_ldo_namespace_);
					ldoSourceTemplate.member_type_->Set("Base");
					ldoSourceTemplate.ldo_namespace_->Set(ldoSourceTemplate.default_ldo_namespace_);
				}
				else
				{
					ldoTemplate.target_lpd_name_->Set(ldoMemberPtr->GetLPD()->GetName());

					ldoTemplate.ldo_namespace_->Set(ldoTemplate.default_ldo_namespace_);
					ldoSourceTemplate.ldo_namespace_->Set(ldoSourceTemplate.default_ldo_namespace_);
					auto iter = LdoMemberHistory.find(ldoMember.type);
					if (iter == LdoMemberHistory.end())
					{
						ldoTemplate.ldo_include_->ExpandVariableField();
						LdoMemberHistory.insert(ldoMember.type);
					}
				}

				if (ldoMember.defaultValue.empty())
				{
					ldoTemplate.optional_default_value_->Set("");
				}
				else
				{
					ldoTemplate.optional_default_value_->Set(ldoTemplate.default_value_);
					ldoTemplate.default_implementation_->Set(ldoMember.defaultValue);
				}
				if (ldoMemberPtr != nullptr || Lower(ldoMember.type) == "base")
				{
					ldoSourceTemplate.ldo_member_reference_->ExpandVariableField();
				}

				ldoTemplate.ldo_ctor_member_->ExpandVariableField();
				ldoTemplate.ldo_member_->ExpandVariableField();

				ldoSourceTemplate.ldo_ctor_member_assignment_->ExpandVariableField();
				ldoSourceTemplate.ldo_ctor_member_->ExpandVariableField();
				ldoSourceTemplate.ldo_compare_->ExpandVariableField();
			}

			if (lpd->IsTool())
			{
				ldoTemplate.loc_impl_->Set(ldoTemplate.loc_tool_);
				ldoSourceTemplate.loc_impl_->Set(ldoSourceTemplate.loc_tool_);
			}
			else
			{
				ldoTemplate.loc_impl_->Set(ldoTemplate.loc_main_);
				ldoSourceTemplate.loc_impl_->Set(ldoSourceTemplate.loc_main_);
			}
			if (lpd != nullptr && lpd->Explicit)
			{
				ldoTemplate.explicit_lpd_namespace_->Set(
					ldoTemplate.explicit_lpd_namespace_dispatch_);
				ldoSourceTemplate.explicit_lpd_namespace_->Set(
					ldoSourceTemplate.explicit_lpd_namespace_dispatch_);
			}
			else
			{
				ldoTemplate.explicit_lpd_namespace_->Set("");
				ldoSourceTemplate.explicit_lpd_namespace_->Set("");
			}

			for (auto& function : ldo->GetFunction())
			{
				if (Split(function.function, '\n').size() < 3)
				{
					// Not valid
					continue;
				}

				// Temporary fix, function prototype needs to be further analyzed
				ldoTemplate.ldo_specific_function_prototype_->Set(function.function);
				ldoTemplate.ldo_specific_function_->ExpandVariableField();

				// ldoTemplate.ldo_specific_function_prototype_->Set(function.GetFunctionPrototype());
				// ldoTemplate.ldo_specific_function_->ExpandVariableField();

				// ldoSourceTemplate.ldo_specific_function_->Set(function.function);
				// ldoSourceTemplate.ldo_specific_function_->ExpandVariableField();
			}

			lpdIncludeDir.AddFile(
				::deamer::file::tool::File(ldo->GetName(), "h", ldoTemplate.GetOutput()));
			lpdSourceDir.AddFile(
				::deamer::file::tool::File(ldo->GetName(), "cpp", ldoSourceTemplate.GetOutput()));
		}

		for (const auto& enumeration : lpd->GetLDOs())
		{
			if (!enumeration->Generate)
			{
				continue;
			}

			enumTemplate.lpd_name_->Set(lpd->GetName());

			if (enumeration->GetLDOType() != ir::LDOType::Enumeration)
			{
				continue;
			}
			enumTemplate.enumeration_->variable_field_->Clear();

			enumTemplate.ldo_name_->Set(enumeration->GetName());
			for (auto& member : enumeration->GetDataMembers())
			{
				enumTemplate.member_name_->Set(member.name);
				if (member.defaultValue.empty())
				{
					enumTemplate.optional_default_value_->Set("");
				}
				else
				{
					enumTemplate.optional_default_value_->Set(enumTemplate.default_value_);
					enumTemplate.value_->Set(member.defaultValue);
				}
				enumTemplate.enumeration_->ExpandVariableField();
			}

			if (lpd->IsTool())
			{
				enumTemplate.loc_impl_->Set(enumTemplate.loc_tool_);
			}
			else
			{
				enumTemplate.loc_impl_->Set(enumTemplate.loc_main_);
			}
			if (lpd != nullptr && lpd->Explicit)
			{
				enumTemplate.explicit_lpd_namespace_->Set(
					enumTemplate.explicit_lpd_namespace_dispatch_);
			}
			else
			{
				enumTemplate.explicit_lpd_namespace_->Set("");
			}

			lpdIncludeDir.AddFile(
				::deamer::file::tool::File(enumeration->GetName(), "h", enumTemplate.GetOutput()));
		}

		/* // Reserved logic in 2.3.0 all structs are LDOs.
		for (const auto& structure : lpd->GetLDOs())
		{
			if (structure->GetLDOType() != ir::LDOType::Struct)
			{
				continue;
			}
		}
		*/

		if (lpd->IsTool())
		{
			toolIncludeLdo.AddDirectory(lpdIncludeDir);
			toolSourceLdo.AddDirectory(lpdSourceDir);
		}
		else
		{
			mainIncludeLdo.AddDirectory(lpdIncludeDir);
			mainSourceLdo.AddDirectory(lpdSourceDir);
		}
	}

	directory.mainLDO = mainIncludeLdo;
	directory.mainSourceLDO = mainSourceLdo;
	directory.toolLDO = toolIncludeLdo;
	directory.toolSourceLDO = toolSourceLdo;
}

void DLDL::generate::lpd::Project::GenerateConverter(LPDDirectory& directory) const
{
	auto E_PT = std::make_unique<filetemplate::lpd::converter::E_PTTemplate>();
	auto PT_E = std::make_unique<filetemplate::lpd::converter::PT_ETemplate>();
	auto OT_T = std::make_unique<filetemplate::lpd::converter::OT_TTemplate>();
	auto T_OT = std::make_unique<filetemplate::lpd::converter::T_OTTemplate>();

	for (const auto& lpd : lpdProject->GetLPDs())
	{
		if (lpd->IsTool())
		{
			E_PT->loc_impl_->Set(E_PT->loc_tool_);
			PT_E->loc_impl_->Set(PT_E->loc_tool_);
			T_OT->loc_impl_->Set(T_OT->loc_tool_);
			OT_T->loc_impl_->Set(OT_T->loc_tool_);
		}
		else // It is main lpd or assume it is
		{
			E_PT->loc_impl_->Set(E_PT->loc_main_);
			PT_E->loc_impl_->Set(PT_E->loc_main_);
			T_OT->loc_impl_->Set(T_OT->loc_main_);
			OT_T->loc_impl_->Set(OT_T->loc_main_);
		}

		if (lpd->Explicit)
		{
			E_PT->explicit_lpd_namespace_->Set(E_PT->explicit_lpd_namespace_dispatch_);
			PT_E->explicit_lpd_namespace_->Set(PT_E->explicit_lpd_namespace_dispatch_);
			T_OT->explicit_lpd_namespace_->Set(T_OT->explicit_lpd_namespace_dispatch_);
			OT_T->explicit_lpd_namespace_->Set(OT_T->explicit_lpd_namespace_dispatch_);
		}
		else
		{
			E_PT->explicit_lpd_namespace_->Set("");
			PT_E->explicit_lpd_namespace_->Set("");
			T_OT->explicit_lpd_namespace_->Set("");
			OT_T->explicit_lpd_namespace_->Set("");
		}

		E_PT->lpd_name_->Set(lpd->GetName());
		PT_E->lpd_name_->Set(lpd->GetName());
		T_OT->lpd_name_->Set(lpd->GetName());
		OT_T->lpd_name_->Set(lpd->GetName());

		for (const auto& ldo : lpd->GetLDOs())
		{
			OT_T->ldo_name_->Set(ldo->GetName());
			T_OT->ldo_name_->Set(ldo->GetName());

			OT_T->ldo_include_->ExpandVariableField();
			OT_T->ldo_implementation_->ExpandVariableField();
			T_OT->ldo_forward_declaration_->ExpandVariableField();
			T_OT->ldo_implementation_->ExpandVariableField();
		}

		E_PT->lpd_include_->ExpandVariableField();
		E_PT->lpd_implementation_->ExpandVariableField();
		PT_E->lpd_forward_declaration_->ExpandVariableField();
		PT_E->lpd_implementation_->ExpandVariableField();
	}

	::deamer::file::tool::Directory converter;
	converter.AddFile(::deamer::file::tool::File("PropertyEnumToType", "h", E_PT->GetOutput()));
	converter.AddFile(::deamer::file::tool::File("PropertyTypeToEnum", "h", PT_E->GetOutput()));
	converter.AddFile(::deamer::file::tool::File("ObjectEnumToType", "h", OT_T->GetOutput()));
	converter.AddFile(::deamer::file::tool::File("ObjectTypeToEnum", "h", T_OT->GetOutput()));
	directory.converter = converter;
}

void DLDL::generate::lpd::Project::GenerateValidater(LPDDirectory& directory) const
{
	auto OEs_PT = std::make_unique<filetemplate::lpd::validater::OEs_PTTemplate>();
	auto PT_OEs = std::make_unique<filetemplate::lpd::validater::PT_OETemplate>();
	OEs_PT->ldo_implementation_->variable_field_separator_->Set("");

	for (auto& lpd : lpdProject->GetLPDs())
	{
		if (lpd->IsTool())
		{
			PT_OEs->loc_impl_->Set(PT_OEs->loc_tool_);
		}
		else // It is main lpd or assume it is
		{
			PT_OEs->loc_impl_->Set(PT_OEs->loc_main_);
		}

		if (lpd->Explicit)
		{
			PT_OEs->explicit_lpd_namespace_->Set(PT_OEs->explicit_lpd_namespace_dispatch_);
		}
		else
		{
			PT_OEs->explicit_lpd_namespace_->Set("");
		}
		PT_OEs->lpd_name_->Set(lpd->GetName());
		for (auto& ldo : lpd->GetLDOs())
		{
			PT_OEs->ldo_name_->Set(ldo->GetName());

			PT_OEs->ldo_forward_declaration_->ExpandVariableField();
			PT_OEs->ldo_implementation_->ExpandVariableField();
		}
		PT_OEs->lpd_forward_declaration_->ExpandVariableField();
	}

	for (auto& lpd : lpdProject->GetLPDs())
	{
		OEs_PT->lpd_name_->Set(lpd->GetName());
		OEs_PT->ldo_implementation_->variable_field_->Clear();

		if (lpd->IsTool())
		{
			OEs_PT->loc_impl_->Set(OEs_PT->loc_tool_);
		}
		else // It is main lpd or assume it is
		{
			OEs_PT->loc_impl_->Set(OEs_PT->loc_main_);
		}

		if (lpd->Explicit)
		{
			OEs_PT->explicit_lpd_namespace_->Set(OEs_PT->explicit_lpd_namespace_dispatch_);
		}
		else
		{
			OEs_PT->explicit_lpd_namespace_->Set("");
		}
		bool first = true;
		for (auto& ldo : lpd->GetLDOs())
		{
			if (first)
			{
				OEs_PT->optional_comma_extension_->Set("");
				first = false;
			}
			else
			{
				OEs_PT->optional_comma_extension_->Set(OEs_PT->comma_extension_);
			}
			OEs_PT->ldo_name_->Set(ldo->GetName());
			OEs_PT->ldo_implementation_->ExpandVariableField();
		}
		OEs_PT->lpd_include_->ExpandVariableField();
		OEs_PT->lpd_implementation_->ExpandVariableField();
	}

	::deamer::file::tool::Directory validatorDirectory;
	validatorDirectory.AddFile(
		::deamer::file::tool::File("GetObjectEnumsFromPropertyType", "h", OEs_PT->GetOutput()));
	validatorDirectory.AddFile(
		::deamer::file::tool::File("GetPropertyTypeFromObjectType", "h", PT_OEs->GetOutput()));
	directory.validater = validatorDirectory;
}

void DLDL::generate::lpd::Project::GenerateGenerater(LPDDirectory& directory) const
{
	auto Default = std::make_unique<filetemplate::lpd::generater::DefaultTemplate>();
	::deamer::file::tool::Directory generaterMainDirectory;
	::deamer::file::tool::Directory generaterToolDirectory;
	Default->lpd_ctor_member_->variable_field_separator_->Set("");

	for (auto& lpd : lpdProject->GetLPDs())
	{
		Default->lpd_ctor_member_->variable_field_->Clear();
		Default->lpd_retrieve_ctor_member_->variable_field_->Clear();
		Default->lpd_name_->Set(lpd->GetName());

		bool first = true;
		for (auto& member : lpd->GetLpdMembers())
		{
			if (first)
			{
				Default->optional_comma_extension_->Set("");
				first = false;
			}
			else
			{
				Default->optional_comma_extension_->Set(Default->comma_extension_);
			}
			Default->ldo_name_->Set(member.type);
			Default->member_name_->Set(member.name);

			const auto ldoMemberPtr = GetLDOfromString(member, lpd);
			if (ldoMemberPtr != nullptr && ldoMemberPtr->GetLPD() != nullptr &&
				ldoMemberPtr->GetLPD()->IsTool())
			{
				Default->loc_impl_->Set(Default->loc_tool_);
			}
			else // It is main lpd or assume it is
			{
				Default->loc_impl_->Set(Default->loc_main_);
			}

			if (ldoMemberPtr != nullptr && ldoMemberPtr->GetLPD() != nullptr &&
				ldoMemberPtr->GetLPD()->Explicit)
			{
				Default->explicit_lpd_namespace_->Set(Default->explicit_lpd_namespace_dispatch_);
			}
			else
			{
				Default->explicit_lpd_namespace_->Set("");
			}

			Default->lpd_ctor_member_->ExpandVariableField();
			Default->lpd_retrieve_ctor_member_->ExpandVariableField();
		}

		if (lpd->IsTool())
		{
			generaterToolDirectory.AddFile(
				::deamer::file::tool::File(lpd->GetName(), "h", Default->GetOutput()));
		}
		else
		{
			generaterMainDirectory.AddFile(
				::deamer::file::tool::File(lpd->GetName(), "h", Default->GetOutput()));
		}
	}

	directory.generater = generaterMainDirectory;
	directory.generaterTool = generaterToolDirectory;
}

void DLDL::generate::lpd::Project::GenerateEnumerations(LPDDirectory& directory) const
{
	auto LDO = std::make_unique<filetemplate::lpd::enumeration::LDOTemplate>();
	auto LPD = std::make_unique<filetemplate::lpd::enumeration::LPDTemplate>();

	for (auto& lpd : lpdProject->GetLPDs())
	{
		LDO->lpd_ldo_member_->variable_field_->Clear();

		LDO->lpd_name_->Set(lpd->GetName());

		for (auto& ldo : lpd->GetLDOs())
		{
			LDO->ldo_name_->Set(ldo->GetName());
			LDO->lpd_ldo_member_->ExpandVariableField();
		}
		LDO->ldo_group_->ExpandVariableField();
	}

	for (auto& lpd : lpdProject->GetLPDs())
	{
		LPD->lpd_name_->Set(lpd->GetName());

		LPD->lpd_implementation_->ExpandVariableField();
	}

	::deamer::file::tool::Directory enumerationsLDO;
	::deamer::file::tool::Directory enumerationsLPD;
	enumerationsLDO.AddFile(::deamer::file::tool::File("Type", "h", LDO->GetOutput()));
	enumerationsLPD.AddFile(::deamer::file::tool::File("Type", "h", LPD->GetOutput()));

	directory.ldoEnumeration = enumerationsLDO;
	directory.lpdEnumeration = enumerationsLPD;
}

DLDL::ir::LDO*
DLDL::generate::lpd::Project::GetLDOfromString(const ir::DataMember& value,
											   const std::unique_ptr<ir::LpdDef>& lpd) const
{
	std::cout << "LPD : " << lpd->GetName() << "\n";
	for (auto& ldo : lpd->GetLDOs())
	{
		std::cout << "ldo: " << ldo->GetName() << " Request: " << value.type << "\n";
		if (ldo->GetName() == value.type)
		{
			return ldo.get();
		}
	}

	for (auto& dependency : lpd->GetDependencies())
	{
		for (auto& lpd_ : lpdProject->GetLPDs())
		{
			if (lpd_->GetName() == dependency.Lpd)
			{
				for (auto& ldo : lpd_->GetLDOs())
				{
					std::cout << "ldo: " << ldo->GetName() << " Request: " << value.type << "\n";
					if (ldo->GetName() == value.type)
					{
						return ldo.get();
					}
				}
			}
		}
	}

	return nullptr;
}

std::string DLDL::generate::lpd::Project::GetLPDFromLDO(const std::unique_ptr<ir::LpdDef>& lpd,
														ir::DataMember lpdMember,
														ir::LDO*& ldo) const
{
	std::string target_lpd;
	ldo = lpd->GetLDOFromString(lpdMember.type);
	if (!lpdMember.explicitLPD.empty())
	{
		std::cout << "Explicit lpd: " << target_lpd << "\n";
		target_lpd = lpdMember.explicitLPD;
	}

	if (ldo == nullptr)
	{
		for (auto dependency : lpd->GetDependencies())
		{
			for (auto& dependencyLpd : lpdProject->GetLPDs())
			{
				if (dependencyLpd->GetName() == dependency.Lpd)
				{
					auto ldo = dependencyLpd->GetLDOFromString(lpdMember.type);
					target_lpd = dependencyLpd->GetName();
					std::cout << "Dependent lpd: " << target_lpd << "\n";
					if (ldo != nullptr)
					{
						break;
					}
				}
			}
			if (ldo != nullptr)
			{
				break;
			}
		}
		target_lpd = lpd->GetName();
	}
	else
	{
		std::cout << "This lpd: " << target_lpd << "\n";
		target_lpd = lpd->GetName();
	}

	if (ldo == nullptr)
	{
		throw std::logic_error("Referenced unknown LDO: " + lpdMember.explicitLPD + ":" +
							   lpdMember.type);
	}

	return target_lpd;
}

DLDL::ir::LpdDef* DLDL::generate::lpd::Project::GetLPDfromString(const std::string& lpdStr) const
{
	for (auto& lpd : lpdProject->GetLPDs())
	{
		if (lpd->GetName() == lpdStr)
		{
			return lpd.get();
		}
	}

	return nullptr;
}
