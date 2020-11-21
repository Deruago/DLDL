#ifndef ASTNODES_ASTNODE_RULE_DECL_H
#define ASTNODES_ASTNODE_RULE_DECL_H

#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include "AstEnum.h"
#include <vector>
namespace deamer {
class AstVisitor;
}
namespace DLDL {

class AstNode_VARLIST;
class AstNode_GENERAL_BLOCK;
class AstNode_RULE_DECL : public deamer::AstNode
{
private:
protected:
public:
    DLDL::AstEnum_t AstType = DLDL::AstEnum_t::RULE_DECL;

    std::vector<AstNode_VARLIST*>* VARLIST1_ = nullptr;
    AstNode_GENERAL_BLOCK* GENERAL_BLOCK1_ = nullptr;

    unsigned int GetAstId() override;
    AstNode_RULE_DECL(std::vector<deamer::AstNode*> astNodes);
    AstNode_RULE_DECL(bool isNode, std::string astNodeName);
    AstNode_RULE_DECL(deamer::AstInformation* astInformation);

    AstNode_RULE_DECL(std::vector<AstNode_VARLIST*>* VARLIST1, AstNode_GENERAL_BLOCK* GENERAL_BLOCK1);

    void Accept(deamer::AstVisitor& ast_visitor);

};
}
#endif //ASTNODES_ASTNODE_RULE_DECL_H

