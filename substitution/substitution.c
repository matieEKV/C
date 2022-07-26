#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

bool final_key_check (int k);
int key_check (string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        string s1 = "abcdefghijklmnopqrstuvwxyz";
    if (strcasecmp(argv[1], s1) == 0)
        {
            printf("they are equal!/n");
        }
    else
    {
        printf("they are not the same\n");
    }
    }
}

int key_check(string s)
{
    int counter1 = 0;
    int counter2 = 0;
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
    string s1 = "abcdefghijklmnopqrstuvwxyz";
    if (strcasecmp(s, s1) == 0)
        {
            return 0;
            printf("they are equal!/n");
        }
    return 1;
    }


// bool final_key_check (int k)
// {

// }
