#include "AstNode_VARNAME.h"
#include <Deamer/AstGen/AstNode.h>
#include <Deamer/AstGen/AstInformation.h>
#include <vector>
#include <Deamer/AstGen/AstVisitor.h>

DLDL::AstNode_VARNAME::AstNode_VARNAME(bool isNode, std::string astNodeName) : deamer::AstNode::AstNode(true, "VARNAME")

{
}

DLDL::AstNode_VARNAME::AstNode_VARNAME(deamer::AstInformation* astInformation) : deamer::AstNode::AstNode(astInformation, true, "VARNAME")

{
	name = astInformation->ValueName;
	std::string newContent = "";
	int slashEncountered = 0;
	for(const char curChar : name)
	{
		switch(curChar)
		{
			case '\\':
				slashEncountered++;
				newContent += curChar;
				break;
			case 's':
				if (slashEncountered == 1)
				{
					newContent[newContent.size() - 1] = ' ';
				}
				else
				{
					newContent += curChar;
				}
				slashEncountered = 0;
				break;
			default:
				slashEncountered = 0;
				newContent += curChar;
				break;
		}
	}
	name = newContent;
}

DLDL::AstNode_VARNAME::AstNode_VARNAME(std::vector<deamer::AstNode*> astNodes) : deamer::AstNode::AstNode(astNodes, true, "VARNAME")

{
}

unsigned int DLDL::AstNode_VARNAME::GetAstId()
{
    return (unsigned int)DLDL::AstNode_VARNAME::AstType;
}

void DLDL::AstNode_VARNAME::Accept(deamer::AstVisitor& ast_visitor)
{
    ast_visitor.Dispatch(*this);
}


