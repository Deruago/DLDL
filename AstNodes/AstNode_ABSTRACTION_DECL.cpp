#include "AstNode_ABSTRACTION_DECL.h"
#include "AstNode_ABSTRACTION.h"
#include "AstNode_VARLIST.h"
#include "AstNode_ABSTRACTION_BLOCK.h"
#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include <vector>
#include <Deamer/AstGen/AstVisitor.h>
DLDL::AstNode_ABSTRACTION_DECL::AstNode_ABSTRACTION_DECL(bool isNode, std::string astNodeName) : AstNode_STMT(false, "ABSTRACTION_DECL")

{
}

DLDL::AstNode_ABSTRACTION_DECL::AstNode_ABSTRACTION_DECL(deamer::AstInformation* astInformation) : AstNode_STMT(astInformation)

{
}

DLDL::AstNode_ABSTRACTION_DECL::AstNode_ABSTRACTION_DECL(std::vector<deamer::AstNode*> astNodes) : AstNode_STMT(astNodes)

{
}

DLDL::AstNode_ABSTRACTION_DECL::AstNode_ABSTRACTION_DECL(AstNode_ABSTRACTION* ABSTRACTION1, std::vector<AstNode_VARLIST*>* VARLIST1, AstNode_ABSTRACTION_BLOCK* ABSTRACTION_BLOCK1) : AstNode_STMT(false, "ABSTRACTION_DECL")

{
    ABSTRACTION1_ = ABSTRACTION1;
    VARLIST1_ = VARLIST1;
    ABSTRACTION_BLOCK1_ = ABSTRACTION_BLOCK1;
}

unsigned int DLDL::AstNode_ABSTRACTION_DECL::GetAstId()
{
    return (unsigned int)DLDL::AstNode_ABSTRACTION_DECL::AstType;
}

void DLDL::AstNode_ABSTRACTION_DECL::Accept(deamer::AstVisitor& ast_visitor)
{
    ast_visitor.Dispatch(*this);
}


