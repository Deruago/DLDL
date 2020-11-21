#ifndef ASTNODES_ASTNODE_STMTS_H
#define ASTNODES_ASTNODE_STMTS_H

#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include "AstEnum.h"
#include <vector>
namespace deamer {
class AstVisitor;
}
namespace DLDL {

class AstNode_STMT;
class AstNode_STMTS : public deamer::AstNode
{
private:
protected:
public:
    DLDL::AstEnum_t AstType = DLDL::AstEnum_t::STMTS;

    AstNode_STMT* STMT1_ = nullptr;

    unsigned int GetAstId() override;
    AstNode_STMTS(std::vector<deamer::AstNode*> astNodes);
    AstNode_STMTS(bool isNode, std::string astNodeName);
    AstNode_STMTS(deamer::AstInformation* astInformation);

    AstNode_STMTS(AstNode_STMT* STMT1);
    AstNode_STMTS();

    void Accept(deamer::AstVisitor& ast_visitor);

};
}
#endif //ASTNODES_ASTNODE_STMTS_H

