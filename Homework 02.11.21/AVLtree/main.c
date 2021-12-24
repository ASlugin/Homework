#define _CRT_SECURE_NO_WARNINGS
#include "AVLtree.h"
#include <stdio.h>
#include <string.h>
#include "Test.h"

#define SIZE 300

int main(void)
{
    if (!isTestPassing())
    {
        printf("Test failed!");
        return -1;
    }
    Tree* dictionary = createTree();
    if (dictionary == NULL)
    {
        return -1;
    }
    
    printf("Commands for the dictionary:\n");
    printf("0 - Exit\n");
    printf("1 - Add value for given key to the dictionary.\n");
    printf("2 - Get the value for given key from the dictionary.\n");
    printf("3 - Check the presence given key in the dictionary.\n");
    printf("4 - Delete given key and its associated value from the dictionary.\n");

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
                char key[SIZE + 1] = {'\0'};
                printf("Enter key: ");
                getchar();
                gets_s(key, SIZE);

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
                char key[SIZE + 1] = {'\0'};
                printf("Enter key: ");
                getchar();
                gets_s(key, SIZE);

                char* result = getValueByKey(dictionary, key);
                if (result == NULL)
                {
                    printf("Key %s is not contained in dictionary\n", key);
                    break;
                }
                printf("Value by key %s: %s\n", key, result);
                break;
            }
            case 3:
            {
                char key[SIZE + 1] = {'\0'};
                printf("Enter key: ");
                getchar();
                gets_s(key, SIZE);

                if (treeContainThisKey(dictionary, key))
                {
                    printf("Key %s is contained in dictionary\n", key);
                    break;
                }
                printf("Key %s is not contained in dictionary\n", key);
                break;
            }
            case 4:
            {
                char key[SIZE + 1] = {'\0'};
                printf("Enter key: ");
                getchar();
                gets_s(key, SIZE);

                deleteNodeByKey(dictionary, key);
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
}