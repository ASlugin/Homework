#include "Test.h"
#include "AVLtree.h"
#include <string.h>

#define AMOUNT 6
#define SIZE 300

bool isTestPassing(void)
{
    Tree* treeTest = createTree();
    if (treeTest == NULL)
    {
        return false;
    }
    int arrayKey[AMOUNT] = {1, 7, 5, 3, 15, 20};
    char arrayValue[AMOUNT][SIZE] = {"ab", "qwe", "rty", "cd", "fg", "rt"};
    
    for (int i = 0; i < AMOUNT; ++i)
    {
        if (!add(treeTest, arrayKey[i], arrayValue[i]))
        {
            deleteTree(&treeTest);
            return false;
        }
    }
    
    for (int i = 0; i < AMOUNT; ++i)
    {
        if (!treeContainThisKey(treeTest, arrayKey[i]) || strcmp(arrayValue[i], getValueByKey(treeTest, arrayKey[i])) != 0)
        {
            deleteTree(&treeTest);
            return false;
        }
    }
    
    deleteNodeByKey(treeTest, 5);
    deleteNodeByKey(treeTest, 7);
    if (treeContainThisKey(treeTest, 5) || treeContainThisKey(treeTest, 7) || treeContainThisKey(treeTest, 50) || treeContainThisKey(treeTest, 6))
    {
        deleteTree(&treeTest);
        return false;
    }

    deleteTree(&treeTest);
    return isEmpty(treeTest);
}
