/**
 * recover.c
 *
 * Harvard CS50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image (.raw file).
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    
    // clear the jpg ptr
    FILE* imgptr = NULL;
    
    // declare array to hold file name
    char file_name[8] = {0}; 
    
    //declare the buffer 
    unsigned char buffer[512] = {0};
    
    //declare file counter 
    int file_counter = 0;
    
    // open card file
    FILE* inptr = fopen("card.raw", "r");
    if(NULL == inptr)
    {
        printf("1.Could not open file %s . \n", "card.raw");
        return 1;
    }
    
    //while the block is not a EOF
    while(fread(buffer, 512, 1, inptr) == 1)
    {
        //check if its the header
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
        {
            //generate file name
            sprintf(file_name, "%.3d.jpg", file_counter);
            
            //if a JPEG is open
            if( NULL != imgptr)
            {
                //close it
                fclose(imgptr);
                imgptr = NULL;
            }
            
            //open a new jpg file
            imgptr = fopen(file_name, "w");
            
            if(NULL == imgptr)
            {
                printf("3.Could not open file %s. \n", file_name);
                return 2;
            }
            
            
            //write in to the new file
            fwrite(buffer, 512, 1, imgptr);
            
            //increment the file number
            file_counter ++;
        }
        else
        {
            // the buffer is of existing file not header, if jpg is open
            if( NULL != imgptr)
            {
                //continue writing into the old file
                fwrite(buffer, 512, 1, imgptr); 
            }
            
        }   
        
     
    }
    
    //if any JPEG file is open after EOF
    if(NULL != imgptr)
    {
        //close it
        fclose(imgptr);
    }
    if(inptr != NULL)
    {
        fclose(inptr);
    }
    
    //return 0 DONE
    return 0;
}   
    
