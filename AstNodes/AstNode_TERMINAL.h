#ifndef ASTNODES_ASTNODE_TERMINAL_H
#define ASTNODES_ASTNODE_TERMINAL_H
#include "AstNode_ABSTRACTION.h"

#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include "AstEnum.h"
#include <vector>
namespace deamer {
class AstVisitor;
}
namespace DLDL {

class AstNode_TERMINAL : public AstNode_ABSTRACTION
{
private:
protected:
public:
    DLDL::AstEnum_t AstType = DLDL::AstEnum_t::TERMINAL;


    unsigned int GetAstId() override;
    AstNode_TERMINAL(std::vector<deamer::AstNode*> astNodes);
    AstNode_TERMINAL(bool isNode, std::string astNodeName);
    AstNode_TERMINAL(deamer::AstInformation* astInformation);


    void Accept(deamer::AstVisitor& ast_visitor);

};
}
#endif //ASTNODES_ASTNODE_TERMINAL_H

