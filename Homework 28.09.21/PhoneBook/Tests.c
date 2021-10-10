#include "Tests.h"
#include "ActionsOnPhoneBook.h"
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

bool testForFindNumber()
{
    PhoneBook testArray[10];
    int count = 0;
    readInitialFile(testArray, &count, "FileTest.txt");
    char nameForSearch[3][10] =
    {
        {'I', 'v', 'a', 'n', '\0'},
        {'M', 'a', 's', 'h', 'a', '\0'},
        {'V', 'a', 'n', 'y', 'a', '\0'}
    };
    char resultSearch[3][15] =
    {
        {'8', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\0'},
        {'4', '5', '6', '7', '8', '9', '1', '2', '3', '0', '\0'},
        {'N', 'o', 't', 'h', 'i', 'n', 'g', ' ', 'f', 'o', 'u', 'n', 'd', '\0'}
    };
    for (int i = 0; i < 3; ++i)
    {
        if (strcmp(findNumberByName(testArray, nameForSearch[i], count), resultSearch[i]) != 0)
        {
            return false;
        }
    }
    return true;
}

bool testForFindName()
{
    PhoneBook testArray[10];
    int count = 0;
    readInitialFile(testArray, &count, "FileTest.txt");
    char numberForSearch[3][15] =
    {
        {'8', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\0'},
        {'4', '5', '6', '7', '8', '9', '1', '2', '3', '0', '\0'},
        {'4', '5', '6', '7', '9', '9', '1', '2', '3', '0', '\0'}
    };
    char resultSearch[3][15] =
    {
        {'I', 'v', 'a', 'n', '\0'},
        {'M', 'a', 's', 'h', 'a', '\0'},
        {'N', 'o', 't', 'h', 'i', 'n', 'g', ' ', 'f', 'o', 'u', 'n', 'd', '\0'}
    };
    for (int i = 0; i < 3; ++i)
    {
        if (strcmp(findNameByNumber(testArray, numberForSearch[i], count), resultSearch[i]) != 0)
        {
            return false;
        }
    }
    return true;
}

bool testReadInitialFile()
{
    PhoneBook testArray[10];
    int count = 0;
    readInitialFile(testArray, &count, "FileTest.txt");
    if (count != 3)
    {
        return false;
    }
    if (strcmp(testArray[0].name, "Ivan") != 0 || strcmp(testArray[1].name, "Vasya") != 0 || strcmp(testArray[2].name, "Masha") != 0)
    {
        return false;
    }
    if (strcmp(testArray[0].number, "8123456789") != 0 || strcmp(testArray[1].number, "987654321") != 0 || strcmp(testArray[2].number, "4567891230") != 0)
    {
        return false;
    }
    return true;
}

bool testSaveData()
{
    PhoneBook testArray[10];
    int count = 0;
    readInitialFile(testArray, &count, "FileTest.txt");
    if (saveData(testArray, count, "EmptyFileForTestSaveData.txt") == -1)
    {
        return false;
    }
    PhoneBook resultArray[10];
    int resultCount = 0;
    readInitialFile(resultArray, &resultCount, "EmptyFileForTestSaveData.txt");
    if (resultCount != 3)
    {
        return false;
    }
    if (strcmp(resultArray[0].name, "Ivan") != 0 || strcmp(resultArray[1].name, "Vasya") != 0 || strcmp(resultArray[2].name, "Masha") != 0)
    {
        return false;
    }
    if (strcmp(resultArray[0].number, "8123456789") != 0 || strcmp(resultArray[1].number, "987654321") != 0 || strcmp(resultArray[2].number, "4567891230") != 0)
    {
        return false;
    }
    FILE* emptyFile = fopen("EmptyFileForTestSaveData.txt", "w");
    fclose(emptyFile);
    return true;
}

bool tests()
{
    return testForFindNumber() && testForFindName() && testReadInitialFile() && testSaveData();
}
