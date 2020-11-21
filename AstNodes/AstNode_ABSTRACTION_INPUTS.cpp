#include "AstNode_ABSTRACTION_INPUTS.h"
#include "AstNode_ABSTRACTION_INPUT.h"
#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include <vector>
#include <Deamer/AstGen/AstVisitor.h>
DLDL::AstNode_ABSTRACTION_INPUTS::AstNode_ABSTRACTION_INPUTS(bool isNode, std::string astNodeName) : deamer::AstNode::AstNode(false, "ABSTRACTION_INPUTS")

{
}

DLDL::AstNode_ABSTRACTION_INPUTS::AstNode_ABSTRACTION_INPUTS(deamer::AstInformation* astInformation) : deamer::AstNode::AstNode(astInformation, false, "ABSTRACTION_INPUTS")

{
}

DLDL::AstNode_ABSTRACTION_INPUTS::AstNode_ABSTRACTION_INPUTS(std::vector<deamer::AstNode*> astNodes) : deamer::AstNode::AstNode(astNodes, false, "ABSTRACTION_INPUTS")

{
}

DLDL::AstNode_ABSTRACTION_INPUTS::AstNode_ABSTRACTION_INPUTS(AstNode_ABSTRACTION_INPUT* ABSTRACTION_INPUT1) : deamer::AstNode::AstNode(false, "ABSTRACTION_INPUTS")

{
    ABSTRACTION_INPUT1_ = ABSTRACTION_INPUT1;
}

DLDL::AstNode_ABSTRACTION_INPUTS::AstNode_ABSTRACTION_INPUTS() : deamer::AstNode::AstNode(false, "ABSTRACTION_INPUTS")

{
}

unsigned int DLDL::AstNode_ABSTRACTION_INPUTS::GetAstId()
{
    return (unsigned int)DLDL::AstNode_ABSTRACTION_INPUTS::AstType;
}

void DLDL::AstNode_ABSTRACTION_INPUTS::Accept(deamer::AstVisitor& ast_visitor)
{
    ast_visitor.Dispatch(*this);
}


