#include "AstNode_START.h"
#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include <vector>
#include <Deamer/AstGen/AstVisitor.h>
DLDL::AstNode_START::AstNode_START(bool isNode, std::string astNodeName) : AstNode_ABSTRACTION(true, "START")

{
}

DLDL::AstNode_START::AstNode_START(deamer::AstInformation* astInformation) : AstNode_ABSTRACTION(astInformation)

{
}

DLDL::AstNode_START::AstNode_START(std::vector<deamer::AstNode*> astNodes) : AstNode_ABSTRACTION(astNodes)

{
}

unsigned int DLDL::AstNode_START::GetAstId()
{
    return (unsigned int)DLDL::AstNode_START::AstType;
}

void DLDL::AstNode_START::Accept(deamer::AstVisitor& ast_visitor)
{
    ast_visitor.Dispatch(*this);
}


