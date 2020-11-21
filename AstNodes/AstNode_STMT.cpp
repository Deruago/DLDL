#include "AstNode_STMT.h"
#include "AstNode_TERMINAL_DECL.h"
#include "AstNode_NONTERMINAL_DECL.h"
#include "AstNode_ABSTRACTION_DECL.h"
#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include <vector>
#include <Deamer/AstGen/AstVisitor.h>
DLDL::AstNode_STMT::AstNode_STMT(bool isNode, std::string astNodeName) : deamer::AstNode::AstNode(false, "STMT")

{
}

DLDL::AstNode_STMT::AstNode_STMT(deamer::AstInformation* astInformation) : deamer::AstNode::AstNode(astInformation, false, "STMT")

{
}

DLDL::AstNode_STMT::AstNode_STMT(std::vector<deamer::AstNode*> astNodes) : deamer::AstNode::AstNode(astNodes, false, "STMT")

{
}

DLDL::AstNode_STMT::AstNode_STMT(AstNode_TERMINAL_DECL* TERMINAL_DECL1) : deamer::AstNode::AstNode(false, "STMT")

{
    TERMINAL_DECL1_ = TERMINAL_DECL1;
}

DLDL::AstNode_STMT::AstNode_STMT(AstNode_NONTERMINAL_DECL* NONTERMINAL_DECL1) : deamer::AstNode::AstNode(false, "STMT")

{
    NONTERMINAL_DECL1_ = NONTERMINAL_DECL1;
}

DLDL::AstNode_STMT::AstNode_STMT(AstNode_ABSTRACTION_DECL* ABSTRACTION_DECL1) : deamer::AstNode::AstNode(false, "STMT")

{
    ABSTRACTION_DECL1_ = ABSTRACTION_DECL1;
}

unsigned int DLDL::AstNode_STMT::GetAstId()
{
    return (unsigned int)DLDL::AstNode_STMT::AstType;
}

void DLDL::AstNode_STMT::Accept(deamer::AstVisitor& ast_visitor)
{
    ast_visitor.Dispatch(*this);
}


