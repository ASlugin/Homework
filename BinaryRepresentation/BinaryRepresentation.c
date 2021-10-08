#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>

void decToBin(int *binArray, int number, int amount)
{
    for (int i = 0; i < amount; ++i)
    {
        binArray[amount - i - 1] = number & 1;
        number = number >> 1;
    }
}

void bitwiseSum(int *firstNumberBin, int *secondNumberBin, int *sumNumber, int amount)
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

int binToDec(int *binArray, int amount)
{
    int decNumber = 0;
    for (int i = amount - 1; i >= 0; --i)
    {
        decNumber = decNumber | (binArray[i] & 1) << (amount - 1 - i);
    }
    return decNumber;
}

void printArray(int *array, int amount)
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
    const int size = sizeof(int) * 8;
    int number[AMOUNTTESTS] = {5, 9, -4};
    const int resultTwoByte[AMOUNTTESTS][16] =
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}
    };
    const int resultFourByte[AMOUNTTESTS][32] =
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}
    };
    for (int i = 0; i < AMOUNTTESTS; ++i)
    {
        int resultTest[32] = {0};
        decToBin(resultTest, number[i], size);
        for (int j = 0; j < size; ++j)
        {
            if (size == 16 && resultTest[j] != resultTwoByte[i][j] || size == 32 && resultTest[j] != resultFourByte[i][j])
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
    const int size = sizeof(int) * 8;
    int binArrayTwoByte[TESTSBINTODEC][16] =
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}
    };
    int binArrayFourByte[TESTSBINTODEC][32] =
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}
    };
    const int result[TESTSBINTODEC] = {5, 9, -4};
    for (int i = 0; i < TESTSBINTODEC; ++i)
    {
        if (size == 16 && binToDec(binArrayTwoByte[i], size) != result[i] || size == 32 && binToDec(binArrayFourByte[i], size) != result[i])
        {
            return false;
        }
    }
    return true;
}

bool testForBitwiseSum()
{
    #define AMOUNTTEST 3
    const int size = sizeof(int) * 8;
    int firstNumberBinTwoByte[AMOUNTTEST][16] =
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}
    };
    int secondNumberBinTwoByte[AMOUNTTEST][16] =
    {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1}
    };
    const int resultTwoByte[AMOUNTTEST][16] =
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1}
    };
    int firstNumberBinFourByte[AMOUNTTEST][32] =
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}
    };
    int secondNumberBinFourByte[AMOUNTTEST][32] =
    {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1}
    };
    const int resultFourByte[AMOUNTTEST][32] =
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1}
    };
    for (int i = 0; i < AMOUNTTEST; ++i)
    {
        int sumNumberBin[32] = {0};
        if (size == 16)
        {
            bitwiseSum(firstNumberBinTwoByte[i], secondNumberBinTwoByte[i], sumNumberBin, size);
        }
        else
        {
            bitwiseSum(firstNumberBinFourByte[i], secondNumberBinFourByte[i], sumNumberBin, size);
        }
        for (int j = 0; j < size; ++j)
        {
            if (size == 16 && sumNumberBin[j] != resultTwoByte[i][j] || size == 32 && sumNumberBin[j] != resultFourByte[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

bool tests()
{
    return testForBinToDec() && testForDecToBin() && testForBitwiseSum();
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

    #define SIZE sizeof(int) * 8
    const int maxValue = (int)pow(2, SIZE - 1) - 1;
    const int minValue = (int)pow(2, SIZE - 1) * -1;
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

    int sumNumber[SIZE] = {0};
    bitwiseSum(firstNumberBin, secondNumberBin, sumNumber, SIZE);
    printf("%s", "Сумма чисел в двоичном представлении: ");
    printArray(sumNumber, SIZE);

    int sumNumbersDec = binToDec(sumNumber, SIZE);
    printf("%s", "Сумма чисел: ");
    printf("%d", sumNumbersDec);

    return 0;
}