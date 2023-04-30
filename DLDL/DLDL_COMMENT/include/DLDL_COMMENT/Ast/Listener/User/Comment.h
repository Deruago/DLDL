#ifndef DLDL_COMMENT_AST_LISTENER_USER_COMMENT_H
#define DLDL_COMMENT_AST_LISTENER_USER_COMMENT_H

#include "DLDL_COMMENT/Ast/Listener/EnterExitListener.h"
#include "DLDL_COMMENT/Ast/Reference/Access.h"
#include "DLDL_COMMENT/IR/Comment.h"

namespace DLDL_COMMENT::ast::listener::user
{
	class Comment : public ::DLDL_COMMENT::ast::listener::EnterExitListener
	{
	private:
		DLDL::ir::Comment* CommentLpd;

	public:
		Comment()
		{
			CommentLpd = new ::DLDL::ir::Comment();
		}
		~Comment() override = default;

	public:
		void ListenEntry(const DLDL_COMMENT::ast::node::comment_value_declaration* node) override
		{
			auto access = reference::Access(node);
			DLDL::ir::CommentValue commentValue;
			commentValue.syntacticReference =
				access.syntactic_reference().GetContent()[0]->GetText();
			access.comment_abstraction().for_all(
				[&](reference::Access<node::comment_abstraction> und) {
					if (!und.start_abstraction().GetContent().empty())
					{
						commentValue.AssignStartPattern(und.start_abstraction()
															.start_sequence()
															.sequence()
															.TEXT()
															.GetContent()[0]
															->GetText());
					}
					else if (!und.end_abstraction().GetContent().empty())
					{
						commentValue.AssignEndPattern(und.end_abstraction()
														  .end_sequence()
														  .sequence()
														  .TEXT()
														  .GetContent()[0]
														  ->GetText());
					}
				});
			CommentLpd->AddCommentValue(commentValue);
		}

	public:
		DLDL::ir::Comment* GetComment()
		{
			return CommentLpd;
		}
	};
}

#endif // DLDL_COMMENT_AST_LISTENER_USER_COMMENT_H
