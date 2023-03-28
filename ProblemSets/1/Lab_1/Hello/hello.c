#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //To get the user's name
    string name = get_string("What is your name?\n");
    //To print the user's name
    printf("hello, %s\n", name);
}