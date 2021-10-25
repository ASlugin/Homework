#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int rewriteElements(const char fileG[], const char fileF[], const char fileH[])
{
    FILE* g = fopen(fileG, "r");
    if (g == NULL)
    {
        return -1;
    }
    int number = 0;
    fscanf(g, "%d", &number);
    fclose(g);

    FILE* f = fopen(fileF, "r");
    if (f == NULL)
    {
        return -1;
    }
    FILE* h = fopen(fileH, "w");
    if (h == NULL)
    {
        fclose(f);
        return -1;
    }

    while (!feof(f))
    {
        int element = 0;
        fscanf(f, "%d", &element);
        if (element < number)
        {
            fprintf(h, "%d ", element);
        }
    }
    fclose(h);
    fclose(f);
    return 0;
}

bool test()
{
    if (rewriteElements("gTest.txt", "fTest.txt", "hTest.txt") == -1)
    {
        return false;
    }
    int number = 21;
    int arrayH[6] = {15, 6, 1, 17, 8, 5};

    FILE* h = fopen("hTest.txt", "r");
    if (h == NULL)
    {
        return false;
    }

    int count = 0;
    while (!feof(h) && count < 6)
    {
        int element = 0;
        fscanf(h, "%d", &element);
        if (element != arrayH[count])
        {
            fclose(h);
            return false;
        }
        ++count;
    }

    if (!feof(h) && count > 6)
    {
        fclose(h);
        return false;
    }
    fclose(h);
    return true;
}

int main()
{
    if (!test())
    {
        printf("Test failed!");
        return 0;
    }
    if (rewriteElements("g.txt", "f.txt", "h.txt") == -1)
    {
        printf("%s", "File not found!");
    }
    else
    {
        printf("%s", "Succesfully");
    }
    return 0;
}
