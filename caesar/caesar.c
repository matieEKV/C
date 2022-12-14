#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
//check if the main takes in 2 arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        // printf("arg: %s\n", argv[1]);
        // string input = argv[1];

        //check if the bool is true, that is if the key cointains only digits
        if (only_digits(argv[1]))
        {
            // convert input string into an int
            int n = atoi(argv[1]);
            //printf("the key is %i\n", key);
            // ask user for plaintext input
            string plaintext = get_string("plaintext:  ");
            //rotate each character in a string for n numbers using a rotate function
            printf("ciphertext: ");
            for (int i = 0; i < strlen(plaintext); i++)
            {
                char c = plaintext[i];
                char rotated = rotate(c, n);
                printf("%c", rotated);
            }
            printf("\n");
        }
        else
        {
            return 1;
        }
    }
}

//check whether key cointains only digits
bool only_digits(string s)
{
    int counter = 0;
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        char argument1 = s[i];
        if (isdigit(argument1))
        {
            counter++;
        }
        else
        {
            printf("uh oh\n");
            return false;
        }
    }
    if (length == counter && length > 0)
    {
        return true;
    }

    return false;
}
// rotate each character in a string for n numbers
char rotate(char c, int n)
{
    int alpha_index = 0;
    int cypher = 0;
    if (isalpha(c))
    {
        if (islower(c))
        {
            alpha_index = c - 'a';
            cypher = (alpha_index + n) % 26;
            char cyphered = cypher + 'a';
            return cyphered;
        }
        if (isupper(c))
        {
            alpha_index = c - 'A';
            cypher = (alpha_index + n) % 26;
            char cyphered = cypher + 'A';
            //    printf ("check upper %c/n", cyphered);
            return cyphered;
        }
    }
    return c;
}