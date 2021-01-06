#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
  do
  {
      height = get_int("Height: ");
  }
  while (height < 1 || height > 8 );




  int n = 0;








for (int i = 0; i < height; ++i) {

  n += 1;
  int u = height - i;
  u -= 1;
  for (int t = 0; t < u; ++t) {
    printf(" ");
  }


  for (int j = 0; j < n; ++j) {
    printf("#");

  }
  printf(" ");
  printf(" ");
  for (int a = 0; a < n; ++a) {
    printf("#");
  }
  printf("\n");


}
}