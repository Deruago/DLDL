#ifndef ASTNODES_ASTENUM_H
#define ASTNODES_ASTENUM_H

namespace DLDL
{
    typedef enum AstEnum_s
    {
        PROG,
        STMTS,
        STMT,
        ABSTRACTION,
        TERMINALS,
        TERMINAL_DECL,
        NONTERMINAL_DECL,
        ABSTRACTION_DECL,
        RULE_DECL,
        TERMINAL_BLOCK,
        NONTERMINAL_BLOCK,
        RULES,
        ABSTRACTION_BLOCK,
        ABSTRACTION_INPUTS,
        ABSTRACTION_INPUT,
        GENERAL_BLOCK,
        VARLIST,
        DELETE,
        IGNORE,
        TERMINAL,
        NONTERMINAL,
        GROUP,
        ALIAS,
        START,
        COMMENT,
        UNIQUE,
        TYPE,
        VARNAME,
    } AstEnum_t;
}

#endif //ASTNODES_ASTENUM_H
