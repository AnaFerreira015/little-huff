#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include "frequency.c"

#define ANSI_COLOR_RESET "\033[0;0m"
#define ANSI_COLOR_LIGHT_MAGENTA "\033[1;95m"
#define ANSI_COLOR_GREEN "\033[1;32m"

int main()
{
    printf(ANSI_COLOR_LIGHT_MAGENTA "\n==============================================\n");
    printf("\n\tWELCOME TO LITTLE HUFF\n");
    printf(ANSI_COLOR_LIGHT_MAGENTA "\n==============================================\n");
    printf(ANSI_COLOR_RESET);

    int opt;

    while (1)
    {
        printf("Choose an Option\n");
        printf("1. Compress\n");
        printf("2. Decompress\n");
        printf("3. Exit\n");
        scanf("%d", &opt);

        char file_name[256];

        switch (opt)
        {
        case 1:
            printf("FILE: ");
            scanf("%s", file_name);
            printf("\n");

            printf("THE FILE %s IS OPENED\n", file_name);

            int *f = create_frequency_array(file_name);
            printing_frequency_array(f);
            break;

        case 2:
            break;

        case 3:
            return 0;
            break;

        default:
            printf("\nInvalid option! Try again: \n\n");
            break;
        }
    }

    return 0;
}
