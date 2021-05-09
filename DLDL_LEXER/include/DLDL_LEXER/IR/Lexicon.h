#ifndef DLDL_LEXER_IR_LEXICON_H
#define DLDL_LEXER_IR_LEXICON_H

#include "DLDL/IR/IR.h"
#include <Deamer/Language/Type/Definition/Object/Main/Lexicon/Terminal.h>
#include <Deamer/Language/Type/Definition/Property/Main/Lexicon.h>
#include <string>
#include <vector>


namespace DLDL::ir
{
	class Lexicon : public DLDL::ir::IR
	{
	private:
		std::vector<deamer::language::type::definition::object::main::Terminal> terminals;

	public:
		Lexicon() : IR(Type::Lexicon)
		{
		}

	public:
		void AddTerminal(
			const std::string& name, const std::string& regex,
			const deamer::language::type::definition::object::main::SpecialType& abstraction =
				deamer::language::type::definition::object::main::SpecialType::Standard)
		{
			terminals.emplace_back(name, regex, abstraction);
		}

		std::vector<deamer::language::type::definition::object::main::Terminal> GetTerminals() const
		{
			return terminals;
		}
	};
}

#endif // DLDL_LEXER_IR_LEXICON_H
