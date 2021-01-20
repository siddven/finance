#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int charcount;
int check = 2015;
string abchigh = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string abclow = "abcdefghijklmnopqrstuvwxyz";
int thingy(char letter1, char letter2);

int main (int argc, string argv[])
{
    int x = 0;
    //Checks if # of arguments is valid
    if (argc != 2)
    {
        printf("Invalid number of arguments.\n");
        return 1;
    }

    else
    {
        if (strlen(argv[1]) != 26)
        {
            printf("The code is invalid because the number of characters entered is invalid.\n");
            return 1;
        }
        
        for (int i = 0, n = strlen(argv[1]); i < n; i++) {
            argv[1][i] =  toupper(argv[1][i]);
            charcount += argv[1][i];
        }
        for (int j = 0, m = strlen(argv[1]); j < m; j++)
        {
            if (argv[1][j] >= 'A' && argv[1][j] <= 'z') {
                if (argv[1][j] >= 93 && argv[1][j] <= 96) {
                    printf("This code has invalid characters. Stop.\n");
                    return 1;
                }
            if (charcount != check) {
                printf("code is invalid because multiple of the same characters are present.");
                return 1;
            }
            }
        }
    }
        string plain = get_string("plain text: ");
        printf("cipher text: ");
        for (int i = 0, n = strlen(plain); i < n; i++) {
            if (plain[i] >= 'a' && plain[i] <= 'z') {
                int diff = 0;
                do {
                    x ++;
                    if (toupper(plain[i]) == abchigh[x]) {
                    diff = thingy(argv[1][x],abchigh[x]);
                    plain[i] += diff;
                    printf("%c", plain[i]);
                    plain[i] -= diff;
                    }
                }
                while (x < 26);
                x = 0;

            }
            if (plain[i] >= 'A' && plain[i] <= 'Z') {
                if (plain[i] >= 91 && plain[i] <= 96) {
                    printf("%c", plain[i]);
                }
                else {
                int diff = 0;
                do {
                    x ++;
                    if (plain[i] == abchigh[x]) {
                    diff = thingy(argv[1][x],abchigh[x]);
                    plain[i] += diff;
                    printf("%c", plain[i]);
                    plain[i] -= diff;
                    }
                }
                while (x < 26);
                x = 0;
                }
        }
        if (plain[i] >= 32 && plain[i] <= 64) {
            printf("%c", plain[i]);
        }
}
    printf("\n");
    }

int thingy (char letter1, char letter2){
    int difference = letter1 - letter2;
    return difference;
    }
