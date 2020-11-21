#include "AstNode_COMMENT.h"
#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include <vector>
#include <Deamer/AstGen/AstVisitor.h>
DLDL::AstNode_COMMENT::AstNode_COMMENT(bool isNode, std::string astNodeName) : AstNode_ABSTRACTION(true, "COMMENT")

{
}

DLDL::AstNode_COMMENT::AstNode_COMMENT(deamer::AstInformation* astInformation) : AstNode_ABSTRACTION(astInformation)

{
}

DLDL::AstNode_COMMENT::AstNode_COMMENT(std::vector<deamer::AstNode*> astNodes) : AstNode_ABSTRACTION(astNodes)

{
}

unsigned int DLDL::AstNode_COMMENT::GetAstId()
{
    return (unsigned int)DLDL::AstNode_COMMENT::AstType;
}

void DLDL::AstNode_COMMENT::Accept(deamer::AstVisitor& ast_visitor)
{
    ast_visitor.Dispatch(*this);
}


