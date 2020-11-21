#ifndef ASTNODES_ASTVISITOR_ASTVISITOR_H
#define ASTNODES_ASTVISITOR_ASTVISITOR_H

#include <Deamer/AstGen/AstVisitor.h>
#include "IR/Abstraction_Terminal.h"
#include "IR/Abstraction_NonTerminal.h"
#include "IR/Abstraction_Group.h"
#include "IR/Abstraction_Delete.h"
#include "IR/Abstraction_Ignore.h"
#include "IR/Abstraction_Start.h"
#include "IR/Abstraction_Alias.h"
#include "IR/Abstraction_Unique.h"
#include "IR/TerminalSymbol.h"
#include "IR/NonTerminalSymbol.h"
#include "IR/ProductionRule.h"
#include <vector>

namespace DLDL
{
	enum class ABSTRACTION_TYPE
	{
		TERMINAL,
		NON_TERMINAL,
		DELETE,
		IGNORE,
		GROUP,
		START,
		ALIAS,
		UNIQUE,
		DEFAULT = -1,
	};
	
    class AstTree_PROG;
    class AstNode_STMTS;
    class AstNode_STMT;
    class AstNode_ABSTRACTION;
    class AstNode_TERMINALS;
    class AstNode_TERMINAL_DECL;
    class AstNode_NONTERMINAL_DECL;
    class AstNode_ABSTRACTION_DECL;
    class AstNode_RULE_DECL;
    class AstNode_TERMINAL_BLOCK;
    class AstNode_NONTERMINAL_BLOCK;
    class AstNode_RULES;
    class AstNode_ABSTRACTION_BLOCK;
    class AstNode_ABSTRACTION_INPUTS;
    class AstNode_ABSTRACTION_INPUT;
    class AstNode_GENERAL_BLOCK;
    class AstNode_VARLIST;
    class AstNode_DELETE;
    class AstNode_IGNORE;
    class AstNode_TERMINAL;
    class AstNode_NONTERMINAL;
    class AstNode_GROUP;
    class AstNode_ALIAS;
    class AstNode_START;
    class AstNode_COMMENT;
    class AstNode_UNIQUE;
    class AstNode_TYPE;
    class AstNode_VARNAME;

    class DLDL_AstVisitor : public deamer::AstVisitor
    {
    private:
    protected:
    public:
		std::vector<Symbol*> Symbols_;
		std::vector<TerminalSymbol> TerminalSymbols_;
		std::vector<NonTerminalSymbol> NonTerminalSymbols_;
		std::vector<AbstractionSymbol*> AbstractedSymbols_;
		std::vector<ProductionRule> current_production_rules;
		ABSTRACTION_TYPE current_abstraction_val;
		bool EncounteredStartType = false;

        DLDL_AstVisitor() = default;
        void Dispatch(deamer::AstNode& ast_node) override;

        void Visit(AstTree_PROG& ast_node);
        void Visit(AstNode_STMTS& ast_node);
        void Visit(AstNode_STMT& ast_node);
        void Visit(AstNode_ABSTRACTION& ast_node);
        void Visit(AstNode_TERMINALS& ast_node);
        void Visit(AstNode_TERMINAL_DECL& ast_node);
        void Visit(AstNode_NONTERMINAL_DECL& ast_node);
        void Visit(AstNode_ABSTRACTION_DECL& ast_node);
        void Visit(AstNode_RULE_DECL& ast_node);
        void Visit(AstNode_TERMINAL_BLOCK& ast_node);
        void Visit(AstNode_NONTERMINAL_BLOCK& ast_node);
        void Visit(AstNode_RULES& ast_node);
        void Visit(AstNode_ABSTRACTION_BLOCK& ast_node);
        void Visit(AstNode_ABSTRACTION_INPUTS& ast_node);
        void Visit(AstNode_ABSTRACTION_INPUT& ast_node);
        void Visit(AstNode_GENERAL_BLOCK& ast_node);
        void Visit(AstNode_VARLIST& ast_node);
        void Visit(AstNode_DELETE& ast_node);
        void Visit(AstNode_IGNORE& ast_node);
        void Visit(AstNode_TERMINAL& ast_node);
        void Visit(AstNode_NONTERMINAL& ast_node);
        void Visit(AstNode_GROUP& ast_node);
        void Visit(AstNode_ALIAS& ast_node);
        void Visit(AstNode_START& ast_node);
        void Visit(AstNode_COMMENT& ast_node);
        void Visit(AstNode_UNIQUE& ast_node);
        void Visit(AstNode_TYPE& ast_node);
        void Visit(AstNode_VARNAME& ast_node);
    };
}
#endif //ASTNODES_ASTVISITOR_ASTVISITOR_H

