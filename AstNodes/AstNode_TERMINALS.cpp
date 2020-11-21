#include "AstNode_TERMINALS.h"
#include "AstNode_TERMINAL_DECL.h"
#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include <vector>
#include <Deamer/AstGen/AstVisitor.h>
DLDL::AstNode_TERMINALS::AstNode_TERMINALS(bool isNode, std::string astNodeName) : deamer::AstNode::AstNode(false, "TERMINALS")

{
}

DLDL::AstNode_TERMINALS::AstNode_TERMINALS(deamer::AstInformation* astInformation) : deamer::AstNode::AstNode(astInformation, false, "TERMINALS")

{
}

DLDL::AstNode_TERMINALS::AstNode_TERMINALS(std::vector<deamer::AstNode*> astNodes) : deamer::AstNode::AstNode(astNodes, false, "TERMINALS")

{
}

DLDL::AstNode_TERMINALS::AstNode_TERMINALS(AstNode_TERMINAL_DECL* TERMINAL_DECL1) : deamer::AstNode::AstNode(false, "TERMINALS")

{
    TERMINAL_DECL1_ = TERMINAL_DECL1;
}

DLDL::AstNode_TERMINALS::AstNode_TERMINALS() : deamer::AstNode::AstNode(false, "TERMINALS")

{
}

unsigned int DLDL::AstNode_TERMINALS::GetAstId()
{
    return (unsigned int)DLDL::AstNode_TERMINALS::AstType;
}

void DLDL::AstNode_TERMINALS::Accept(deamer::AstVisitor& ast_visitor)
{
    ast_visitor.Dispatch(*this);
}


