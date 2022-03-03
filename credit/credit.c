#include <cs50.h>
#include <stdio.h>

int get_number (void);
int checksum (int cc_number);

int main(void)
{
    int cc_number = get_number();

    int test = checksum();
    printf 
}

int get_number(void)
{
    int cc_number = get_long ("What is your credit card number?\n");
    return cc_number;
}

int checksum (int cc_number)
{
    cc_nummber = cc_number/10
    return cc_number;
}