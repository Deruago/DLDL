#ifndef DLDL_LEXER_FLEX_LEXER_H
#define DLDL_LEXER_FLEX_LEXER_H

#include <Deamer/External/Cpp/Lexer/Interface/Lexer.h>

namespace DLDL_LEXER { namespace lexer {

	class Lexer : public deamer::external::cpp::lexer::Lexer
	{
	public:
		Lexer() = default;
		~Lexer() override = default;
	public:
		std::vector<const deamer::external::cpp::lexer::TerminalObject*> Tokenize(const std::string& text) const override;
	};

}}

#endif // DLDL_LEXER_FLEX_LEXER_H
