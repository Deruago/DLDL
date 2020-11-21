#include "./DLDL_AstVisitor.h"
#include "AstEnum.h"
#include "AstNodes.h"
#include <iostream>

void DLDL::DLDL_AstVisitor::Visit(AstTree_PROG& ast_node)
{
    if (ast_node.STMTS1_ != nullptr)
    {
        for(int i = (*ast_node.STMTS1_).size() - 1; i >= 0; i--)
        {
            (*ast_node.STMTS1_)[i]->Accept(*this);
        }
    }
}

void DLDL::DLDL_AstVisitor::Visit(AstNode_STMTS& ast_node)
{
    if (ast_node.STMT1_ != nullptr)
    {
        ast_node.STMT1_->Accept(*this);
    }
}

void DLDL::DLDL_AstVisitor::Visit(AstNode_STMT& ast_node)
{
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
}

void DLDL::DLDL_AstVisitor::Visit(AstNode_ABSTRACTION& ast_node)
{
}

void DLDL::DLDL_AstVisitor::Visit(AstNode_TERMINALS& ast_node)
{
    if (ast_node.TERMINAL_DECL1_ != nullptr)
    {
        ast_node.TERMINAL_DECL1_->Accept(*this);
    }
}

void DLDL::DLDL_AstVisitor::Visit(AstNode_TERMINAL_DECL& ast_node)
{
	std::string Name = ast_node.VARNAME1_->name;
	std::string Regex;
    if (ast_node.VARLIST1_ != nullptr)
    {
        for(int i = (*ast_node.VARLIST1_).size() - 1; i >= 0; i--)
        {
			Regex += (*ast_node.VARLIST1_)[i]->VARNAME1_->name;
			if (i >= 1)
			{
				Regex +=  + " ";
			}
        }
    }
	
	TerminalSymbol* terminal = new TerminalSymbol(Name, Regex);
	TerminalSymbols_.push_back(*terminal);
	Symbols_.push_back(terminal);
    if (ast_node.TERMINAL_BLOCK1_ != nullptr)
    {
        ast_node.TERMINAL_BLOCK1_->Accept(*this);
    }
}

void DLDL::DLDL_AstVisitor::Visit(AstNode_NONTERMINAL_DECL& ast_node)
{
	std::string Name = ast_node.VARNAME1_->name;
    if (ast_node.NONTERMINAL_BLOCK1_ != nullptr)
    {
        ast_node.NONTERMINAL_BLOCK1_->Accept(*this);
    }
	NonTerminalSymbol* non_terminal = new NonTerminalSymbol(Name, current_production_rules);
	NonTerminalSymbols_.push_back(*non_terminal);
	Symbols_.push_back(non_terminal);
}

void DLDL::DLDL_AstVisitor::Visit(AstNode_ABSTRACTION_DECL& ast_node)
{
    if (ast_node.ABSTRACTION1_ != nullptr)
    {
        ast_node.ABSTRACTION1_->Accept(*this);
    }
	std::vector<std::string> abstraction_direct_input;
    if (ast_node.VARLIST1_ != nullptr)
    {
        for(int i = (*ast_node.VARLIST1_).size() - 1; i >= 0; i--)
        {
			abstraction_direct_input.push_back((*ast_node.VARLIST1_)[i]->VARNAME1_->name);
        }
    }
	std::vector<std::string> abstraction_content;
    if (ast_node.ABSTRACTION_BLOCK1_ != nullptr)
    {
        ast_node.ABSTRACTION_BLOCK1_->Accept(*this);
    }
	
	Symbol* abstracted_symbol;
	switch(current_abstraction_val)
	{
	case ABSTRACTION_TYPE::TERMINAL:
		abstracted_symbol = new Abstraction_Terminal(abstraction_direct_input, abstraction_content);
		break;
	case ABSTRACTION_TYPE::NON_TERMINAL:
		abstracted_symbol = new Abstraction_NonTerminal(abstraction_direct_input, abstraction_content);
		break;
	case ABSTRACTION_TYPE::DELETE:
		abstracted_symbol = new Abstraction_Delete(abstraction_direct_input, abstraction_content);
		break;
	case ABSTRACTION_TYPE::IGNORE:
		abstracted_symbol = new Abstraction_Ignore(abstraction_direct_input, abstraction_content);
		break;
	case ABSTRACTION_TYPE::GROUP:	
		abstracted_symbol = new Abstraction_Group(abstraction_direct_input, abstraction_content);
		break;
	case ABSTRACTION_TYPE::START:	
		abstracted_symbol = new Abstraction_Start(abstraction_direct_input, abstraction_content);
		EncounteredStartType = true;
		break;
	case ABSTRACTION_TYPE::ALIAS:	
		abstracted_symbol = new Abstraction_Alias(abstraction_direct_input, abstraction_content);
		break;
	case ABSTRACTION_TYPE::UNIQUE:	
		abstracted_symbol = new Abstraction_Unique(abstraction_direct_input, abstraction_content);
		break;
	case ABSTRACTION_TYPE::DEFAULT:
		break;
	}
	Symbols_.push_back(abstracted_symbol);
	//AbstractedSymbols_.push_back(abstracted_symbol);
	
	current_abstraction_val = ABSTRACTION_TYPE::DEFAULT;
}

void DLDL::DLDL_AstVisitor::Visit(AstNode_RULE_DECL& ast_node)
{
    if (ast_node.VARLIST1_ != nullptr)
    {
        ProductionRule current_production_rule = {};
        for(int i = (*ast_node.VARLIST1_).size() - 1; i >= 0; i--)
        {
            current_production_rule.Symbols.push_back({ (*ast_node.VARLIST1_)[i]->VARNAME1_->name });
        }
		current_production_rules.push_back(current_production_rule);
    }
    if (ast_node.GENERAL_BLOCK1_ != nullptr)
    {
        ast_node.GENERAL_BLOCK1_->Accept(*this);
    }
}

void DLDL::DLDL_AstVisitor::Visit(AstNode_TERMINAL_BLOCK& ast_node)
{
    if (ast_node.GENERAL_BLOCK1_ != nullptr)
    {
        ast_node.GENERAL_BLOCK1_->Accept(*this);
    }
}

void DLDL::DLDL_AstVisitor::Visit(AstNode_NONTERMINAL_BLOCK& ast_node)
{
    if (ast_node.RULES1_ != nullptr)
    {
		current_production_rules = {};
        for(int i = (*ast_node.RULES1_).size() - 1; i >= 0; i--)
        {
            (*ast_node.RULES1_)[i]->Accept(*this);
        }
    }
}

void DLDL::DLDL_AstVisitor::Visit(AstNode_RULES& ast_node)
{
    if (ast_node.RULE_DECL1_ != nullptr)
    {
        ast_node.RULE_DECL1_->Accept(*this);
    }
}

void DLDL::DLDL_AstVisitor::Visit(AstNode_ABSTRACTION_BLOCK& ast_node)
{
    if (ast_node.ABSTRACTION_INPUTS1_ != nullptr)
    {
        for(int i = (*ast_node.ABSTRACTION_INPUTS1_).size() - 1; i >= 0; i--)
        {
            (*ast_node.ABSTRACTION_INPUTS1_)[i]->Accept(*this);
        }
    }
}

void DLDL::DLDL_AstVisitor::Visit(AstNode_ABSTRACTION_INPUTS& ast_node)
{
    if (ast_node.ABSTRACTION_INPUT1_ != nullptr)
    {
        ast_node.ABSTRACTION_INPUT1_->Accept(*this);
    }
}

void DLDL::DLDL_AstVisitor::Visit(AstNode_ABSTRACTION_INPUT& ast_node)
{
    if (ast_node.VARLIST1_ != nullptr)
    {
        for(int i = (*ast_node.VARLIST1_).size() - 1; i >= 0; i--)
        {
            (*ast_node.VARLIST1_)[i]->Accept(*this);
        }
    }
}

void DLDL::DLDL_AstVisitor::Visit(AstNode_GENERAL_BLOCK& ast_node)
{
    if (ast_node.VARLIST1_ != nullptr)
    {
        for(int i = (*ast_node.VARLIST1_).size() - 1; i >= 0; i--)
        {
            (*ast_node.VARLIST1_)[i]->Accept(*this);
        }
    }
}

void DLDL::DLDL_AstVisitor::Visit(AstNode_VARLIST& ast_node)
{
}

void DLDL::DLDL_AstVisitor::Visit(AstNode_DELETE& ast_node)
{
	current_abstraction_val = ABSTRACTION_TYPE::DELETE;
}

void DLDL::DLDL_AstVisitor::Visit(AstNode_IGNORE& ast_node)
{
	current_abstraction_val = ABSTRACTION_TYPE::IGNORE;
}

void DLDL::DLDL_AstVisitor::Visit(AstNode_TERMINAL& ast_node)
{
	current_abstraction_val = ABSTRACTION_TYPE::TERMINAL;
}

void DLDL::DLDL_AstVisitor::Visit(AstNode_NONTERMINAL& ast_node)
{
	current_abstraction_val = ABSTRACTION_TYPE::NON_TERMINAL;
}

void DLDL::DLDL_AstVisitor::Visit(AstNode_GROUP& ast_node)
{
	current_abstraction_val = ABSTRACTION_TYPE::GROUP;
}

void DLDL::DLDL_AstVisitor::Visit(AstNode_ALIAS& ast_node)
{
	current_abstraction_val = ABSTRACTION_TYPE::ALIAS;
}

void DLDL::DLDL_AstVisitor::Visit(AstNode_START& ast_node)
{
	current_abstraction_val = ABSTRACTION_TYPE::START;
}

void DLDL::DLDL_AstVisitor::Visit(AstNode_COMMENT& ast_node)
{
	//current_abstraction_val = ABSTRACTION_TYPE::COMMENT;
}

void DLDL::DLDL_AstVisitor::Visit(AstNode_UNIQUE& ast_node)
{
	current_abstraction_val = ABSTRACTION_TYPE::UNIQUE;
}

void DLDL::DLDL_AstVisitor::Visit(AstNode_TYPE& ast_node)
{
	//current_abstraction_val = ABSTRACTION_TYPE::TYPE;
}

void DLDL::DLDL_AstVisitor::Visit(AstNode_VARNAME& ast_node)
{
}

void DLDL::DLDL_AstVisitor::Dispatch(deamer::AstNode& ast_node)
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


