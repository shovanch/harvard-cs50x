/**
 * greedy.c
 * 
 * Problem Set 1
 * 
 * Shovan Chattejee
 * 
 * Implements greedy algorithm 
 * Asks user for change($) owed, prints the minimum number
 * of coins to give the change back.
 * 
 **/

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // initializes the variables
    float change;
    int  cent;
    int amount = 0;
    
    // for repromt check
    do
    {
        printf("Enter change: ");
        change = GetFloat();
    }
    while(change < 0);  
    
    // changing dollar to cents
    cent = round(change * 100);
    
    // for quarters
    while(cent >= 25)
    {
        cent = cent - 25;
        amount++;
    }
    
    // for dimes
    while(cent >= 10)
    {
        cent = cent - 10;
        amount++;
    }
    
    // for nickels
    while(cent >= 5)
    {
        cent = cent - 5;
        amount++;
    }
    
    // for cents
    while(cent >= 1)
    {
        cent = cent - 1;
        amount++;
    }
    
    // print the number of coin retrun
    printf("%d\n", amount);
    
}
