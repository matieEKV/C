#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words (string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    printf ("%s\n", text);

    int letter_count = count_letters(text);
    int word_count = count_words(text);
    int sentence_count = count_sentences(text);

    float L = letter_count / word_count * 100;
    float S = sentence_count / word_count * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    printf ("%f\n", index);

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
          if (punctuation == 46 || punctuation == 33 || punctuation == 63) {
        counter++;
        }
    }
    printf("%i sentences\n", counter);
    return counter;
    }