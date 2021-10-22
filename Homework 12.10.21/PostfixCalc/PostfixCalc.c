#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../Stack/Stack.h"

int calc(StackElement** head, const int element)
{
    if (element >= '0' && element <= '9')
    {
        int number = element - '0';
        *head = push(*head, number);
        return 0;
    }
    if (isEmpty((*head)->next))
    {
        return -1;
    }
    int number = 0;
    switch (element)
    {
        case '-':
        {
            number = -pop(head) + pop(head);
            break;
        }
        case '+':
        {
            number = pop(head) + pop(head);
            break;
        }
        case '*':
        {
            number = pop(head) * pop(head);
            break;
        }
        case '/':
        {
            int secondNumber = pop(head);
            int firstNumber = pop(head);
            number = firstNumber / secondNumber;
            break;
        }
        default:
        {
            return -1;
        }
    }
    *head = push(*head, number);
    return 0;
}

bool tests()
{
    #define AMOUNT 3
    const char string[AMOUNT][20] = {"9 3 / 1 + 5 2 * +", "9 6 - 1 2 + *", "8 6 9 - +"};
    const int result[AMOUNT] = {14, 9, 5};

    StackElement* headTest = NULL;
    for (int i = 0; i < AMOUNT; ++i)
    {
        const int length = strlen(string[i]);
        for (int j = 0; j < length; ++j)
        {
            if (string[i][j] != ' ')
            {
                if (calc(&headTest, string[i][j]) == -1)
                {
                    deleteStack(&headTest);
                    return false;
                }
            }
        }
        const int answer = pop(&headTest);
        if (!isEmpty(headTest))
        {
            deleteStack(&headTest);
            return false;
        }
        if (answer != result[i])
        {
            printf("%d\n", i);
            deleteStack(&headTest);
            return false;
        }
    }

    deleteStack(&headTest);
    return true;
}

int main()
{
    if (!tests())
    {
        printf("%s", "Tests is failed!");
        return 0;
    }

    StackElement* head = NULL;
    printf("%s", "Enter expression in postfix form: ");
    int element = getchar();
    while (element != '\n')
    {
        if (element != ' ')
        {
            if (calc(&head, element) == -1)
            {
                printf("%s", "Error");
                deleteStack(&head);
                return 0;
            }
        }
        element = getchar();
    }

    const int result = pop(&head);
    if (!isEmpty(head))
    {
        printf("%s", "Error. Digits have been entered more than operations");
        deleteStack(&head);
        return 0;
    }
    printf("%s %d", "Result:", result);

    deleteStack(&head);
    return 0;
}
