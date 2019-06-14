#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SIZE 256

typedef unsigned char BYTE;

void initialize_array(int *array, int size, int i)
{
    if (i < size)
    {
        array[i] = 0;
        i += 1;
        initialize_array(array, size, i);
    }
}

int *create_frequency_array(char arq[])
{
    FILE *file = fopen(arq, "rb");

    int *freq = (int *)calloc(MAX_SIZE, sizeof(int));

    // initialize_array(freq, MAX_SIZE, 0);

    int i;
    while (1)
    {
        if (!feof(file))
        {
            BYTE c = fgetc(file);
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

void printing_frequency_array(int *array)
{
    int i;
    for (i = 0; i < MAX_SIZE; i++)
    {
        if (array[i])
        {
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