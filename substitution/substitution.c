#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

bool key_check1(string s);
bool key_check2(string s);
int conversion(string s);
char encypher(string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (key_check1(argv[1]) && key_check2(argv[1]))
    {
        string plaintext = get_string("Plaintext: ");
        char c = argv[1];
    }
}

// function checks whether key is alphabetical and if the key is 26 characters long
bool key_check1(string s)
{
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        char individual = s[i];
        if (!isalpha(individual))
        {
            printf("The key must be alphabetical\n");
            return false;
        }
    }
    if (length != 26)
    {
        printf("The key must contain 26 alphabetic characters\n");
        return false;
    }
    return true;
}

// function checks for repeating characters
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

// functions converts ascii values of the key

int conversion(string s)
{
     char c[0] = 65;
     for (int i = 1; i < strlen(s); i++)
    {
        char c++
        printf("this is something i%\n", c);
    }
}
// this functions encyphers the plaintext using the key
char encypher(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        char c = plaintext[i];
    }
}