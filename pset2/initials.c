/**
 * initials.c
 * 
 * Problem Set 2
 * 
 * Shovan Chatterjee
 * 
 * Prompts user from their name and prints out their initials in Upper Case.
 * preserves space and period(.)
 * assumes user name will have uppercase and lowercase letter only with single spaces
 * 
 **/
 
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // prompts user
    printf("Enter name: ");
    
    // gets user input
    string name = GetString(); 
    
    // converts the first letter to Upper Case
    printf("%c", toupper(name[0]));
    
    // check for space, capitalize the next letter after space
    for(int i = 0, n = strlen(name); i < n; i++)
    {
        if (name[i] == ' ')
        {
            printf("%c", toupper(name[i + 1]));  
        }
        
    }
    printf("\n");
    
}
