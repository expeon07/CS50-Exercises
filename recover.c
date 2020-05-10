#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // program should only take 1 argument
    if (argc != 2) 
    {
        printf("Usage: ./recover image");
        return 1;
    }
    
    // Open image file
    char *imgfile = argv[1];
    
    FILE *inptr = fopen(imgfile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", imgfile);
        return 1;
    }
    
    BYTE buffer[BLOCK_SIZE];
    int img_count = 0;
    bool flag = false;
    
    char filename[8];
    
    FILE *outptr;
    
    while (fread(buffer, BLOCK_SIZE, 1, inptr) == 1)
    {
        
        // check for jpeg
        // use bitwise and for 4th byte and should be 11100000 or 0xe0 sine first 4bits should be 1110
        bool isJpeg = (buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0);
        
        // check if jpeg found
        if (isJpeg)
        {
            // close previous file if new jpeg found
            if (flag == true)
            {
                fclose(outptr);
            }
            else 
            {
                flag = true;
            }
        
            // make filename
            sprintf(filename, "%03i.jpg", img_count);
            // open output file
            outptr = fopen(filename, "w");
            img_count++;
            
        }
        
        // write file
        if (flag == true)
        {
            fwrite(&buffer, BLOCK_SIZE, 1, outptr);    
        }
        
    }
    
    // close files
    fclose(outptr);
    fclose(inptr);
    
    return 0;
}
