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
        printf ("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        // printf("arg: %s\n", argv[1]);
        // string input = argv[1];

//check if the bool is true, that is if the key cointains only digits
        if (only_digits(argv[1]) == true)
        {
// convert input string into an int
            int n = atoi (argv[1]);
            //printf("the key is %i\n", key);

        }
// ask user for plaintext input
        string plaintext = get_string("plaintext:  ");
       for (int i = 0; i < strlen(plaintext); i++)
       {
        char c = plaintext[i];
        char rotate(char c, int n);
        printf ("cyphertext:  %s", plaintext);

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
            // printf ("wow, good!\n");
            return true;
        }
        // printf("uh oh 1\n");
        return false;
}

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
                printf ("check lower %c/n", cyphered);
                return cyphered;
            }
            if (isupper(c))
            {
               alpha_index = c - 'A';
               cypher = (alpha_index + n) % 26;
               char cyphered = cypher + 'a';
               printf ("check upper %c/n", cyphered);
               return cyphered;
            }
        }
        return c;
}


// bool result = false;

// for ... {
//     char item = string[i];
//     if (isdigit(item)) {
//         result = true;
//     } else {
//         return false;
//     }
// }
// return result;