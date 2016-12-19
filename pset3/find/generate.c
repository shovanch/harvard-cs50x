/**
 * generate.c
 *
 * Harvard CS50
 * Problem Set 3
 * 
 * Shovan Chatterjee
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // Checks if the entered argument count is more than 3 or less than 2
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // Converts the entered pseudo num selector in string to an int
    int n = atoi(argv[1]);

    // Checks if there is an optional seed provided then seed the function with that
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // Generate the pseudo number capped under limit from 0 - 65536 is limit of value by unsigned int
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}