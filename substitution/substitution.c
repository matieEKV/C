#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

int key_check1 (string s);
int key_check2 (string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        if (key_check1(argv[1]) == 0 && key_check2(argv[1]) == 0)
        {
            printf("wow, good work!\n");
        }
        else {
            printf("not good\n");
        }
    }
}


//function checks whether key is alphabetical and if the key is 26 characters long
int key_check1(string s)
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
            return 1;
        }
    }
    if (length != 26)
    {
        printf ("The key must contain 26 alphabetic characters\n");
        return 1;
    }
    else
    {
        return 0;
    }
    return 1;
}

//function checks for repeating characters
int key_check2(string s)
{
        for (int i = 0; i < strlen(s); i++)
        {
            printf("printing over here too!\n");
            for (int j = i + 1; j < strlen(s); j++)
            {
                if (s[i] == s[j])
                {
                    printf("key cannot have repeating characters\n");
                    return 1;
                }
                else
                {
                    printf("printing here!\n");
                    return 0;
                }
            }
        }
        return 1;
}
