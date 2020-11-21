#ifndef ASTNODES_ASTNODE_VARNAME_H
#define ASTNODES_ASTNODE_VARNAME_H

#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include "AstEnum.h"
#include <vector>
namespace deamer {
class AstVisitor;
}
namespace DLDL {

class AstNode_VARNAME : public deamer::AstNode
{
private:
protected:
public:
    DLDL::AstEnum_t AstType = DLDL::AstEnum_t::VARNAME;
	std::string name;

    unsigned int GetAstId() override;
    AstNode_VARNAME(std::vector<deamer::AstNode*> astNodes);
    AstNode_VARNAME(bool isNode, std::string astNodeName);
    AstNode_VARNAME(deamer::AstInformation* astInformation);


    void Accept(deamer::AstVisitor& ast_visitor);

};
}
#endif //ASTNODES_ASTNODE_VARNAME_H

