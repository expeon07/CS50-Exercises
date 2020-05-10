#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.00);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int tmp[3];
    
    for (int i = 0; i < height; i++)
    {
        // should be divided by 2 since swapping is done both ways inwards
        for (int j = 0; j < width / 2; j++)
        {
            tmp[0] = image[i][j].rgbtBlue;
            tmp[1] = image[i][j].rgbtGreen;
            tmp[2] = image[i][j].rgbtRed;
            
            // swap right pixels with left
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            
            // swap left pixels with right
            image[i][width - j - 1].rgbtBlue = tmp[0];
            image[i][width - j - 1].rgbtGreen = tmp[1];
            image[i][width - j - 1].rgbtRed = tmp[2];
            
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int sum_blue, sum_green, sum_red;
    float pixels_num;
    RGBTRIPLE tmp[height][width];
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // reset sum to 0
            sum_blue = 0;
            sum_green = 0;
            sum_red = 0;
            pixels_num = 0.00;
            
            // find neighboring pixels
            for (int k = -1; k < 2; k++)
            {
                // skip edges
                if (i + k < 0 || i + k > height - 1)
                {
                    continue;
                }
                
                for (int h = -1; h < 2; h++)
                {
                    // skip edges
                    if (j + h < 0 || j + h > width - 1)
                    {
                        continue;
                    }
                    
                    sum_blue += image[i + k][j + h].rgbtBlue;
                    sum_green += image[i + k][j + h].rgbtGreen;
                    sum_red += image[i + k][j + h].rgbtRed;
                    pixels_num++;
                }
            }
            
            // get average of sums
            tmp[i][j].rgbtBlue = round(sum_blue / pixels_num);
            tmp[i][j].rgbtGreen = round(sum_green / pixels_num);
            tmp[i][j].rgbtRed = round(sum_red / pixels_num);
        }
    }
    
    // copy values
    //copies values from temporary table
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[j][i].rgbtBlue = tmp[j][i].rgbtBlue;
            image[j][i].rgbtGreen = tmp[j][i].rgbtGreen;
            image[j][i].rgbtRed = tmp[j][i].rgbtRed;
        }
    }
    
    return;
}
