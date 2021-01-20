#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string abchigh = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string abclow = "abcdefghijklmnopqrstuvwxyz";
int thingy(char letter1, char letter2);

int main (int argc, string argv[])
{
    int x = 0;
    int y = 0;
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
        }
        for (int j = 0, m = strlen(argv[1]); j < m; j++)
        {
            if (argv[1][j] >= 'A' && argv[1][j] <= 'z') {
                if (argv[1][j] >= 91 && argv[1][j] <= 96) {
                    printf("This code has invalid characters. Stop.\n");
                    return 1;
                }
                if (argv[1][j] >= 32 && argv[1][j] <= 64) {
                    printf("This code has invalid characters. Stop.\n");
                    return 1;
                }
                if (argv[1][j] >= 123  && argv[1][j] <= 126) {
                    printf("This code has invalid characters. Stop.\n");
                    return 1;
                }

                for (int k = 25; k > j; k--) {
                    if (argv[1][j] == argv[1][k]) {
                        printf("Your code cannot have repeating characters.");
                        return 1;
                    }
                }


            }
        }
    }
        string plain = get_string("plain text: ");
        printf("ciphertext: ");
        for (int i = 0, n = strlen(plain); i < n; i++) {
            if (plain[i] >= 'a' && plain[i] <= 'z') {
                int diff = 0;
                do {

                    if (toupper(plain[i]) == abchigh[x]) {
                    diff = thingy(argv[1][x],abchigh[x]);
                    plain[i] += diff;
                    printf("%c", plain[i]);
                    plain[i] -= diff;

                    }
                    x ++;
                }
                while (x < 27);
                x = 0;
            }
            if (plain[i] >= 'A' && plain[i] <= 'Z') {
                if (plain[i] >= 91 && plain[i] <= 96) {
                    printf("%c", plain[i]);
                }

                int diff = 0;
                do {
                    if (plain[i] == abchigh[x]) {
                    diff = thingy(argv[1][x],abchigh[x]);
                    plain[i] += diff;
                    printf("%c", plain[i]);
                    plain[i] -= diff;

                    }
                    x ++;


                }
                while (x < 27);
                x = 0;

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
