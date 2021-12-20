#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tree.h"
#include "Test.h"

int main(int argc, char* argv[])
{
    if (!isTestPassing())
    {
        if (argc <= 1)
        {
            printf("Tests failed!");
        }
        return -1;
    }
    if (argc > 1)
    {
        return 0;
    }

    Tree* dictionary = createTree();
    if (dictionary == NULL)
    {
        return -1;
    }
    
    printf("Commands for the dictionary:\n");
    printf("0 - Exit\n");
    printf("1 - Add value for given key to the dictionary. If such a key already exists, the value is replaced with a new one.\n");
    printf("2 - Get the value for given key from the dictionary.\n");
    printf("3 - Check the presence given key in the dictionary.\n");
    printf("4 - Delete given key and its associated value from the dictionary.\n");
    
    #define SIZE 300
    
    while (true)
    {
        int code = -1;
        printf("Enter code: ");
        scanf("%d", &code);
        int key = 0;
        switch (code)
        {
            case 0:
            {
                deleteTree(&dictionary);
                return 0;
            }
            case 1:
            {
                printf("Enter key: ");
                scanf("%d", &key);
                getchar();
                char value[SIZE + 1] = {'\0'};
                printf("Enter value less than %d characters: ", SIZE);
                gets_s(value, SIZE);
                if (!add(dictionary, key, value))
                {
                    deleteTree(&dictionary);
                    printf("Error add");
                    return -1;
                }
                printf("Added\n");
                break;
            }
            case 2:
            {
                printf("Enter key: ");
                scanf("%d", &key);
                char* result = getValueByKey(dictionary, key);
                if (result == NULL)
                {
                    printf("Key %d is not contained in dictionary\n", key);
                    break;
                }
                printf("Value by key %d: %s\n", key, getValueByKey(dictionary, key));
                break;
            }
            case 3:
            {
                printf("Enter key: ");
                scanf("%d", &key);
                if (treeContainThisKey(dictionary, key))
                {
                    printf("Key %d is contained in dictionary\n", key);
                    break;
                }
                printf("Key %d is not contained in dictionary\n", key);
                break;
            }
            case 4:
            {
                printf("Enter key: ");
                scanf("%d", &key);
                if (!deleteNodeByKey(dictionary, key))
                {
                    printf("Error delete node by key");
                    return -1;
                }
                printf("Deleted\n");
                break;
            }
            default:
            {
                printf("Incorrect code!\n");
                break;
            }
        }
    }
    return 0;
}
