#ifndef ASTNODES_ASTNODE_ABSTRACTION_INPUTS_H
#define ASTNODES_ASTNODE_ABSTRACTION_INPUTS_H

#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include "AstEnum.h"
#include <vector>
namespace deamer {
class AstVisitor;
}
namespace DLDL {

class AstNode_ABSTRACTION_INPUT;
class AstNode_ABSTRACTION_INPUTS : public deamer::AstNode
{
private:
protected:
public:
    DLDL::AstEnum_t AstType = DLDL::AstEnum_t::ABSTRACTION_INPUTS;

    AstNode_ABSTRACTION_INPUT* ABSTRACTION_INPUT1_ = nullptr;

    unsigned int GetAstId() override;
    AstNode_ABSTRACTION_INPUTS(std::vector<deamer::AstNode*> astNodes);
    AstNode_ABSTRACTION_INPUTS(bool isNode, std::string astNodeName);
    AstNode_ABSTRACTION_INPUTS(deamer::AstInformation* astInformation);

    AstNode_ABSTRACTION_INPUTS(AstNode_ABSTRACTION_INPUT* ABSTRACTION_INPUT1);
    AstNode_ABSTRACTION_INPUTS();

    void Accept(deamer::AstVisitor& ast_visitor);

};
}
#endif //ASTNODES_ASTNODE_ABSTRACTION_INPUTS_H

