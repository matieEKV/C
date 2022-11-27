#include "helpers.h"
#include <stdio.h>
#include <math.h>

int blur_Bluecalculations(int height, int width, RGBTRIPLE image[height][width]);
int blur_Greencalculations(int height, int width, RGBTRIPLE image[height][width]);
int blur_Redcalculations(int height, int width, RGBTRIPLE image[height][width]);

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
    // RGBTRIPLE copy[height][width];
    // for(int i = 0; i < height; i++)
    // {
    //     for (int j = 0; j < width; j++)
    //     {
    //         copy[height][width] = image[height][width];
    //     }
    // }

    for(int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                int rgbtBlue_average =
                int rgbtGreen_average =
                int rgbtRed_average =
            }
        }
    return;
}

int blur_Bluecalculations(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[height][width] = image[height][width];
        }
    }
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int row_aboveBlue = (copy[i-1][j-1].rgbtBlue + copy[i-1][j].rgbtBlue + copy[i-1][j+1].rgbtBlue);
            int row_aroundBlue = (copy[i-1][j-1].rgbtBlue + copy[i][j].rgbtBlue + copy[i][j+1].rgbtBlue);
            int row_belowBlue = (copy[i-1][j-1].rgbtBlue + copy[i+1][j].rgbtBlue + copy[i+1][j+1].rgbtBlue);
            int AverageBlue = round((row_aboveBlue + row_aroundBlue + row_belowBlue) / 3.0);
}

int blur_Greencalculations(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[height][width] = image[height][width];
        }
    }
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int row_aboveGreen = (copy[i-1][j-1].rgbtGreen + copy[i-1][j].rgbtGreen + copy[i-1][j+1].rgbtGreen);
            int row_aroundGreen = (copy[i-1][j-1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j+1].rgbtGreen);
            int row_belowGreen = (copy[i-1][j-1].rgbtGreen + copy[i+1][j].rgbtGreen + copy[i+1][j+1].rgbtGreen);
            int AverageGreen = round((row_aboveGreen + row_aroundGreen + row_belowGreen) / 3.0);
}

int blur_Redcalculations(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[height][width] = image[height][width];
        }
    }
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int row_aboveRed = (copy[i-1][j-1].rgbtRed + copy[i-1][j].rgbtRed + copy[i-1][j+1].rgbtRed);
            int row_aroundRed = (copy[i-1][j-1].rgbtRed + copy[i][j].rgbtRed + copy[i][j+1].rgbtRed);
            int row_belowRed = (copy[i-1][j-1].rgbtRed + copy[i+1][j].rgbtRed + copy[i+1][j+1].rgbtRed);
            int AverageRed = round((row_aboveRed + row_aroundRed + row_belowRed) / 3.0);
}