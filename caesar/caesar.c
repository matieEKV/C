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
      if (length == counter)
        {
            printf ("wow, good!\n");
            return true;
        }
        return false;
}


bool result = false;

for ... {
    char item = string[i];
    if (isdigit(item)) {
        result = true;
    } else {
        return false;
    }
}
return result;