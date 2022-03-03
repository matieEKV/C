#include <cs50.h>
#include <stdio.h>

int get_number (void);
int checksum (int cc_number);

int main(void)
{
    int cc_number = get_number();

    int test = checksum(cc_number);
    test = cc_number % 10;
    printf ("%i\n", test);
}

int get_number(void)
{
    int cc_number = get_long ("What is your credit card number?\n");
    return cc_number;
}

int checksum (int cc_number)
{
    int alternate_number_sum = 0;
    while (cc_number > 0)
    {
        cc_number /= 10;
        alternate_number_sum += cc_number % 10;
    }
    return alternate_number_sum;
}