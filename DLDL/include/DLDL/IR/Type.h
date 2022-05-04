#ifndef DLDL_IR_TYPE_H
#define DLDL_IR_TYPE_H

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
}

#endif // DLDL_IR_TYPE_H
