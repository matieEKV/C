#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

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