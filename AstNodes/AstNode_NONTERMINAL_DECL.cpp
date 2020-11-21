#include "AstNode_NONTERMINAL_DECL.h"
#include "AstNode_VARNAME.h"
#include "AstNode_NONTERMINAL_BLOCK.h"
#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include <vector>
#include <Deamer/AstGen/AstVisitor.h>
DLDL::AstNode_NONTERMINAL_DECL::AstNode_NONTERMINAL_DECL(bool isNode, std::string astNodeName) : AstNode_STMT(false, "NONTERMINAL_DECL")

{
}

DLDL::AstNode_NONTERMINAL_DECL::AstNode_NONTERMINAL_DECL(deamer::AstInformation* astInformation) : AstNode_STMT(astInformation)

{
}

DLDL::AstNode_NONTERMINAL_DECL::AstNode_NONTERMINAL_DECL(std::vector<deamer::AstNode*> astNodes) : AstNode_STMT(astNodes)

{
}

DLDL::AstNode_NONTERMINAL_DECL::AstNode_NONTERMINAL_DECL(AstNode_VARNAME* VARNAME1, AstNode_NONTERMINAL_BLOCK* NONTERMINAL_BLOCK1) : AstNode_STMT(false, "NONTERMINAL_DECL")

{
    VARNAME1_ = VARNAME1;
    NONTERMINAL_BLOCK1_ = NONTERMINAL_BLOCK1;
}

unsigned int DLDL::AstNode_NONTERMINAL_DECL::GetAstId()
{
    return (unsigned int)DLDL::AstNode_NONTERMINAL_DECL::AstType;
}

void DLDL::AstNode_NONTERMINAL_DECL::Accept(deamer::AstVisitor& ast_visitor)
{
    ast_visitor.Dispatch(*this);
}


