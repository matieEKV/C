#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

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
        // string input = argv[1];

        if (only_digits(argv[1]) == true)
        {
            printf("great\n");
        }

    }

}

bool only_digits(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        int counter = 0;
        char argument1 = s[i];
        int length = strlen(s);
        if (isdigit(argument1))
        {
            counter++;
        }
        if (length == counter)
        {
            printf ("wow, good!\n");
            return true;
        }
        else
        {
             printf("uh oh\n");
             return false;
        }
      }
        return true;
}