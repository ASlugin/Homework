#include "Test.h"
#include "Tree.h"
#include <string.h>

#define AMOUNT 6
#define SIZE 300

bool testTreeContainKey(Tree* treeTest, const int* arrayKey)
{
    for (int i = 0; i < AMOUNT; ++i)
    {
        if (!treeContainThisKey(treeTest, arrayKey[i]))
        {
            deleteTree(&treeTest);
            return false;
        }
    }
    if (treeContainThisKey(treeTest, 6) || treeContainThisKey(treeTest, 10))
    {
        deleteTree(&treeTest);
        return false;
    }
    return true;
}

bool areTestPassing()
{
    Tree* treeTest = createTree();
    if (treeTest == NULL || !isEmpty(treeTest))
    {
        return false;
    }

    int arrayKey[AMOUNT] = {3, 1, 2, 5, 4, 7};
    char arrayValue[AMOUNT][SIZE] = {"root", "left1", "right12", "right2", "left21", "right22"};
    for (int i = 0; i < AMOUNT; ++i)
    {
        if (!add(treeTest, arrayKey[i], arrayValue[i]))
        {
            deleteTree(&treeTest);
            return false;
        }
    }
    if (!testTreeContainKey(treeTest, arrayKey))
    {
        deleteTree(&treeTest);
        return false;
    }

    for (int i = 0; i < AMOUNT; ++i)
    {
        if (strcmp(arrayValue[i], getValueByKey(treeTest, arrayKey[i])) != 0)
        {
            deleteTree(&treeTest);
            return false;
        }
    }
    if (getValueByKey(treeTest, 6) != NULL || getValueByKey(treeTest, 10) != NULL)
    {
        deleteTree(&treeTest);
        return false;
    }

    if (!deleteNodeByKey(treeTest, 3) || treeContainThisKey(treeTest, 3))
    {
        deleteTree(&treeTest);
        return false;
    }
    if (!deleteNodeByKey(treeTest, 7) || treeContainThisKey(treeTest, 7))
    {
        deleteTree(&treeTest);
        return false;
    }
    
    deleteTree(&treeTest);
    return isEmpty(treeTest);
}