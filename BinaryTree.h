//
//  BinaryTree.h
//  Lab4
//
//  Created by Daniel Wong and Adam Miller
//

#ifndef Lab4_BinaryTree_h
#define Lab4_BinaryTree_h

#include <string.h>
#include "Token.h"

struct LineList
{
private:
	int lineNumber;
	struct LineList *next;
public:
	void setLineNumber(int lineNumber);
	void setNext(LineList next);
	int getLineNumber();
	LineList* getNext();
	LineList(int line);
	~LineList();
};

struct treeNode
{
private:
	struct Token *id;
	struct LineList *line;
	struct treeNode *left;
	struct treeNode *right;
public:
	void setLeft(treeNode *leftNode);
	void setRight(treeNode *rightNode);
	treeNode* getRight();
	treeNode* getLeft();
	treeNode(Token *id, int lineNum);
	~treeNode();
	void insertNode(Token *add, int lineNum);
};
#endif
