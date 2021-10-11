#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file = fopen("file.txt", "r");
    if (file == NULL)
    {
        printf("%s", "File not found");
        return 0;
    }

    int position = 0;
    char *string = calloc(100, sizeof(char));
    if (string == NULL)
    {
        printf("%s", "Allocation error");
        return 0;
    }
    int readBytes = fscanf(file, "%c", &string[position]);
    if (readBytes < 0)
    {
        printf("%s", "Error");
        return 0;
    }
    position++;

    while (!feof(file))
    {
        readBytes = fscanf(file, "%c", &string[position]);
        if (readBytes == NULL)
        {
            printf("%s", "Error");
            return 0;
        }
        if (string[position - 1] != string[position])
        {
            position++;
        }
    }

    printf("%s", string);
    fclose(file);
    free(string);
    return 0;
}