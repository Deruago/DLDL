#ifndef ASTNODES_ASTNODE_TERMINAL_DECL_H
#define ASTNODES_ASTNODE_TERMINAL_DECL_H
#include "AstNode_STMT.h"

#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include "AstEnum.h"
#include <vector>
namespace deamer {
class AstVisitor;
}
namespace DLDL {

class AstNode_VARNAME;
class AstNode_VARLIST;
class AstNode_TERMINAL_BLOCK;
class AstNode_TERMINAL_DECL : public AstNode_STMT
{
private:
protected:
public:
    DLDL::AstEnum_t AstType = DLDL::AstEnum_t::TERMINAL_DECL;

    AstNode_VARNAME* VARNAME1_ = nullptr;
    std::vector<AstNode_VARLIST*>* VARLIST1_ = nullptr;
    AstNode_TERMINAL_BLOCK* TERMINAL_BLOCK1_ = nullptr;

    unsigned int GetAstId() override;
    AstNode_TERMINAL_DECL(std::vector<deamer::AstNode*> astNodes);
    AstNode_TERMINAL_DECL(bool isNode, std::string astNodeName);
    AstNode_TERMINAL_DECL(deamer::AstInformation* astInformation);

    AstNode_TERMINAL_DECL(AstNode_VARNAME* VARNAME1, std::vector<AstNode_VARLIST*>* VARLIST1, AstNode_TERMINAL_BLOCK* TERMINAL_BLOCK1);

    void Accept(deamer::AstVisitor& ast_visitor);

};
}
#endif //ASTNODES_ASTNODE_TERMINAL_DECL_H

