#include <cs50.h>
#include <stdio.h>

void printHashSymbols(int count, int height);
void printPyramid(int height);

int main(void)
{
    int height = 0;
    do {
        height = get_int("Height: ");
    } while (height <= 0 || height >= 9);
    printPyramid(height);
}

void printPyramid(int height)
{
    for (int i = 1; i <= height; i++)
    {
        printHashSymbols(i, height);
        printf("  ");
        printHashSymbols(i, 0);
        printf("\n");
    }
}

void printHashSymbols(int count, int height)
{
    for (int i = 0; i < height - count; i++)
    {
        printf(" ");
    }
    for (int i = 1; i <= count; i++)
    {
        printf("#");
    }
}
