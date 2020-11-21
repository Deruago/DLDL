#include "AstNode_RULES.h"
#include "AstNode_RULE_DECL.h"
#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include <vector>
#include <Deamer/AstGen/AstVisitor.h>
DLDL::AstNode_RULES::AstNode_RULES(bool isNode, std::string astNodeName) : deamer::AstNode::AstNode(false, "RULES")

{
}

DLDL::AstNode_RULES::AstNode_RULES(deamer::AstInformation* astInformation) : deamer::AstNode::AstNode(astInformation, false, "RULES")

{
}

DLDL::AstNode_RULES::AstNode_RULES(std::vector<deamer::AstNode*> astNodes) : deamer::AstNode::AstNode(astNodes, false, "RULES")

{
}

DLDL::AstNode_RULES::AstNode_RULES(AstNode_RULE_DECL* RULE_DECL1) : deamer::AstNode::AstNode(false, "RULES")

{
    RULE_DECL1_ = RULE_DECL1;
}

unsigned int DLDL::AstNode_RULES::GetAstId()
{
    return (unsigned int)DLDL::AstNode_RULES::AstType;
}

void DLDL::AstNode_RULES::Accept(deamer::AstVisitor& ast_visitor)
{
    ast_visitor.Dispatch(*this);
}


