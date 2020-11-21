#include "AstNode_UNIQUE.h"
#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include <vector>
#include <Deamer/AstGen/AstVisitor.h>
DLDL::AstNode_UNIQUE::AstNode_UNIQUE(bool isNode, std::string astNodeName) : AstNode_ABSTRACTION(true, "UNIQUE")

{
}

DLDL::AstNode_UNIQUE::AstNode_UNIQUE(deamer::AstInformation* astInformation) : AstNode_ABSTRACTION(astInformation)

{
}

DLDL::AstNode_UNIQUE::AstNode_UNIQUE(std::vector<deamer::AstNode*> astNodes) : AstNode_ABSTRACTION(astNodes)

{
}

unsigned int DLDL::AstNode_UNIQUE::GetAstId()
{
    return (unsigned int)DLDL::AstNode_UNIQUE::AstType;
}

void DLDL::AstNode_UNIQUE::Accept(deamer::AstVisitor& ast_visitor)
{
    ast_visitor.Dispatch(*this);
}


