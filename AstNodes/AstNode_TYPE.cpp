#include "AstNode_TYPE.h"
#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include <vector>
#include <Deamer/AstGen/AstVisitor.h>
DLDL::AstNode_TYPE::AstNode_TYPE(bool isNode, std::string astNodeName) : AstNode_ABSTRACTION(true, "TYPE")

{
}

DLDL::AstNode_TYPE::AstNode_TYPE(deamer::AstInformation* astInformation) : AstNode_ABSTRACTION(astInformation)

{
}

DLDL::AstNode_TYPE::AstNode_TYPE(std::vector<deamer::AstNode*> astNodes) : AstNode_ABSTRACTION(astNodes)

{
}

unsigned int DLDL::AstNode_TYPE::GetAstId()
{
    return (unsigned int)DLDL::AstNode_TYPE::AstType;
}

void DLDL::AstNode_TYPE::Accept(deamer::AstVisitor& ast_visitor)
{
    ast_visitor.Dispatch(*this);
}


