#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    typedef uint8_t BYTE;
    
    BYTE block[512];
    int amount = 0;
    int jcount = 0;
    char x;
    bool newfile = false;
    bool currentfile = false;
    char *filename = NULL;
    

    FILE *data = fopen(argv[1], "r");
    FILE *fp = data;
    
    while (!feof(fp))
    {

        fread(block, sizeof(BYTE), 512, &data[amount]);

        if ((block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff) && ((block[3] & 0xf0) == 0xe0))
        {
            newfile = true;
            currentfile = true;
        }
        else
        {
            newfile = false;
        }





        //start of new jpeg
        if (currentfile || newfile)
        {
            //read and create new file
            
            //create new file 
            //write block onto it
            sprintf(filename, "%03i.jpg", jcount);
            FILE *y = fopen(filename, "w");
            fwrite(block, sizeof(BYTE), 512, y);
            newfile = false;
            jcount++;
        }
        //continuation of jpeg
        else if (currentfile)
        {
            //continue reading and writing new file
            
            //write block onto current file
            newfile = false;
        }
        //first jpeg has still not been found
        else
        {
            fread(block, sizeof(BYTE), 512, &data[amount]);                    
            amount += 512;
        }

    }







}