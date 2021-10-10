#pragma once

typedef struct
{
    char name[50];
    char number[30];
} PhoneBook;

//Reads data from a file into an array
void readInitialFile(PhoneBook* array, int* count, char file[]);

//Saves the actual data from the array to a file
int saveData(PhoneBook* array, int count, char file[]);

//Searches the array for a phone number that matches the name, if not found returns "Nothing Found"
char* findNumberByName(PhoneBook* array, char name[], const int count);

//Searches the array for a name that matches the phone number, if not found returns "Nothing Found"
char* findNameByNumber(PhoneBook* array, char number[], const int count);