#include <stdio.h>
#include <cs50.h>
//user input hello world
int main(void)
{
    string name = get_string("What is your name?:");
    printf("hello, %s", name);
}