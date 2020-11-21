#include "AstNode_TERMINAL_BLOCK.h"
#include "AstNode_GENERAL_BLOCK.h"
#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include <vector>
#include <Deamer/AstGen/AstVisitor.h>
DLDL::AstNode_TERMINAL_BLOCK::AstNode_TERMINAL_BLOCK(bool isNode, std::string astNodeName) : deamer::AstNode::AstNode(false, "TERMINAL_BLOCK")

{
}

DLDL::AstNode_TERMINAL_BLOCK::AstNode_TERMINAL_BLOCK(deamer::AstInformation* astInformation) : deamer::AstNode::AstNode(astInformation, false, "TERMINAL_BLOCK")

{
}

DLDL::AstNode_TERMINAL_BLOCK::AstNode_TERMINAL_BLOCK(std::vector<deamer::AstNode*> astNodes) : deamer::AstNode::AstNode(astNodes, false, "TERMINAL_BLOCK")

{
}

DLDL::AstNode_TERMINAL_BLOCK::AstNode_TERMINAL_BLOCK(AstNode_GENERAL_BLOCK* GENERAL_BLOCK1) : deamer::AstNode::AstNode(false, "TERMINAL_BLOCK")

{
    GENERAL_BLOCK1_ = GENERAL_BLOCK1;
}

unsigned int DLDL::AstNode_TERMINAL_BLOCK::GetAstId()
{
    return (unsigned int)DLDL::AstNode_TERMINAL_BLOCK::AstType;
}

void DLDL::AstNode_TERMINAL_BLOCK::Accept(deamer::AstVisitor& ast_visitor)
{
    ast_visitor.Dispatch(*this);
}


