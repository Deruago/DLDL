#ifndef ASTNODES_ASTTREE_PROG_H
#define ASTNODES_ASTTREE_PROG_H

#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include "AstEnum.h"
#include <vector>
namespace deamer {
class AstVisitor;
}
namespace DLDL {

class AstNode_STMTS;
class AstTree_PROG : public deamer::AstNode
{
private:
protected:
public:
    DLDL::AstEnum_t AstType = DLDL::AstEnum_t::PROG;
    void SetCurrentTree(AstTree_PROG* new_ast_base_node);

    std::vector<AstNode_STMTS*>* STMTS1_ = nullptr;

    unsigned int GetAstId() override;
    AstTree_PROG(std::vector<deamer::AstNode*> astNodes);
    AstTree_PROG(bool isNode, std::string astNodeName);
    AstTree_PROG(deamer::AstInformation* astInformation);

    AstTree_PROG(std::vector<AstNode_STMTS*>* STMTS1);

    void Accept(deamer::AstVisitor& ast_visitor);

    static AstTree_PROG* currentTree;
};
}
#endif //ASTNODES_ASTTREE_PROG_H

