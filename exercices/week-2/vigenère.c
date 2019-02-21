#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int getcharCodeFromKey(string word, int index);
int isLowerCase(int charCode);
int isUpperCase(int charCode);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }
    string keyWord = argv[1];
    for (int i = 0; i < strlen(keyWord); i++)
    {
        if (isdigit(keyWord[i]))
        {
            printf("Usage: ./caesar key \n");
            return 1;
        }
    }

    string word = get_string("plaintext: ");
    int length = strlen(word);
    int keyWordCounter = 0;
    for (int i = 0; i < length; i++)
    {
        int charCode = word[i];
        int key = getcharCodeFromKey(keyWord, keyWordCounter);
        if (isLowerCase(charCode))
        {
            int distance = charCode + key;
            while (distance > 'z')
            {
                int difference = distance - 'z';
                distance = difference + 'a' - 1;
            }
            keyWordCounter++;
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
            keyWordCounter++;
            printf("%c", distance);
        }
        else
        {
            printf("%c", charCode);
        }
    }

    printf("\n");
}

int getcharCodeFromKey(string word, int index)
{
    int letter = word[index % strlen(word)];
    return letter - (isUpperCase(letter) ? 'A' : 'a');
}

int isUpperCase(int charCode)
{
    return charCode >= 'A' && charCode <= 'Z';
}

int isLowerCase(int charCode)
{
    return charCode >= 'a' && charCode <= 'z';
}
