#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float a;
    int b;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            a = ((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen));

            b = round(a / 3);
            image[i][j].rgbtRed = b;
            image[i][j].rgbtGreen = b;
            image[i][j].rgbtBlue = b;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int a, b, c, d, e, f;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            a = image[i][j].rgbtRed, b = image[i][j].rgbtGreen, c = image[i][j].rgbtBlue;
            d = round(.393 * a + .769 * b + .189 * c);
            e = round(.349 * a + .686 * b + .168 * c);
            f = round(.272 * a + .534 * b + .131 * c);
            if (d > 255)
            {
                d = 255;
            }
            if (e > 255)
            {
                e = 255;
            }
            if (f > 255)
            {
                f = 255;
            }
            image[i][j].rgbtRed = d;
            image[i][j].rgbtGreen = e;
            image[i][j].rgbtBlue = f;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int r[height][width], g[height][width], b[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            r[i][j] = image[i][j].rgbtRed;
            g[i][j] = image[i][j].rgbtGreen;
            b[i][j] = image[i][j].rgbtBlue;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = r[i][width - j - 1];
            image[i][j].rgbtGreen = g[i][width - j - 1];
            image[i][j].rgbtBlue = b[i][width - j - 1];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int count = 0;
    float r = 0, g = 0, b = 0;
    int red[height][width], green[height][width], blue[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            red[i][j] = image[i][j].rgbtRed;
            green[i][j] = image[i][j].rgbtGreen;
            blue[i][j] = image[i][j].rgbtBlue;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int l = j - 1; l <= j + 1; l++)
                {
                    if (k >= 0 && l >= 0 && k <= height - 1 && l <= width - 1)
                    {
                        r += red[k][l];
                        g += green[k][l];
                        b += blue[k][l];
                        count++;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            r = (round(r / count));
            g = (round(g / count));
            b = (round(b / count));
            count = 0;
            image[i][j].rgbtRed = r;
            image[i][j].rgbtGreen = g;
            image[i][j].rgbtBlue = b;
            r = 0;
            g = 0;
            b = 0;
        }
    }
    return;
}







