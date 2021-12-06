#include "Tree.h"
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    char* value;
    struct Node* leftSon;
    struct Node* rightSon;
    struct Node* parent;
} Node;

typedef struct Tree
{
    Node* root;
} Tree;

Tree* createTree()
{
    return calloc(1, sizeof(Tree));
}

bool isEmpty(Tree* tree)
{
    if (tree == NULL)
    {
        return true;
    }
    return tree->root == NULL;
}

void deleteNodeRecursive(Node* nodeForDelete)
{
    if (nodeForDelete->rightSon != NULL)
    {
        deleteNodeRecursive(nodeForDelete->rightSon);
        nodeForDelete->rightSon = NULL;
    }
    if (nodeForDelete->leftSon != NULL)
    {
        deleteNodeRecursive(nodeForDelete->leftSon);
        nodeForDelete->leftSon = NULL;
    }
    free(nodeForDelete->value);
    free(nodeForDelete);
}

void deleteTree(Tree** tree)
{
    if ((*tree) == NULL)
    {
        return;
    }
    if ((*tree)->root != NULL)
    {
        deleteNodeRecursive((*tree)->root);
    }
    free(*tree);
    *tree = NULL;
}

Node* searchNode(Tree* tree, const int key)
{
    if (isEmpty(tree))
    {
        return NULL;
    }
    Node* current = tree->root;
    while (current != NULL && current->key != key)
    {
        if (key < current->key)
        {
            current = current->leftSon;
        }
        else
        {
            current = current->rightSon;
        }
    }
    if (current != NULL && current->key == key)
    {
        return current;
    }
    return NULL;
}

char* getValueByKey(Tree* tree, const int key)
{
    Node* nodeWithThisKey = searchNode(tree, key);
    if (nodeWithThisKey == NULL)
    {
        return NULL;
    }
    return nodeWithThisKey->value;
}

bool treeContainThisKey(Tree* tree, const int key)
{
    return searchNode(tree, key) != NULL;
}

bool add(Tree* tree, const int key, const char value[])
{
    if (tree == NULL)
    {
        return false;
    }
    
    Node* newNode = searchNode(tree, key);
    if (newNode != NULL)
    {
        free(newNode->value);
        newNode->value = calloc(strlen(value) + 1, sizeof(char));
        if (newNode->value == NULL)
        {
            return false;
        }
        strcpy(newNode->value, value);
        return true;
    }
    
    newNode = calloc(1, sizeof(Node));
    if (newNode == NULL)
    {
        return false;
    }
    newNode->key = key;

    newNode->value = calloc(strlen(value) + 1, sizeof(char));
    if (newNode->value == NULL)
    {
        free(newNode);
        return false;
    }
    strcpy(newNode->value, value);

    if (isEmpty(tree))
    {
        tree->root = newNode;
        newNode->parent = NULL;
        return true;
    }
    
    Node* parent = tree->root;
    while (key < parent->key && parent->leftSon != NULL || key >= parent->key && parent->rightSon != NULL)
    {
        if (key < parent->key)
        {
            parent = parent->leftSon;
        }
        else
        {
            parent = parent->rightSon;
        }
    }
    
    if (key < parent->key)
    {
        parent->leftSon = newNode;
    }
    else
    {
        parent->rightSon = newNode;
    }
    newNode->parent = parent;
    return true;
}

void moveSonToParent(Node* nodeForDelete, Node* son)
{
    if (son != NULL)
    {
        son->parent = nodeForDelete->parent;
    }

    if (nodeForDelete == nodeForDelete->parent->leftSon)
    {
        nodeForDelete->parent->leftSon = son;
    }
    else
    {
        nodeForDelete->parent->rightSon = son;
    }
}

bool deleteNode(Tree* tree, Node* nodeForDelete)
{
    if (nodeForDelete->leftSon == NULL && nodeForDelete->rightSon == NULL)
    {
        if (nodeForDelete->parent != NULL)
        {
            moveSonToParent(nodeForDelete, NULL);
        }
        else
        {
            tree->root = NULL;
        }
        free(nodeForDelete->value);
        free(nodeForDelete);
        return true;
    }

    if (nodeForDelete->leftSon == NULL)
    {
        if (nodeForDelete->parent != NULL)
        {
            moveSonToParent(nodeForDelete, nodeForDelete->parent);
            free(nodeForDelete->value);
            free(nodeForDelete);
            return true;
        }
        else
        {
            nodeForDelete->rightSon->parent = NULL;
            tree->root = nodeForDelete->rightSon;
            free(nodeForDelete->value);
            free(nodeForDelete);
            return true;
        }
    }
    if (nodeForDelete->rightSon == NULL)
    {
        if (nodeForDelete->parent != NULL)
        {
            moveSonToParent(nodeForDelete, nodeForDelete->leftSon);
            free(nodeForDelete->value);
            free(nodeForDelete);
            return true;
        }
        else
        {
            nodeForDelete->leftSon->parent = NULL;
            tree->root = nodeForDelete->leftSon;
            free(nodeForDelete->value);
            free(nodeForDelete);
            return true;
        }
    }

    Node* nodeForSwap = nodeForDelete->leftSon;
    while (nodeForSwap->rightSon != NULL)
    {
        nodeForSwap = nodeForSwap->rightSon;
    }

    nodeForDelete->key = nodeForSwap->key;
    free(nodeForDelete->value);
    nodeForDelete->value = calloc(strlen(nodeForSwap->value) + 1, sizeof(char));
    if (nodeForDelete->value == NULL)
    {
        return false;
    }
    strcpy(nodeForDelete->value, nodeForSwap->value);
    return deleteNode(tree, nodeForSwap);
}

bool deleteNodeByKey(Tree* tree, const int key)
{
    Node* nodeForDelete = searchNode(tree, key);
    if (nodeForDelete == NULL)
    {
        return true;
    }
    return deleteNode(tree, nodeForDelete);
}