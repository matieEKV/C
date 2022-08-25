#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

bool key_check1(string s);
bool key_check2(string s);
char conversion(char c, string s);
char encypher(string s);

int main(int argc, string argv[])
{
//check for 2 command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (key_check1(argv[1]) && key_check2(argv[1]))
    {
//get plaintext to be enciphered
        string plaintext = get_string("Plaintext: ");
        printf("ciphertext: ");
//print out enciphered characters by calling the function that substitutes them with the key
        for (int i = 0; i < strlen(plaintext); i++)
        {
            char c = plaintext[i];
            char substituted = conversion(c, argv[1]);
            printf("%c", substituted);
        }
        printf("\n");
        return 0;
    }
    else
    {
        return 1;
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

// function substitutes the plaintext into ciphertext
char conversion(char c, string s)
{
//if characters in plaintext is lower case, substitute at index -lowercase a of the key, and print out lowercase character
    int alpha_index = 0;
    if (isalpha(c))
    {
        if (islower(c))
        {
            alpha_index = c - 'a';
            char cyphered = tolower(s[alpha_index]);
            return cyphered;
        }
//if characters in plaintext is upper case, substitute at index -uppercase A of the key, and print out uppercase character
        if (isupper(c))
        {
            alpha_index = c - 'A';
            char cyphered = toupper(s[alpha_index]);
            return cyphered;
        }
        return c;
    }
    return c;
}