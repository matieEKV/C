#include <cs50.h>
#include <stdio.h>

long get_number (void);
int checksum1 (long cc_number);
int checksum2 (long cc_number);
int number_digit_sum (int number);

int main(void)
{
    //ask user for input
    long cc_number = get_number();

    int sum = checksum1(cc_number) + checksum2(cc_number);
    printf ("%i\n", sum);
    if (sum%10==0)
    {
        printf ("VALID\n");
    }
    else
    {
        printf ("INVALID\n");
    }
}

long get_number(void)
{
    return get_long ("What is your credit card number?\n");
}

int checksum1(long cc_number)
{
    // printf ("checking input: %i\n", cc_number);
    int alternate_number_sum = 0;
    int double_digit_sum = 0;

    while (cc_number > 0)
    {
        cc_number /= 10;

        //alternate_number_sum += cc_number % 10;
        double_digit_sum += number_digit_sum ((cc_number % 10)* 2);
        cc_number /= 10;
    }

    //printf ("alternate nums: %i\n", alternate_number_sum);
    //printf ("double digits: %i\n", double_digit_sum);
    return alternate_number_sum + double_digit_sum;
}

int checksum2 (long cc_number)
{
    int other_number_sum = 0;
while (cc_number > 0)
    {
        other_number_sum += cc_number%10;
        cc_number/=10;
        cc_number/=10;
        //printf ("other number sum: %i\n", other_number_sum);
    }
    return other_number_sum;
}

int number_digit_sum(int number)
{
    return number/10 + number%10;
}