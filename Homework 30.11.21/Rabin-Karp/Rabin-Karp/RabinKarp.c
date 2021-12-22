#define _CRT_SECURE_NO_WARNINGS
#include "RabinKarp.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 500
#define MULTIPLIER 7
#define MODULE 9999999999

int hash(const char string[], const int start, const int length)
{
    int hash = 0;
    for (int i = 0; i < length; ++i)
    {
        hash = (hash * MULTIPLIER + string[start + i]) % MODULE;
    }
    return hash;
}

int rollingHash(const int prevHash, const char string[], int start, int length)
{
    int multiplier = 1;
    for (int i = 0; i < length - 1; ++i)
    {
        multiplier *= MULTIPLIER;
    }
    int hash = ((prevHash - multiplier * string[start - 1]) * MULTIPLIER + string[start + length -1]) % MODULE;
    return hash;
}

bool stringsMatch(const char searchString[], const char string[], const int start, const int length)
{
    for (int i = 0; i < length; ++i)
    {
        if (searchString[i] != string[start + i])
        {
            return false;
        }
    }
    return true;
}

// Returns position of first occurrence searchString in string
// Returns -1 if searchString not found in string
int rabinKarpSearchInString(const char searchString[], const char string[])
{
    int lengthSearchString = strlen(searchString);
    int lengthString = strlen(string);
    if (lengthSearchString > lengthString)
    {
        return -1;
    }
    int hashSearchString = hash(searchString, 0, lengthSearchString);
    int hashStringForComparison = hash(string, 0, lengthSearchString);
    if (hashSearchString == hashStringForComparison && stringsMatch(searchString, string, 0, lengthSearchString))
    {
        return 0;
    }
    for (int i = 1; i < lengthString - lengthSearchString + 1; ++i)
    {
        hashStringForComparison = rollingHash(hashStringForComparison, string, i, lengthSearchString);
        if (hashSearchString == hashStringForComparison && stringsMatch(searchString, string, i, lengthSearchString))
        {
            return i;
        }
    }
    return -1;
}

int rabinKarpSearchInFile(const char searchString[], const char nameFile[])
{
    FILE* file = fopen(nameFile, "r");
    if (file == NULL)
    {
        return -2;
    }

    int countSymbolsInText = 0;
    while (!feof(file))
    {
        char stringFromFile[SIZE] = {'\0'};
        fgets(stringFromFile, SIZE, file);
        int result = rabinKarpSearchInString(searchString, stringFromFile);
        if (result != -1)
        {
            fclose(file);
            return result + countSymbolsInText;
        }
        countSymbolsInText += strlen(stringFromFile) - 1; // "-1" --- not counting '\n'
    }
    fclose(file);
    return -1;
}