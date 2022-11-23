#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int gscale_average = 0;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            gscale_average = (image[i].rgbtBlue + image[i].rgbtGreen + image[i].rgbtRed) / 3.0;
        }
            image[i].rgbtBlue = gscale_average;
            image[i].rgbtGreen = gscale_average;
            image[i].rgbtRed = gscale_average;
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
