#include "./DLDL_AstPrinter.h"
#include "AstEnum.h"
#include "AstNodes.h"
#include <iostream>

void DLDL::DLDL_AstPrinter::Visit(AstTree_PROG& ast_node)
{
    std::cout << MakeIndentation() << "PROG" << std::endl;

    depth++;
    if (ast_node.STMTS1_ != nullptr)
    {
        for(int i = (*ast_node.STMTS1_).size() - 1; i >= 0; i--)
        {
            (*ast_node.STMTS1_)[i]->Accept(*this);
        }
    }
    --depth;
}

void DLDL::DLDL_AstPrinter::Visit(AstNode_STMTS& ast_node)
{

    if (ast_node.STMT1_ != nullptr)
    {
        ast_node.STMT1_->Accept(*this);
    }
}

void DLDL::DLDL_AstPrinter::Visit(AstNode_STMT& ast_node)
{
    std::cout << MakeIndentation() << "STMT" << std::endl;

    depth++;
    if (ast_node.TERMINAL_DECL1_ != nullptr)
    {
        ast_node.TERMINAL_DECL1_->Accept(*this);
    }
    if (ast_node.NONTERMINAL_DECL1_ != nullptr)
    {
        ast_node.NONTERMINAL_DECL1_->Accept(*this);
    }
    if (ast_node.ABSTRACTION_DECL1_ != nullptr)
    {
        ast_node.ABSTRACTION_DECL1_->Accept(*this);
    }
    --depth;
}

void DLDL::DLDL_AstPrinter::Visit(AstNode_ABSTRACTION& ast_node)
{
    std::cout << MakeIndentation() << "ABSTRACTION" << std::endl;

    depth++;
    if (ast_node.DELETE1_ != nullptr)
    {
        ast_node.DELETE1_->Accept(*this);
    }
    if (ast_node.IGNORE1_ != nullptr)
    {
        ast_node.IGNORE1_->Accept(*this);
    }
    if (ast_node.TERMINAL1_ != nullptr)
    {
        ast_node.TERMINAL1_->Accept(*this);
    }
    if (ast_node.NONTERMINAL1_ != nullptr)
    {
        ast_node.NONTERMINAL1_->Accept(*this);
    }
    if (ast_node.GROUP1_ != nullptr)
    {
        ast_node.GROUP1_->Accept(*this);
    }
    if (ast_node.ALIAS1_ != nullptr)
    {
        ast_node.ALIAS1_->Accept(*this);
    }
    if (ast_node.START1_ != nullptr)
    {
        ast_node.START1_->Accept(*this);
    }
    if (ast_node.COMMENT1_ != nullptr)
    {
        ast_node.COMMENT1_->Accept(*this);
    }
    if (ast_node.UNIQUE1_ != nullptr)
    {
        ast_node.UNIQUE1_->Accept(*this);
    }
    if (ast_node.TYPE1_ != nullptr)
    {
        ast_node.TYPE1_->Accept(*this);
    }
    --depth;
}

void DLDL::DLDL_AstPrinter::Visit(AstNode_TERMINALS& ast_node)
{

    if (ast_node.TERMINAL_DECL1_ != nullptr)
    {
        ast_node.TERMINAL_DECL1_->Accept(*this);
    }
}

void DLDL::DLDL_AstPrinter::Visit(AstNode_TERMINAL_DECL& ast_node)
{
    std::cout << MakeIndentation() << "TERMINAL_DECL" << std::endl;

    depth++;
    if (ast_node.VARNAME1_ != nullptr)
    {
        ast_node.VARNAME1_->Accept(*this);
    }
    if (ast_node.VARLIST1_ != nullptr)
    {
        for(int i = (*ast_node.VARLIST1_).size() - 1; i >= 0; i--)
        {
            (*ast_node.VARLIST1_)[i]->Accept(*this);
        }
    }
    if (ast_node.TERMINAL_BLOCK1_ != nullptr)
    {
        ast_node.TERMINAL_BLOCK1_->Accept(*this);
    }
    --depth;
}

void DLDL::DLDL_AstPrinter::Visit(AstNode_NONTERMINAL_DECL& ast_node)
{
    std::cout << MakeIndentation() << "NONTERMINAL_DECL" << std::endl;

    depth++;
    if (ast_node.VARNAME1_ != nullptr)
    {
        ast_node.VARNAME1_->Accept(*this);
    }
    if (ast_node.NONTERMINAL_BLOCK1_ != nullptr)
    {
        ast_node.NONTERMINAL_BLOCK1_->Accept(*this);
    }
    --depth;
}

void DLDL::DLDL_AstPrinter::Visit(AstNode_ABSTRACTION_DECL& ast_node)
{
    std::cout << MakeIndentation() << "ABSTRACTION_DECL" << std::endl;

    depth++;
    if (ast_node.ABSTRACTION1_ != nullptr)
    {
        ast_node.ABSTRACTION1_->Accept(*this);
    }
    if (ast_node.VARLIST1_ != nullptr)
    {
        for(int i = (*ast_node.VARLIST1_).size() - 1; i >= 0; i--)
        {
            (*ast_node.VARLIST1_)[i]->Accept(*this);
        }
    }
    if (ast_node.ABSTRACTION_BLOCK1_ != nullptr)
    {
        ast_node.ABSTRACTION_BLOCK1_->Accept(*this);
    }
    --depth;
}

void DLDL::DLDL_AstPrinter::Visit(AstNode_RULE_DECL& ast_node)
{
    std::cout << MakeIndentation() << "RULE_DECL" << std::endl;

    depth++;
    if (ast_node.VARLIST1_ != nullptr)
    {
        for(int i = (*ast_node.VARLIST1_).size() - 1; i >= 0; i--)
        {
            (*ast_node.VARLIST1_)[i]->Accept(*this);
        }
    }
    if (ast_node.GENERAL_BLOCK1_ != nullptr)
    {
        ast_node.GENERAL_BLOCK1_->Accept(*this);
    }
    --depth;
}

void DLDL::DLDL_AstPrinter::Visit(AstNode_TERMINAL_BLOCK& ast_node)
{
    std::cout << MakeIndentation() << "TERMINAL_BLOCK" << std::endl;

    depth++;
    if (ast_node.GENERAL_BLOCK1_ != nullptr)
    {
        ast_node.GENERAL_BLOCK1_->Accept(*this);
    }
    --depth;
}

void DLDL::DLDL_AstPrinter::Visit(AstNode_NONTERMINAL_BLOCK& ast_node)
{
    std::cout << MakeIndentation() << "NONTERMINAL_BLOCK" << std::endl;

    depth++;
    if (ast_node.RULES1_ != nullptr)
    {
        for(int i = (*ast_node.RULES1_).size() - 1; i >= 0; i--)
        {
            (*ast_node.RULES1_)[i]->Accept(*this);
        }
    }
    --depth;
}

void DLDL::DLDL_AstPrinter::Visit(AstNode_RULES& ast_node)
{

    if (ast_node.RULE_DECL1_ != nullptr)
    {
        ast_node.RULE_DECL1_->Accept(*this);
    }
}

void DLDL::DLDL_AstPrinter::Visit(AstNode_ABSTRACTION_BLOCK& ast_node)
{
    std::cout << MakeIndentation() << "ABSTRACTION_BLOCK" << std::endl;

    depth++;
    if (ast_node.ABSTRACTION_INPUTS1_ != nullptr)
    {
        for(int i = (*ast_node.ABSTRACTION_INPUTS1_).size() - 1; i >= 0; i--)
        {
            (*ast_node.ABSTRACTION_INPUTS1_)[i]->Accept(*this);
        }
    }
    --depth;
}

void DLDL::DLDL_AstPrinter::Visit(AstNode_ABSTRACTION_INPUTS& ast_node)
{

    if (ast_node.ABSTRACTION_INPUT1_ != nullptr)
    {
        ast_node.ABSTRACTION_INPUT1_->Accept(*this);
    }
}

void DLDL::DLDL_AstPrinter::Visit(AstNode_ABSTRACTION_INPUT& ast_node)
{
    std::cout << MakeIndentation() << "ABSTRACTION_INPUT" << std::endl;

    depth++;
    if (ast_node.VARLIST1_ != nullptr)
    {
        for(int i = (*ast_node.VARLIST1_).size() - 1; i >= 0; i--)
        {
            (*ast_node.VARLIST1_)[i]->Accept(*this);
        }
    }
    --depth;
}

void DLDL::DLDL_AstPrinter::Visit(AstNode_GENERAL_BLOCK& ast_node)
{
    std::cout << MakeIndentation() << "GENERAL_BLOCK" << std::endl;

    depth++;
    if (ast_node.VARLIST1_ != nullptr)
    {
        for(int i = (*ast_node.VARLIST1_).size() - 1; i >= 0; i--)
        {
            (*ast_node.VARLIST1_)[i]->Accept(*this);
        }
    }
    --depth;
}

void DLDL::DLDL_AstPrinter::Visit(AstNode_VARLIST& ast_node)
{

    if (ast_node.VARNAME1_ != nullptr)
    {
        ast_node.VARNAME1_->Accept(*this);
    }
}

void DLDL::DLDL_AstPrinter::Visit(AstNode_DELETE& ast_node)
{
    ast_node.PrintNode(depth);
}

void DLDL::DLDL_AstPrinter::Visit(AstNode_IGNORE& ast_node)
{
    ast_node.PrintNode(depth);
}

void DLDL::DLDL_AstPrinter::Visit(AstNode_TERMINAL& ast_node)
{
    ast_node.PrintNode(depth);
}

void DLDL::DLDL_AstPrinter::Visit(AstNode_NONTERMINAL& ast_node)
{
    ast_node.PrintNode(depth);
}

void DLDL::DLDL_AstPrinter::Visit(AstNode_GROUP& ast_node)
{
    ast_node.PrintNode(depth);
}

void DLDL::DLDL_AstPrinter::Visit(AstNode_ALIAS& ast_node)
{
    ast_node.PrintNode(depth);
}

void DLDL::DLDL_AstPrinter::Visit(AstNode_START& ast_node)
{
    ast_node.PrintNode(depth);
}

void DLDL::DLDL_AstPrinter::Visit(AstNode_COMMENT& ast_node)
{
    ast_node.PrintNode(depth);
}

void DLDL::DLDL_AstPrinter::Visit(AstNode_UNIQUE& ast_node)
{
    ast_node.PrintNode(depth);
}

void DLDL::DLDL_AstPrinter::Visit(AstNode_TYPE& ast_node)
{
    ast_node.PrintNode(depth);
}

void DLDL::DLDL_AstPrinter::Visit(AstNode_VARNAME& ast_node)
{
    ast_node.PrintNode(depth);
}

void DLDL::DLDL_AstPrinter::Dispatch(deamer::AstNode& ast_node)
{
    switch(ast_node.GetAstId())
    {
    case DLDL::AstEnum_t::PROG:
        Visit(static_cast<AstTree_PROG&>(ast_node));
        break;
    case DLDL::AstEnum_t::STMTS:
        Visit(static_cast<AstNode_STMTS&>(ast_node));
        break;
    case DLDL::AstEnum_t::STMT:
        Visit(static_cast<AstNode_STMT&>(ast_node));
        break;
    case DLDL::AstEnum_t::ABSTRACTION:
        Visit(static_cast<AstNode_ABSTRACTION&>(ast_node));
        break;
    case DLDL::AstEnum_t::TERMINALS:
        Visit(static_cast<AstNode_TERMINALS&>(ast_node));
        break;
    case DLDL::AstEnum_t::TERMINAL_DECL:
        Visit(static_cast<AstNode_TERMINAL_DECL&>(ast_node));
        break;
    case DLDL::AstEnum_t::NONTERMINAL_DECL:
        Visit(static_cast<AstNode_NONTERMINAL_DECL&>(ast_node));
        break;
    case DLDL::AstEnum_t::ABSTRACTION_DECL:
        Visit(static_cast<AstNode_ABSTRACTION_DECL&>(ast_node));
        break;
    case DLDL::AstEnum_t::RULE_DECL:
        Visit(static_cast<AstNode_RULE_DECL&>(ast_node));
        break;
    case DLDL::AstEnum_t::TERMINAL_BLOCK:
        Visit(static_cast<AstNode_TERMINAL_BLOCK&>(ast_node));
        break;
    case DLDL::AstEnum_t::NONTERMINAL_BLOCK:
        Visit(static_cast<AstNode_NONTERMINAL_BLOCK&>(ast_node));
        break;
    case DLDL::AstEnum_t::RULES:
        Visit(static_cast<AstNode_RULES&>(ast_node));
        break;
    case DLDL::AstEnum_t::ABSTRACTION_BLOCK:
        Visit(static_cast<AstNode_ABSTRACTION_BLOCK&>(ast_node));
        break;
    case DLDL::AstEnum_t::ABSTRACTION_INPUTS:
        Visit(static_cast<AstNode_ABSTRACTION_INPUTS&>(ast_node));
        break;
    case DLDL::AstEnum_t::ABSTRACTION_INPUT:
        Visit(static_cast<AstNode_ABSTRACTION_INPUT&>(ast_node));
        break;
    case DLDL::AstEnum_t::GENERAL_BLOCK:
        Visit(static_cast<AstNode_GENERAL_BLOCK&>(ast_node));
        break;
    case DLDL::AstEnum_t::VARLIST:
        Visit(static_cast<AstNode_VARLIST&>(ast_node));
        break;
    case DLDL::AstEnum_t::DELETE:
        Visit(static_cast<AstNode_DELETE&>(ast_node));
        break;
    case DLDL::AstEnum_t::IGNORE:
        Visit(static_cast<AstNode_IGNORE&>(ast_node));
        break;
    case DLDL::AstEnum_t::TERMINAL:
        Visit(static_cast<AstNode_TERMINAL&>(ast_node));
        break;
    case DLDL::AstEnum_t::NONTERMINAL:
        Visit(static_cast<AstNode_NONTERMINAL&>(ast_node));
        break;
    case DLDL::AstEnum_t::GROUP:
        Visit(static_cast<AstNode_GROUP&>(ast_node));
        break;
    case DLDL::AstEnum_t::ALIAS:
        Visit(static_cast<AstNode_ALIAS&>(ast_node));
        break;
    case DLDL::AstEnum_t::START:
        Visit(static_cast<AstNode_START&>(ast_node));
        break;
    case DLDL::AstEnum_t::COMMENT:
        Visit(static_cast<AstNode_COMMENT&>(ast_node));
        break;
    case DLDL::AstEnum_t::UNIQUE:
        Visit(static_cast<AstNode_UNIQUE&>(ast_node));
        break;
    case DLDL::AstEnum_t::TYPE:
        Visit(static_cast<AstNode_TYPE&>(ast_node));
        break;
    case DLDL::AstEnum_t::VARNAME:
        Visit(static_cast<AstNode_VARNAME&>(ast_node));
        break;
    }
}

std::string DLDL::DLDL_AstPrinter::MakeIndentation()
{
    std::string indentation;
    for(unsigned i = 0; i < depth; i++)
    {
        indentation += MakeIndent();
    }
    return indentation;
}

std::string DLDL::DLDL_AstPrinter::MakeIndent()
{
    std::string indent;
    for(unsigned i = 0; i < indent_size; i++)
    {
        indent += ' ';
    }
    return indent;
}

