#ifndef ASTNODES_ASTNODE_ALIAS_H
#define ASTNODES_ASTNODE_ALIAS_H
#include "AstNode_ABSTRACTION.h"

#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include "AstEnum.h"
#include <vector>
namespace deamer {
class AstVisitor;
}
namespace DLDL {

class AstNode_ALIAS : public AstNode_ABSTRACTION
{
private:
protected:
public:
    DLDL::AstEnum_t AstType = DLDL::AstEnum_t::ALIAS;


    unsigned int GetAstId() override;
    AstNode_ALIAS(std::vector<deamer::AstNode*> astNodes);
    AstNode_ALIAS(bool isNode, std::string astNodeName);
    AstNode_ALIAS(deamer::AstInformation* astInformation);


    void Accept(deamer::AstVisitor& ast_visitor);

};
}
#endif //ASTNODES_ASTNODE_ALIAS_H

