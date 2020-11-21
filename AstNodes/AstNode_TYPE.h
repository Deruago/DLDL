#ifndef ASTNODES_ASTNODE_TYPE_H
#define ASTNODES_ASTNODE_TYPE_H
#include "AstNode_ABSTRACTION.h"

#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include "AstEnum.h"
#include <vector>
namespace deamer {
class AstVisitor;
}
namespace DLDL {

class AstNode_TYPE : public AstNode_ABSTRACTION
{
private:
protected:
public:
    DLDL::AstEnum_t AstType = DLDL::AstEnum_t::TYPE;


    unsigned int GetAstId() override;
    AstNode_TYPE(std::vector<deamer::AstNode*> astNodes);
    AstNode_TYPE(bool isNode, std::string astNodeName);
    AstNode_TYPE(deamer::AstInformation* astInformation);


    void Accept(deamer::AstVisitor& ast_visitor);

};
}
#endif //ASTNODES_ASTNODE_TYPE_H

