#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start = get_int("Start size:");
    if (start < 9) {
        start = get_int("Start size:");
    }


    // TODO: Prompt for end size
    int end = get_int("End size:");
    if(end < start) {
        end = get_int("End size:");
    }

    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    while (start < end) {
    float born = start / 3;
    float death = start/ 4;
    start += born;
    start -= death;
    years += 1;}
    printf("Years: %d",years);

    }





    // TODO: Print number of years
