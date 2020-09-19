#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


int main(int argc, char *argv[])
{


    // fread(data, size, number, inptr)
    // data: pointer to where to store data you're reading
    // size: size of each element to read  // the number of bytes of each element you're gonna read from the file 512?
    // number: number of elements to read
    // inprt: FILE * to read from

    // how will we know if the block of 512 is a jpeg
    // if buffer[0] == 0xff
    // if buffer[1] == 0xd8
    // if buffer[2] == oxff

    // for the fourth byte there's 16 possible values
    // if buffer[3] & 0xf-) == 0xe0

    // create new jpeg file using jpegNum
    // string filename[4]
    // sprintf(filename, "%03i,jpg", jpegNum)
    // FILE *img = fopen(filename, w)
    // fwrite(data, size, number, outptr)



    typedef uint8_t BYTE;

    //printf("argc: %i \n",argc);

    if (argc != 2)
    {
        printf("Program needs 2 args\n");

        return 1;
    }


        // open memory card
    FILE *file = fopen(argv[1], "r");

    int jpegCount = 0;


    // read 512 bytes & store into array
    // theres 50 jpegs that can be found in the file

    // repeat until end of card
    BYTE buffer[512];

    FILE *img = NULL;

    char fileName[7];
    //printf("data?: %s\n", buffer[300]);

    int loop = 0;

    while (loop == 0)
    {
        size_t bytesRead = fread(buffer, sizeof(BYTE), 512, file);


        if (bytesRead < 512)
        {
            loop = 1;
            break;
        }


        bool jpegFound = buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;



        if (jpegFound && img != NULL)
        {
            fclose(img);
            jpegCount++;
        }

        if (jpegFound)
        {
            sprintf(fileName, "%03i.jpg", jpegCount);
            img = fopen(fileName, "w");
        }

        if (img != NULL)
        {
            fwrite(buffer, sizeof(BYTE), bytesRead, img);
        }



    }

    fclose(img);
    fclose(file);

    return 0;



}
