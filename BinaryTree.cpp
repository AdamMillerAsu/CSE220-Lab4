//
//  BinaryTree.cpp
//  Lab4
//
//  Created by Daniel Wong and Adam Miller
//

#include <string.h>
#include "Token.h"
#include "BinaryTree.h"
void LineList::setLineNumber(int lineNumber) // setters
{
	this->lineNumber = lineNumber;
}
void LineList::setNext(LineList next)
{
	this->next = &next;
}

int LineList::getLineNumber() // getters
{
	return lineNumber;
}
LineList* LineList::getNext()
{
	return next;
}
LineList::LineList(int line) // constructor
{
	setLineNumber(line);
	next = NULL;
}

LineList::~LineList() // destructor
{
	delete next;
	next = NULL;
}

void TreeNode::setLeft(TreeNode *leftNode) // setters
{
	left = leftNode;
}
void TreeNode::setRight(TreeNode *rightNode)
{
	right = rightNode;
}
TreeNode* TreeNode::getRight() // getters
{
	return right;
}
TreeNode* TreeNode::getLeft()
{
	return left;
}
TreeNode::TreeNode(Token *id, int lineNum) // constructor
{
	LineList *newNum;
	newNum = new LineList(lineNum);
	line = newNum;
	left = NULL;
	right = NULL;
	this->id = id;
}
TreeNode::~TreeNode() // destructor
{
	delete left;
	left = NULL;
	delete right;
	right = NULL;
	delete line;
	line = NULL;
	delete id;
	id = NULL;
}
void TreeNode::insertNode(Token *add, int lineNum)
{
	if(add->getTokenString().compare(id->getTokenString()) == 0) // if string is the same
	{
		LineList *newNum; 
		newNum = new LineList(lineNum);
		LineList *temp = line;
		while(temp->getNext() != NULL) // add line number
		{
			temp = temp->getNext();
		}
		temp->setNext(*newNum);
	}
	else
	{
		if(add->getTokenString().compare(id->getTokenString()) < 0) // if string is less than
		{
			if(left == NULL) // add node if left is empty
			{
				TreeNode *newNode;
				newNode = new TreeNode(add, lineNum);
				left = newNode;
			}
			else // recursively call insertNode
			{
				left->insertNode(add, lineNum);
			}
		} // if string is greater than
		else
		{
			if(right == NULL)
			{
				TreeNode *newNode;
				newNode = new TreeNode(add, lineNum);
				right = newNode;
			}
			else
			{
				right->insertNode(add, lineNum);
			}
		}
	}
}
