#include<stdio.h>//standard library
#include<cs50.h>

int main(void)
{
    int c = 0, x, y = 0, z = 0;
    long long num, num1;//long long for taking credit card number

    do
    {
        num = get_long_long("Number: ");
    }
    while (num < 0);
    num1 = num;
    //validating the number
    while (num > 0)
    {
        x = (2 * ((num % 100) / 10));
        if (x >= 10)
        {
            x = (x % 10) + (x / 10);
        }
        c = c + x;
        num = num / 100;
    }
    num = num1;
    while (num > 0)
    {
        y = y + (num % 10);
        num = num / 100;
    }
    c = c + y;

    if (c % 10 != 0)
    {
        printf("INVALID\n"); // if the number does not satisfied the condition
    }

    else
    {
        num = num1;
        // number of digits
        while (num > 0)
        {
            num = num / 10;
            z++;
        }
        num = num1;
        //cheaking for american express credit card
        if ((z == 15 && (num / 10000000000000 == 34)) || (z == 15 && (num / 10000000000000 == 37)))
        {
            printf("AMEX\n");
        }
        //cheaking for visa credit card
        else if ((z == 16 && num / 1000000000000000 == 4) || (z == 13 && num / 1000000000000 == 4))
        {
            printf("VISA\n");
        }
        //cheaking for master card credit card
        else if ((z == 16 && num / 100000000000000 == 51) || (z == 16 && num / 100000000000000 == 52)
                 || (z == 16 && num / 100000000000000 == 53) || (z == 16 && num / 100000000000000 == 54)
                 || (z == 16 && num / 100000000000000 == 55))
        {
            printf("MASTERCARD\n");
        }

        else
        {
            printf("INVALID\n");

        }
    }

}
