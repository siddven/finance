#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
int main(int argc, char *argv[])
{
    FILE *placeholder = NULL;
    char filename[7];
    if (argc != 2)
    {
        //checks if proper # of arguments are entered (1 argument)
        printf("Usage: ./recover image\n");
        return 1;

    }
//opening the memory card
    FILE *file = fopen(argv[1], "r");

    uint8_t buffer[512];
    int check = 0;
    bool newjpeg = false;
    bool currentjpeg = false;

    while (fread(&buffer, sizeof(uint8_t), 512, file) == 512)
    {

        if ((buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0))
        {

            newjpeg = true;
            currentjpeg = true;
        }
        else
        {
            newjpeg = false;
        }
        if (newjpeg && currentjpeg)
        {
            if (placeholder != NULL)
            {
                fclose(placeholder);
            }
            sprintf(filename, "%03i.jpg", check);
            check ++;
            placeholder = fopen(filename, "w");
            fwrite(&buffer, sizeof(uint8_t), 512, placeholder);
            newjpeg = false;
        }

        else if (currentjpeg)
        {
            fwrite(&buffer, sizeof(uint8_t), 512, placeholder);

        }

        else
        {
            newjpeg = false;
        }

    }
    fclose(placeholder);
}
