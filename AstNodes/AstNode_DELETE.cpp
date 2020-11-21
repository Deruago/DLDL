#include "AstNode_DELETE.h"
#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include <vector>
#include <Deamer/AstGen/AstVisitor.h>
DLDL::AstNode_DELETE::AstNode_DELETE(bool isNode, std::string astNodeName) : AstNode_ABSTRACTION(true, "DELETE")

{
}

DLDL::AstNode_DELETE::AstNode_DELETE(deamer::AstInformation* astInformation) : AstNode_ABSTRACTION(astInformation)

{
}

DLDL::AstNode_DELETE::AstNode_DELETE(std::vector<deamer::AstNode*> astNodes) : AstNode_ABSTRACTION(astNodes)

{
}

unsigned int DLDL::AstNode_DELETE::GetAstId()
{
    return (unsigned int)DLDL::AstNode_DELETE::AstType;
}

void DLDL::AstNode_DELETE::Accept(deamer::AstVisitor& ast_visitor)
{
    ast_visitor.Dispatch(*this);
}


