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
    const char nameForSearch[3][10] =
    {
        {"Ivan"},
        {"Masha"},
        {"Vanya"}
    };
    const char resultSearch[2][15] =
    {
        {"8123456789"},
        {"4567891230"}
    };
    for (int i = 0; i < 2; ++i)
    {
        if (strcmp(findNumberByName(testArray, nameForSearch[i], count), resultSearch[i]) != 0)
        {
            return false;
        }
    }    
    return findNumberByName(testArray, nameForSearch[2], count) == NULL;
}

bool testForFindName()
{
    PhoneBook testArray[10];
    int count = 0;
    readInitialFile(testArray, &count, "FileTest.txt");
    const char numberForSearch[3][15] =
    {
        {"8123456789"},
        {"4567891230"},
        {"4567991230"}
    };
    const char resultSearch[2][15] =
    {
        {"Ivan"},
        {"Masha"}
    };
    for (int i = 0; i < 2; ++i)
    {
        if (strcmp(findNameByNumber(testArray, numberForSearch[i], count), resultSearch[i]) != 0)
        {
            return false;
        }
    }
    return findNameByNumber(testArray, numberForSearch[2], count) == NULL;
}

bool testReadInitialFile()
{
    PhoneBook testArray[10];
    int count = 0;
    readInitialFile(testArray, &count, "FileTest.txt");
    if (count != 3 || strcmp(testArray[0].name, "Ivan") != 0 || strcmp(testArray[1].name, "Vasya") != 0 || strcmp(testArray[2].name, "Masha") != 0)
    {
        return false;
    }
    return strcmp(testArray[0].number, "8123456789") == 0 && strcmp(testArray[1].number, "987654321") == 0 && strcmp(testArray[2].number, "4567891230") == 0;
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
    if (resultCount != 3 || strcmp(resultArray[0].name, "Ivan") != 0 || strcmp(resultArray[1].name, "Vasya") != 0 || strcmp(resultArray[2].name, "Masha") != 0)
    {
        return false;
    }
    FILE* emptyFile = fopen("EmptyFileForTestSaveData.txt", "w");
    fclose(emptyFile);
    return strcmp(resultArray[0].number, "8123456789") == 0 && strcmp(resultArray[1].number, "987654321") == 0 && strcmp(resultArray[2].number, "4567891230") == 0;
}

bool tests()
{
    return testForFindNumber() && testForFindName() && testReadInitialFile() && testSaveData();
}
