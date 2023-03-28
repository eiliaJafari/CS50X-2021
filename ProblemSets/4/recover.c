#include <stdio.h>
#include <stdlib.h>
//#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }

    // Open the input file in r mode
    FILE *input_file = fopen(argv[1], "r");

    // if there was a problem
    if (input_file == NULL)
    {
        printf("Error");
        return 1;
    }

    // 512 size block
    unsigned char buffer[512];

    // counting the image
    int counter = 0;

    // Pointer for output file
    FILE *output_file = NULL;

    // Allocating space
    char *the_file = malloc(8 * sizeof(char));

    // Read 512 bytes
    while (fread(buffer, sizeof(char), 512, input_file))
    {
        // Check if it's a JPEG file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Write jpeg
            sprintf(the_file, "%03i.jpg", counter);

            // Open output file in w mode
            output_file = fopen(the_file, "w");

            counter++;
        }

        // Checking if output is valid
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }

    }

    // Freeing up the space
    free(the_file);
    fclose(input_file);
    fclose(output_file);

    return 0;
}