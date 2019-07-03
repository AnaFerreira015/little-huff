#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libs/frequency.h"

#define ANSI_COLOR_RED "\033[0;31m"
#define ANSI_COLOR_RESET "\033[0;0m"

#define MAX_SIZE 256

/**
 * - Uses unsigned char to preserve the pattern and the most significant bit to lose its function as signal bit
 */
typedef unsigned char U_BYTE;

/**
 * The function receives an array, its size and an index, and returns an array initialized with 0's
 */
void initialize_array(int *array, int size, int i)
{
    if (i < size)
    {
        array[i] = 0;
        i += 1;
        initialize_array(array, size, i);
    }
}

/**
* The function receives the file name and returns an array with the frequency of each byte in the file
 */
void create_frequency_array(char arq[], int freq[])
{
    /** Opens the file in binary read mode */
    FILE *file = fopen(arq, "rb");

    // if(file != NULL) {
        /** Initializes the array with 0's */
        initialize_array(freq, MAX_SIZE, 0);
        
        char i[2];
        while (fscanf(file, "%c", i) != EOF)
        {
            U_BYTE c = i[0];
            freq[c] += 1;
        }

    // }
    // else {
    //     printf("File doesn't exist\n");
    // }

}

/**
 * Receive an array already created and display what's in it
 */
void printing_frequency_array(int *array)
{
    int i;
    for (i = 0; i < MAX_SIZE; i++)
    {
        if (array[i])
        {
            /** Displays character and frequency */
            printf("%c %d\n", i, array[i]);
        }
    }
}