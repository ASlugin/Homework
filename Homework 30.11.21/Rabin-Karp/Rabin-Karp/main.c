#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "RabinKarp.h"
#include "Test.h"

#define SIZE 500

int main(int argc, char* argv[])
{
    if (!testPassed())
    {
        if (argc <= 1)
        {
            printf("Tests failed!\n");
        }
        return -1;
    }
    if (argc > 1)
    {
        return 0;
    }

    char searchString[SIZE] = {'\0'};
    printf("Enter string for search in text: ");
    gets_s(searchString, SIZE);
    int result = rabinKarpSearchInFile(searchString, "Input.txt");
    switch (result)
    {
        case -2:
        {
            printf("File not found!\n");
            return -1;
        }
        case -1:
        {
            printf("Such string is not found in file\n");
            return 0;
        }
        default:
        {
            printf("Position of first occurrence of string in file: %d\n", result);
            return 0;
        }
    }
}