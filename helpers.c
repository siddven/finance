#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
int avg;
    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {
        avg = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed;
        avg = avg / 3;
        float r = avg % 1;
        float sub = 1 - r;
        if (r > 0.0)
        {

            if (r >= 0.5)
            {
                avg += sub;
            }
            else
            {
                avg -= r;
            }
        }
        image[i][j].rgbtRed = avg;
        image[i][j].rgbtGreen = avg;
        image[i][j].rgbtBlue = avg;
        }

    }


    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
