#ifndef ASTNODES_ASTNODE_TERMINALS_H
#define ASTNODES_ASTNODE_TERMINALS_H

#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include "AstEnum.h"
#include <vector>
namespace deamer {
class AstVisitor;
}
namespace DLDL {

class AstNode_TERMINAL_DECL;
class AstNode_TERMINALS : public deamer::AstNode
{
private:
protected:
public:
    DLDL::AstEnum_t AstType = DLDL::AstEnum_t::TERMINALS;

    AstNode_TERMINAL_DECL* TERMINAL_DECL1_ = nullptr;

    unsigned int GetAstId() override;
    AstNode_TERMINALS(std::vector<deamer::AstNode*> astNodes);
    AstNode_TERMINALS(bool isNode, std::string astNodeName);
    AstNode_TERMINALS(deamer::AstInformation* astInformation);

    AstNode_TERMINALS(AstNode_TERMINAL_DECL* TERMINAL_DECL1);
    AstNode_TERMINALS();

    void Accept(deamer::AstVisitor& ast_visitor);

};
}
#endif //ASTNODES_ASTNODE_TERMINALS_H

