#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long cardnumber;
    long a;
    long b;
    long c;
    long d;
    long e;
    long f;
    long g;
    long h;

    do {
         cardnumber = get_long("Enter a card number:");
         a = cardnumber % 100;
         b = cardnumber % 10000;
         c = cardnumber % 100000;
         d = cardnumber % 10000000;
         e = cardnumber % 1000000000;
         f = cardnumber % 100000000000;
         g = cardnumber % 10000000000000;
         h = cardnumber % 1000000000000000;





    }
    while (cardnumber < 1000000000000);
    if (cardnumber / 1000000000000 == 4 || cardnumber / 1000000000000000 == 4 ) {
        printf("VISA\n");
    }
    else if (cardnumber / 100000000000000 == 55|| cardnumber / 100000000000000 == 54 || cardnumber / 100000000000000 == 53 || cardnumber / 100000000000000 == 52 || cardnumber / 100000000000000 == 51 ) {
        printf("MASTERCARD\n");
    }
    else if (cardnumber / 10000000000000 == 34 || cardnumber / 10000000000000 == 37) {
        printf("AMEX\n");
    }
    else {
        printf("INVALID\n");
    }





}