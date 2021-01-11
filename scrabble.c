#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2) {
        printf("Player 1 wins!");
    }
    else if (score2 > score1) {
        printf("Player 2 wins!");
    }
    else if (score1 == score2) {
        printf("Tie!");
    }
}

int compute_score(string word)
{
    int score = 0;

    for (int j = 0, a = strlen(word); j < a; j++) {
        word[j] = toupper(word[j]);
    }

   for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            int a = word[i] - 65;
            score = score + POINTS[a];
        }

    // TODO: Compute and return score for string
}
return score;
}
