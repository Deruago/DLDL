#include "AstNode_VARLIST.h"
#include "AstNode_VARNAME.h"
#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include <vector>
#include <Deamer/AstGen/AstVisitor.h>
DLDL::AstNode_VARLIST::AstNode_VARLIST(bool isNode, std::string astNodeName) : deamer::AstNode::AstNode(false, "VARLIST")

{
}

DLDL::AstNode_VARLIST::AstNode_VARLIST(deamer::AstInformation* astInformation) : deamer::AstNode::AstNode(astInformation, false, "VARLIST")

{
}

DLDL::AstNode_VARLIST::AstNode_VARLIST(std::vector<deamer::AstNode*> astNodes) : deamer::AstNode::AstNode(astNodes, false, "VARLIST")

{
}

DLDL::AstNode_VARLIST::AstNode_VARLIST(AstNode_VARNAME* VARNAME1) : deamer::AstNode::AstNode(false, "VARLIST")

{
    VARNAME1_ = VARNAME1;
}

unsigned int DLDL::AstNode_VARLIST::GetAstId()
{
    return (unsigned int)DLDL::AstNode_VARLIST::AstType;
}

void DLDL::AstNode_VARLIST::Accept(deamer::AstVisitor& ast_visitor)
{
    ast_visitor.Dispatch(*this);
}


