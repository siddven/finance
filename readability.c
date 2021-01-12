#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

float letter(string text);
float word(string text);
float sentence(string text);
int main(void)
{
    string text = get_string("Text:");
    float average_letter = 100/ word(text);

    float L = letter(text) * average_letter;


    float S = sentence(text) *average_letter;

    int index = 0.0588 * L - 0.296 * S - 15.8;
    index = index + 1;
    if (index < 1) {
        printf("Before Grade 1...");

    }
    if (index > 16 ) {
        printf("Grade 16+\n");
    }
    if (index > 1 && index <=16){
        printf("Grade %i\n", index);
}
}


float letter(string text)
{
    float letters = 0.0;
    for (int i = 0,n = strlen(text); i < n; ++i ) {
        text[i] = toupper(text[i]);
    }
    for (int j = 0, a = strlen(text); j < a; ++j) {
        if (text[j] >= 'A' && text[j] <= 'Z') {
            letters += 1;
        }




}
return letters;
}

float word(string text)
{
  float words = 0.0;
  for (int d = 0, b = strlen(text); d < b; ++d) {
      if (text[d] == 32) {
          words += 1;
      }


  }
  words += 1;
return words;
}
float sentence(string text)
{
  float sentences = 0.0;
  for (int c = 0, h = strlen(text); c < h; ++c) {
      if (text[c] == 33 || text[c] == 63 || text[c] == 46 ) {
          sentences += 1;
      }


  }
return sentences;
}