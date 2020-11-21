#include "AstNode_TERMINAL.h"
#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include <vector>
#include <Deamer/AstGen/AstVisitor.h>
DLDL::AstNode_TERMINAL::AstNode_TERMINAL(bool isNode, std::string astNodeName) : AstNode_ABSTRACTION(true, "TERMINAL")

{
}

DLDL::AstNode_TERMINAL::AstNode_TERMINAL(deamer::AstInformation* astInformation) : AstNode_ABSTRACTION(astInformation)

{
}

DLDL::AstNode_TERMINAL::AstNode_TERMINAL(std::vector<deamer::AstNode*> astNodes) : AstNode_ABSTRACTION(astNodes)

{
}

unsigned int DLDL::AstNode_TERMINAL::GetAstId()
{
    return (unsigned int)DLDL::AstNode_TERMINAL::AstType;
}

void DLDL::AstNode_TERMINAL::Accept(deamer::AstVisitor& ast_visitor)
{
    ast_visitor.Dispatch(*this);
}


