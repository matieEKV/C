#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int gscale_average = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            gscale_average = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
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
    int excess = 0;
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaBlue = round((image[i][j].rgbtBlue * 0.131) + (image[i][j].rgbtGreen * 0.534) + (image[i][j].rgbtRed * 0.272));
            int sepiaGreen = round((image[i][j].rgbtBlue * 0.168) + (image[i][j].rgbtGreen * 0.686) + (image[i][j].rgbtRed * 0.349));
            int sepiaRed = round((image[i][j].rgbtBlue * 0.189) + (image[i][j].rgbtGreen * 0.769) + (image[i][j].rgbtRed * 0.393));

            if (sepiaBlue + sepiaGreen + sepiaRed - 765 > 0)
            {
                if (sepiaBlue - 255 > 0)
                {
                    int excessBlue = sepiaBlue - 255;
                    image[i][j].rgbtBlue = sepiaBlue - excessBlue;
                    printf("Excess Blue :%i\n", excessBlue);
                }
                if (sepiaGreen - 255 > 0)
                {
                    int excessGreen = sepiaGreen - 255;
                    image[i][j].rgbtGreen = sepiaGreen - excessGreen;
                    printf("Excess Green: %i\n", excessGreen);
                }
                if (sepiaRed - 255 > 0)
                {
                    int excessRed = sepiaRed - 255;
                    image[i][j].rgbtRed = sepiaRed - excessRed;
                    printf("Excess Red: %i\n", excessRed);
                }

            }
            printf("Blue: %i\n", sepiaBlue);
            printf("Green: %i\n", sepiaGreen);
            printf("Red: %i\n", sepiaRed);
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
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
