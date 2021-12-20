#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc > 1)
    {
        return 1;
    }

    FILE* file = fopen("file.txt", "r");
    if (file == NULL)
    {
        printf("%s", "File not found!");
        return 0;
    }
    char prevElement = 0;
    fscanf(file, "%c", &prevElement);
    printf("%c", prevElement);
    while (!(feof(file)))
    {
        char element = 0;
        fscanf(file, "%c", &element);
        if (prevElement != element)
        {
            printf("%c", element);
        }
        prevElement = element;
    }
    fclose(file);
    return 0;
}