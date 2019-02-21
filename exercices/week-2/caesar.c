#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isLowerCase(int charCode);
int isUpperCase(int charCode);

int main(int argc, string argv[])
{    
    if (argc > 2)
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }
    string param = argv[1];
    for (int i = 0; i < strlen(param); i++)
    {
        if (!isdigit(param[i]))
        {
            printf("Usage: ./caesar key \n");
            return 1;
        }
    }
    int key = atoi(param);
    
    string word = get_string("plaintext:");
    int length = strlen(word);
    for (int i = 0; i < length; i++)
    {
        int charCode = word[i];
        if (isLowerCase(charCode))
        {
            int distance = charCode + key;
            while (distance > 'z')
            {
                int difference = distance - 'z';
                distance = difference + 'a' - 1;
            }
            printf("%c", distance);
        }
        else if (isUpperCase(charCode))
        {
            int distance = charCode + key;
            while (distance > 'Z')
            {
                int difference = distance - 'Z';
                distance = difference + 'A' - 1;
            }
            printf("%c", distance);
        }
        else
        {
            printf("%c", charCode);
        }
    }
    
    printf("\n");
}

int isUpperCase(int charCode)
{
    return charCode >= 'A' && charCode <= 'Z';
}

int isLowerCase(int charCode)
{
    return charCode >= 'a' && charCode <= 'z';
}
