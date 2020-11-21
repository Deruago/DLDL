#ifndef ASTNODES_ASTNODE_STMT_H
#define ASTNODES_ASTNODE_STMT_H

#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include "AstEnum.h"
#include <vector>
namespace deamer {
class AstVisitor;
}
namespace DLDL {

class AstNode_TERMINAL_DECL;
class AstNode_NONTERMINAL_DECL;
class AstNode_ABSTRACTION_DECL;
class AstNode_STMT : public deamer::AstNode
{
private:
protected:
public:
    DLDL::AstEnum_t AstType = DLDL::AstEnum_t::STMT;

    AstNode_TERMINAL_DECL* TERMINAL_DECL1_ = nullptr;
    AstNode_NONTERMINAL_DECL* NONTERMINAL_DECL1_ = nullptr;
    AstNode_ABSTRACTION_DECL* ABSTRACTION_DECL1_ = nullptr;

    unsigned int GetAstId() override;
    AstNode_STMT(std::vector<deamer::AstNode*> astNodes);
    AstNode_STMT(bool isNode, std::string astNodeName);
    AstNode_STMT(deamer::AstInformation* astInformation);

    AstNode_STMT(AstNode_TERMINAL_DECL* TERMINAL_DECL1);
    AstNode_STMT(AstNode_NONTERMINAL_DECL* NONTERMINAL_DECL1);
    AstNode_STMT(AstNode_ABSTRACTION_DECL* ABSTRACTION_DECL1);

    void Accept(deamer::AstVisitor& ast_visitor);

};
}
#endif //ASTNODES_ASTNODE_STMT_H

