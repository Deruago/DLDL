#include "AstNode_RULE_DECL.h"
#include "AstNode_VARLIST.h"
#include "AstNode_GENERAL_BLOCK.h"
#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include <vector>
#include <Deamer/AstGen/AstVisitor.h>
DLDL::AstNode_RULE_DECL::AstNode_RULE_DECL(bool isNode, std::string astNodeName) : deamer::AstNode::AstNode(false, "RULE_DECL")

{
}

DLDL::AstNode_RULE_DECL::AstNode_RULE_DECL(deamer::AstInformation* astInformation) : deamer::AstNode::AstNode(astInformation, false, "RULE_DECL")

{
}

DLDL::AstNode_RULE_DECL::AstNode_RULE_DECL(std::vector<deamer::AstNode*> astNodes) : deamer::AstNode::AstNode(astNodes, false, "RULE_DECL")

{
}

DLDL::AstNode_RULE_DECL::AstNode_RULE_DECL(std::vector<AstNode_VARLIST*>* VARLIST1, AstNode_GENERAL_BLOCK* GENERAL_BLOCK1) : deamer::AstNode::AstNode(false, "RULE_DECL")

{
    VARLIST1_ = VARLIST1;
    GENERAL_BLOCK1_ = GENERAL_BLOCK1;
}

unsigned int DLDL::AstNode_RULE_DECL::GetAstId()
{
    return (unsigned int)DLDL::AstNode_RULE_DECL::AstType;
}

void DLDL::AstNode_RULE_DECL::Accept(deamer::AstVisitor& ast_visitor)
{
    ast_visitor.Dispatch(*this);
}


