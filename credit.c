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
    long i;
    long j;
    long k;
    long l;
    long m;
    long n;
    long o;
    long p;
    bool check = false;
    do {
         cardnumber = get_long("Enter a card number:");
         a = cardnumber % 100;
         a = a / 10;
         a = a * 2;
         b = cardnumber % 10000;
         b = b / 1000;
         b = b * 2;
         c = cardnumber % 100000;
         c = c /10000;
         c = c * 2;
         d = cardnumber % 10000000;
         d = d /1000000;
         d = d * 2;
         e = cardnumber % 1000000000;
         e = e /10000000;
         e = e * 2;
         f = cardnumber % 100000000000;
         f = f /100000000;
         f = f * 2;
         g = cardnumber % 10000000000000;
         g = g /1000000000;
         g = g * 2;
         h = cardnumber % 1000000000000000;
         h = h /1000000000000;
         h = h * 2;
         i = cardnumber % 10;
         j = cardnumber % 1000;
         j = j / 100;
         k = cardnumber % 100000;
         k = k / 10000;
         l = cardnumber % 10000000;
         l = l / 1000000;
         m = cardnumber % 1000000000;
         m = m / 100000000;
         n = cardnumber % 100000000000;
         n = n / 10000000000;
         o = cardnumber % 10000000000000;
         o = o / 1000000000000;
         p = cardnumber % 1000000000000000;
         p = p / 100000000000000;



         long z = a + b + c + d + e + f + g + h;
         long y = i + j + k + l + m + n + o + p;
         long x = z + y;
         if (x % 10 == 0) {
             check = true;

         }



    }
    while (cardnumber < 1000000000000 && check == true);
    printf("%li\n",a);
    printf("%li\n",b);
    printf("%li\n",h);
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