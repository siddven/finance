#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long cardnumber;
    long a;
    long b;
    long mult = 100;
    long mult2 = 10;
    long mult3 = 1;
    long add = 0;
    long addb = 0;
    long addall = 0;


    bool check = false;
    do
    {

        cardnumber = get_long("Enter a card number:");


        //printf("%li\n", b);

    }


    while (cardnumber < 1000000000);

    for (int i = 0; i < 16; ++i)
    {
        a = cardnumber % mult;
        a = a / mult2;
        a = a * 2;
        if (a >= 10)
        {
            long a1 = a / 10;
            long a2 = a % 10;
            add += a1 + a2;
        }
        else
        {
            add += a;

        }
        b = cardnumber % mult2;
        b = b / mult3;
        addb += b;
        mult = mult * 100;
        mult2 = mult2 * 100;
        mult3 = mult3 * 100;

    }

    addall = addb + add;

    long an = addall % 10;
    //printf("%li\n", an);
    if (an > 0)
    {
        printf("INVALID\n");
    }


    else if (cardnumber / 1000000000000 == 4 || cardnumber / 1000000000000000 == 4)
    {
        if (an == 0)
        {
            printf("VISA\n");

        }

    }
    else if (cardnumber / 100000000000000 == 55 || cardnumber / 100000000000000 == 54 || cardnumber / 100000000000000 == 53
             || cardnumber / 100000000000000 == 52 || cardnumber / 100000000000000 == 51)
    {
        if (an == 0)
        {

            printf("MASTERCARD\n");

        }

    }
    else if (cardnumber / 10000000000000 == 34 || cardnumber / 10000000000000 == 37)
    {
        if (an == 0)
        {
            printf("AMEX\n");

        }

    }
    else
    {
        printf("INVALID\n");
    }
}


