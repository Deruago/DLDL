#include "AstNode_ABSTRACTION_BLOCK.h"
#include "AstNode_ABSTRACTION_INPUTS.h"
#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include <vector>
#include <Deamer/AstGen/AstVisitor.h>
DLDL::AstNode_ABSTRACTION_BLOCK::AstNode_ABSTRACTION_BLOCK(bool isNode, std::string astNodeName) : deamer::AstNode::AstNode(false, "ABSTRACTION_BLOCK")

{
}

DLDL::AstNode_ABSTRACTION_BLOCK::AstNode_ABSTRACTION_BLOCK(deamer::AstInformation* astInformation) : deamer::AstNode::AstNode(astInformation, false, "ABSTRACTION_BLOCK")

{
}

DLDL::AstNode_ABSTRACTION_BLOCK::AstNode_ABSTRACTION_BLOCK(std::vector<deamer::AstNode*> astNodes) : deamer::AstNode::AstNode(astNodes, false, "ABSTRACTION_BLOCK")

{
}

DLDL::AstNode_ABSTRACTION_BLOCK::AstNode_ABSTRACTION_BLOCK(std::vector<AstNode_ABSTRACTION_INPUTS*>* ABSTRACTION_INPUTS1) : deamer::AstNode::AstNode(false, "ABSTRACTION_BLOCK")

{
    ABSTRACTION_INPUTS1_ = ABSTRACTION_INPUTS1;
}

unsigned int DLDL::AstNode_ABSTRACTION_BLOCK::GetAstId()
{
    return (unsigned int)DLDL::AstNode_ABSTRACTION_BLOCK::AstType;
}

void DLDL::AstNode_ABSTRACTION_BLOCK::Accept(deamer::AstVisitor& ast_visitor)
{
    ast_visitor.Dispatch(*this);
}


