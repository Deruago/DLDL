#ifndef ASTNODES_ASTNODE_ABSTRACTION_BLOCK_H
#define ASTNODES_ASTNODE_ABSTRACTION_BLOCK_H

#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include "AstEnum.h"
#include <vector>
namespace deamer {
class AstVisitor;
}
namespace DLDL {

class AstNode_ABSTRACTION_INPUTS;
class AstNode_ABSTRACTION_BLOCK : public deamer::AstNode
{
private:
protected:
public:
    DLDL::AstEnum_t AstType = DLDL::AstEnum_t::ABSTRACTION_BLOCK;

    std::vector<AstNode_ABSTRACTION_INPUTS*>* ABSTRACTION_INPUTS1_ = nullptr;

    unsigned int GetAstId() override;
    AstNode_ABSTRACTION_BLOCK(std::vector<deamer::AstNode*> astNodes);
    AstNode_ABSTRACTION_BLOCK(bool isNode, std::string astNodeName);
    AstNode_ABSTRACTION_BLOCK(deamer::AstInformation* astInformation);

    AstNode_ABSTRACTION_BLOCK(std::vector<AstNode_ABSTRACTION_INPUTS*>* ABSTRACTION_INPUTS1);

    void Accept(deamer::AstVisitor& ast_visitor);

};
}
#endif //ASTNODES_ASTNODE_ABSTRACTION_BLOCK_H

