#ifndef ASTNODES_ASTNODE_ABSTRACTION_H
#define ASTNODES_ASTNODE_ABSTRACTION_H

#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include "AstEnum.h"
#include <vector>
namespace deamer {
class AstVisitor;
}
namespace DLDL {

class AstNode_DELETE;
class AstNode_IGNORE;
class AstNode_TERMINAL;
class AstNode_NONTERMINAL;
class AstNode_GROUP;
class AstNode_ALIAS;
class AstNode_START;
class AstNode_COMMENT;
class AstNode_UNIQUE;
class AstNode_TYPE;
class AstNode_ABSTRACTION : public deamer::AstNode
{
private:
protected:
public:
    DLDL::AstEnum_t AstType = DLDL::AstEnum_t::ABSTRACTION;

    AstNode_DELETE* DELETE1_ = nullptr;
    AstNode_IGNORE* IGNORE1_ = nullptr;
    AstNode_TERMINAL* TERMINAL1_ = nullptr;
    AstNode_NONTERMINAL* NONTERMINAL1_ = nullptr;
    AstNode_GROUP* GROUP1_ = nullptr;
    AstNode_ALIAS* ALIAS1_ = nullptr;
    AstNode_START* START1_ = nullptr;
    AstNode_COMMENT* COMMENT1_ = nullptr;
    AstNode_UNIQUE* UNIQUE1_ = nullptr;
    AstNode_TYPE* TYPE1_ = nullptr;

    unsigned int GetAstId() override;
    AstNode_ABSTRACTION(std::vector<deamer::AstNode*> astNodes);
    AstNode_ABSTRACTION(bool isNode, std::string astNodeName);
    AstNode_ABSTRACTION(deamer::AstInformation* astInformation);

    AstNode_ABSTRACTION(AstNode_DELETE* DELETE1);
    AstNode_ABSTRACTION(AstNode_IGNORE* IGNORE1);
    AstNode_ABSTRACTION(AstNode_TERMINAL* TERMINAL1);
    AstNode_ABSTRACTION(AstNode_NONTERMINAL* NONTERMINAL1);
    AstNode_ABSTRACTION(AstNode_GROUP* GROUP1);
    AstNode_ABSTRACTION(AstNode_ALIAS* ALIAS1);
    AstNode_ABSTRACTION(AstNode_START* START1);
    AstNode_ABSTRACTION(AstNode_COMMENT* COMMENT1);
    AstNode_ABSTRACTION(AstNode_UNIQUE* UNIQUE1);
    AstNode_ABSTRACTION(AstNode_TYPE* TYPE1);

    void Accept(deamer::AstVisitor& ast_visitor);

};
}
#endif //ASTNODES_ASTNODE_ABSTRACTION_H

