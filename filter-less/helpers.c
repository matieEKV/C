#include "helpers.h"
#include <stdio.h>
#include <math.h>

RGBTRIPLE blurredPixel(int height, int width, RGBTRIPLE image[height][width], int x, int y);


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int gscale_average = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            gscale_average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = gscale_average;
            image[i][j].rgbtGreen = gscale_average;
            image[i][j].rgbtRed = gscale_average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaBlue = round((image[i][j].rgbtBlue * 0.131) + (image[i][j].rgbtGreen * 0.534) + (image[i][j].rgbtRed * 0.272));
            int sepiaGreen = round((image[i][j].rgbtBlue * 0.168) + (image[i][j].rgbtGreen * 0.686) + (image[i][j].rgbtRed * 0.349));
            int sepiaRed = round((image[i][j].rgbtBlue * 0.189) + (image[i][j].rgbtGreen * 0.769) + (image[i][j].rgbtRed * 0.393));
            //printf ("%i\n", sepiaBlue);

            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;

            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width-1-j];
            image[i][width-1-j] = temp;

            // 0       n-1
            // 1       n-1-1
            // 2       n-2-1
            // 3       n-3-1
            // x       n-1-x
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
//     height = 3;
//     width = 3;
//     // image = [[(10, 20, 30), (40, 50, 60), (70, 80, 90)],[(110, 130, 140), (120, 140, 150), (130, 150, 160)],[(200, 210, 220), (220, 230, 240), (240, 250, 255)]];
//     RGBTRIPLE imageA[3][3] = {
//         { {10, 20, 30}, {40, 50, 60}, {70, 80, 90} } ,
//         { {110, 130, 140}, {120, 140, 150}, {130, 150, 160} } ,
//         { {200, 210, 220}, {220, 230, 240}, {240, 250, 255} }
//     };

    // RGBTRIPLE imageRowA[3] = { {10, 20, 30}, {40, 50, 60}, {70, 80, 90} };
    // RGBTRIPLE imageRowB[3] = { {110, 130, 140}, {120, 140, 150}, {130, 150, 160} };
    // RGBTRIPLE imageRowC[3] = { {200, 210, 220}, {220, 230, 240}, {240, 250, 255} };

    RGBTRIPLE copy[height][width];
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for(int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                image[i][j] = blurredPixel(height, width, copy, i, j);
            }
        }
    return;
}

RGBTRIPLE blurredPixel(int height, int width, RGBTRIPLE copy[height][width], int x, int y)
{
    float rgbtBlue = 0.0;
    float rgbtGreen = 0;
    float rgbtRed = 0;
    // int startX = x;
    // int endX = x;
    // int startY = y;
    // int endY = y;
    int counter = 0.0;
    int averageBlue = 0.0;
    int averageGreen;
    int averageRed;
    // if (x!=0)
    // {
    //     startX = x-1;
    // }
    // if (x < height-1)
    // {
    //     endX = x+1;
    // }
    // if (y!=0)
    // {
    //     startY = y-1;
    // }
    // if (y < width-1)
    // {
    //     endY = y+1;
    // }

    int offSetX[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    int offSetY[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

    for (int i = x; i < height; i++)
    {
        for (int j = y; j < width; j++)
        {
            int nx = x + offSetX[i];
            int ny = y + offSetY[j];

            if (nx < 0 || nx > height || ny > 0 || ny > width)
        {
            continue;
        }
            rgbtBlue += copy[i][j].rgbtBlue;
            rgbtGreen += copy[i][j].rgbtGreen;
            rgbtRed += copy[i][j].rgbtRed;

            printf("\nPixel: R %f, G %f, B %f", rgbtRed, rgbtGreen, rgbtBlue);
            counter++;
        }
    }
    averageBlue = round(rgbtBlue / counter);
    averageGreen = round(rgbtGreen / counter);
    averageRed = round(rgbtRed / counter);
    printf("\nAverage: R %d, G %d, B %d\n", averageRed, averageGreen, averageBlue);

    RGBTRIPLE newValues;
    newValues.rgbtBlue = averageBlue;
    newValues.rgbtGreen = averageGreen;
    newValues.rgbtRed = averageRed;
    return newValues;
}
