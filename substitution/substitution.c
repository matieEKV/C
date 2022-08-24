#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

bool key_check1 (string s);
bool key_check2 (string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (key_check1(argv[1]) && key_check2(argv[1]))
        {
            printf("wow, good work!\n");
        }
        else {
            printf("not good\n");
        }
    }
}


//function checks whether key is alphabetical and if the key is 26 characters long
bool key_check1(string s)
{
    int counter = 0;
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        char individual = s[i];
        if (isalpha(individual))
        {
            counter++;
        }
        else
        {
            printf("The key must be alphabetical\n");
            return false;
        }
    }
    if (length != 26)
    {
        printf ("The key must contain 26 alphabetic characters\n");
        return false;
    }
    else
    {
        return true;
    }
    return false;
}

//function checks for repeating characters
bool key_check2(string s)
{
        for (int i = 0; i < strlen(s); i++)
        {
            for (int j = i + 1; j < strlen(s); j++)
            {
                if (s[i] == s[j])
                {
                    printf("key cannot have repeating characters\n");
                    return false;
                }
            }
        }
        return true;
}
