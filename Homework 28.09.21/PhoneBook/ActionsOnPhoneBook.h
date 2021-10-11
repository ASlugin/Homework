#pragma once

//struct for phone book, includes name and phone number
typedef struct
{
    char name[50];
    char number[30];
} PhoneBook;

//Reads data from a file into an array
void readInitialFile(PhoneBook* array, int* count, const char file[]);

//Saves the actual data from the array to a file
int saveData(const PhoneBook* array, const int count, const char file[]);

//Searches the array for a phone number that matches the name, if not found returns NULL
const char* findNumberByName(const PhoneBook* array, const char name[], const int count);

//Searches the array for a name that matches the phone number, if not found returns NULL
const char* findNameByNumber(const PhoneBook* array, const char number[], const int count);