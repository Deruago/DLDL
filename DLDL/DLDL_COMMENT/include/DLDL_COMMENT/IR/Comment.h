#ifndef DLDL_COMMENT_IR_COMMENT_H
#define DLDL_COMMENT_IR_COMMENT_H

#include "DLDL/IR/IR.h"
#include "DLDL_COMMENT/IR/CommentValue.h"
#include <deque>
#include <memory>
#include <optional>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace DLDL::ir
{
	class Comment : public DLDL::ir::IR
	{
	private:
		std::vector<CommentValue> commentValues;

	public:
		Comment();
		virtual ~Comment() = default;

	public:
		std::vector<CommentValue> GetCommentValues() const;
		void AddCommentValue(const CommentValue& newCommentValue);
	};
}

#endif // DLDL_COMMENT_IR_COMMENT_H
