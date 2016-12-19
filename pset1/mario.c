/**
 * mario.c
 * 
 * Harvard CS50
 * Problem Set 1
 * 
 * Shovan Chatterjee
 * 
 * Prints mario's reverse half pyramind in hashes(#)
 * gets height from user input. (height between 1 to 23)
 * 
 **/

#include <stdio.h>
#include <cs50.h>
int main(void)
{
    int i, h, s, height;

    do
    {
        printf("Enter height: ");
        height = GetInt();
    }
    while(height < 0 || height > 23);
    
    for (i = 0; i < height; i++) // prints new rows
    {
        for (s = 0; s < height-i-1; s++) // prints spaces
        {
            printf(" ");
        }
        for (h = 0; h < i+2; h++) // prints hashes
        {   
            printf("#");
        }
        printf("\n"); // print new line
    }    
    
}