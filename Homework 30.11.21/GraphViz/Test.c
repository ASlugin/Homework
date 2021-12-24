#define _CRT_SECURE_NO_WARNINGS
#include "Test.h"
#include "GraphToDotFile.h"
#include <stdio.h>
#include <string.h>

#define AMOUNT 9
#define SIZE 100

bool isCorrectString(const char string[], const char numberFrom, const char numberTo, const char weight)
{
    return string[0] == numberFrom && string[5] == numberTo && string[17] == weight;
}
bool testPassed(void)
{
    if (!generateDotFile("InputTest.txt", "graphTest.dot"))
    {
        return false;
    }
    FILE* fileDot = fopen("graphTest.dot", "r");
    if (fileDot == NULL)
    {
        return false;
    }
    const char arrayFrom[AMOUNT][SIZE] = {"0", "0", "0", "1", "2", "2", "3", "4", "4"};
    const char arrayTo[AMOUNT][SIZE] = {"2", "3", "4", "0", "2", "4", "2", "0", "1"};
    const char arrayWeight[AMOUNT][SIZE] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    int counter = 1;

    char string[SIZE] = {'\0'};
    fgets(string, SIZE, fileDot);
    if (strcmp(string, "digraph Graph {\n") != 0)
    {
        fclose(fileDot);
        return false;
    }

    while (!feof(fileDot))
    {
        fgets(string, SIZE, fileDot);
        if (counter == AMOUNT + 1)
        {
            fclose(fileDot);
            return strcmp(string, "}") == 0;
        }

        char correctString[SIZE] = {'\0'};
        strcat(correctString, arrayFrom[counter - 1]);
        strcat(correctString, " -> ");
        strcat(correctString, arrayTo[counter - 1]);
        strcat(correctString, " [label = \"");
        strcat(correctString, arrayWeight[counter - 1]);
        strcat(correctString, "\"];\n");

        if (strcmp(string, correctString) != 0)
        {
            fclose(fileDot);
            return false;
        }
        ++counter;
    }
    fclose(fileDot);
    return true;
}