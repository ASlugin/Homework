#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Tree.h"
#include "Test.h"

int main(int argc, char* argv[])
{
    if (!areTestsPassing())
    {
        if (argc <= 1)
        {
            printf("Test failed!");
        }
        return -1;
    }
    if (argc > 1)
    {
        return 0;
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
