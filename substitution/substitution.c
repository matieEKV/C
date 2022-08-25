#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

int key_check1(string s);
int key_check2(string s);
char conversion(char c, string s);
char encypher(string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (key_check1(argv[1]) == 0 && key_check2(argv[1]) == 0)
    {
        string plaintext = get_string("Plaintext: ");
        printf("ciphertext: ");
        for (int i = 0; i < strlen(plaintext); i++)
            {
                char c = plaintext[i];
                char substituted = conversion(c, argv[1]);
                printf("%c", substituted);
            }
            printf ("\n");
            return 0;
    }
}

// function checks whether key is alphabetical and if the key is 26 characters long
int key_check1(string s)
{
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        char individual = s[i];
        if (!isalpha(individual))
        {
            printf("The key must be alphabetical\n");
            return 1;
        }
    }
    if (length != 26)
    {
        printf("The key must contain 26 alphabetic characters\n");
        return 1;
    }
    return 0;
}

// function checks for repeating characters
int key_check2(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        for (int j = i + 1; j < strlen(s); j++)
        {
            if (s[i] == s[j])
            {
                printf("key cannot have repeating characters\n");
                return 1;
            }
        }
    }
    return 0;
}

// functions converts ascii values of the key

char conversion(char c, string s)
{
    int alpha_index = 0;
    if (isalpha(c))
    {
        if (islower(c))
        {
            alpha_index = c - 'a';
            char cyphered = tolower (s[alpha_index]);
            return cyphered;
        }
        if (isupper(c))
        {
            alpha_index = c - 'A';
            char cyphered = toupper (s[alpha_index]);
            return cyphered;
        }
    return c;
 }
 return c;
}