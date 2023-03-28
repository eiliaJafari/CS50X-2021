#include "helpers.h"
#include "math.h"

// To limit the amount for sepia func
int rgb_amount(int amount)
{
    if (amount > 255)
    {
        amount = 255;
    }

    return amount;
}

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float gray;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Extracting the colors
            int green = image[i][j].rgbtGreen;
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;

            // Final filter
            gray = round((green + red + blue) / 3.00);

            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtBlue = gray;
            image[i][j].rgbtRed = gray;

        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Filter colors
    int sRed;
    int sGreen;
    int sBlue;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sRed = rgb_amount(round(0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue + 0.393 * image[i][j].rgbtRed));
            sGreen = rgb_amount(round(0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue + 0.349 * image[i][j].rgbtRed));
            sBlue = rgb_amount(round(0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue + 0.272 * image[i][j].rgbtRed));

            // Final filter
            image[i][j].rgbtGreen = sGreen;
            image[i][j].rgbtBlue = sBlue;
            image[i][j].rgbtRed = sRed;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // To swap colors
    int swap[3];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Extracting colors
            swap[2] = image[i][j].rgbtRed;
            swap[1] = image[i][j].rgbtGreen;
            swap[0] = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;

            // Final filter
            image[i][width - j - 1].rgbtRed = swap[2];
            image[i][width - j - 1].rgbtGreen = swap[1];
            image[i][width - j - 1].rgbtBlue = swap[0];
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // A temporary image for bluring
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int tRed;
            int tGreen;
            int tBlue;
            tRed = 0;
            tGreen = 0;
            tBlue = 0;

            float counter = 0.00;

            // To Get the pixels
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    int X = i + k;
                    int Y = j + l;

                    // Checking valid pixels
                    if (X < 0 || X > (height - 1) || Y < 0 || Y > (width - 1))
                    {
                        continue;
                    }

                    //Get the values
                    tRed += image[X][Y].rgbtRed;
                    tGreen += image[X][Y].rgbtGreen;
                    tBlue += image[X][Y].rgbtBlue;

                    counter++;
                }

                // Calculating average
                temp[i][j].rgbtRed = round(tRed / counter);
                temp[i][j].rgbtGreen = round(tGreen / counter);
                temp[i][j].rgbtBlue = round(tBlue / counter);
            }
        }

    }

    // Copying temp image into original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }

    return;
}
