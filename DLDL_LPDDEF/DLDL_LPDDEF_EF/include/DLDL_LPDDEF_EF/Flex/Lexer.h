#ifndef DLDL_LPDDEF_EF_FLEX_LEXER_H
#define DLDL_LPDDEF_EF_FLEX_LEXER_H

#include <Deamer/External/Cpp/Lexer/Interface/Lexer.h>

namespace DLDL_LPDDEF_EF { namespace lexer {

	class Lexer : public deamer::external::cpp::lexer::Lexer
	{
	public:
		Lexer() = default;
		~Lexer() override = default;
	public:
		std::vector<const deamer::external::cpp::lexer::TerminalObject*> Tokenize(const std::string& text) const override;
	};

}}

#endif // DLDL_LPDDEF_EF_FLEX_LEXER_H
