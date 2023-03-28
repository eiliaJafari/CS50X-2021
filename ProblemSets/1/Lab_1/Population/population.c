#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start_size;
    while (true)
    {
        start_size = get_int("Start size: ");
        if (start_size >= 9)
        {
            break;
        }
        //if it was in violation of our conditions
        else
        {
            continue;
        }
    }

    // TODO: Prompt for end size
    int end_size;
    while (true)
    {
        end_size = get_int("End size: ");
        if (end_size >= start_size)
        {
            break;
        }
        // if it was in violation of our conditions
        else
        {
            continue;
        }
    }

    // TODO: Calculate number of years until we reach threshold
    int years = 1;
    // If the start size and end size were equal
    if (start_size == end_size)
    {
        years = 0;
        printf("Years: %i\n", years);
    }

    int new_born_rate = start_size / 3;
    int death_rate = start_size / 4;
    int result = start_size + (new_born_rate - death_rate);

    while (result < end_size)
    {
        start_size = result;
        new_born_rate = start_size / 3;
        death_rate = start_size / 4;
        result = start_size + (new_born_rate - death_rate);
        years++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);
}