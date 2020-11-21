#include "AstNode_NONTERMINAL.h"
#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include <vector>
#include <Deamer/AstGen/AstVisitor.h>
DLDL::AstNode_NONTERMINAL::AstNode_NONTERMINAL(bool isNode, std::string astNodeName) : AstNode_ABSTRACTION(true, "NONTERMINAL")

{
}

DLDL::AstNode_NONTERMINAL::AstNode_NONTERMINAL(deamer::AstInformation* astInformation) : AstNode_ABSTRACTION(astInformation)

{
}

DLDL::AstNode_NONTERMINAL::AstNode_NONTERMINAL(std::vector<deamer::AstNode*> astNodes) : AstNode_ABSTRACTION(astNodes)

{
}

unsigned int DLDL::AstNode_NONTERMINAL::GetAstId()
{
    return (unsigned int)DLDL::AstNode_NONTERMINAL::AstType;
}

void DLDL::AstNode_NONTERMINAL::Accept(deamer::AstVisitor& ast_visitor)
{
    ast_visitor.Dispatch(*this);
}


