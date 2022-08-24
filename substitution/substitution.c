#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

int key_check1 (string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        if (key_check1(argv[1]))
        {
            printf("so far so good!\n");
        } else {
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
    printf("returning 1\n");
    return 1;
}
//function checks for repeating characters
// bool key_check2 (string s)
// {
    // int repeating_character = s[i], s[j];
        // for (i = 0; i < strlen(s); i++)
        // {
            // for (j = i + 1; j < strlen(s); j++)
            // {
                // if (s[i] == s[j])
                // {
                    // printf("your input cannot have repeating characters!\n");
                    // return 1;
                // }
            // }