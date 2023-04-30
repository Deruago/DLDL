#ifndef DLDL_LPDDEF_EF_AST_LISTENER_USER_LPDDEF_H
#define DLDL_LPDDEF_EF_AST_LISTENER_USER_LPDDEF_H

#include "DLDL_LPDDEF/IR/LPDDEF.h"
#include "DLDL_LPDDEF_EF/Ast/Listener/EnterExitListener.h"
#include "DLDL_LPDDEF_EF/Ast/Reference/Access.h"

namespace DLDL_LPDDEF_EF::ast::listener::user
{
	class LpdDefEf : public ::DLDL_LPDDEF_EF::ast::listener::EnterExitListener
	{
	private:
		std::vector<DLDL::ir::DataMember> dataMembers;
		std::string currentComment;

	public:
		LpdDefEf()
		{
		}
		~LpdDefEf() override = default;

	public:
		void ListenEntry(const DLDL_LPDDEF_EF::ast::node::standard_variant* node) override
		{
			DLDL::ir::DataMember newMember;
			newMember.comments = currentComment;
			newMember.name = reference::Access(node).enum_name().GetContent()[0]->GetText();
			dataMembers.push_back(newMember);
			currentComment.clear();
		}

		void ListenEntry(
			const DLDL_LPDDEF_EF::ast::node::standard_variant_specific_number* node) override
		{
			DLDL::ir::DataMember newMember;
			newMember.comments = currentComment;
			newMember.name = reference::Access(node).enum_name().GetContent()[0]->GetText();
			newMember.defaultValue = reference::Access(node).value().GetContent()[0]->GetText();
			dataMembers.push_back(newMember);
			currentComment.clear();
		}

		void ListenEntry(const DLDL_LPDDEF_EF::ast::node::comment_line* node) override
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

#endif // DLDL_LPDDEF_EF_AST_LISTENER_USER_LPDDEF_H
