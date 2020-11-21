#ifndef ASTNODES_ASTVISITOR_ASTPRINTER_H

/* This is an system generated AstPrinter. We recommend not changing code in this file
   If you have improvements, make an pull request.
   If you have suggestions, make an issue or contact a developer or maintainer.
*/

#define ASTNODES_ASTVISITOR_ASTPRINTER_H

#include <Deamer/AstGen/AstVisitor.h>

namespace DLDL
{
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

    class DLDL_AstPrinter : public deamer::AstVisitor
    {
    private:
        unsigned depth = 0;
        unsigned indent_size = 4;
        std::string MakeIndentation();
        std::string MakeIndent();
    protected:
    public:
        DLDL_AstPrinter() = default;
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
#endif //ASTNODES_ASTVISITOR_ASTPRINTER_H

