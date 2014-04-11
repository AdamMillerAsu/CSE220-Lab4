//
//  main.cpp
//  Lab4
//
//  Created by Daniel Wong, Adam Miller, and Mike Burgett
//

#include <string.h>
#include "Token.h"
#include <stdio.h>
struct LineList
{
private:
	int lineNumber;
	struct LineList *next;
public:
	//getter functions
	void setLineNumber(int lineNumber)
	{
		this->lineNumber = lineNumber;
	}
	void setNext(LineList next)
	{
		this->next = &next;
	}
	//setter functions
	int getLineNumber()
	{
		return lineNumber;
	}
	LineList getNext()
	{
		return *next;
	}

	LineList(int line) // constructor
	{
		lineNumber = line;
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
	void insertNode(Token *add, int lineNum)
	{
		if(add->getTokenString().compare(id->getTokenString()) == 0)
		{
			LineList *newNum = new LineList(lineNum);
			LineList *temp = line;
			while(&temp->getNext() != NULL)
			{
				temp = &temp->getNext();
			}
			temp->setNext(*newNum);
		}
		else
		{
			if(add->getTokenString().compare(id->getTokenString()) < 0)
			{

			}
		}
	}
};
