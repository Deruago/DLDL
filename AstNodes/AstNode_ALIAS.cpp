#include "AstNode_ALIAS.h"
#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include <vector>
#include <Deamer/AstGen/AstVisitor.h>
DLDL::AstNode_ALIAS::AstNode_ALIAS(bool isNode, std::string astNodeName) : AstNode_ABSTRACTION(true, "ALIAS")

{
}

DLDL::AstNode_ALIAS::AstNode_ALIAS(deamer::AstInformation* astInformation) : AstNode_ABSTRACTION(astInformation)

{
}

DLDL::AstNode_ALIAS::AstNode_ALIAS(std::vector<deamer::AstNode*> astNodes) : AstNode_ABSTRACTION(astNodes)

{
}

unsigned int DLDL::AstNode_ALIAS::GetAstId()
{
    return (unsigned int)DLDL::AstNode_ALIAS::AstType;
}

void DLDL::AstNode_ALIAS::Accept(deamer::AstVisitor& ast_visitor)
{
    ast_visitor.Dispatch(*this);
}


