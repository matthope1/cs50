#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    /*
    This function should take an image and turn it into a black-and-white
    version of the same image
    */

    // get the average of the three rgb values for each pixel
    // make sure each value is an integer between 0-255
    // we gotta make a nested loop


    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j++)
        {
            //lets see if we can print the rbg values for every pixel in the image
            //printf("bValue: %i\n", image[i][j].rgbtBlue);
            //printf("bValue: %i\ngValue: %i\nrValue: %i\n", image[i][j].rgbtBlue, image[i][j].rbgtGreen, image[i][j].rbgtRed);

            int average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.00) ;

            //printf("%i",average);

            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;


        }
    }



    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    //To reverse an image, we are essentially going to have to
    //reverse the uuhhhhh

    // difference between even and odd # of pixels when reflecting a row? NOOOOOOO THERE ISNTTT
    for (int i = 0; i < height; i++)
    {

        int start = 0;
        int end = width - 1;

        while (start < end)
        {
            RGBTRIPLE temp = image[i][start];
            image[i][start] = image[i][end];
            image[i][end] = temp;
            start ++;
            end --;

        }

    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    int indexO[9][2] =
    {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1}, {0, 0}, {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };

    RGBTRIPLE tempImage[height][width];

    // to get new index we add indexO [0] to OP index
    // and we add              indexO [1] to OP index
    // then we gotta check if this index is valid
    // if its valid then we add 1 to our count
    // and add its total for when we later calculate the average

    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j ++)
        {
            int redTotal = 0, greenTotal = 0, blueTotal = 0;

            int vPCount = 0; // we need to keep track of the num of valid pixels for calculating average;

            // current pixel = image[i][j];

            for (int k = 0; k < 9; k ++)
            {
                int firstO = indexO[k][0];
                int secondO = indexO[k][1];

                int newI = i + firstO;
                int newJ = j + secondO;

                if (newI < height && newI >= 0 && newJ < width
                    && newJ >= 0)// if the new transformed index is valid then we can add rgb values for average
                {
                    redTotal += image[newI][newJ].rgbtRed;
                    greenTotal += image[newI][newJ].rgbtGreen;
                    blueTotal += image[newI][newJ].rgbtBlue;
                    vPCount ++;
                }

            }

            // assign calculated rgb averages

            tempImage[i][j].rgbtRed = round((float)redTotal / vPCount);
            tempImage[i][j].rgbtGreen = round((float)greenTotal / vPCount);
            tempImage[i][j].rgbtBlue = round((float)blueTotal / vPCount);

        }

    }

    // one last nested loop to get new values from temp image to real image

    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tempImage[i][j];
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int indexO[9][2] =
    {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1}, {0, 0}, {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };

    int gx[9] =
    {
        -1, 0, 1,
            -2, 0, 2,
            -1, 0, 1
        };

    int gy[9] =
    {
        -1, -2, -1,
            0, 0, 0,
            1, 2, 1
        };

    RGBTRIPLE tempImage[height][width];

    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j++)
        {

            int redGx = 0, greenGx = 0, blueGx = 0;
            int redGy = 0, greenGy = 0, blueGy = 0;

            for (int k = 0; k < 9; k++)
            {
                int firstO = indexO[k][0];
                int secondO = indexO[k][1];

                int newI = i + firstO;
                int newJ = j + secondO;

                if (newI < height && newI >= 0 && newJ < width
                    && newJ >= 0)// if the new transformed index is valid then we can add rgb values for average
                {

                    redGx += gx[k] * image[newI][newJ].rgbtRed;
                    greenGx += gx[k] * image[newI][newJ].rgbtGreen;
                    blueGx += gx[k] * image[newI][newJ].rgbtBlue;

                    redGy += gy[k] * image[newI][newJ].rgbtRed;
                    greenGy += gy[k] * image[newI][newJ].rgbtGreen;
                    blueGy += gy[k] * image[newI][newJ].rgbtBlue;

                }

            }
            // new value = sqrt (gx^2  + gy^2)
            // if new value is bigger than 255 then we need to set it to 255
            // rgb values cant exceed the number 255

            if (round(sqrt(pow(redGx, 2) + pow(redGy, 2))) > 255)
            {
                tempImage[i][j].rgbtRed = 255;
            }
            else
            {
                tempImage[i][j].rgbtRed = round(sqrt(pow(redGx, 2) + pow(redGy, 2)));
            }


            if (round(sqrt(pow(greenGx, 2) + pow(greenGy, 2))) > 255)
            {
                tempImage[i][j].rgbtGreen = 255;
            }
            else
            {
                tempImage[i][j].rgbtGreen = round(sqrt(pow(greenGx, 2) + pow(greenGy, 2)));
            }


            if (round(sqrt(pow(blueGx, 2) + pow(blueGy, 2))) > 255)
            {
                tempImage[i][j].rgbtBlue = 255;
            }
            else
            {
                tempImage[i][j].rgbtBlue = round(sqrt(pow(blueGx, 2) + pow(blueGy, 2)));
            }



        }
    }

    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tempImage[i][j];
        }
    }

    return;
}
