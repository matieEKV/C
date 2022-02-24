#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // ask user for input
    int height = get_int("What is your desired height?");

    //check if condition is correct
    do {
        printf ("good so far/n");
    }
    while (height <1 || height >8);
}