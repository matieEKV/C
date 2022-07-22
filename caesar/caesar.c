#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

bool only_digits(string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf ("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        // printf("arg: %s\n", argv[1]);
        string input = argv[1];

        if (isdigit())
        {
            printf("great\n");
        }
         else
        {
             printf("uh oh\n");
        }
    }

}

bool only_digits(string s)
{
    for (int i = 0; i < strlen(s); i++)
    char argument1 = s[i];
        if (isspace(argument1))
        {
            printf("good job! \n);
        }
}