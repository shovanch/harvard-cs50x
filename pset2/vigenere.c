/**
 * vigenere.c
 * 
 * Problem Set 2
 * 
 * Shovan Chatterjee
 * 
 * Encrypts user messsage with keyword from user using Vignere Cipher.
 * 
 * USAGE: ./vigenere keyword
 * keyword is a string composed of alphabetical characters only.
 * 
 * 
 **/
 
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    string key = argv[1];
    
    // validates user input 
    if (argc != 2)
    {   
        printf("USAGE: ./vignere <keyword>\n");
        return 1;
    }
    
    // checks if the keyword contains only alphabetical characters
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Only enter alphabets 'A-Z' , 'a-z'\n");
            return 1;
        }
    }
    
    // gets message from user
    printf("Enter message: ");
    string p_text = GetString();
    
    int j = 0;
    int m = 0;
    int cipher;
    
    //outputs the cipher message
    printf("Cipher Message: ");
    
    // iterate over every letter in the user message
    for ( int i = 0, n = strlen(p_text); i < n; i++) 
    {
        // checks if the letter from message is an alphabet
        if (isalpha(p_text[i])) 
        {
            j = m % strlen(key);
            
            // checks if the letter from message is Uppercase
            if (isupper(p_text[i])) 
            {
                // checks if the letter from keyword is Uppercase
                if (isupper(key[j])) 
                {
                    cipher = ((p_text[i] - 65 + key[j] - 65) % 26) + 65; 
                    printf("%c", cipher);
                }
                else
                {
                    cipher = ((p_text[i] - 65 + key[j] - 97) % 26) + 65;
                    printf("%c", cipher);
                }
                
            }
            
            // checks if the letter from message is lowercase
            if (islower(p_text[i])) 
            {
                if (isupper(key[j]))
                {
                    cipher = ((p_text[i] - 97 + key[j] - 65 ) % 26) + 97;
                    printf("%c", cipher);
                }
                else
                {
                    cipher = ((p_text[i] - 97 + key[j] - 97) % 26) + 97;
                    printf("%c", cipher);
                }
            }
            
            // increment m by 1 if the calculation is done ;else ignore to the next step
            m++; 
        
        }
        else
        {
            printf("%c", p_text[i]);
        }
            
        
    }
    printf("\n");
    return 0;
}   