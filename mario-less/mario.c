#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;

    //check if condition is correct
    do {
         height = get_int("What is your desired height?");
    }
    while (height <1 || height >8);

// loop line by line
    for (int line=0; line<height; line++) {
// print dots
        for (int dots=0; dots<(height-line); dots++){
            printf(".");
        }
// print hashtags
        for (int index=0; index<=line; index++){
            // printf("#");
        }
        printf("\n");
    }
}