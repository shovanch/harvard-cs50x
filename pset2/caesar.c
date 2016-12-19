/**
 * caesar.c
 * 
 * Harvard CS50
 * Problem Set 2
 * 
 * Shovan Chatterjee
 * 
 * Encrypts user inputted message using Caesar cipher with key from user input.
 *
 * USAGE: ./caesar key
 * where key is a non-negative integer
 * 
 **/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // validates the user input
    if (argc != 2)
    {
        printf("USAGE: ./caesar key\n");
        return 1;
    }
    
    // converts the user inputted key to int
    int k  = atoi(argv[1]);
    
    // gets the message to encrypt from user
    printf("Enter message: ");
    string ptext = GetString();
    
    // outputs the cipher message
    printf("Cipher Message: ");
    
    // go over each character in the message text
    for (int i = 0, n = strlen(ptext); i < n; i++)
    {
        // checks if the character is an alpahabet
        if (isalpha(ptext[i]))        
        {   
            // checks if the alphabet is UppperCase
            if (isupper(ptext[i]))    
            {
                // converts the ASCII to alphabet Index
                int alIndexUp  = ptext[i] - 65; 
                
                // apply the caesar cipher
                int cipherUp = (alIndexUp + k) % 26; 
                
                // convert the cipher in alphabetindex to its ASCII
                int c_asciiUp = cipherUp + 65;  
                
                printf("%c", c_asciiUp);
            }    
            // checks if the alphabet is LowerCase
            if (islower(ptext[i]))    
            {
                // converts the ASCII to alphabet Index
                int alIndexLow  = ptext[i] - 97 ;
                
                // apply the caesar cipher
                int cipherLow = (alIndexLow + k) % 26; 
                
                // convert the cipher in alphaBetindex to its ASCII
                int c_asciiLow = cipherLow + 97;  
                
                printf("%c", c_asciiLow);
            }
            
        }
        
        // preserve the space from message text
        if (isspace(ptext[i]) || isdigit(ptext[i]) || ispunct(ptext[i]))       
        {
            printf("%c", ptext[i]);
        }
        
    }
    
    printf("\n");
    
    return 0;
}



