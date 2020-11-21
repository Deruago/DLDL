#include "AstNode_ABSTRACTION.h"
#include "AstNode_DELETE.h"
#include "AstNode_IGNORE.h"
#include "AstNode_TERMINAL.h"
#include "AstNode_NONTERMINAL.h"
#include "AstNode_GROUP.h"
#include "AstNode_ALIAS.h"
#include "AstNode_START.h"
#include "AstNode_COMMENT.h"
#include "AstNode_UNIQUE.h"
#include "AstNode_TYPE.h"
#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include <vector>
#include <Deamer/AstGen/AstVisitor.h>
DLDL::AstNode_ABSTRACTION::AstNode_ABSTRACTION(bool isNode, std::string astNodeName) : deamer::AstNode::AstNode(false, "ABSTRACTION")

{
}

DLDL::AstNode_ABSTRACTION::AstNode_ABSTRACTION(deamer::AstInformation* astInformation) : deamer::AstNode::AstNode(astInformation, false, "ABSTRACTION")

{
}

DLDL::AstNode_ABSTRACTION::AstNode_ABSTRACTION(std::vector<deamer::AstNode*> astNodes) : deamer::AstNode::AstNode(astNodes, false, "ABSTRACTION")

{
}

DLDL::AstNode_ABSTRACTION::AstNode_ABSTRACTION(AstNode_DELETE* DELETE1) : deamer::AstNode::AstNode(false, "ABSTRACTION")

{
    DELETE1_ = DELETE1;
}

DLDL::AstNode_ABSTRACTION::AstNode_ABSTRACTION(AstNode_IGNORE* IGNORE1) : deamer::AstNode::AstNode(false, "ABSTRACTION")

{
    IGNORE1_ = IGNORE1;
}

DLDL::AstNode_ABSTRACTION::AstNode_ABSTRACTION(AstNode_TERMINAL* TERMINAL1) : deamer::AstNode::AstNode(false, "ABSTRACTION")

{
    TERMINAL1_ = TERMINAL1;
}

DLDL::AstNode_ABSTRACTION::AstNode_ABSTRACTION(AstNode_NONTERMINAL* NONTERMINAL1) : deamer::AstNode::AstNode(false, "ABSTRACTION")

{
    NONTERMINAL1_ = NONTERMINAL1;
}

DLDL::AstNode_ABSTRACTION::AstNode_ABSTRACTION(AstNode_GROUP* GROUP1) : deamer::AstNode::AstNode(false, "ABSTRACTION")

{
    GROUP1_ = GROUP1;
}

DLDL::AstNode_ABSTRACTION::AstNode_ABSTRACTION(AstNode_ALIAS* ALIAS1) : deamer::AstNode::AstNode(false, "ABSTRACTION")

{
    ALIAS1_ = ALIAS1;
}

DLDL::AstNode_ABSTRACTION::AstNode_ABSTRACTION(AstNode_START* START1) : deamer::AstNode::AstNode(false, "ABSTRACTION")

{
    START1_ = START1;
}

DLDL::AstNode_ABSTRACTION::AstNode_ABSTRACTION(AstNode_COMMENT* COMMENT1) : deamer::AstNode::AstNode(false, "ABSTRACTION")

{
    COMMENT1_ = COMMENT1;
}

DLDL::AstNode_ABSTRACTION::AstNode_ABSTRACTION(AstNode_UNIQUE* UNIQUE1) : deamer::AstNode::AstNode(false, "ABSTRACTION")

{
    UNIQUE1_ = UNIQUE1;
}

DLDL::AstNode_ABSTRACTION::AstNode_ABSTRACTION(AstNode_TYPE* TYPE1) : deamer::AstNode::AstNode(false, "ABSTRACTION")

{
    TYPE1_ = TYPE1;
}

unsigned int DLDL::AstNode_ABSTRACTION::GetAstId()
{
    return (unsigned int)DLDL::AstNode_ABSTRACTION::AstType;
}

void DLDL::AstNode_ABSTRACTION::Accept(deamer::AstVisitor& ast_visitor)
{
    ast_visitor.Dispatch(*this);
}


