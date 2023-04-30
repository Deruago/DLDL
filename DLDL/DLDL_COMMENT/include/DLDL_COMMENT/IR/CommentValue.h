#ifndef DLDL_COMMENT_IR_COMMENTVALUE_H
#define DLDL_COMMENT_IR_COMMENTVALUE_H

#include <optional>
#include <string>

namespace DLDL::ir
{
	struct CommentValue
	{
		std::string syntacticReference;
		std::optional<std::string> startPattern;
		std::optional<std::string> endPattern;

		void AssignStartPattern(std::string cs)
		{
			if (cs.size() <= 2)
			{
				return;
			}

			cs.erase(0, 1);
			cs.pop_back();
			startPattern = cs;
		}

		void AssignEndPattern(std::string cs)
		{
			if (cs.size() <= 2)
			{
				return;
			}

			cs.erase(0, 1);
			cs.pop_back();
			endPattern = cs;
		}
	};
}

#endif // DLDL_COMMENT_IR_COMMENTVALUE_H
