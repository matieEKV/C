#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        int repeating_character = i, j;
        for (i = 0; i < strlen(s); i++)
        {
            for (j = i + 1; j < strlen(s); j++)
            {
                if (s[i] == s[j])
                {
                    printf("your input cannot have repeating characters!\n);
                    return 1;

    }