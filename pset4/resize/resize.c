/**
 * resize.c
 *
 * Harvard CS50
 * Problem Set 4
 *
 * Resizes a BMP by a factor of n, where n is a postive integer less than or 
 * equal to 100.
 * 
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }
    
    
    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];
    int n = atoi(argv[1]);
    
    // checks if n is in the scope between 1 - 100
    if(n > 100 || n <= 0)
    {
        printf("n must be between 1 to 100\n");
        return 2;
    }

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);


    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    
    
    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 5;
    }

    
    // get new structures 
    BITMAPINFOHEADER out_bi = bi;
    BITMAPFILEHEADER out_bf = bf;
    
    // update the variables
    out_bi.biWidth = bi.biWidth * n;
    out_bi.biHeight = bi.biHeight * n;
    
    // new padding
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int out_padding =  (4 - (out_bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // update bi.ImageSize
    out_bi.biSizeImage = (out_bi.biWidth * sizeof(RGBTRIPLE) + out_padding) * abs(out_bi.biHeight);
    
    //update the bf.Size
    out_bf.bfSize = out_bi.biSizeImage + 54;
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&out_bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    

    // write outfile's BITMAPINFOHEADER
    fwrite(&out_bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        
        // iterate for factor times as for the verticality;
        for(int x = 0; x < n; x++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;
    
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                
                // write the pixel factor times
                for(int p = 0; p < n; p++)
                    {
                        // write RGB triple to outfile
                        fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                    }
            }
            
            // skip over padding in infile, if any
            fseek(inptr, padding, SEEK_CUR);
            
            // then add it back to outfile
            for (int k = 0; k < out_padding; k++)
            {
                fputc(0x00, outptr);
            }
            
            // reach the end of current scanfile, starting the next scanfile
            if( x != (n-1))
            {
                fseek(inptr, -(bi.biWidth * sizeof(RGBTRIPLE) + padding), SEEK_CUR);
            }
            
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
