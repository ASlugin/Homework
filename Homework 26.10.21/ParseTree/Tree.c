#define _CRT_SECURE_NO_WARNINGS
#include "Tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node
{
    char operation;
    int operand;
    struct Node* leftSon;
    struct Node* rightSon;
} Node;

typedef struct Tree
{
    Node* root;
} Tree;

bool isEmpty(Tree* tree)
{
    return tree == NULL || tree->root == NULL;
}

bool isOperator(const char symbol)
{
    return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}

bool isDigit(const char symbol)
{
    return symbol >= '0' && symbol <= '9';
}

bool isNegativeNumber(char* string, int* position)
{
    return string[*position] == '-' && isDigit(string[*position + 1]);
}

int number(char* string, int* position, bool* success)
{
    char* stringForNumber = calloc(strlen(string), sizeof(char));
    if (stringForNumber == NULL)
    {
        *success = false;
        return 0;
    }

    int result = 0;
    if (isNegativeNumber(string, position))
    {
        strcpy(stringForNumber, string + (*position) + 1);
        (*position)++;
        result = -1 * atoi(stringForNumber);
    }
    else
    {
        strcpy(stringForNumber, string + (*position));
        result = atoi(stringForNumber);
    }
    
    while (string[*position] != '\0' && isDigit(string[*position]))
    {
        (*position)++;
    }
    free(stringForNumber);
    *success = true;
    return result;
}

Node* addNodeRecursive(char* string, int* position)
{
    int length = strlen(string);
    while ((*position) < length && !isOperator(string[*position]) && !isDigit(string[*position]))
    {
        (*position)++;
    }
    
    Node* newNode = calloc(1, sizeof(Node));
    if (newNode == NULL)
    {
        return NULL;
    }
    
    if (isOperator(string[*position]) && !isNegativeNumber(string, position))
    {
        newNode->operation = string[*position];
        (*position)++;
        newNode->leftSon = addNodeRecursive(string, position);
        if (newNode->leftSon == NULL)
        {
            free(newNode);
            return NULL;
        }
        newNode->rightSon = addNodeRecursive(string, position);
        if (newNode->rightSon == NULL)
        {
            free(newNode->leftSon);
            free(newNode);
            return NULL;
        }
    }
    else if (isDigit(string[*position]) || isNegativeNumber(string, position))
    {
        bool success = true;
        newNode->operand = number(string, position, &success);
        if (!success)
        {
            free(newNode);
            return NULL;
        }
    }
    
    return newNode;
}

Tree* createTreeAndReadFromFile(const char fileName[])
{
    Tree* tree = calloc(1, sizeof(Tree));
    if (tree == NULL)
    {
        return NULL;
    }
    FILE* file = fopen(fileName, "r");
    if (file == NULL)
    {
        free(tree);
        return NULL;
    }

    #define SIZE 500
    char expression[SIZE + 1] = {"\0"};
    fgets(expression, SIZE, file);
    fclose(file);

    int position = 0;
    tree->root = addNodeRecursive(expression, &position);
    if (tree->root == NULL)
    {
        free(tree);
        return NULL;
    }
    return tree;
}

void deleteNodeRecursive(Node* nodeForDelete)
{
    if (nodeForDelete == NULL)
    {
        return;
    }
    deleteNodeRecursive(nodeForDelete->leftSon);
    deleteNodeRecursive(nodeForDelete->rightSon);
    free(nodeForDelete);
}

void deleteTree(Tree** tree)
{
    deleteNodeRecursive((*tree)->root);
    free(*tree);
    *tree = NULL;
}

void printNode(Node* node)
{
    if (node->leftSon == NULL && node->rightSon == NULL)
    {
        printf("%d", node->operand);
        return;
    }
    printf("(%c ", node->operation);
    printNode(node->leftSon);
    printf(" ");
    printNode(node->rightSon);
    printf(")");
}

void printTree(Tree* tree)
{
    if (isEmpty(tree))
    {
        printf("\n");
        return;
    }
    printNode(tree->root);
    printf("\n");
}

int calculateNode(Node* node)
{
    if (node->leftSon == NULL && node->rightSon == NULL)
    {
        return node->operand;
    }
    int first = calculateNode(node->leftSon);
    int second = calculateNode(node->rightSon);
    switch (node->operation)
    {
        case '+':
        {
            return first + second;
        }
        case '-':
        {
            return first - second;
        }
        case '*':
        {
            return first * second;
        }
        case '/':
        {
            return first / second;
        }
        default:
        {
            return 0;
        }
    }
}

int calculate(Tree* tree)
{
    if (isEmpty(tree))
    {
        return 0;
    }
    return calculateNode(tree->root);
}