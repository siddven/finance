#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start;
    int end;
    // TODO: Prompt for start size

    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);



    // TODO: Prompt for end size
    do
    {
        end = get_int("End size:");
    }
    while (end < start);

    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    while (start < end)
    {
        float born = start / 3;
        float death = start / 4;
        start += born;
        start -= death;
        years += 1;
    }
    printf("Years: %d", years);

}





// TODO: Print number of years
