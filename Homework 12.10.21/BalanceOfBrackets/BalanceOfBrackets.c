#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../Stack/Stack.h"

bool isBracket(const char symbol)
{
    return symbol == '(' || symbol == ')' || symbol == '[' || symbol == ']' || symbol == '{' || symbol == '}';
}

bool inCorrectBrackets(const char prevElement, const char element)
{
    return prevElement == '(' && element == ']' || prevElement == '(' && element == '}' ||
           prevElement == '[' && element == '}' || prevElement == '[' && element == ')' ||
           prevElement == '{' && element == ']' || prevElement == '{' && element == ')';
}

bool CorrectBrackets(const char prevElement, const char element)
{
    return prevElement == '(' && element == ')' || prevElement == '[' && element == ']' || prevElement == '{' && element == '}';
}

bool checkBalanceBrackets(const char string[])
{
    const int length = strlen(string);
    StackElement* head = NULL;
    for (int i = 0; i < length; ++i)
    {
        if (isBracket(string[i]))
        {
            if (!isEmpty(head))
            {
                const char prevElement = pop(&head);
                if (inCorrectBrackets(prevElement, string[i]))
                {
                    deleteStack(&head);
                    return false;
                }
                else if (!CorrectBrackets(prevElement, string[i]))
                {
                    head = push(head, prevElement);
                    head = push(head, string[i]);
                }
            }
            else
            {
                head = push(head, string[i]);
            }
        }
    }
    if (!isEmpty(head))
    {
        deleteStack(&head);
        return false;
    }
    deleteStack(&head);
    return true;
}

bool tests()
{
    #define AMOUNT 5
    const char stringTest[AMOUNT][20] = {"([qwe]{(rty)})", "ab[{]c}d", "{)()(}", "(([])[])", "[({}())[]"};
    const bool result[AMOUNT] = {true, false, false, true, false};
    for (int i = 0; i < AMOUNT; ++i)
    {
        if (checkBalanceBrackets(stringTest[i]) != result[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
   if (!tests())
    {
        printf("%s", "Tests is failed!");
        return 0;
    }

    #define SIZE 300
    printf("%s%d%s", "Enter string less than ", SIZE, " characters: ");
    char string[SIZE] = "\0";
    gets_s(string, SIZE);

    if (checkBalanceBrackets(string))
    {
        printf("%s", "String is correct");
        return 0;
    }
    printf("%s", "String is not correct");
    return 0;
}
