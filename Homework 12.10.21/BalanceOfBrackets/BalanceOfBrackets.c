#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../Stack/Stack.h"

bool isBracket(const char symbol)
{
    return symbol == '(' || symbol == ')' || symbol == '[' || symbol == ']' || symbol == '{' || symbol == '}';
}

bool correctBrackets(const char prevElement, const char element)
{
    return prevElement == '(' && element == ')' || prevElement == '[' && element == ']' || prevElement == '{' && element == '}';
}

bool isOpeningBracket(const char element)
{
    return element == '(' || element == '[' || element == '{';
}

bool areBracketsBalanced(const char string[])
{
    const int length = strlen(string);
    StackElement* head = NULL;
    for (int i = 0; i < length; ++i)
    {
        if (isBracket(string[i]))
        {
            if (!isOpeningBracket(string[i]) && isEmpty(head))
            {
                deleteStack(&head);
                return false;
            }
            if (isOpeningBracket(string[i]) || isEmpty(head))
            {
                bool successPush = true;
                push(&head, string[i], &successPush);
                if (!successPush)
                {
                    deleteStack(&head);
                    return false;
                }
            }
            else
            {
                bool successPop = true;
                const char prevElement = pop(&head, &successPop);
                if (!successPop)
                {
                    deleteStack(&head);
                    return false;
                }
                if (!correctBrackets(prevElement, string[i]))
                {
                    deleteStack(&head);
                    return false;
                }
            }
        }
    }
    if (!isEmpty(head))
    {
        deleteStack(&head);
        return false;
    }

    return true;
}

bool areTestsPassing()
{
    #define AMOUNT 6
    const char stringTest[AMOUNT][20] = {"([qwe]{(rty)})", "ab[{]c}d", "{)()(}", "(([])[])", "[({}())[]", "["};
    const bool result[AMOUNT] = {true, false, false, true, false, false};
    for (int i = 0; i < AMOUNT; ++i)
    {
        if (areBracketsBalanced(stringTest[i]) != result[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
   if (!areTestsPassing())
    {
        printf("%s", "Tests failed!");
        return -1;
    }

    #define SIZE 300
    printf("Enter string less than %d characters: ", SIZE);
    char string[SIZE] = "\0";
    gets_s(string, SIZE);

    if (!areBracketsBalanced(string))
    {
        printf("%s", "String is not correct");
        return -1;
    }
    printf("%s", "String is correct");
    return 0;
}
