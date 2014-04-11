//
//  main.cpp
//  Lab4
//
//  Created by Daniel Wong, Adam Miller, and Mike Burgett
//

#include <string.h>
#include "Token.h"
struct LineList
{
private:
	int lineNumber;
	struct LineList *next;
public:
	
	void setLineNumber(int lineNumber) // setters
	{
		this->lineNumber = lineNumber;
	}
	void setNext(LineList next)
	{
		this->next = &next;
	}
	
	int getLineNumber() // getters
	{
		return lineNumber;
	}
	LineList* getNext()
	{
		return next;
	}

	LineList(int line) // constructor
	{
		setLineNumber(line);
		next = NULL;
	}
	
	~LineList() // destructor
	{
		delete next;
		next = NULL;
	}
};

struct treeNode
{
private:
	struct Token *id;
	struct LineList *line;
	struct treeNode *left;
	struct treeNode *right;
public:

	void setLeft(treeNode *leftNode) // setters
	{
		left = leftNode;
	}
	void setRight(treeNode *rightNode)
	{
		right = rightNode;
	}

	treeNode* getRight() // getters
	{
		return right;
	}
	treeNode* getLeft()
	{
		return left;
	}

	treeNode(Token *id, int lineNum) // constructor
	{
		LineList *newNum;
		newNum = new LineList(lineNum);
		line = newNum;
		left = NULL;
		right = NULL;
		this->id = id;
	}

	~treeNode() // destructor
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

	void insertNode(Token *add, int lineNum)
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
};
