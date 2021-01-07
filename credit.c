#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long cardnumber;
    long a;
    long b;
   long mult;
   long mult2;
   long mult3;
   long add = 0;
   long addb = 0;
   long addall = 0;

    bool check = false;
    do {
         cardnumber = get_long("Enter a card number:");
         mult = 100;

         mult2 = 10;
         mult3 = 1;
         for (int i = 0; i < 16; ++i ) {
         a = cardnumber % mult;
         a = a / mult2;
         a = a * 2;
         if (a >= 10) {
             long a1 = a / 10;
             long a2 = a % 10;
             add += a1 + a2;
         }
         else {add += a;}
         b = cardnumber % mult2;
         b = b / mult3;
         addb += b;

         ;
         mult = mult *100;
         mult2 = mult2 * 100;
         mult3 = mult3 * 100;


         }
         addall = addb+ add;

         if (addall % 10 == 0) {
             check = true;
         }


    }
    while (cardnumber < 1000000000000 && check == false );

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