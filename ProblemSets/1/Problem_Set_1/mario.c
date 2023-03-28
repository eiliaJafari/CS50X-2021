#include <stdio.h>
#include <cs50.h>

int main()
{
    int i, j;
    int num;

    while (true)
    {
        num = get_int("Height: ");
        if (num >= 1 && num <= 8)
        {
            break;
        }
    }

    for (i = 1; i <= num; i++)
    {
        // Logic to print spaces
        for (j = 1; j <= num - i; j++)
        {
            printf(" ");
        }

        // Logic to print stars
        for (j = 1; j <= i; j++)
        {
            printf("#");
        }

        // Printing two spaces between triangles
        printf("  ");

        // Printing second triangle
        for (j = 1; j <= i; j++)
        {
            printf("#");
        }

        // Next line
        printf("\n");
    }
}
