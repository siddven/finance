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
    float avggreen = 0;

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

            if (i == 0 && j == 0)
            {

                //for top left corner
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
            else if (i == height-1 && j == 0)
            {
                //for bottom left corner
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
            else if ( j == width-1 && i == 0)
            {

                //for top right corner
                avgblue = buffer[i][j-1].rgbtBlue + buffer[i+1][j].rgbtBlue + buffer[i+1][j-1].rgbtBlue + buffer[i][j].rgbtBlue;
                avgred = buffer[i][j-1].rgbtRed + buffer[i+1][j].rgbtRed + buffer[i+1][j-1].rgbtRed + buffer[i][j].rgbtRed;
                avggreen = buffer[i][j-1].rgbtGreen + buffer[i+1][j].rgbtGreen + buffer[i+1][j-1].rgbtGreen + buffer[i][j].rgbtGreen;

                avgblue = avgblue / 4.0;
                avgred = avgred / 4.0;
                avggreen = avggreen / 4.0;

                avgblue = round(avgblue);
                avgred = round(avgred);
                avggreen = round(avggreen);

            }
             else if  (i == height-1 && j == width-1)
                {
                //for bottom edge
                avgblue = buffer[i-1][j-1].rgbtBlue + buffer[i-1][j].rgbtBlue + buffer[i][j-1].rgbtBlue + buffer[i][j].rgbtBlue;
                avgred = buffer[i-1][j-1].rgbtRed + buffer[i-1][j].rgbtRed + buffer[i][j-1].rgbtRed + buffer[i][j].rgbtRed;
                avggreen = buffer[i-1][j-1].rgbtGreen + buffer[i-1][j].rgbtGreen + buffer[i][j-1].rgbtGreen + buffer[i][j].rgbtGreen;

                avgblue = avgblue / 4.0;
                avgred = avgred / 4.0;
                avggreen = avggreen / 4.0;

                avgblue = round(avgblue);
                avgred = round(avgred);
                avggreen = round(avggreen);
                }



            else if (i == 0 && j != width-1 && j != 0)
            {
            //for top edge
            avgblue =  buffer[i+1][j].rgbtBlue + buffer[i+1][j+1].rgbtBlue + buffer[i][j+1].rgbtBlue + buffer[i][j].rgbtBlue +
            buffer[i][j-1].rgbtBlue + buffer[i+1][j-1].rgbtBlue;
            avgred = buffer[i+1][j].rgbtRed + buffer[i+1][j+1].rgbtRed + buffer[i][j+1].rgbtRed + buffer[i][j].rgbtRed +
            buffer[i][j-1].rgbtRed + buffer[i+1][j-1].rgbtRed;
            avggreen = buffer[i+1][j].rgbtGreen + buffer[i+1][j+1].rgbtGreen + buffer[i][j+1].rgbtGreen + buffer[i][j].rgbtGreen +
            buffer[i][j-1].rgbtGreen + buffer[i+1][j-1].rgbtGreen;

            avgblue = avgblue / 6.0;
            avgred = avgred / 6.0;
            avggreen = avggreen / 6.0;

            avgblue = round(avgblue);
            avggreen = round(avggreen);
            avgred = round(avgred);
            }



            else if (i == height-1 && j != 0 && j != width-1)
            {


            avgblue =  buffer[i-1][j].rgbtBlue + buffer[i-1][j+1].rgbtBlue + buffer[i][j+1].rgbtBlue + buffer[i][j].rgbtBlue +
            buffer[i][j-1].rgbtBlue + buffer[i-1][j-1].rgbtBlue;
            avgred = buffer[i-1][j].rgbtRed + buffer[i-1][j+1].rgbtRed + buffer[i][j+1].rgbtRed + buffer[i][j].rgbtRed +
            buffer[i][j-1].rgbtRed + buffer[i-1][j-1].rgbtRed;
            avggreen = buffer[i-1][j].rgbtGreen + buffer[i-1][j+1].rgbtGreen + buffer[i][j+1].rgbtGreen + buffer[i][j].rgbtGreen +
            buffer[i][j-1].rgbtGreen + buffer[i-1][j-1].rgbtGreen;

            avgblue = avgblue / 6.0;
            avgred = avgred / 6.0;
            avggreen = avggreen / 6.0;

            avgblue = round(avgblue);
            avggreen = round(avggreen);
            avgred = round(avgred);
            }




            else if (j == width-1 && i != height-1 && i != 0)
            {

            //for right edge
            avgblue =  buffer[i][j-1].rgbtBlue + buffer[i+1][j].rgbtBlue + buffer[i+1][j-1].rgbtBlue + buffer[i][j].rgbtBlue +
            buffer[i-1][j].rgbtBlue + buffer[i-1][j-1].rgbtBlue;
            avgred = buffer[i][j-1].rgbtRed + buffer[i+1][j].rgbtRed + buffer[i+1][j-1].rgbtRed + buffer[i][j].rgbtRed +
            buffer[i-1][j].rgbtRed + buffer[i-1][j-1].rgbtRed;
            avggreen = buffer[i][j-1].rgbtGreen + buffer[i+1][j].rgbtGreen + buffer[i+1][j-1].rgbtGreen + buffer[i][j].rgbtGreen +
            buffer[i-1][j].rgbtGreen + buffer[i-1][j-1].rgbtGreen;
            avgblue = avgblue / 6.0;
            avgred = avgred / 6.0;
            avggreen = avggreen / 6.0;
            avgblue = round(avgblue);
            avggreen = round(avggreen);
            avgred = round(avgred);
            }

            else if (j == 0 && i != 0 && i != height-1)
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
int sobel(float x, float y)

{
    x = x*x;
    y = y*y;
    x = x+y;
    x = sqrt(x);
    x = round(x);
    if (x > 255)
        {
            x = 255;
        }
    return x;

}
// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE buffer[height][width];
    float avgblueX = 0;
    float avgredX = 0;
    float avggreenX = 0;
    float avgblueY = 0;
    float avgredY = 0;
    float avggreenY = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            buffer[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++ )
    {
        avgblueX = 0;
        avgredX = 0;
        avggreenX = 0;
        avgblueY = 0;
        avgredY = 0;
        avggreenY = 0;


        for (int j = 0; j < width; j++)
        {



            if (i == 0 && j == 0)
            {
                //Calculate GX for all color channels
                avgblueX = buffer[i][j].rgbtBlue*0 + buffer[i+1][j].rgbtBlue*0 + buffer[i+1][j+1].rgbtBlue*1 + buffer[i][j+1].rgbtBlue*2;

                avgredX = buffer[i][j].rgbtRed*0 + buffer[i+1][j].rgbtRed*0 + buffer[i+1][j+1].rgbtRed*1 + buffer[i][j+1].rgbtRed*2;

                avggreenX = buffer[i][j].rgbtGreen*0 + buffer[i+1][j].rgbtGreen*0 + buffer[i+1][j+1].rgbtGreen*1 + buffer[i][j+1].rgbtGreen*2;

                //Calculate Gy for all color channels
                avgblueY = buffer[i][j].rgbtBlue*0 + buffer[i+1][j].rgbtBlue*2 + buffer[i+1][j+1].rgbtBlue*1 + buffer[i][j+1].rgbtBlue*0 + buffer[i-1][j].rgbtBlue*0+
                buffer[i-1][j-1].rgbtBlue*0 + buffer[i][j-1].rgbtBlue*0 + buffer[i-1][j+1].rgbtBlue*0 + buffer[i+1][j-1].rgbtBlue*0;

                avgredY = buffer[i][j].rgbtRed*0 + buffer[i+1][j].rgbtRed*2 + buffer[i+1][j+1].rgbtRed*1 + buffer[i][j+1].rgbtRed*0 + buffer[i-1][j].rgbtRed*0+
                buffer[i-1][j-1].rgbtRed*0 + buffer[i][j-1].rgbtRed*0 + buffer[i-1][j+1].rgbtRed*0 + buffer[i+1][j-1].rgbtRed*0;

                avggreenY = buffer[i][j].rgbtGreen*0 + buffer[i+1][j].rgbtGreen*2 + buffer[i+1][j+1].rgbtGreen*1 + buffer[i][j+1].rgbtGreen*0 + buffer[i-1][j].rgbtGreen*0+
                buffer[i-1][j-1].rgbtGreen*0 + buffer[i][j-1].rgbtGreen*0 + buffer[i-1][j+1].rgbtGreen*-1 + buffer[i+1][j-1].rgbtGreen*0;

                //Calculate square root of Gx and Gy
                avgblueX = sobel(avgblueX, avgblueY);
                avgredX = sobel(avgredX, avgredY);
                avggreenX = sobel(avggreenX, avggreenY);
            }


            else if (i == height-1 && j == 0)
            {
                //Calculate GX for all color channels
                avgblueX = buffer[i][j].rgbtBlue*0 + buffer[i][j+1].rgbtBlue*2  + buffer[i-1][j+1].rgbtBlue*1 + buffer[i+1][j-1].rgbtBlue*-1;

                avgredX = buffer[i][j].rgbtRed*0 + buffer[i][j+1].rgbtRed*2 + buffer[i-1][j+1].rgbtRed*1 + buffer[i+1][j-1].rgbtRed*-1;

                avggreenX = buffer[i][j].rgbtGreen*0 + buffer[i][j+1].rgbtGreen*2 + buffer[i-1][j+1].rgbtGreen*1 + buffer[i+1][j-1].rgbtGreen*-1;



                //Calculate Gy for all color channels
                avgblueY = buffer[i][j].rgbtBlue*0+ buffer[i][j+1].rgbtBlue*0 + buffer[i-1][j].rgbtBlue*-2 + buffer[i-1][j+1].rgbtBlue*-1 + buffer[i+1][j-1].rgbtBlue*1;

                avgredY = buffer[i][j].rgbtRed*0+ buffer[i][j+1].rgbtRed*0 + buffer[i-1][j].rgbtRed*-2 + buffer[i-1][j+1].rgbtRed*-1 + buffer[i+1][j-1].rgbtRed*1;

                avggreenY = buffer[i][j].rgbtGreen*0+ buffer[i][j+1].rgbtGreen*0 + buffer[i-1][j].rgbtGreen*-2 + buffer[i-1][j+1].rgbtGreen*-1 + buffer[i+1][j-1].rgbtGreen*1;
                //Calculate square root of Gx and Gy
                avgblueX = sobel(avgblueX, avgblueY);
                avgredX = sobel(avgredX, avgredY);
                avggreenX = sobel(avggreenX, avggreenY);
            }
            else if ( j == width-1 && i == 0)
            {
                avgblueX = buffer[i][j-1].rgbtBlue*-2 + buffer[i+1][j].rgbtBlue*0 + buffer[i+1][j-1].rgbtBlue*-1 + buffer[i][j].rgbtBlue*0;

                avgredX = buffer[i][j-1].rgbtRed*-2 + buffer[i+1][j].rgbtRed*0 + buffer[i+1][j-1].rgbtRed*-1 + buffer[i][j].rgbtRed*0;

                avggreenX = buffer[i][j-1].rgbtGreen*-2 + buffer[i+1][j].rgbtGreen*0 + buffer[i+1][j-1].rgbtGreen*-1 + buffer[i][j].rgbtGreen*0;

                avgblueY = buffer[i][j-1].rgbtBlue*0 + buffer[i+1][j].rgbtBlue*2 + buffer[i+1][j-1].rgbtBlue*1 + buffer[i][j].rgbtBlue*0;

                avgredY = buffer[i][j-1].rgbtRed*0 + buffer[i+1][j].rgbtRed*2 + buffer[i+1][j-1].rgbtRed*1 + buffer[i][j].rgbtRed*0;

                avggreenY = buffer[i][j-1].rgbtGreen*0 + buffer[i+1][j].rgbtGreen*2 + buffer[i+1][j-1].rgbtGreen*1 + buffer[i][j].rgbtGreen*0;


                avgblueX = sobel(avgblueX, avgblueY);
                avgredX = sobel(avgredX, avgredY);
                avggreenX = sobel(avggreenX, avggreenY);

            }
            else if  (i == height-1 && j == width-1)
            {
                avgblueX = buffer[i-1][j-1].rgbtBlue*-1 + buffer[i-1][j].rgbtBlue*0 + buffer[i][j-1].rgbtBlue*-2 + buffer[i][j].rgbtBlue*0;
                avgredX = buffer[i-1][j-1].rgbtRed*-1 + buffer[i-1][j].rgbtRed*0 + buffer[i][j-1].rgbtRed*-2 + buffer[i][j].rgbtRed*0;
                avggreenX = buffer[i-1][j-1].rgbtGreen*-1 + buffer[i-1][j].rgbtGreen*0 + buffer[i][j-1].rgbtGreen*-2 + buffer[i][j].rgbtGreen*0;

                avgblueY = buffer[i-1][j-1].rgbtBlue*-1 + buffer[i-1][j].rgbtBlue*-2 + buffer[i][j-1].rgbtBlue*0 + buffer[i][j].rgbtBlue*0;
                avgredY = buffer[i-1][j-1].rgbtRed*-1 + buffer[i-1][j].rgbtRed*-2 + buffer[i][j-1].rgbtRed*0 + buffer[i][j].rgbtRed*0;
                avggreenY = buffer[i-1][j-1].rgbtGreen*-1 + buffer[i-1][j].rgbtGreen*-2 + buffer[i][j-1].rgbtGreen*0 + buffer[i][j].rgbtGreen*0;

                avgblueX = sobel(avgblueX, avgblueY);
                avgredX = sobel(avgredX, avgredY);
                avggreenX = sobel(avggreenX, avggreenY);


            }
            else if (i == 0 && j != width-1 && j != 0)
            {
                //for top edge
                avgblueX =  buffer[i+1][j].rgbtBlue*0 + buffer[i+1][j+1].rgbtBlue*1 + buffer[i][j+1].rgbtBlue*2 + buffer[i][j].rgbtBlue*0 +
                buffer[i][j-1].rgbtBlue*-2 + buffer[i+1][j-1].rgbtBlue*-1;

                avgredX = buffer[i+1][j].rgbtRed*0 + buffer[i+1][j+1].rgbtRed*1 + buffer[i][j+1].rgbtRed*2 + buffer[i][j].rgbtRed*0 +
                buffer[i][j-1].rgbtRed*-2 + buffer[i+1][j-1].rgbtRed*-1;

                avggreenX = buffer[i+1][j].rgbtGreen*0 + buffer[i+1][j+1].rgbtGreen*1 + buffer[i][j+1].rgbtGreen*2 + buffer[i][j].rgbtGreen*0 +
                buffer[i][j-1].rgbtGreen*-2 + buffer[i+1][j-1].rgbtGreen*-1;

                avgblueY =  buffer[i+1][j].rgbtBlue*2 + buffer[i+1][j+1].rgbtBlue*1 + buffer[i][j+1].rgbtBlue*1 + buffer[i][j].rgbtBlue*0 +
                buffer[i][j-1].rgbtBlue*0 + buffer[i+1][j-1].rgbtBlue*1;

                avgredY = buffer[i+1][j].rgbtRed*2 + buffer[i+1][j+1].rgbtRed*1 + buffer[i][j+1].rgbtRed*1 + buffer[i][j].rgbtRed*0 +
                buffer[i][j-1].rgbtRed*0 + buffer[i+1][j-1].rgbtRed*1;

                avggreenY = buffer[i+1][j].rgbtGreen*2 + buffer[i+1][j+1].rgbtGreen*1 + buffer[i][j+1].rgbtGreen*1 + buffer[i][j].rgbtGreen*0 +
                buffer[i][j-1].rgbtGreen*0 + buffer[i+1][j-1].rgbtGreen*1;


                avgblueX = sobel(avgblueX, avgblueY);
                avgredX = sobel(avgredX, avgredY);
                avggreenX = sobel(avggreenX, avggreenY);

            }
            else if (j == width-1 && i != 0 && i != height-1)
            {
                //for right edge

                avgblueX =  buffer[i][j-1].rgbtBlue*-2 + buffer[i+1][j].rgbtBlue*0 + buffer[i+1][j-1].rgbtBlue*-1 + buffer[i][j].rgbtBlue*0 +
                buffer[i-1][j].rgbtBlue*0 + buffer[i-1][j-1].rgbtBlue*-1;

                avgredX = buffer[i][j-1].rgbtRed*-2 + buffer[i+1][j].rgbtRed*0 + buffer[i+1][j-1].rgbtRed*-1 + buffer[i][j].rgbtRed*0 +
                buffer[i-1][j].rgbtRed*-2 + buffer[i-1][j-1].rgbtRed*-1;

                avggreenX = buffer[i][j-1].rgbtGreen*-2 + buffer[i+1][j].rgbtGreen*0 + buffer[i+1][j-1].rgbtGreen*-1 + buffer[i][j].rgbtGreen*0 +
                buffer[i-1][j].rgbtGreen*-2 + buffer[i-1][j-1].rgbtGreen*-1;

                avgblueY =  buffer[i][j-1].rgbtBlue*0 + buffer[i+1][j].rgbtBlue*2 + buffer[i+1][j-1].rgbtBlue*1 + buffer[i][j].rgbtBlue*0 +
                buffer[i-1][j].rgbtBlue*0 + buffer[i-1][j-1].rgbtBlue*-1;

                avgredY = buffer[i][j-1].rgbtRed*0 + buffer[i+1][j].rgbtRed*2 + buffer[i+1][j-1].rgbtRed*1 + buffer[i][j].rgbtRed*0 +
                buffer[i-1][j].rgbtRed*0 + buffer[i-1][j-1].rgbtRed*-1;

                avggreenY = buffer[i][j-1].rgbtGreen*0 + buffer[i+1][j].rgbtGreen*2 + buffer[i+1][j-1].rgbtGreen*1 + buffer[i][j].rgbtGreen*0 +
                buffer[i-1][j].rgbtGreen*0 + buffer[i-1][j-1].rgbtGreen*-1;

                avgblueX = sobel(avgblueX, avgblueY);
                avgredX = sobel(avgredX, avgredY);
                avggreenX = sobel(avggreenX, avggreenY);


            }
            else if (i == height-1 && j!= width-1 && j != 0)
            {
                //for bottom edge
                avgblueX =  buffer[i-1][j].rgbtBlue*0 + buffer[i-1][j+1].rgbtBlue*1 + buffer[i][j+1].rgbtBlue*2 + buffer[i][j].rgbtBlue*0 +
                buffer[i][j-1].rgbtBlue*-2 + buffer[i-1][j-1].rgbtBlue*-1;

                avgredX = buffer[i-1][j].rgbtRed*0 + buffer[i-1][j+1].rgbtRed*1 + buffer[i][j+1].rgbtRed*2 + buffer[i][j].rgbtRed*0 +
                buffer[i][j-1].rgbtRed*0 + buffer[i-1][j-1].rgbtRed*-1;

                avggreenX = buffer[i-1][j].rgbtGreen*0 + buffer[i-1][j+1].rgbtGreen*1 + buffer[i][j+1].rgbtGreen*2 + buffer[i][j].rgbtGreen*0 +
                buffer[i][j-1].rgbtGreen*0 + buffer[i-1][j-1].rgbtGreen*-1;

                avgblueY =  buffer[i-1][j].rgbtBlue*-2 + buffer[i-1][j+1].rgbtBlue*-1 + buffer[i][j+1].rgbtBlue*0 + buffer[i][j].rgbtBlue*0 +
                buffer[i][j-1].rgbtBlue*0 + buffer[i-1][j-1].rgbtBlue*-1;

                avgredY = buffer[i-1][j].rgbtRed*-2 + buffer[i-1][j+1].rgbtRed*-1 + buffer[i][j+1].rgbtRed*0 + buffer[i][j].rgbtRed*0 +
                buffer[i][j-1].rgbtRed*0 + buffer[i-1][j-1].rgbtRed*-1;

                avggreenY = buffer[i-1][j].rgbtGreen*-2 + buffer[i-1][j+1].rgbtGreen*-1 + buffer[i][j+1].rgbtGreen*0 + buffer[i][j].rgbtGreen*0 +
                buffer[i][j-1].rgbtGreen*0 + buffer[i-1][j-1].rgbtGreen*-1;

                avgblueX = sobel(avgblueX, avgblueY);
                avgredX = sobel(avgredX, avgredY);
                avggreenX = sobel(avggreenX, avggreenY);


            }
            else if (j == 0 && i != height-1 && i != 0)
            {
                avgblueX =  buffer[i][j+1].rgbtBlue*2 + buffer[i+1][j].rgbtBlue*0 + buffer[i+1][j+1].rgbtBlue*1 + buffer[i][j].rgbtBlue*0 +
                buffer[i-1][j].rgbtBlue*0 + buffer[i-1][j+1].rgbtBlue*1;

                avgredX = buffer[i][j+1].rgbtRed*2 + buffer[i+1][j].rgbtRed*0 + buffer[i+1][j+1].rgbtRed*1 + buffer[i][j].rgbtRed*0 +
                buffer[i-1][j].rgbtRed*0 + buffer[i-1][j+1].rgbtRed*1;

                avggreenX = buffer[i][j+1].rgbtGreen*2 + buffer[i+1][j].rgbtGreen*0 + buffer[i+1][j+1].rgbtGreen*1 + buffer[i][j].rgbtGreen*0 +
                buffer[i-1][j].rgbtGreen*0 + buffer[i-1][j+1].rgbtGreen*0;

                avgblueY =  buffer[i][j+1].rgbtBlue*0 + buffer[i+1][j].rgbtBlue*2 + buffer[i+1][j+1].rgbtBlue*1 + buffer[i][j].rgbtBlue*0 +
                buffer[i-1][j].rgbtBlue*-2 + buffer[i-1][j+1].rgbtBlue*-1;

                avgredY = buffer[i][j+1].rgbtRed*0 + buffer[i+1][j].rgbtRed*2 + buffer[i+1][j+1].rgbtRed*1 + buffer[i][j].rgbtRed*0 +
                buffer[i-1][j].rgbtRed*-2 + buffer[i-1][j+1].rgbtRed*-1;

                avggreenY = buffer[i][j+1].rgbtGreen*0 + buffer[i+1][j].rgbtGreen*2 + buffer[i+1][j+1].rgbtGreen*1 + buffer[i][j].rgbtGreen*0 +
                buffer[i-1][j].rgbtGreen*-2 + buffer[i-1][j+1].rgbtGreen*-1;

                avgblueX = sobel(avgblueX, avgblueY);
                avgredX = sobel(avgredX, avgredY);
                avggreenX = sobel(avggreenX, avggreenY);

            }
        else
        {
            //Calculate GX for all color channels

            avgblueX = buffer[i][j].rgbtBlue*0 + buffer[i+1][j].rgbtBlue*0 + buffer[i+1][j+1].rgbtBlue*1 + buffer[i][j+1].rgbtBlue*2 + buffer[i-1][j].rgbtBlue*0+
            buffer[i-1][j-1].rgbtBlue*-1 + buffer[i][j-1].rgbtBlue*-2 + buffer[i-1][j+1].rgbtBlue*1 + buffer[i+1][j-1].rgbtBlue*-1;

            avgredX = buffer[i][j].rgbtRed*0 + buffer[i+1][j].rgbtRed*0 + buffer[i+1][j+1].rgbtRed*1 + buffer[i][j+1].rgbtRed*2 + buffer[i-1][j].rgbtRed*0+
            buffer[i-1][j-1].rgbtRed*-1 + buffer[i][j-1].rgbtRed*-2 + buffer[i-1][j+1].rgbtRed*1 + buffer[i+1][j-1].rgbtRed*-1;

            avggreenX = buffer[i][j].rgbtGreen*0 + buffer[i+1][j].rgbtGreen*0 + buffer[i+1][j+1].rgbtGreen*1 + buffer[i][j+1].rgbtGreen*2 + buffer[i-1][j].rgbtGreen*0+
            buffer[i-1][j-1].rgbtGreen*-1 + buffer[i][j-1].rgbtGreen*-2 + buffer[i-1][j+1].rgbtGreen*1 + buffer[i+1][j-1].rgbtGreen*-1;



            //Calculate Gy for all color channels
            avgblueY = buffer[i][j].rgbtBlue*0 + buffer[i+1][j].rgbtBlue*2 + buffer[i+1][j+1].rgbtBlue*1 + buffer[i][j+1].rgbtBlue*0 + buffer[i-1][j].rgbtBlue*-2+
            buffer[i-1][j-1].rgbtBlue*-1 + buffer[i][j-1].rgbtBlue*0 + buffer[i-1][j+1].rgbtBlue*-1 + buffer[i+1][j-1].rgbtBlue*1;

            avgredY = buffer[i][j].rgbtRed*0 + buffer[i+1][j].rgbtRed*2 + buffer[i+1][j+1].rgbtRed*1 + buffer[i][j+1].rgbtRed*0 + buffer[i-1][j].rgbtRed*-2+
            buffer[i-1][j-1].rgbtRed*-1 + buffer[i][j-1].rgbtRed*0 + buffer[i-1][j+1].rgbtRed*-1 + buffer[i+1][j-1].rgbtRed*1;

            avggreenY = buffer[i][j].rgbtGreen*0 + buffer[i+1][j].rgbtGreen*2 + buffer[i+1][j+1].rgbtGreen*1 + buffer[i][j+1].rgbtGreen*0 + buffer[i-1][j].rgbtGreen*-2+
            buffer[i-1][j-1].rgbtGreen*-1 + buffer[i][j-1].rgbtGreen*0 + buffer[i-1][j+1].rgbtGreen*-1 + buffer[i+1][j-1].rgbtGreen*1;

            //Calculate square root of Gx and Gy
            avgblueX = sobel(avgblueX, avgblueY);
            avgredX = sobel(avgredX, avgredY);
            avggreenX = sobel(avggreenX, avggreenY);
        }

        image[i][j].rgbtBlue = avgblueX;
        image[i][j].rgbtGreen = avggreenX;
        image[i][j].rgbtRed = avgredX;

    }
    }
    return;

}



