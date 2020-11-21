#include "AstNode_STMTS.h"
#include "AstNode_STMT.h"
#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include <vector>
#include <Deamer/AstGen/AstVisitor.h>
DLDL::AstNode_STMTS::AstNode_STMTS(bool isNode, std::string astNodeName) : deamer::AstNode::AstNode(false, "STMTS")

{
}

DLDL::AstNode_STMTS::AstNode_STMTS(deamer::AstInformation* astInformation) : deamer::AstNode::AstNode(astInformation, false, "STMTS")

{
}

DLDL::AstNode_STMTS::AstNode_STMTS(std::vector<deamer::AstNode*> astNodes) : deamer::AstNode::AstNode(astNodes, false, "STMTS")

{
}

DLDL::AstNode_STMTS::AstNode_STMTS(AstNode_STMT* STMT1) : deamer::AstNode::AstNode(false, "STMTS")

{
    STMT1_ = STMT1;
}

DLDL::AstNode_STMTS::AstNode_STMTS() : deamer::AstNode::AstNode(false, "STMTS")

{
}

unsigned int DLDL::AstNode_STMTS::GetAstId()
{
    return (unsigned int)DLDL::AstNode_STMTS::AstType;
}

void DLDL::AstNode_STMTS::Accept(deamer::AstVisitor& ast_visitor)
{
    ast_visitor.Dispatch(*this);
}


