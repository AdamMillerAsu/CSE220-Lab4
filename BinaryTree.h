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

struct TreeNode
{
private:
	struct Token *id;
	struct LineList *line;
	struct TreeNode *left;
	struct TreeNode *right;
public:
	void setLeft(TreeNode *leftNode);
	void setRight(TreeNode *rightNode);
	TreeNode* getRight();
	TreeNode* getLeft();
	TreeNode(Token *id, int lineNum);
	~TreeNode();
	void insertNode(Token *add, int lineNum);
};
#endif
