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

		return Type::Unknown;
	}
}

#endif // DLDL_IR_TYPE_H
