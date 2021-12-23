#include "GraphToDotFile.h"
#include "Test.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    if (!testPassed())
    {
        if (argc < 1)
        {
            printf("Test failed!");
        }
        return -1;
    }
    if (argc > 2)
    {
        return -0;
    }

    if (!generateDotFile("Input.txt", "graph.dot"))
    {
        return -1;
    }
    return 0;
}
