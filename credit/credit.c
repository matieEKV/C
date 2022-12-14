#include <cs50.h>
#include <stdio.h>
#include <math.h>

long get_number(void);
int checksum(long cc_number);
int number_digit_sum(int number);
int get_length(long cc_number);

int main(void)
{
    //ask user for input
    long cc_number = get_number();

    int sum = checksum(cc_number);
    //printf ("%i\n", sum);
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    int length = get_length(cc_number);
    int power_1 = length - 1;
    int first_digit = cc_number / pow(10, power_1);
    //printf ("%i\n", first_digit);
    int power_2 = length - 2;
    int two_digits = cc_number / pow(10, power_2);
    //printf ("%i\n", second_digit);

    if (first_digit == 4 && (length == 13 || length == 16))
    {
        printf("VISA\n");
        return 0;
    }
    if ((two_digits == 34 || two_digits == 37) && length == 15)
    {
        printf("AMEX\n");
        return 0;
    }
    if ((two_digits >= 51 && two_digits <= 55) && length == 16)
    {
        printf("MASTERCARD\n");
        return 0;
    }
    else
    {
        printf("INVALID\n");
    }
}

long get_number(void)
{
    return get_long("What is your credit card number?\n");
}

int checksum(long cc_number)
{
    // printf ("checking input: %i\n", cc_number);
    int alternate_number_sum = 0;
    int double_digit_sum = 0;

    while (cc_number > 0)
    {
        alternate_number_sum += cc_number % 10;
        cc_number /= 10;

        double_digit_sum += number_digit_sum((cc_number % 10) * 2);
        cc_number /= 10;
    }

    return alternate_number_sum + double_digit_sum;
}

int number_digit_sum(int number)
{
    return number / 10 + number % 10;
}

int get_length(long cc_number)
{
    int counter = 0;
    while (cc_number > 0)
    {
        cc_number = cc_number / 10;
        counter++;
    }
    //printf ("%i\n", counter);
    return counter;
}

