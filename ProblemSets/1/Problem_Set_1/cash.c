#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // The variables
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;
    int counter = 0;

    float dollars;

    // To get the number from user
    while (true)
    {
        dollars = get_float("Change owed: ");
        if (dollars >= 0)
        {
            break;
        }
    }

    // Converting to cents
    int cents = round(dollars * 100);

    // Calculating the result
    while (cents != 0)
    {
        if (cents >= quarter)
        {
            cents -= quarter;
            counter++;
            continue;
        }

        if (cents >= dime)
        {
            cents -= dime;
            counter++;
            continue;
        }

        if (cents >= nickel)
        {
            cents -= nickel;
            counter++;
            continue;
        }

        if (cents >= penny)
        {
            cents -= penny;
            counter++;
            continue;
        }
    }

    // Printing the result
    printf("%i\n", counter);
}