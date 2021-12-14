#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 20

void binToDec(char* binArray, char* result)
{
    int decNumber = 0;
    const int amount = strlen(binArray);
    for (int i = amount - 1; i >= 0; --i)
    {
        decNumber = decNumber | (binArray[i] & 1) << (amount - 1 - i);
    }
    _itoa(decNumber, result, 10);
}

bool isTestPassing(void)
{
    #define AMOUNTTEST 3
    char binString[AMOUNTTEST][SIZE] = {"101", "110011", "11101010"};
    const char resultString[AMOUNTTEST][SIZE] = {"5", "51", "234" };
    for (int i = 0; i < AMOUNTTEST; ++i)
    {
        char result[SIZE] = {'\0'};
        binToDec(binString[i], result);
        if (strcmp(resultString[i], result) != 0)
        {
            return false;
        }
    }
    return true;
}

int main(void)
{
    if (!isTestPassing())
    {
        printf("Test failed!");
        return -1;
    }

    char string[SIZE] = {'\0'};
    printf("Enter binary number: ");
    scanf("%s", string);

    char result[SIZE] = {'\0'};
    binToDec(string, result);
    printf("Number in decimal form: %s\n", result);
    
    return 0;
}
