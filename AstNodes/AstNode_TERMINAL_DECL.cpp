#include "AstNode_TERMINAL_DECL.h"
#include "AstNode_VARNAME.h"
#include "AstNode_VARLIST.h"
#include "AstNode_TERMINAL_BLOCK.h"
#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include <vector>
#include <Deamer/AstGen/AstVisitor.h>
DLDL::AstNode_TERMINAL_DECL::AstNode_TERMINAL_DECL(bool isNode, std::string astNodeName) : AstNode_STMT(false, "TERMINAL_DECL")

{
}

DLDL::AstNode_TERMINAL_DECL::AstNode_TERMINAL_DECL(deamer::AstInformation* astInformation) : AstNode_STMT(astInformation)

{
}

DLDL::AstNode_TERMINAL_DECL::AstNode_TERMINAL_DECL(std::vector<deamer::AstNode*> astNodes) : AstNode_STMT(astNodes)

{
}

DLDL::AstNode_TERMINAL_DECL::AstNode_TERMINAL_DECL(AstNode_VARNAME* VARNAME1, std::vector<AstNode_VARLIST*>* VARLIST1, AstNode_TERMINAL_BLOCK* TERMINAL_BLOCK1) : AstNode_STMT(false, "TERMINAL_DECL")

{
    VARNAME1_ = VARNAME1;
    VARLIST1_ = VARLIST1;
    TERMINAL_BLOCK1_ = TERMINAL_BLOCK1;
}

unsigned int DLDL::AstNode_TERMINAL_DECL::GetAstId()
{
    return (unsigned int)DLDL::AstNode_TERMINAL_DECL::AstType;
}

void DLDL::AstNode_TERMINAL_DECL::Accept(deamer::AstVisitor& ast_visitor)
{
    ast_visitor.Dispatch(*this);
}


