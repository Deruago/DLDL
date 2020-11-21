#ifndef ASTNODES_ASTNODE_START_H
#define ASTNODES_ASTNODE_START_H
#include "AstNode_ABSTRACTION.h"

#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include "AstEnum.h"
#include <vector>
namespace deamer {
class AstVisitor;
}
namespace DLDL {

class AstNode_START : public AstNode_ABSTRACTION
{
private:
protected:
public:
    DLDL::AstEnum_t AstType = DLDL::AstEnum_t::START;


    unsigned int GetAstId() override;
    AstNode_START(std::vector<deamer::AstNode*> astNodes);
    AstNode_START(bool isNode, std::string astNodeName);
    AstNode_START(deamer::AstInformation* astInformation);


    void Accept(deamer::AstVisitor& ast_visitor);

};
}
#endif //ASTNODES_ASTNODE_START_H

