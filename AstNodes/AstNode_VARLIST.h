#ifndef ASTNODES_ASTNODE_VARLIST_H
#define ASTNODES_ASTNODE_VARLIST_H

#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include "AstEnum.h"
#include <vector>
namespace deamer {
class AstVisitor;
}
namespace DLDL {

class AstNode_VARNAME;
class AstNode_VARLIST : public deamer::AstNode
{
private:
protected:
public:
    DLDL::AstEnum_t AstType = DLDL::AstEnum_t::VARLIST;

    AstNode_VARNAME* VARNAME1_ = nullptr;

    unsigned int GetAstId() override;
    AstNode_VARLIST(std::vector<deamer::AstNode*> astNodes);
    AstNode_VARLIST(bool isNode, std::string astNodeName);
    AstNode_VARLIST(deamer::AstInformation* astInformation);

    AstNode_VARLIST(AstNode_VARNAME* VARNAME1);

    void Accept(deamer::AstVisitor& ast_visitor);

};
}
#endif //ASTNODES_ASTNODE_VARLIST_H

