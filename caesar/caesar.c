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
        if (isdigit((unsigned char) argv[1]))
        {
            printf("great\n");
        }
         else
        {
             printf("uh oh\n");
        }
    }

}