#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "ActionsOnPhoneBook.h"
#include "Tests.h"

int main()
{
    if (!tests())
    {
        printf("%s", "Tests failed!");
        return 0;
    }
    PhoneBook records[101];
    int countRecords = 0;
    readInitialFile(records, &countRecords, "PhoneBook.txt");

    printf("%s", "Phonebook commands:\n0 - exit\n1 - add record (name and number)\n2 - print all available records\n");
    printf("%s", "3 - find number phone by name\n4 - find name by number phone\n5 - save actual data to the file\n");
    while (1)
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
                printf("%s\n", findNumberByName(records, nameSearch, countRecords));
                break;
            }
            case 4:
            {
                char numberSearch[30];
                printf("%s", "Enter number for search: ");
                scanf("%s", numberSearch);
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