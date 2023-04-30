#include "DLDL_COMMENT/IR/Comment.h"

DLDL::ir::Comment::Comment() : IR(Type::Comment)
{
}

std::vector<DLDL::ir::CommentValue> DLDL::ir::Comment::GetCommentValues() const
{
	return commentValues;
}

void DLDL::ir::Comment::AddCommentValue(const CommentValue& newCommentValue)
{
	commentValues.push_back(newCommentValue);
}
