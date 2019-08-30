#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libs/frequency.h"

#define MAX_SIZE 256

typedef unsigned char U_BYTE;

void initialize_array(int *array, int i)
{
    if (i < MAX_SIZE)
    {
        array[i] = 0;
        i += 1;
        initialize_array(array, i);
    }
}

void initialize_string(U_BYTE *array, int i)
{
    if (i < MAX_SIZE)
    {
        array[i] = '0';
        i += 1;
        initialize_string(array, i);
    }
}

void create_frequency_array(FILE *file, int freq[])
{    
    U_BYTE character;
    while (fscanf(file, "%c", &character) != EOF)
    {
        freq[character] += 1;
    }   
}

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