#include "AstNode_ABSTRACTION_INPUT.h"
#include "AstNode_VARLIST.h"
#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include <vector>
#include <Deamer/AstGen/AstVisitor.h>
DLDL::AstNode_ABSTRACTION_INPUT::AstNode_ABSTRACTION_INPUT(bool isNode, std::string astNodeName) : deamer::AstNode::AstNode(false, "ABSTRACTION_INPUT")

{
}

DLDL::AstNode_ABSTRACTION_INPUT::AstNode_ABSTRACTION_INPUT(deamer::AstInformation* astInformation) : deamer::AstNode::AstNode(astInformation, false, "ABSTRACTION_INPUT")

{
}

DLDL::AstNode_ABSTRACTION_INPUT::AstNode_ABSTRACTION_INPUT(std::vector<deamer::AstNode*> astNodes) : deamer::AstNode::AstNode(astNodes, false, "ABSTRACTION_INPUT")

{
}

DLDL::AstNode_ABSTRACTION_INPUT::AstNode_ABSTRACTION_INPUT(std::vector<AstNode_VARLIST*>* VARLIST1) : deamer::AstNode::AstNode(false, "ABSTRACTION_INPUT")

{
    VARLIST1_ = VARLIST1;
}

unsigned int DLDL::AstNode_ABSTRACTION_INPUT::GetAstId()
{
    return (unsigned int)DLDL::AstNode_ABSTRACTION_INPUT::AstType;
}

void DLDL::AstNode_ABSTRACTION_INPUT::Accept(deamer::AstVisitor& ast_visitor)
{
    ast_visitor.Dispatch(*this);
}


