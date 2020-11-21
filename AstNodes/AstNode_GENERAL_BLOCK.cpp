#include "AstNode_GENERAL_BLOCK.h"
#include "AstNode_VARLIST.h"
#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include <vector>
#include <Deamer/AstGen/AstVisitor.h>
DLDL::AstNode_GENERAL_BLOCK::AstNode_GENERAL_BLOCK(bool isNode, std::string astNodeName) : deamer::AstNode::AstNode(false, "GENERAL_BLOCK")

{
}

DLDL::AstNode_GENERAL_BLOCK::AstNode_GENERAL_BLOCK(deamer::AstInformation* astInformation) : deamer::AstNode::AstNode(astInformation, false, "GENERAL_BLOCK")

{
}

DLDL::AstNode_GENERAL_BLOCK::AstNode_GENERAL_BLOCK(std::vector<deamer::AstNode*> astNodes) : deamer::AstNode::AstNode(astNodes, false, "GENERAL_BLOCK")

{
}

DLDL::AstNode_GENERAL_BLOCK::AstNode_GENERAL_BLOCK(std::vector<AstNode_VARLIST*>* VARLIST1) : deamer::AstNode::AstNode(false, "GENERAL_BLOCK")

{
    VARLIST1_ = VARLIST1;
}

DLDL::AstNode_GENERAL_BLOCK::AstNode_GENERAL_BLOCK() : deamer::AstNode::AstNode(false, "GENERAL_BLOCK")

{
}

unsigned int DLDL::AstNode_GENERAL_BLOCK::GetAstId()
{
    return (unsigned int)DLDL::AstNode_GENERAL_BLOCK::AstType;
}

void DLDL::AstNode_GENERAL_BLOCK::Accept(deamer::AstVisitor& ast_visitor)
{
    ast_visitor.Dispatch(*this);
}


