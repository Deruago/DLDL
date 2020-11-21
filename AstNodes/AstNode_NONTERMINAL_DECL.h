#ifndef ASTNODES_ASTNODE_NONTERMINAL_DECL_H
#define ASTNODES_ASTNODE_NONTERMINAL_DECL_H
#include "AstNode_STMT.h"

#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include "AstEnum.h"
#include <vector>
namespace deamer {
class AstVisitor;
}
namespace DLDL {

class AstNode_VARNAME;
class AstNode_NONTERMINAL_BLOCK;
class AstNode_NONTERMINAL_DECL : public AstNode_STMT
{
private:
protected:
public:
    DLDL::AstEnum_t AstType = DLDL::AstEnum_t::NONTERMINAL_DECL;

    AstNode_VARNAME* VARNAME1_ = nullptr;
    AstNode_NONTERMINAL_BLOCK* NONTERMINAL_BLOCK1_ = nullptr;

    unsigned int GetAstId() override;
    AstNode_NONTERMINAL_DECL(std::vector<deamer::AstNode*> astNodes);
    AstNode_NONTERMINAL_DECL(bool isNode, std::string astNodeName);
    AstNode_NONTERMINAL_DECL(deamer::AstInformation* astInformation);

    AstNode_NONTERMINAL_DECL(AstNode_VARNAME* VARNAME1, AstNode_NONTERMINAL_BLOCK* NONTERMINAL_BLOCK1);

    void Accept(deamer::AstVisitor& ast_visitor);

};
}
#endif //ASTNODES_ASTNODE_NONTERMINAL_DECL_H

