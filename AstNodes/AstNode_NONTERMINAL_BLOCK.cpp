#include "AstNode_NONTERMINAL_BLOCK.h"
#include "AstNode_RULES.h"
#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include <vector>
#include <Deamer/AstGen/AstVisitor.h>
DLDL::AstNode_NONTERMINAL_BLOCK::AstNode_NONTERMINAL_BLOCK(bool isNode, std::string astNodeName) : deamer::AstNode::AstNode(false, "NONTERMINAL_BLOCK")

{
}

DLDL::AstNode_NONTERMINAL_BLOCK::AstNode_NONTERMINAL_BLOCK(deamer::AstInformation* astInformation) : deamer::AstNode::AstNode(astInformation, false, "NONTERMINAL_BLOCK")

{
}

DLDL::AstNode_NONTERMINAL_BLOCK::AstNode_NONTERMINAL_BLOCK(std::vector<deamer::AstNode*> astNodes) : deamer::AstNode::AstNode(astNodes, false, "NONTERMINAL_BLOCK")

{
}

DLDL::AstNode_NONTERMINAL_BLOCK::AstNode_NONTERMINAL_BLOCK(std::vector<AstNode_RULES*>* RULES1) : deamer::AstNode::AstNode(false, "NONTERMINAL_BLOCK")

{
    RULES1_ = RULES1;
}

unsigned int DLDL::AstNode_NONTERMINAL_BLOCK::GetAstId()
{
    return (unsigned int)DLDL::AstNode_NONTERMINAL_BLOCK::AstType;
}

void DLDL::AstNode_NONTERMINAL_BLOCK::Accept(deamer::AstVisitor& ast_visitor)
{
    ast_visitor.Dispatch(*this);
}


