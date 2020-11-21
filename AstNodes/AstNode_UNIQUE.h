#ifndef ASTNODES_ASTNODE_UNIQUE_H
#define ASTNODES_ASTNODE_UNIQUE_H
#include "AstNode_ABSTRACTION.h"

#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include "AstEnum.h"
#include <vector>
namespace deamer {
class AstVisitor;
}
namespace DLDL {

class AstNode_UNIQUE : public AstNode_ABSTRACTION
{
private:
protected:
public:
    DLDL::AstEnum_t AstType = DLDL::AstEnum_t::UNIQUE;


    unsigned int GetAstId() override;
    AstNode_UNIQUE(std::vector<deamer::AstNode*> astNodes);
    AstNode_UNIQUE(bool isNode, std::string astNodeName);
    AstNode_UNIQUE(deamer::AstInformation* astInformation);


    void Accept(deamer::AstVisitor& ast_visitor);

};
}
#endif //ASTNODES_ASTNODE_UNIQUE_H

