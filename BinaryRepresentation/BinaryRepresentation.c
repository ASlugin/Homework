#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <math.h>

void swapArray(int* array, int amount)
{
    for (int i = 0; i < amount / 2; ++i)
    {
        const int temp = array[i];
        array[i] = array[amount - i - 1];
        array[amount - i - 1] = temp;
    }
}

void convertToAdditionalCode(int* array, int amount)
{
    bool firstOneFromTheEnd = true;
    for (int i = amount - 1; i > 0; --i)
    {
        if (firstOneFromTheEnd && array[i] == 1)
        {
            array[i] = 2 - array[i];
            firstOneFromTheEnd = false;
        }
        else if (!firstOneFromTheEnd)
        {
            array[i] = 1 - array[i];
        }
    }
}

void decToBin(int* binArray, int number, int amount)
{
    int position = 0;
    int absNumber = abs(number);
    while (absNumber > 0)
    {
        binArray[position] = absNumber % 2;
        absNumber = absNumber / 2;
        ++position;
    }
    swapArray(binArray, amount);
    
    if (number < 0)
    {
        binArray[0] = 1;
        convertToAdditionalCode(binArray, amount);
    }
}

void bitwiseAddition(int* firstNumberBin, int* secondNumberBin, int* sumNumber, int amount)
{
    for (int i = amount - 1; i >= 0; --i)
    {
        sumNumber[i] = sumNumber[i] + firstNumberBin[i] + secondNumberBin[i];
        if (i > 0 && sumNumber[i] > 1)
        {
            ++sumNumber[i - 1];
            sumNumber[i] = sumNumber[i] % 2;
        }
        else if (i == 0 && sumNumber[i] > 1)
        {
            sumNumber[i] = sumNumber[i] % 2;
        }
    }
}

int exponentiation(int number, int power)
{
    int result = 1;
    for (int i = 0; i < power; ++i)
    {
        result = result * number;
    }
    return result;
}

int binToDec(int* binArray, int amount)
{
    if (binArray[0] == 1)
    {
        convertToAdditionalCode(binArray, amount);
    }
    int decNumber = 0;
    for (int i = amount - 1; i > 0; --i)
    {
        decNumber = decNumber + binArray[i] * exponentiation(2, amount - 1 - i);
    }
    if (binArray[0] == 1)
    {
        decNumber = -1 * decNumber;
    }
    return decNumber;
}

void printArray(int* array, int amount)
{
    for (int i = 0; i < amount; ++i)
    {
        printf("%d", array[i]);
    }
    printf("\n");
}

bool testForDecToBin()
{   
    #define AMOUNTTESTS 3
    int number[AMOUNTTESTS] = {5, 9, -4};
    const int result[AMOUNTTESTS][16] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}};
    for (int i = 0; i < AMOUNTTESTS; ++i)
    {
        int resultTest[16] = {0};
        decToBin(resultTest, number[i], 16);
        for (int j = 0; j < 16; ++j)
        {
            if (resultTest[j] != result[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

bool testForBinToDec()
{
    #define TESTSBINTODEC 3
    int binArray[TESTSBINTODEC][16] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}};
    const int result[TESTSBINTODEC] = {5, 9, -4};
    for (int i = 0; i < TESTSBINTODEC; ++i)
    {
        if (binToDec(binArray[i], 16) != result[i])
        {
            return false;
        }
    }
    return true;
}

bool testForBitwiseAddition()
{
    #define AMOUNTTEST 3
    int firstNumberBin[AMOUNTTEST][16] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}};
    int secondNumberBin[AMOUNTTEST][16] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1}};
    const int result[AMOUNTTEST][16] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1}};    
    for (int i = 0; i < AMOUNTTEST; ++i)
    {
        int sumNumberBin[16] = {0};
        bitwiseAddition(firstNumberBin[i], secondNumberBin[i], sumNumberBin, 16);
        for (int j = 0; j < 16; ++j)
        {
            if (sumNumberBin[j] != result[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

bool tests()
{
    return testForBinToDec() && testForDecToBin() && testForBitwiseAddition();
}

int main()
{
    if (!tests())
    {
        printf("%s", "Tests failed!");
        return 0;
    }
    setlocale(LC_ALL, "Rus");
    int firstNumber = 0;
    printf("%s ", "Введите первое число:");
    scanf("%d", &firstNumber);
    int seсondNumber = 0;
    printf("%s ", "Введите второе число:");
    scanf("%d", &seсondNumber);

    #define SIZE 16
    const int maxValue = exponentiation(2, SIZE - 1) - 1;
    const int minValue = exponentiation(2, SIZE - 1) * -1;
    if (firstNumber > maxValue || firstNumber < minValue || seсondNumber > maxValue || seсondNumber < minValue)
    {
        printf("%s%d%s%d%s", "Введите числа из диапазона [", minValue, "; ", maxValue, "]");
        return 0;
    }

    int firstNumberBin[SIZE] = {0};
    decToBin(firstNumberBin, firstNumber, SIZE);
    printf("%s", "Двоичное представление первого числа: ");
    printArray(firstNumberBin, SIZE);

    int secondNumberBin[SIZE] = {0};
    decToBin(secondNumberBin, seсondNumber, SIZE);
    printf("%s", "Двоичное представление второго числа: ");
    printArray(secondNumberBin, SIZE);
    
    if (firstNumber + seсondNumber > maxValue || firstNumber + seсondNumber < minValue)
    {
        printf("%s", "Сумма чисел переполнена");
        return 0;
    }
    int sumNumber[SIZE] = {0};
    bitwiseAddition(firstNumberBin, secondNumberBin, sumNumber, SIZE);
    printf("%s", "Сумма чисел в двоичном представлении: ");
    printArray(sumNumber, SIZE);

    int sumNumbersDec = binToDec(sumNumber, SIZE);
    printf("%s", "Сумма чисел: ");
    printf("%d", sumNumbersDec);

    return 0;
}