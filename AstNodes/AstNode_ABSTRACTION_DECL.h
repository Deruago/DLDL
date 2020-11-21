#ifndef ASTNODES_ASTNODE_ABSTRACTION_DECL_H
#define ASTNODES_ASTNODE_ABSTRACTION_DECL_H
#include "AstNode_STMT.h"

#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include "AstEnum.h"
#include <vector>
namespace deamer {
class AstVisitor;
}
namespace DLDL {

class AstNode_ABSTRACTION;
class AstNode_VARLIST;
class AstNode_ABSTRACTION_BLOCK;
class AstNode_ABSTRACTION_DECL : public AstNode_STMT
{
private:
protected:
public:
    DLDL::AstEnum_t AstType = DLDL::AstEnum_t::ABSTRACTION_DECL;

    AstNode_ABSTRACTION* ABSTRACTION1_ = nullptr;
    std::vector<AstNode_VARLIST*>* VARLIST1_ = nullptr;
    AstNode_ABSTRACTION_BLOCK* ABSTRACTION_BLOCK1_ = nullptr;

    unsigned int GetAstId() override;
    AstNode_ABSTRACTION_DECL(std::vector<deamer::AstNode*> astNodes);
    AstNode_ABSTRACTION_DECL(bool isNode, std::string astNodeName);
    AstNode_ABSTRACTION_DECL(deamer::AstInformation* astInformation);

    AstNode_ABSTRACTION_DECL(AstNode_ABSTRACTION* ABSTRACTION1, std::vector<AstNode_VARLIST*>* VARLIST1, AstNode_ABSTRACTION_BLOCK* ABSTRACTION_BLOCK1);

    void Accept(deamer::AstVisitor& ast_visitor);

};
}
#endif //ASTNODES_ASTNODE_ABSTRACTION_DECL_H

