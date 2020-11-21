#ifndef ASTNODES_ASTNODE_GROUP_H
#define ASTNODES_ASTNODE_GROUP_H
#include "AstNode_ABSTRACTION.h"

#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include "AstEnum.h"
#include <vector>
namespace deamer {
class AstVisitor;
}
namespace DLDL {

class AstNode_GROUP : public AstNode_ABSTRACTION
{
private:
protected:
public:
    DLDL::AstEnum_t AstType = DLDL::AstEnum_t::GROUP;


    unsigned int GetAstId() override;
    AstNode_GROUP(std::vector<deamer::AstNode*> astNodes);
    AstNode_GROUP(bool isNode, std::string astNodeName);
    AstNode_GROUP(deamer::AstInformation* astInformation);


    void Accept(deamer::AstVisitor& ast_visitor);

};
}
#endif //ASTNODES_ASTNODE_GROUP_H

