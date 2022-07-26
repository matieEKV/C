#include <cs50.h>
#include <stdio.h>

bool final_key_check (int k);
int key_check (string s;);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
}

int key_check(string s)
{
    int counter = 0;
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        char individual = s[i];
        if (isdigit(individual))
        {
            counter++;
        }
    }

}

bool final_key_check (int k)
{

}
