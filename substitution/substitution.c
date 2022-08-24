#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

bool final_key_check (int k);
bool key_check1 (string s);

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
        }
    }
}






        // string s1 = "abcdefghijklmnopqrstuvwxyz";
    // if (strcasecmp(argv[1], s1) == 0)
        // {
            // printf("they are equal!\n");
        // }
    // else
    // {
        // printf("they are not the same\n");
    // }
    // }
// }
//function checks whether key is alphabetical and if the key is 26 characters long
bool key_check1(string s)
{
    int counter1 = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        char individual = s[i];
        if (isalpha(individual))
        {
            counter1++;
            return 0;
        }
        else
        {
            printf("The key must be alphabetical\n");
            return 1;
        }
    }
    if (counter1 != 26)
    {
        printf ("The key must contain 26 alphabetic characters\n");
        return false;
    }
    return false;
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

    // string s1 = "abcdefghijklmnopqrstuvwxyz";
    // if (strcasecmp(s, s1) == 0)
        // {
            // return 0;
            // printf("they are equal!/n");
        // }
    // return false;
    // }


// bool final_key_check (int k)
// {

// }
