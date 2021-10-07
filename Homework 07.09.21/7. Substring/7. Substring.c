#include <stdio.h>
#include <string.h>

int main()
{
    char s[51] = { 0 };
    char s1[51] = { 0 };
    printf("%s", "Enter string \"s\" no longer than 50 characters: ");
    scanf("%s", s);
    printf("%s", "Enter string \"s1\" no longer than 50 characters: ");
    scanf("%s", s1);
    const int length = strlen(s);
    const int length1 = strlen(s1);
    int count = 0;
    for (int i = 0; i <= length - length1; ++i)
    {
        int currentIndex = i;
        while ((s[currentIndex] == s1[currentIndex - i]) && (currentIndex - i) < length1)
        {
            currentIndex++;
        }
        if (currentIndex - i == length1)
        {
            count++;
        }
    }

    printf("%s %d", "Number of strings \"s1\" in string \"s\":", count);
    return  0;
}
