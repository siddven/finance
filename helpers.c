#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg;
    float average;
    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {
        avg = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed;
        average = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed;
        float r = avg % 3;
        float sub = 1.0-r;
        if (r > 0)
        {
            if (r > 0.5)
            {
                average = average / 3.0;
                average += sub;
            }
            else
            {
                average = average / 3.0;
                average -= r;
            }
        image[i][j].rgbtRed = average;
        image[i][j].rgbtGreen = average;
        image[i][j].rgbtBlue = average;

        }
        else
        {
        avg = avg / 3;
        image[i][j].rgbtRed = avg;
        image[i][j].rgbtGreen = avg;
        image[i][j].rgbtBlue = avg;
        }


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
