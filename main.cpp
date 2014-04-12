//
//  main.cpp
//  Lab4
//
//  Created by Bryce Holton.
//	Added on by Daniel Wong and Adam Miller

#include <iostream>
#include "common.h"
#include "Print.h"
#include "Scanner.h"
#include "Token.h"
#include "BinaryTree.h"

FILE *init_lister(const char *name, char source_file_name[], char dte[]);
void quit_scanner(FILE *src_file, Token *list);
void add_token_to_list(Token *list, Token *new_token);

int main(int argc, const char * argv[])
{
    /******************************************
     This is not a correct implementation, you will need to modfy this
     so that it satisfies the project problem.  Currently, this just
     prints every token and then deletes every token.
     *****************************************/
    Token *token = NULL;
	TreeNode *root = NULL; // root of Binary Tree
    char source_name[MAX_FILE_NAME_LENGTH];
    char date[DATE_STRING_LENGTH];
    FILE *source_file = init_lister(argv[1], source_name, date);
    Print print(source_name, date);
    Scanner scanner(source_file, source_name, date, print);
    
    do
    {
        token = scanner.getToken();
        print.printToken(token);
		if(token->getCode() == IDENTIFIER && root == NULL)
		{
			TreeNode *rootNode;
			rootNode = new TreeNode(token,token->getLineNumber());
			root = rootNode;
		}
		else
		{
			if(token->getCode() == IDENTIFIER)
			{
				TreeNode *newNode;
				newNode = new TreeNode(token,token->getLineNumber());
				root->insertNode(token,token->getLineNumber());
			}
		}
        if (token->getCode() != PERIOD && token->getCode() != END_OF_FILE
			&& token->getCode() != IDENTIFIER)
        {
            delete token;
        }
    }
    while (token->getCode() != PERIOD && token->getCode() != END_OF_FILE);
    
	cout << "\nCross Reference Information\nIdentifier\t\tLine Numbers\n";
	cout << "-----------		------------\n";
	print.printBinaryTree(root);

    delete token;
    fclose(source_file);
    return 0;
}
FILE *init_lister(const char *name, char source_file_name[], char dte[])
{
    time_t timer;
    FILE *file;
    
    strcpy(source_file_name, name);
    file = fopen(source_file_name, "r");
    time(&timer);
    strcpy(dte, asctime(localtime(&timer)));
    return file;
}

