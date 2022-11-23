#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE rgbtriple[3];
    int gscale_average = 0;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            gscale_average = (rgbtriple[i].rgbtBlue + rgbtriple.rgbtGreen[i] + rgbtriple[i].rgbtRed) / 3.0;
            RGBTRIPLE.rgbtBlue = gscale_average;
            RGBTRIPLE.rgbtGreen = gscale_average;
            RGBTRIPLE.rgbtRed = gscale_average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
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
