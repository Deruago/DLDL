#include "AstNode_GROUP.h"
#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include <vector>
#include <Deamer/AstGen/AstVisitor.h>
DLDL::AstNode_GROUP::AstNode_GROUP(bool isNode, std::string astNodeName) : AstNode_ABSTRACTION(true, "GROUP")

{
}

DLDL::AstNode_GROUP::AstNode_GROUP(deamer::AstInformation* astInformation) : AstNode_ABSTRACTION(astInformation)

{
}

DLDL::AstNode_GROUP::AstNode_GROUP(std::vector<deamer::AstNode*> astNodes) : AstNode_ABSTRACTION(astNodes)

{
}

unsigned int DLDL::AstNode_GROUP::GetAstId()
{
    return (unsigned int)DLDL::AstNode_GROUP::AstType;
}

void DLDL::AstNode_GROUP::Accept(deamer::AstVisitor& ast_visitor)
{
    ast_visitor.Dispatch(*this);
}


