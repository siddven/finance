// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

uint8_t BYTES[44];
int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file

    fread(&BYTES,sizeof(uint8_t),HEADER_SIZE,input);
    fwrite(&BYTES,sizeof(uint8_t),HEADER_SIZE,output);


    // TODO: Read samples from input file and write updated data to output file
    fseek(input,0,SEEK_END);
    int end = ftell(input) -44;
    printf("%i",end);
    int16_t buffer[end];
    fseek(input,44,0);
    fseek(output,44, 0);

    fread(&buffer,sizeof(int16_t),end,input);
    for (int i = 0; i <= end; i++)
    {
        buffer[i] = buffer[i] * factor;
    }




        fwrite(&buffer,sizeof(int16_t),end,output);

    // Close files
    fclose(input);
    fclose(output);
}
