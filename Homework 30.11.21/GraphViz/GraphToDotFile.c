#define _CRT_SECURE_NO_WARNINGS
#include "GraphToDotFile.h"
#include <stdio.h>

bool generateDotFile(const char nameInputFile[], const char nameDotFile[])
{
    FILE* file = fopen(nameInputFile, "r");
    if (file == NULL)
    {
        return false;
    }
    FILE* dotFile = fopen(nameDotFile, "w");
    if (dotFile == NULL)
    {
        fclose(file);
        return false;
    }

    int amount = 0;
    fscanf(file, "%d", &amount);
    fprintf(dotFile, "digraph Graph {\n");

    for (int i = 0; i < amount; ++i)
    {
        for (int j = 0; j < amount; ++j)
        {
            if (feof(file))
            {
                fclose(file);
                fclose(dotFile);
                return false;
            }
            int weight = -1;
            fscanf(file, "%d", &weight);
            if (weight > 0)
            {
                fprintf(dotFile, "%d -> %d [label = \"%d\"];\n", i, j, weight);
            }
        }
    }
    fprintf(dotFile, "}");

    fclose(file);
    fclose(dotFile);
    return true;
}