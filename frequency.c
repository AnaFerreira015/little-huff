#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libs/frequency.h"

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
int *create_frequency_array(char arq[])
{
    /** Opens the file in binary read mode */
    FILE *file = fopen(arq, "rb");

    /** Creates an initialized array for the frequency */
    int *freq = (int *)calloc(MAX_SIZE, sizeof(int));

    // initialize_array(freq, MAX_SIZE, 0);

    int i;
    while (1)
    {
        if (!feof(file))
        {
            /** It takes each byte of the array and stores its frequency in the array. */
            U_BYTE c = fgetc(file);
            i = (int)c;
            freq[i] += 1;
        }
        else
        {
            break;
        }
    }

    return freq;
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

int main()
{
    int i;
    char file_name[256];

    printf("FILE: ");
    scanf("%s", file_name);

    printf("THE FILE %s IS OPENED\n", file_name);
    int *f = create_frequency_array(file_name);

    printing_frequency_array(f);

    return 0;
}