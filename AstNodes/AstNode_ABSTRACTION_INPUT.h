#ifndef ASTNODES_ASTNODE_ABSTRACTION_INPUT_H
#define ASTNODES_ASTNODE_ABSTRACTION_INPUT_H

#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include "AstEnum.h"
#include <vector>
namespace deamer {
class AstVisitor;
}
namespace DLDL {

class AstNode_VARLIST;
class AstNode_ABSTRACTION_INPUT : public deamer::AstNode
{
private:
protected:
public:
    DLDL::AstEnum_t AstType = DLDL::AstEnum_t::ABSTRACTION_INPUT;

    std::vector<AstNode_VARLIST*>* VARLIST1_ = nullptr;

    unsigned int GetAstId() override;
    AstNode_ABSTRACTION_INPUT(std::vector<deamer::AstNode*> astNodes);
    AstNode_ABSTRACTION_INPUT(bool isNode, std::string astNodeName);
    AstNode_ABSTRACTION_INPUT(deamer::AstInformation* astInformation);

    AstNode_ABSTRACTION_INPUT(std::vector<AstNode_VARLIST*>* VARLIST1);

    void Accept(deamer::AstVisitor& ast_visitor);

};
}
#endif //ASTNODES_ASTNODE_ABSTRACTION_INPUT_H

