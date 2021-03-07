#include "helpers.h"
#include "math.h"
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float avg;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
        avg = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed;
        avg = avg / 3.0;
        avg = round(avg);
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

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            RGBTRIPLE buffer = image[i][j];
            image[i][j] = image[i][width-j-1];
            image[i][width-j-1] = buffer;

        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{


    RGBTRIPLE buffer[height][width];
    float avgblue = 0;
    float avgred = 0;
    int avggreen = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            buffer[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++ )
    {
        avgblue = 0;
        avgred = 0;
        avggreen = 0;
        for (int j = 0; j < width; j++)
        {

            if (i == 0)
            {
                if (j == 0)
            {
                avgblue = buffer[i+1][j].rgbtBlue + buffer[i+1][j+1].rgbtBlue + buffer[i][j+1].rgbtBlue + buffer[i][j].rgbtBlue;
                avgred = buffer[i+1][j].rgbtRed + buffer[i+1][j+1].rgbtRed + buffer[i][j+1].rgbtRed + buffer[i][j].rgbtRed;
                avggreen = buffer[i+1][j].rgbtGreen + buffer[i+1][j+1].rgbtGreen + buffer[i][j+1].rgbtGreen + buffer[i][j].rgbtGreen;
                avgblue = avgblue / 4.0;
                avgred = avgred / 4.0;
                avggreen = avggreen / 4.0;
                avgblue = round(avgblue);
                avgred = round(avgred);
                avggreen = round(avggreen);

            }


            else
            {
            avgblue =  buffer[i+1][j].rgbtBlue + buffer[i+1][j+1].rgbtBlue + buffer[i][j+1].rgbtBlue + buffer[i][j].rgbtBlue +
            buffer[i][j-1].rgbtBlue + buffer[i+1][j-1].rgbtBlue;
            avgred = buffer[i+1][j].rgbtRed + buffer[i+1][j+1].rgbtRed + buffer[i][j+1].rgbtRed + buffer[i][j].rgbtRed +
            buffer[i][j-1].rgbtRed + buffer[i+1][j-1].rgbtRed;
            avggreen = buffer[i+1][j].rgbtGreen + buffer[i+1][j+1].rgbtGreen + buffer[i][j+1].rgbtGreen + buffer[i][j].rgbtGreen +
            buffer[i][j-1].rgbtGreen + buffer[1][j-1].rgbtGreen;
            avgblue = avgblue / 6.0;
            avgred = avgred / 6.0;
            avggreen = avggreen / 6.0;
            avgblue = round(avgblue);
            avggreen = round(avggreen);
            avgred = round(avgred);

            }

            }
            if (i == height)
            {

                if (j == 0)
                {
                avgblue = buffer[i-1][j].rgbtBlue + buffer[i-1][j+1].rgbtBlue + buffer[i][j+1].rgbtBlue + buffer[i][j].rgbtBlue;
                avgred = buffer[i-1][j].rgbtRed + buffer[i-1][j+1].rgbtRed + buffer[i][j+1].rgbtRed + buffer[i][j].rgbtRed;
                avggreen = buffer[i-1][j].rgbtGreen + buffer[i-1][j+1].rgbtGreen + buffer[i][j+1].rgbtGreen + buffer[i][j].rgbtGreen;
                avgblue = avgblue / 4.0;
                avgred = avgred / 4.0;
                avggreen = avggreen / 4.0;
                avgblue = round(avgblue);
                avgred = round(avgred);
                avggreen = round(avggreen);

                }

            else {


            avgblue =  buffer[i-1][j].rgbtBlue + buffer[i-1][j+1].rgbtBlue + buffer[i][j+1].rgbtBlue + buffer[i][j].rgbtBlue +
            buffer[i][j-1].rgbtBlue + buffer[i-1][j-1].rgbtBlue;
            avgred = buffer[i+1][j].rgbtRed + buffer[i+1][j+1].rgbtRed + buffer[i][j+1].rgbtRed + buffer[i][j].rgbtRed +
            buffer[i][j-1].rgbtRed + buffer[i-1][j-1].rgbtRed;
            avggreen = buffer[i+1][j].rgbtGreen + buffer[i+1][j+1].rgbtGreen + buffer[i][j+1].rgbtGreen + buffer[i][j].rgbtGreen +
            buffer[i][j-1].rgbtGreen + buffer[i-1][j-1].rgbtGreen;
            avgblue = avgblue / 6.0;
            avgred = avgred / 6.0;
            avggreen = avggreen / 6.0;
            avgblue = round(avgblue);
            avggreen = round(avggreen);
            avgred = round(avgred);

            }
            }
            if ( j == width)
            {

                if (i == 0)
                {
                avgblue = buffer[i][j-1].rgbtBlue + buffer[i+1][j].rgbtBlue + buffer[i+1][j-1].rgbtBlue + buffer[i][j].rgbtBlue;
                avgred = buffer[i][j-1].rgbtRed + buffer[i-1][j].rgbtRed + buffer[i+1][j-1].rgbtRed + buffer[i][j].rgbtRed;
                avggreen = buffer[i][j-1].rgbtGreen + buffer[i+1][j].rgbtGreen + buffer[i+1][j-1].rgbtGreen + buffer[i][j].rgbtGreen;
                avgblue = avgblue / 4.0;
                avgred = avgred / 4.0;
                avggreen = avggreen / 4.0;
                avgblue = round(avgblue);
                avgred = round(avgred);
                avggreen = round(avggreen);

                }
                if (i == height)
                {
                avgblue = buffer[i-1][j-1].rgbtBlue + buffer[i-1][j].rgbtBlue + buffer[i-1][j-1].rgbtBlue + buffer[i][j].rgbtBlue;
                avgred = buffer[i-1][j-1].rgbtRed + buffer[i-1][j].rgbtRed + buffer[i-1][j+1].rgbtRed + buffer[i][j].rgbtRed;
                avggreen = buffer[i-1][j-1].rgbtGreen + buffer[i-1][j].rgbtGreen + buffer[i-1][j+1].rgbtGreen + buffer[i][j].rgbtGreen;
                avgblue = avgblue / 4.0;
                avgred = avgred / 4.0;
                avggreen = avggreen / 4.0;
                avgblue = round(avgblue);
                avgred = round(avgred);
                avggreen = round(avggreen);

                }
            else
            {
            avgblue =  buffer[i][j+1].rgbtBlue + buffer[i+1][j].rgbtBlue + buffer[i+1][j+1].rgbtBlue + buffer[i][j].rgbtBlue +
            buffer[i][j-1].rgbtBlue + buffer[i+1][j-1].rgbtBlue;
            avgred = buffer[i][j+1].rgbtRed + buffer[i+1][j].rgbtRed + buffer[i+1][j+1].rgbtRed + buffer[i][j].rgbtRed +
            buffer[i][j-1].rgbtRed + buffer[i+1][j-1].rgbtRed;
            avggreen = buffer[i][j+1].rgbtGreen + buffer[i+1][j].rgbtGreen + buffer[i+1][j+1].rgbtGreen + buffer[i][j].rgbtGreen +
            buffer[i][j-1].rgbtGreen + buffer[i+1][j-1].rgbtGreen;
            avgblue = avgblue / 6.0;
            avgred = avgred / 6.0;
            avggreen = avggreen / 6.0;
            avgblue = round(avgblue);
            avggreen = round(avggreen);
            avgred = round(avgred);

            }
            }
            if (j == 0)
            {






            avgblue =  buffer[i][j+1].rgbtBlue + buffer[i+1][j].rgbtBlue + buffer[i+1][j+1].rgbtBlue + buffer[i][j].rgbtBlue +
            buffer[i-1][j].rgbtBlue + buffer[i-1][j+1].rgbtBlue;
            avgred = buffer[i][j+1].rgbtRed + buffer[i+1][j].rgbtRed + buffer[i+1][j+1].rgbtRed + buffer[i][j].rgbtRed +
            buffer[i-1][j].rgbtRed + buffer[i-1][j+1].rgbtRed;
            avggreen = buffer[i][j+1].rgbtGreen + buffer[i+1][j].rgbtGreen + buffer[i+1][j+1].rgbtGreen + buffer[i][j].rgbtGreen +
            buffer[i-1][j].rgbtGreen + buffer[i-1][j+1].rgbtGreen;
            avgblue = avgblue / 6.0;
            avgred = avgred / 6.0;
            avggreen = avggreen / 6.0;
            avgblue = round(avgblue);
            avggreen = round(avggreen);
            avgred = round(avgred);


            }
            else
            {
            avgblue = buffer[i][j].rgbtBlue + buffer[i+1][j].rgbtBlue + buffer[i+1][j+1].rgbtBlue + buffer[i][j+1].rgbtBlue + buffer[i-1][j].rgbtBlue+
            buffer[i-1][j-1].rgbtBlue + buffer[i][j-1].rgbtBlue + buffer[i-1][j+1].rgbtBlue + buffer[i+1][j-1].rgbtBlue;
            avgred = buffer[i][j].rgbtRed + buffer[i+1][j].rgbtRed + buffer[i+1][j+1].rgbtRed + buffer[i][j+1].rgbtRed + buffer[i-1][j].rgbtRed+
            buffer[i-1][j-1].rgbtRed + buffer[i][j-1].rgbtRed + buffer[i-1][j+1].rgbtRed + buffer[i+1][j-1].rgbtRed;
            avggreen = buffer[i][j].rgbtGreen + buffer[i+1][j].rgbtGreen + buffer[i+1][j+1].rgbtGreen + buffer[i][j+1].rgbtGreen + buffer[i-1][j].rgbtGreen+
            buffer[i-1][j-1].rgbtGreen + buffer[i][j-1].rgbtGreen + buffer[i-1][j+1].rgbtGreen + buffer[i+1][j-1].rgbtGreen;
            avgblue = avgblue / 9.0;
            avgred = avgred / 9.0;
            avggreen = avggreen / 9.0;
            avgblue = round(avgblue);
            avggreen = round(avggreen);
            avgred = round(avgred);
            }
            image[i][j].rgbtBlue = avgblue;
            image[i][j].rgbtGreen = avggreen;
            image[i][j].rgbtRed = avgred;

        }
    }



    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

