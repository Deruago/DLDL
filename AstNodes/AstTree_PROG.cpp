#include "AstTree_PROG.h"
#include "AstNode_STMTS.h"
#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include <vector>
#include <Deamer/AstGen/AstVisitor.h>
DLDL::AstTree_PROG* DLDL::AstTree_PROG::currentTree;

DLDL::AstTree_PROG::AstTree_PROG(bool isNode, std::string astNodeName) : deamer::AstNode::AstNode(false, "PROG")

{
}

DLDL::AstTree_PROG::AstTree_PROG(deamer::AstInformation* astInformation) : deamer::AstNode::AstNode(astInformation, false, "PROG")

{
}

DLDL::AstTree_PROG::AstTree_PROG(std::vector<deamer::AstNode*> astNodes) : deamer::AstNode::AstNode(astNodes, false, "PROG")

{
}

DLDL::AstTree_PROG::AstTree_PROG(std::vector<AstNode_STMTS*>* STMTS1) : deamer::AstNode::AstNode(false, "PROG")

{
    STMTS1_ = STMTS1;
}

unsigned int DLDL::AstTree_PROG::GetAstId()
{
    return (unsigned int)DLDL::AstTree_PROG::AstType;
}

void DLDL::AstTree_PROG::SetCurrentTree(AstTree_PROG* new_ast_base_node)
{
    currentTree = new_ast_base_node;
}
void DLDL::AstTree_PROG::Accept(deamer::AstVisitor& ast_visitor)
{
    ast_visitor.Dispatch(*this);
}


