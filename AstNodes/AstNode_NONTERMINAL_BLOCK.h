#ifndef ASTNODES_ASTNODE_NONTERMINAL_BLOCK_H
#define ASTNODES_ASTNODE_NONTERMINAL_BLOCK_H

#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include "AstEnum.h"
#include <vector>
namespace deamer {
class AstVisitor;
}
namespace DLDL {

class AstNode_RULES;
class AstNode_NONTERMINAL_BLOCK : public deamer::AstNode
{
private:
protected:
public:
    DLDL::AstEnum_t AstType = DLDL::AstEnum_t::NONTERMINAL_BLOCK;

    std::vector<AstNode_RULES*>* RULES1_ = nullptr;

    unsigned int GetAstId() override;
    AstNode_NONTERMINAL_BLOCK(std::vector<deamer::AstNode*> astNodes);
    AstNode_NONTERMINAL_BLOCK(bool isNode, std::string astNodeName);
    AstNode_NONTERMINAL_BLOCK(deamer::AstInformation* astInformation);

    AstNode_NONTERMINAL_BLOCK(std::vector<AstNode_RULES*>* RULES1);

    void Accept(deamer::AstVisitor& ast_visitor);

};
}
#endif //ASTNODES_ASTNODE_NONTERMINAL_BLOCK_H

