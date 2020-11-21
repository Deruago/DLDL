#ifndef ASTNODES_ASTNODE_RULES_H
#define ASTNODES_ASTNODE_RULES_H

#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include "AstEnum.h"
#include <vector>
namespace deamer {
class AstVisitor;
}
namespace DLDL {

class AstNode_RULE_DECL;
class AstNode_RULES : public deamer::AstNode
{
private:
protected:
public:
    DLDL::AstEnum_t AstType = DLDL::AstEnum_t::RULES;

    AstNode_RULE_DECL* RULE_DECL1_ = nullptr;

    unsigned int GetAstId() override;
    AstNode_RULES(std::vector<deamer::AstNode*> astNodes);
    AstNode_RULES(bool isNode, std::string astNodeName);
    AstNode_RULES(deamer::AstInformation* astInformation);

    AstNode_RULES(AstNode_RULE_DECL* RULE_DECL1);

    void Accept(deamer::AstVisitor& ast_visitor);

};
}
#endif //ASTNODES_ASTNODE_RULES_H

