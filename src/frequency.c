#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libs/frequency.h"

// #define ANSI_COLOR_RED "\033[0;31m"
// #define ANSI_COLOR_RESET "\033[0;0m"

/**
 * @define MAX_SIZE
 * 
 * @discussion Maximum array size
*/
#define MAX_SIZE 256

/**
 * @typedef BYTE 
 * 
 * @discussion Uses unsigned char to preserve the pattern and the most significant bit to lose its function as signal bit
 */
typedef unsigned char U_BYTE;

/**
 * @discussion The function receives an array, its size and an index, and returns an array initialized with 0's
 * 
 * @param array An array
 * @param size The size of array
 * @param i An index
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
 * @discussion The function receives the file name and returns an array with the frequency of each byte in the file 
 *
 * @param arq The name of a file
 * @param freq The array for frequency 
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
 * @discussion Receive an array already created and display what's in it
 * 
 * @param array A frequency array
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