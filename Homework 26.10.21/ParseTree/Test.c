#include "Test.h"
#include "Tree.h"
#include <stddef.h>

bool areTestPassing()
{
    Tree* treeTest = createTreeAndReadFromFile("InputTest.txt");
    if (treeTest == NULL)
    {
        return false;
    }
    if (calculate(treeTest) != -257)
    {
        deleteTree(&treeTest);
        return false;
    }
    deleteTree(&treeTest);
    return treeTest == NULL;
}