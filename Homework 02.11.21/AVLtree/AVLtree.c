#define _CRT_SECURE_NO_WARNINGS
#include "AVLtree.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Node
{
    char* key;
    char* value;
    int balance;
    struct Node* leftSon;
    struct Node* rightSon;
} Node;

typedef struct Tree
{
    Node* root;
} Tree;

Tree* createTree(void)
{
    return calloc(1, sizeof(Tree));
}

bool isEmpty(Tree* tree)
{
    return tree == NULL || tree->root == NULL;
}

void deleteNodeRecursive(Node* nodeForDelete)
{
    if (nodeForDelete == NULL)
    {
        return;
    }
    deleteNodeRecursive(nodeForDelete->rightSon);
    deleteNodeRecursive(nodeForDelete->leftSon);
    free(nodeForDelete->value);
    free(nodeForDelete->key);
    free(nodeForDelete);
}

void deleteTree(Tree** tree)
{
    if (*tree == NULL)
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

// Finds node of tree by key. Returns pointer to node.
// If node with such key not found, returns NULL
Node* searchNode(Tree* tree, const char key[])
{
    if (isEmpty(tree))
    {
        return NULL;
    }
    Node* current = tree->root;
    while (current != NULL && strcmp(current->key, key) != 0)
    {
        if (strcmp(key, current->key) < 0)
        {
            current = current->leftSon;
        }
        else
        {
            current = current->rightSon;
        }
    }
    return current;
}

bool treeContainThisKey(Tree* tree, const char key[])
{
    return searchNode(tree, key) != NULL;
}

Node* rotateLeft(Node* node)
{
    if (node->rightSon == NULL)
    {
        return NULL;
    }
    if (node->rightSon->balance == 0)
    {
        node->balance = 1;
        node->rightSon->balance = -1;
    }
    else if (node->rightSon->balance == 1)
    {
        node->balance = 0;
        node->rightSon->balance = 0;
    }
    Node* newRoot = node->rightSon;
    node->rightSon = newRoot->leftSon;
    newRoot->leftSon = node;
    return newRoot;
}

Node* rotateRight(Node* node)
{
    if (node->leftSon == NULL)
    {
        return NULL;
    }
    if (node->leftSon->balance == -1)
    {
        node->balance = 0;
        node->leftSon->balance = 0;
    }
    else if (node->leftSon->balance == 0)
    {
        node->balance = -1;
        node->leftSon->balance = 1;
    }
    Node* newRoot = node->leftSon;
    node->leftSon = newRoot->rightSon;
    newRoot->rightSon = node;
    return newRoot;
}

Node* bigRotateLeft(Node* node)
{
    if (node->rightSon == NULL || node->rightSon->leftSon == NULL)
    {
        return NULL;
    }
    switch (node->rightSon->leftSon->balance)
    {
        case 0:
        {
            node->balance = 0;
            node->rightSon->balance = 0;
            break;
        }
        case 1:
        {
            node->balance = -1;
            node->rightSon->balance = 0;
            break;
        }
        case -1:
        {
            node->balance = 0;
            node->rightSon->balance = 1;
            break;
        }
    }
    node->rightSon->leftSon->balance = 0;

    Node* newRoot = node->rightSon->leftSon;
    Node* rightNewRoot = node->rightSon;
    node->rightSon = newRoot->leftSon;
    rightNewRoot->leftSon = newRoot->rightSon;
    newRoot->leftSon = node;
    newRoot->rightSon = rightNewRoot;
    return newRoot;
}

Node* bigRotateRight(Node* node)
{
    if (node->leftSon == NULL || node->leftSon->rightSon == NULL)
    {
        return NULL;
    }
    switch (node->leftSon->rightSon->balance)
    {
        case 0:
        {
            node->balance = 0;
            node->leftSon->balance = 0;
            break;
        }
        case 1:
        {
            node->balance = 0;
            node->leftSon->balance = -1;
            break;
        }
        case -1:
        {
            node->balance = 1;
            node->leftSon->balance = 0;
            break;
        }
    }
    node->leftSon->rightSon->balance = 0;

    Node* newRoot = node->leftSon->rightSon;
    Node* leftNewRoot = node->leftSon;
    node->leftSon = newRoot->rightSon;
    leftNewRoot->rightSon = newRoot->leftSon;
    newRoot->leftSon = leftNewRoot;
    newRoot->rightSon = node;
    return newRoot;
}

Node* balance(Node* node)
{
    if (node == NULL)
    {
        return NULL;
    }
    if (node->balance == 2)
    {
        if (node->rightSon->balance >= 0)
        {
            return rotateLeft(node);
        }
        return bigRotateLeft(node);
    }
    else if (node->balance == -2)
    {
        if (node->leftSon->balance <= 0)
        {
            return rotateRight(node);
        }
        return bigRotateRight(node);
    }
    return node;
}

Node* insert(Node* current, const char key[], const char value[], bool* needToCorrectBalance)
{
    if (current == NULL)
    {
        Node* newNode = calloc(1, sizeof(Node));
        if (newNode == NULL)
        {
            return NULL;
        }
        newNode->value = calloc(strlen(value) + 1, sizeof(char));;
        if (newNode->value == NULL)
        {
            free(newNode);
            return NULL;
        }
        newNode->key = calloc(strlen(key) + 1, sizeof(char));
        if (newNode->key == NULL)
        {
            free(newNode->value);
            free(newNode);
            return NULL;
        }
        strcpy(newNode->key, key);
        strcpy(newNode->value, value);
        return newNode;
    }
    if (strcmp(key, current->key) < 0)
    {
        current->leftSon = insert(current->leftSon, key, value, needToCorrectBalance);
        if (*needToCorrectBalance)
        {
            (current->balance)--;
        }
        if (current->balance == 0)
        {
            *needToCorrectBalance = false;
        }
    }
    else
    {
        current->rightSon = insert(current->rightSon, key, value, needToCorrectBalance);
        if (*needToCorrectBalance)
        {
            (current->balance)++;
        }
        if (current->balance == 0)
        {
            *needToCorrectBalance = false;
        }
    }
    Node* result = balance(current);
    if (result->balance == 0)
    {
        *needToCorrectBalance =  false;
    }
    return result;
}

bool add(Tree* tree, const char key[], const char value[])
{
    if (tree == NULL)
    {
        return false;
    }
    
    Node* newNode = searchNode(tree, key);
    if (newNode != NULL)
    {
        char* newValue = calloc(strlen(value) + 1, sizeof(char));
        if (newValue == NULL)
        {
            return false;
        }
        strcpy(newValue, value);
        free(newNode->value);
        newNode->value = newValue;
        return true;
    }
    
    bool needToCorrectBalance = true;
    tree->root = insert(tree->root, key, value, &needToCorrectBalance);
    return tree->root != NULL;
}

Node* deleteNode(Node* node, const char key[], bool* needToCorrectBalance)
{
    if (node == NULL)
    {
        *needToCorrectBalance = false;
        return NULL;
    }

    if (strcmp(node->key, key) == 0)
    {
        if (node->leftSon == NULL && node->rightSon == NULL)
        {
            free(node->value);
            free(node->key);
            free(node);
            return NULL;
        }
        if (node->leftSon == NULL)
        {
            Node* result = node->rightSon;
            free(node->value);
            free(node->key);
            free(node);
            return result;
        }
        if (node->rightSon == NULL)
        {
            Node* result = node->leftSon;
            free(node->value);
            free(node->key);
            free(node);
            return result;
        }

        Node* nodeForSwap = node->leftSon;
        while (nodeForSwap->rightSon != NULL)
        {
            nodeForSwap = nodeForSwap->rightSon;
        }

        char* newKey = calloc(strlen(nodeForSwap->key) + 1, sizeof(char));
        char* newValue = calloc(strlen(nodeForSwap->value) + 1, sizeof(char));
        if (newKey == NULL || newValue == NULL)
        {
            return NULL;
        }
        strcpy(newKey, nodeForSwap->key);
        strcpy(newValue, nodeForSwap->value);
        free(node->key);
        free(node->value);
        node->key = newKey;
        node->value = newValue;

        node->leftSon = deleteNode(node->leftSon, *(nodeForSwap->key), needToCorrectBalance);
        if (*needToCorrectBalance)
        {
            (node->balance)++;
        }
        if (node->balance == 1 || node->balance == -1)
        {
            *needToCorrectBalance = false;
        }
        return balance(node);
    }
    else if (strcmp(key, node->key) < 0)
    {
        node->leftSon = deleteNode(node->leftSon, key, needToCorrectBalance);
        if (*needToCorrectBalance)
        {
            (node->balance)++;
        }
        if (node->balance == 1 || node->balance == -1)
        {
            *needToCorrectBalance = false;
        }
    }
    else
    {
        node->rightSon = deleteNode(node->rightSon, key, needToCorrectBalance);
        if (*needToCorrectBalance)
        {
            (node->balance)--;
        }
        if (node->balance == 1 || node->balance == -1)
        {
            *needToCorrectBalance = false;
        }
    }
    Node* result = balance(node);
    if (node->balance == 1 || node->balance == -1)
    {
        *needToCorrectBalance = false;
    }
    return result;
}

void deleteNodeByKey(Tree* tree, const char key[])
{
    if (isEmpty(tree))
    {
        return;
    }
    bool needToCorrectBalance = true;
    tree->root = deleteNode(tree->root, key, &needToCorrectBalance);
}

char* getValueByKey(Tree* tree, const char key[])
{
    if (isEmpty(tree))
    {
        return NULL;
    }
    Node* nodeWithThiskey = searchNode(tree, key);
    if (nodeWithThiskey == NULL)
    {
        return NULL;
    }
    return nodeWithThiskey->value;
}

int getHeight(Node* node)
{
    if (node == NULL)
    {
        return 0;
    }
    if (node->leftSon == NULL && node->rightSon == NULL)
    {
        return 1;
    }
    return max(getHeight(node->leftSon), getHeight(node->rightSon)) + 1;
}

bool isNodeBalanced(Node* node)
{
    if (getHeight(node->rightSon) - getHeight(node->leftSon) == node->balance && abs(node->balance) <= 1)
    {
        return true;
    }
    return false;
}

bool testBalanceRecursive(Node* node)
{
    if (node == NULL || node->leftSon == NULL && node->rightSon == NULL)
    {
        return true;
    }
    return isNodeBalanced(node) && testBalanceRecursive(node->leftSon) && testBalanceRecursive(node->rightSon);
}

bool isTreeBalanced(Tree* tree)
{
    if (isEmpty(tree))
    {
        return true;
    }
    return testBalanceRecursive(tree->root);
}