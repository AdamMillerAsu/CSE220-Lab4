//
//  BinaryTree.cpp
//  Lab4
//
//  Created by Daniel Wong and Adam Miller
//

#include <string.h>
#include "Token.h"
#include "BinaryTree.h"
LineList::void setLineNumber(int lineNumber) // setters
{
	this->lineNumber = lineNumber;
}
LineList::void setNext(LineList next)
{
	this->next = &next;
}

LineList::int getLineNumber() // getters
{
	return lineNumber;
}
LineList::LineList* getNext()
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

TreeNode::void setLeft(treeNode *leftNode) // setters
{
	left = leftNode;
}
TreeNode::void setRight(treeNode *rightNode)
{
	right = rightNode;
}
	treeNode* getRight() // getters
{
	return right;
}
TreeNode::treeNode* getLeft()
{
	return left;
}
TreeNode::treeNode(Token *id, int lineNum) // constructor
{
	LineList *newNum;
	newNum = new LineList(lineNum);
	line = newNum;
	left = NULL;
	right = NULL;
	this->id = id;
}
TreeNode::~treeNode() // destructor
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
TreeNode::void insertNode(Token *add, int lineNum)
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
				treeNode *newNode;
				newNode = new treeNode(add, lineNum);
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
				treeNode *newNode;
				newNode = new treeNode(add, lineNum);
				right = newNode;
			}
			else
			{
				right->insertNode(add, lineNum);
			}
		}
	}
}
