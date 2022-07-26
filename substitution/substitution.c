#include <cs50.h>
#include <stdio.h>
#include <strings.h>

bool final_key_check (int k);
int key_check (string s;);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
}

int key_check(string s)
{
    int counter1 = 0;
    int counter2 = 0;
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        char individual = s[i];
        if (isalpha(individual))
        {
            counter1++;
        }
        else
        {
            printf("The key must be alphabetical\n");
        }
    }
    string s1 = 'abcdefghijklmnopqrstuvwxyz';
    if (strcasecmp(s, s1) == 0)
        {
            printf("they are equal!/n");
        }
    }


bool final_key_check (int k)
{

}
