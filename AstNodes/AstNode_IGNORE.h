#ifndef ASTNODES_ASTNODE_IGNORE_H
#define ASTNODES_ASTNODE_IGNORE_H
#include "AstNode_ABSTRACTION.h"

#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include "AstEnum.h"
#include <vector>
namespace deamer {
class AstVisitor;
}
namespace DLDL {

class AstNode_IGNORE : public AstNode_ABSTRACTION
{
private:
protected:
public:
    DLDL::AstEnum_t AstType = DLDL::AstEnum_t::IGNORE;


    unsigned int GetAstId() override;
    AstNode_IGNORE(std::vector<deamer::AstNode*> astNodes);
    AstNode_IGNORE(bool isNode, std::string astNodeName);
    AstNode_IGNORE(deamer::AstInformation* astInformation);


    void Accept(deamer::AstVisitor& ast_visitor);

};
}
#endif //ASTNODES_ASTNODE_IGNORE_H

