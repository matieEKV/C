#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text);
int count_words (string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    printf ("%s\n", text);

    int letter_count = count_letters(text);
    int word_count = count_words(text);
    int sentence_count = count_letters(text);

}

int count_letters(string text)
{
    int counter = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        char individual = text[i];
        if (isalpha (individual)) {
        counter++;
        }

    }
    printf("%i letters\n", counter);
    return counter;
}

    int count_words (string text)
    {
        int counter = 1;
        for (int i = 0; i < strlen(text); i++)
    {
        char white_space = text[i];
        if (isspace (white_space)) {
        counter++;
        }
    }
    printf("%i words\n", counter);
    return counter;
    }

    int count_sentences (string text)
    {
        int counter = 0;
        for (int i = 0; i < strlen(text); i++)
    {
        char punctuation = text[i];
          if (punctuation == 46) {
        counter++;
        }
    }
    printf("%i sentences\n", counter);
    return counter;
    }