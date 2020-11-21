#ifndef ASTNODES_ASTNODE_GENERAL_BLOCK_H
#define ASTNODES_ASTNODE_GENERAL_BLOCK_H

#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include "AstEnum.h"
#include <vector>
namespace deamer {
class AstVisitor;
}
namespace DLDL {

class AstNode_VARLIST;
class AstNode_GENERAL_BLOCK : public deamer::AstNode
{
private:
protected:
public:
    DLDL::AstEnum_t AstType = DLDL::AstEnum_t::GENERAL_BLOCK;

    std::vector<AstNode_VARLIST*>* VARLIST1_ = nullptr;

    unsigned int GetAstId() override;
    AstNode_GENERAL_BLOCK(std::vector<deamer::AstNode*> astNodes);
    AstNode_GENERAL_BLOCK(bool isNode, std::string astNodeName);
    AstNode_GENERAL_BLOCK(deamer::AstInformation* astInformation);

    AstNode_GENERAL_BLOCK(std::vector<AstNode_VARLIST*>* VARLIST1);
    AstNode_GENERAL_BLOCK();

    void Accept(deamer::AstVisitor& ast_visitor);

};
}
#endif //ASTNODES_ASTNODE_GENERAL_BLOCK_H

