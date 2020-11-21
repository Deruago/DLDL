#ifndef ASTNODES_ASTNODE_DELETE_H
#define ASTNODES_ASTNODE_DELETE_H
#include "AstNode_ABSTRACTION.h"

#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include "AstEnum.h"
#include <vector>
namespace deamer {
class AstVisitor;
}
namespace DLDL {

class AstNode_DELETE : public AstNode_ABSTRACTION
{
private:
protected:
public:
    DLDL::AstEnum_t AstType = DLDL::AstEnum_t::DELETE;


    unsigned int GetAstId() override;
    AstNode_DELETE(std::vector<deamer::AstNode*> astNodes);
    AstNode_DELETE(bool isNode, std::string astNodeName);
    AstNode_DELETE(deamer::AstInformation* astInformation);


    void Accept(deamer::AstVisitor& ast_visitor);

};
}
#endif //ASTNODES_ASTNODE_DELETE_H

