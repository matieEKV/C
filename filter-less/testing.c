#include <stdio.h>
#include <math.h>
#include <stdint.h>

typedef struct
{
    int  rgbtBlue;
    int  rgbtGreen;
    int  rgbtRed;
}
RGBTRIPLE;


// Blur image
RGBTRIPLE blur(int height, int width, RGBTRIPLE image[3][3])
{
    height = 3;
    width = 3;
    // image = [[(10, 20, 30), (40, 50, 60), (70, 80, 90)],[(110, 130, 140), (120, 140, 150), (130, 150, 160)],[(200, 210, 220), (220, 230, 240), (240, 250, 255)]];
    RGBTRIPLE image[3][3] = {
        { {10, 20, 30}, {40, 50, 60}, {70, 80, 90} } ,
        { {110, 130, 140}, {120, 140, 150}, {130, 150, 160} } ,
        { {200, 210, 220}, {220, 230, 240}, {240, 250, 255} }
    };

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
    RGBTRIPLE newImage;
    newImage.rgbtBlue = rgbtBlue;
    newImage.rgbtGreen = rgbtGreen;
    newImage.rgbtRed = rgbtRed;
    return newImage;
}

RGBTRIPLE blurredPixel(int height, int width, RGBTRIPLE copy[height][width], int x, int y)
{
    float rgbtBlue = 0.0;
    int rgbtGreen = 0;
    int rgbtRed = 0;
    int startX = x;
    int endX = x;
    int startY = y;
    int endY = y;
    float counter = 0.0;
    float averageBlue = 0.0;
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

    for (int i = x-1; i < height; i++)
    {
        for (int j = y-1; j < width; j++)
        {
            rgbtBlue += (((float) copy[i][j].rgbtBlue) * 1.0);
            rgbtGreen += copy[i][j].rgbtGreen;
            rgbtRed += copy[i][j].rgbtRed;

            printf("\nPixel: R %d, G %d, B %f", rgbtRed, rgbtGreen, rgbtBlue);
            counter += 1.0;
        }
    }
    averageBlue = round(rgbtBlue / counter);
    averageGreen = rgbtGreen / counter;
    averageRed = rgbtRed / counter;
    printf("Average: R %d, G %d, B %f", averageRed, averageGreen, averageBlue);

    RGBTRIPLE newValues;
    newValues.rgbtBlue = averageBlue;
    newValues.rgbtGreen = averageGreen;
    newValues.rgbtRed = averageRed;
    return newValues;
}
