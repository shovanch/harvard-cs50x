/**
 * helpers.c
 *
 * Harvard CS50
 * Problem Set 3
 *
 * Shovan Chatterjee
 * 
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // implements a binary search
    
    // initialize min, max and midpoint
    int min = 0, max = n-1, mid;
    
    // runs untill the list has altleast one element left
    while(max >= min)
    {
        // calculate midpoint in each iteration   
        mid = (max + min) / 2;
        
        // if value found, returns true
        if(values[mid] == value)
        {
            return true;
        }
        else if(values[mid] < value) // if target value higher, go right
        {
            min = mid + 1;
        }
        else if(values[mid] > value) // if target  value lower, go left
        {
            max = mid - 1;
        }
    }
    
    return false;
    
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // implements selection sort
    int i , j , min , swap_val;
    
    for(i = 0; i < n ; i++)
    {
        min = i;
        
        for(j = i+1; j < n; j++)
        {
            if(values[j] < values[min])
            {
                min = j;
                
            }
            
        }
        
         swap_val = values[i];
         values[i] = values[min];
         values[min] = swap_val;
        
    }
    return  ;
}