#ifndef DLDL_LPDDEF_DF_AST_LISTENER_USER_LPDDEF_H
#define DLDL_LPDDEF_DF_AST_LISTENER_USER_LPDDEF_H

#include "DLDL_LPDDEF/IR/LPDDEF.h"
#include "DLDL_LPDDEF_DF/Ast/Listener/EnterExitListener.h"
#include "DLDL_LPDDEF_DF/Ast/Reference/Access.h"

namespace DLDL_LPDDEF_DF::ast::listener::user
{
	class LpdDefDf : public ::DLDL_LPDDEF_DF::ast::listener::EnterExitListener
	{
	private:
		std::vector<DLDL::ir::DataMember> dataMembers;
		std::string currentComment;

	public:
		LpdDefDf()
		{
		}
		~LpdDefDf() override = default;

	public:
		void ListenEntry(const DLDL_LPDDEF_DF::ast::node::standard_variant* node) override
		{
			DLDL::ir::DataMember newMember;
			newMember.comments = currentComment;
			auto type_ = reference::Access(node).var_type().VARNAME().GetContent();
			if (type_.size() == 2)
			{
				newMember.explicitLPD = type_[0]->GetText();
				newMember.type = type_[1]->GetText();
			}
			else if (type_.size() == 1)
			{
				newMember.type = type_[0]->GetText();
			}
			else
			{
				std::cout << "Error!\n";
				// unsupported
			}
			newMember.name = reference::Access(node).var_name().GetContent()[0]->GetText();
			if (!reference::Access(node).value_part().value().GetContent().empty())
			{
				newMember.defaultValue =
					reference::Access(node).value_part().value().GetContent()[0]->GetText();
			}
			dataMembers.push_back(newMember);
			currentComment.clear();
		}

		void ListenEntry(const DLDL_LPDDEF_DF::ast::node::vector_variant* node) override
		{
			DLDL::ir::DataMember newMember;
			newMember.comments = currentComment;
			auto type_ = reference::Access(node).var_type().VARNAME().GetContent();
			if (type_.size() == 2)
			{
				newMember.explicitLPD = type_[0]->GetText();
				newMember.type = type_[1]->GetText();
			}
			else if (type_.size() == 1)
			{
				newMember.type = type_[0]->GetText();
			}
			else
			{
				std::cout << "Error!\n";
				// unsupported
			}
			newMember.name = reference::Access(node).var_name().GetContent()[0]->GetText();
			if (!reference::Access(node).value_part().value().GetContent().empty())
			{
				newMember.defaultValue =
					reference::Access(node).value_part().value().GetContent()[0]->GetText();
			}
			newMember.variadic = true;
			dataMembers.push_back(newMember);
			currentComment.clear();
		}

		void ListenEntry(const DLDL_LPDDEF_DF::ast::node::optional_variant* node) override
		{
			DLDL::ir::DataMember newMember;
			newMember.comments = currentComment;
			auto type_ = reference::Access(node).var_type().VARNAME().GetContent();
			if (type_.size() == 2)
			{
				newMember.explicitLPD = type_[0]->GetText();
				newMember.type = type_[1]->GetText();
			}
			else if (type_.size() == 1)
			{
				newMember.type = type_[0]->GetText();
			}
			else
			{
				std::cout << "Error!\n";
				// unsupported
			}
			newMember.name = reference::Access(node).var_name().GetContent()[0]->GetText();
			if (!reference::Access(node).value_part().value().GetContent().empty())
			{
				newMember.defaultValue =
					reference::Access(node).value_part().value().GetContent()[0]->GetText();
			}
			newMember.optional = true;
			dataMembers.push_back(newMember);
			currentComment.clear();
		}

		void ListenEntry(const DLDL_LPDDEF_DF::ast::node::comment_line* node) override
		{
			// Remove "/ " and append to currentComment;
			const auto iter = node->GetText().find(' ');
			if (iter == std::string::npos)
			{
				currentComment += node->GetText();
			}
			else
			{
				currentComment += node->GetText().erase(0, iter);
			}
		}

	public:
		std::vector<DLDL::ir::DataMember> GetDataMembers()
		{
			return dataMembers;
		}
	};
}

#endif // DLDL_LPDDEF_DF_AST_LISTENER_USER_LPDDEF_H
