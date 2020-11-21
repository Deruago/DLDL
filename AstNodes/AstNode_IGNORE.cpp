#include "AstNode_IGNORE.h"
#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include <vector>
#include <Deamer/AstGen/AstVisitor.h>
DLDL::AstNode_IGNORE::AstNode_IGNORE(bool isNode, std::string astNodeName) : AstNode_ABSTRACTION(true, "IGNORE")

{
}

DLDL::AstNode_IGNORE::AstNode_IGNORE(deamer::AstInformation* astInformation) : AstNode_ABSTRACTION(astInformation)

{
}

DLDL::AstNode_IGNORE::AstNode_IGNORE(std::vector<deamer::AstNode*> astNodes) : AstNode_ABSTRACTION(astNodes)

{
}

unsigned int DLDL::AstNode_IGNORE::GetAstId()
{
    return (unsigned int)DLDL::AstNode_IGNORE::AstType;
}

void DLDL::AstNode_IGNORE::Accept(deamer::AstVisitor& ast_visitor)
{
    ast_visitor.Dispatch(*this);
}


