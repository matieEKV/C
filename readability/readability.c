#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text);

int main(void)
{
    string text = get_string("Text: ");
    printf ("%s\n", text);

    int count = count_letters(text);
}

int count_letters(string text)
{
    int counter = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        char individual = text[i];
        if (isalpha (individual)) {
        counter++;
        printf("There are %i letters\n", counter);
        }
    }
    return counter;
}