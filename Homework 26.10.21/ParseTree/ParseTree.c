#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Tree.h"
#include "Test.h"

int main()
{
    if (!areTestsPassing())
    {
        printf("Test failed!");
        return -1;
    }

    Tree* tree = createTreeAndReadFromFile("Input.txt");
    if (tree == NULL)
    {
        return -1;
    }
    printTree(tree);
    
    const int result = calculate(tree);
    printf("%d", result);

    deleteTree(&tree);
    return 0;
}
