#include <cs50.h>
#include <stdio.h>

void printHashSymbols(int count, int height);
void printPyramid(int height);

int main(void)
{
    int height = 0;
    do
    {
        height = get_int("Height: ");
        // The input must be an int less than 9 and more than 0.
    }
    while (height <= 0 || height >= 9);
    printPyramid(height);
}

void printPyramid(int height)
{
    for (int i = 1; i <= height; i++)
    {
        // Call hash symbols with actual index, and passing the height
        printHashSymbols(i, height);
        printf("\n");
    }
}

void printHashSymbols(int count, int height)
{
    for (int i = 0; i < height - count; i++) 
    {
        // Print a white space based on difference from height to actual index
        printf(" ");
    }
    for (int i = 1; i <= count; i++)
    {
        // Print hashsymbol
        printf("#");
    }
}


