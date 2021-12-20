#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "ActionsOnPhoneBook.h"
#include "Tests.h"

int main(int argc, char* argv[])
{
    if (!tests())
    {
        if (argc <= 1)
        {
            printf("%s", "Tests failed!");
        }
        return -1;
    }
    if (argc > 1)
    {
        return 0;
    }

    PhoneBook records[100];
    int countRecords = 0;
    readInitialFile(records, &countRecords, "PhoneBook.txt");

    printf("%s", "Phonebook commands:\n");
    printf("%s", "0 - exit\n");
    printf("%s", "1 - add record (name and number)\n");
    printf("%s", "2 - print all available records\n");
    printf("%s", "3 - find number phone by name\n");
    printf("%s", "4 - find name by number phone\n");
    printf("%s", "5 - save actual data to the file\n");

    while (true)
    {
        int code = -1;
        printf("%s", "Enter code: ");
        scanf("%d", &code);
        switch (code)
        {
            case 0:
            {
                return 0;
            }
            case 1:
            {
                if (countRecords < 100)
                {
                    printf("%s", "Enter name and number: ");
                    scanf("%s %s", &records[countRecords].name, &records[countRecords].number);
                    ++countRecords;
                }
                else
                {
                    printf("%s\n", "Can not add more than 100 records to the phone book");
                }
                break;
            }
            case 2:
            {    
                for (int i = 0; i < countRecords; ++i)
                {
                    printf("%s %s\n", records[i].name, records[i].number);
                }
                break;
            }
            case 3:
            {
                printf("%s", "Enter name for search: ");
                char nameSearch[50];
                scanf("%s", nameSearch);
                if (findNumberByName(records, nameSearch, countRecords) == NULL)
                {
                    printf("%s\n", "Nothing found");
                    break;
                }
                printf("%s\n", findNumberByName(records, nameSearch, countRecords));
                break;
            }
            case 4:
            {
                char numberSearch[30];
                printf("%s", "Enter number for search: ");
                scanf("%s", numberSearch);
                if (findNameByNumber(records, numberSearch, countRecords) == NULL)
                {
                    printf("%s\n", "Nothing found");
                    break;
                }
                printf("%s\n", findNameByNumber(records, numberSearch, countRecords));
                break;
            }
            case 5:
            {
                if (saveData(records, countRecords, "PhoneBook.txt") != -1)
                {
                    printf("%s\n", "Data saved");
                }
                else
                {
                    printf("%s", "files not found");
                    return 0;
                }
                break;
            }
            default:
            {
                printf("%s\n", "Incorrect code");
            }
        }
    }
    return 0;
}