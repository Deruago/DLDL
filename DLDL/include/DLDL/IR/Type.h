#ifndef DLDL_IR_TYPE_H
#define DLDL_IR_TYPE_H

#include <string>

namespace DLDL::ir
{
	enum class Type
	{
		Unknown = 0,

		Lexicon,
		Grammar,
		Precedence,
		Associativity,

		Generation,
		Identity,

		AstOptimization,
		AstTranslation,

		Coloring,
		Formatting,
		Documentation,
		Threat,

		LpdDef,
		LpdStruct,
		LdoStruct,

		ToolDef,
		ToolStruct,

		OopSyntax,

		Argument,
		Comment,
		Import,
		Value,

		// Lexer/Parser Generator definition import
		Antlr,
	};

	static Type GetLpdType(const std::string& text)
	{
		if (text == "lexicon")
		{
			return Type::Lexicon;
		}
		if (text == "grammar")
		{
			return Type::Grammar;
		}
		if (text == "associativity")
		{
			return Type::Associativity;
		}
		if (text == "precedence")
		{
			return Type::Precedence;
		}
		if (text == "generation")
		{
			return Type::Generation;
		}
		if (text == "identity")
		{
			return Type::Identity;
		}
		if (text == "oopsyntax")
		{
			return Type::OopSyntax;
		}
		if (text == "argument")
		{
			return Type::Argument;
		}
		if (text == "comment")
		{
			return Type::Comment;
		}
		if (text == "import")
		{
			return Type::Import;
		}
		if (text == "value")
		{
			return Type::Value;
		}
		if (text == "formatting")
		{
			return Type::Formatting;
		}
		if (text == "antlr")
		{
			return Type::Antlr;
		}

		return Type::Unknown;
	}
}

#endif // DLDL_IR_TYPE_H
