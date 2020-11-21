#ifndef ASTNODES_ASTNODE_TERMINAL_BLOCK_H
#define ASTNODES_ASTNODE_TERMINAL_BLOCK_H

#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include "AstEnum.h"
#include <vector>
namespace deamer {
class AstVisitor;
}
namespace DLDL {

class AstNode_GENERAL_BLOCK;
class AstNode_TERMINAL_BLOCK : public deamer::AstNode
{
private:
protected:
public:
    DLDL::AstEnum_t AstType = DLDL::AstEnum_t::TERMINAL_BLOCK;

    AstNode_GENERAL_BLOCK* GENERAL_BLOCK1_ = nullptr;

    unsigned int GetAstId() override;
    AstNode_TERMINAL_BLOCK(std::vector<deamer::AstNode*> astNodes);
    AstNode_TERMINAL_BLOCK(bool isNode, std::string astNodeName);
    AstNode_TERMINAL_BLOCK(deamer::AstInformation* astInformation);

    AstNode_TERMINAL_BLOCK(AstNode_GENERAL_BLOCK* GENERAL_BLOCK1);

    void Accept(deamer::AstVisitor& ast_visitor);

};
}
#endif //ASTNODES_ASTNODE_TERMINAL_BLOCK_H

