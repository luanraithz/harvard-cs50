#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef uint8_t  BYTE;

int isJPEGStart(BYTE buffer[]);

void getNextFileName();
char fileNameBuffer[8];

int main(int argc, char *argv[])
{
    // Validate arguments
    if (argc != 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }

    // getting pointer to file from argument
    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        return 1;
    }
    // Declaring chuck buffer
    BYTE buffer[512];
    FILE *jpeg = NULL;
    while (fread(&buffer, 512, 1, file) > 0)
    {
        if (isJPEGStart(buffer))
        {
            // Check if is not the first JPEG
            if (jpeg != NULL)
            {
                // If is not the first, close it
                fclose(jpeg);
            }
            // Fill buffer with next file name
            getNextFileName();

            // Create a new one
            jpeg = fopen(fileNameBuffer, "w");

            if (jpeg == NULL)
            {
                printf("Could create a new jpeg file");
                return 1;
            }
        }
        if (jpeg != NULL)
        {
            fwrite(&buffer, sizeof(buffer), 1, jpeg);
        }
    }
    fclose(file);
    if (jpeg != NULL)
    {
        fclose(jpeg);
    }
    return 0;

}

int fileIndex = 0;
void getNextFileName()
{
    sprintf(fileNameBuffer, "%03d.jpg", fileIndex);

    fileIndex++;

}

int isJPEGStart(BYTE buffer[512])
{
    return buffer[0] == 0xff &&
           buffer[1] == 0xd8 &&
           buffer[2] == 0xff &&
           (buffer[3] & 0xf0) == 0xe0;
}
