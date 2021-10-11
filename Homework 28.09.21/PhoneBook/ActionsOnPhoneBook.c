#include "ActionsOnPhoneBook.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void readInitialFile(PhoneBook* array, int* count, const char file[])
{
    FILE* book = fopen(file, "r");
    if (book == NULL)
    {
        return;
    }
    while (!feof(book))
    {
        fscanf(book, "%s %s\n", array[(*count)].name, array[(*count)].number);
        (*count)++;
    }
    fclose(book);
}

int saveData(const PhoneBook* array, const int count, const char file[])
{
    FILE* phonesBook = fopen(file, "w");
    if (phonesBook == NULL)
    {
        return -1;
    }
    for (int i = 0; i < count; ++i)
    {
        fprintf(phonesBook, "%s %s\n", array[i].name, array[i].number);
    }
    fclose(phonesBook);
    return 1;
}

const char* findNumberByName(const PhoneBook* array, const char name[], const int count)
{
    for (int i = 0; i < count; ++i)
    {
        if (strcmp(array[i].name, name) == 0)
        {
            return array[i].number;
        }
    }
    return NULL;
}

const char* findNameByNumber(const PhoneBook* array, const char number[], const int count)
{
    for (int i = 0; i < count; ++i)
    {
        if (strcmp(array[i].number, number) == 0)
        {
            return array[i].name;
        }
    }
    return NULL;
}